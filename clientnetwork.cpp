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
        Customer C(identity);
        //add to vector clients
    }
}
void clientNetwork::loadRestaurantFromDb(QJsonDocument doc)
{
    QJsonObject root = doc.object();
    QJsonArray restaurantsArray = root["restaurants"].toArray();
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
        Score score;
        score.addScore(obj["score"].toDouble());
        score.setCounter(obj["score_counter"].toInt());
        identity.setScore(score);
        MyTime time;
        time.setTime(obj["time"].toString());
        identity.setTime(time);
        Restaurant R;
        R.setIdentity(identity);

        //add to vector restaurants
    }
}
void clientNetwork::loadMenuFromDb(QJsonDocument doc)
{
    QJsonObject root = doc.object();
    QJsonArray menuArray = root["menus"].toArray();
    for (auto val : menuArray)
    {
        QJsonObject obj = val.toObject();
        Food *f = nullptr;
        if (obj["type"]=="salad")
        {
            f = new Salad(obj["name"].toString() , obj["ingredients"].toString(), obj["capacity"].toInt() ,obj["price"].toDouble() , obj["id"].toInt());
        }
        else if (obj["type"]=="drinks")
        {
            f = new Drinks(obj["name"].toString() , obj["ingredients"].toString(), obj["capacity"].toInt() ,obj["price"].toDouble() ,obj["id"].toInt());
        }
        else if (obj["type"]=="dessert")
        {
            f = new Dessert(obj["name"].toString() , obj["ingredients"].toString(), obj["capacity"].toInt() ,obj["price"].toDouble() ,obj["id"].toInt());
        }
        else if (obj["type"]=="iranifood")
        {
            f = new IraniFood(obj["name"].toString() , obj["ingredients"].toString(), obj["capacity"].toInt() ,obj["price"].toDouble() ,obj["id"].toInt());
        }
        else if (obj["type"]=="fastfood")
        {
            f = new FastFood(obj["name"].toString() , obj["ingredients"].toString(), obj["capacity"].toInt() ,obj["price"].toDouble() ,obj["id"].toInt());
        }
        if (f)
        {
            //add to vector menus

        }
    }
}
void clientNetwork::loadOrderFromDb(QJsonDocument doc)
{

}
void clientNetwork::loadDeliveryFromDb(QJsonDocument doc)
{
    QJsonObject root = doc.object();
    QJsonArray deliveiesArray = root["clients"].toArray();
    for (auto val : deliveiesArray)
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
        delivery D(identity);
        //add to vector clients
    }
}
