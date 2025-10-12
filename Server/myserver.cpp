#include "myserver.h"
#include <QDateTime>

MyServer::MyServer(QObject *parent):QTcpServer(parent)
{
    if (!listen(QHostAddress::Any, 1234))
    {
        qDebug()<<"server is not listening!";
    }
    else
    {
        qDebug()<<"serverz is listening!";
    }
}
void MyServer::incomingConnection(qintptr socketDescriptor)
{
    QTcpSocket *socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket , &QTcpSocket::readyRead , this , &MyServer::onReadyRead);
    connect(socket , &QTcpSocket::disconnected , this , &MyServer::onDisconnected);
    roles[socket] = "unknown";
    qDebug()<<"new connection!";
    QJsonObject allData;
    allData["clients"] = clientDataBase.dbToJson().array();
    allData["delivery"] = deliveryDataBase.dbToJson().array();
    allData["restaurants"] = restaurantDataBase.dbToJson().array();
    allData["menus"] = menuDataBase.dbToJson().array();
    allData["orders"] = orderDataBase.dbToJson().array();
    allData["ordered_foods"] = orderedDataBase.dbToJson().array();
    QJsonDocument doc(allData);
    QByteArray jsonData = doc.toJson(QJsonDocument::Compact);
    socket->write(jsonData);
    socket->flush();
}
void MyServer::onReadyRead()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    QByteArray data = socket->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isObject()) return;

    QJsonObject obj = doc.object();

    QString type = obj["type"].toString();
//dash bayad tooye json ye chizi bezari ke maloom bashe az taraf client
    QJsonDocument responseDoc;
    if (type == "signup")
    {
        QString role = obj["role"].toString();
        if(role=="Client")
        {
        responseDoc =handleClientSignUp(obj);
        }
        else if(role == "Delivery")
        {
        responseDoc =handleDeliverySignUp(obj);
        }
        else if(role == "Restaurant")
        {
        responseDoc =handleRestaurantSignUp(obj);
        }
        socket->write(responseDoc.toJson());
    }
}
void MyServer::onDisconnected()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    roles.remove(socket);
    socket->deleteLater();
}
QJsonDocument MyServer::handleClientSignUp(QJsonObject obj)
{
    QString username = obj["username"].toString();
    QString password = obj["password"].toString();
    QString firstname = obj["firstname"].toString();
    QString lastname = obj["lastname"].toString();
    int age = obj["age"].toInt();
    QString country = obj["country"].toString();
    QString city = obj["city"].toString();
    int postalcode = obj["postalcode"].toString().toInt();
    QString homeAddress = obj["homeAddress"].toString();
    QString homePhone = obj["homePhone"].toString();
    QString phoneNumber = obj["phoneNumber"].toString();

    bool success = clientDataBase.addUser(username, password, firstname, lastname, age, country, city, postalcode, homeAddress, homePhone, phoneNumber);

    QJsonObject reply;
    reply["type"] = "signup_response";
    reply["success"] = success;

    QJsonDocument responseDoc(reply);
    return responseDoc;
}
QJsonDocument MyServer::handleDeliverySignUp(QJsonObject obj)
{
    QString username = obj["username"].toString();
    QString password = obj["password"].toString();
    QString firstname = obj["firstname"].toString();
    QString lastname = obj["lastname"].toString();
    int age = obj["age"].toInt();
    QString country = obj["country"].toString();
    QString city = obj["city"].toString();
    int postalcode = obj["postalcode"].toString().toInt();
    QString homeAddress = obj["homeAddress"].toString();
    QString homePhone = obj["homePhone"].toString();
    QString phoneNumber = obj["phoneNumber"].toString();

    bool success = deliveryDataBase.addUser(username, password, firstname, lastname, age, country, city, postalcode, homeAddress, homePhone, phoneNumber);

    QJsonObject reply;
    reply["type"] = "signup_response";
    reply["success"] = success;

    QJsonDocument responseDoc(reply);
    return responseDoc;
}
QJsonDocument MyServer::handleRestaurantSignUp(QJsonObject obj)
{
    QString username = obj["username"].toString();
    QString password = obj["password"].toString();
    QString restaurantName = obj["restaurantName"].toString();
    QString bio = obj["bio"].toString();
    QString country = obj["country"].toString();
    QString city = obj["city"].toString();
    int postalcode = obj["postalcode"].toString().toInt();
    QString address = obj["address"].toString();
    QString homePhone = obj["homePhone"].toString();
    QString phoneNumber = obj["phoneNumber"].toString();
    QString currentDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd");

    bool success = restaurantDataBase.addRestaurant(username, password, restaurantName,
                                                    country, city, postalcode,
                                                    address,homePhone, bio , phoneNumber, currentDateTime, "0" , "0");
    QJsonObject reply;
    reply["type"] = "restaurant_signup_response";
    reply["success"] = success;

    QJsonDocument responseDoc(reply);
    return responseDoc;
}
