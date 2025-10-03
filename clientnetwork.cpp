#include "clientnetwork.h"

clientNetwork::clientNetwork(QObject *parent):QObject(parent)
{
    socket.connectToHost("127.0.0.1" , 1234);
    connect(&socket , &QTcpSocket::connected , [](){qDebug()<<"connected!"; });
    connect(&socket , &QTcpSocket::readyRead , [&](){
        QByteArray receivedData = socket.readAll();
        qDebug()<<"received data:"<<receivedData;
    });
}
void clientNetwork::sendData(const QString& message)
{
        if (socket.state()== QTcpSocket::ConnectedState)
        {
        socket.write(message.toUtf8());
        }
}
void clientNetwork::onReadyRead()
{
    QByteArray allData = socket.readAll();
    QJsonDocument jsDoc = QJsonDocument::fromJson(allData);
    if (!jsDoc.isNull() && jsDoc.isObject())
    {
        QJsonObject allData = jsDoc.object();

    }
}
void clientNetwork::loadClientFromDb(QJsonDocument doc)
{
    QJsonObject root = doc.object();
    QJsonArray clientsArray = root["clients"].toArray();
    for (auto val : clientsArray)
    {
        QJsonObject obj = val.toObject();
        Address addr;
        QJsonObject addrObj = obj["address"].toObject();
        addr.setCity(addrObj["city"].toString());
        addr.setCountry(addrObj["country"].toString());
        addr.setPostalCode(addrObj["postalCode"].toInt());
        addr.setHomeAddress(addrObj["homeAddress"].toString());
        addr.setHomePhone(addrObj["homePhone"].toString());
        PersonIdentity identity;
        identity.setUsername(obj["username"].toString());
        identity.setPassword(obj["password"].toString());
        identity.setFirstName(obj["firstName"].toString());
        identity.setLastName(obj["lastName"].toString());
        identity.setPhoneNumber(obj["phoneNumber"].toString());
        identity.setAge(obj["age"].toInt());
        identity.setAddress(addr);
        Person p;
        p.setIdentity(identity);
        //add to vector clients
    }
}
void clientNetwork::loadRestaurantFromDb(QJsonDocument doc)
{
    QJsonObject root = doc.object();
    QJsonArray restaurantsArray = root["clients"].toArray();
    for (auto val : restaurantsArray)
    {
        QJsonObject obj = val.toObject();
        Address addr;
        QJsonObject addrObj = obj["address"].toObject();
        addr.setCity(addrObj["city"].toString());
        addr.setCountry(addrObj["country"].toString());
        addr.setPostalCode(addrObj["postalCode"].toInt());
        addr.setHomeAddress(addrObj["homeAddress"].toString());
        addr.setHomePhone(addrObj["homePhone"].toString());
        RestaurantIdentity identity;
        identity.setUsername(obj["username"].toString());
        identity.setPassword(obj["password"].toString());
        identity.setName(obj["restaurantName"].toString());
        identity.setBio(obj["bio"].toString());
        identity.setPhonenumber(obj["phoneNumber"].toString());
        identity.setAddress(addr);
        Restaurant R;
        R.setIdentity(identity);
        //add to vector clients
        obj["id"] = query.value("id").toInt();
        obj["username"] = query.value("username").toString();
        obj["password"] = query.value("password").toString();
        obj["restaurantname"] = query.value("restaurantname").toString();
        obj["bio"] = query.value("bio").toString();
        obj["phoneNumber"] = query.value("phoneNumber").toString();
        obj["time"] = query.value("time").toString();
        obj["score"] = query.value("score").toString();
        obj["score_counter"] = query.value("score_counter").toString();
    }
}
void clientNetwork::loadMenuFromDb(QJsonDocument doc)
{

}
void clientNetwork::loadOrderFromDb(QJsonDocument doc)
{

}
void clientNetwork::loadDeliveryFromDb(QJsonDocument doc)
{

}
