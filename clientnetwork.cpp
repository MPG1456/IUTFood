#include "clientnetwork.h"
#include "datastore.h"

clientNetwork::clientNetwork(QObject *parent):QObject(parent)
{
    socket.connectToHost("127.0.0.1" , 1234);
    connect(&socket , &QTcpSocket::connected , [](){qDebug()<<"connected!"; });
    connect(&socket, &QTcpSocket::readyRead, this, &clientNetwork::onReadyRead);

}
Q_INVOKABLE void clientNetwork::sendData(const QString& message)
{
        if (socket.state()== QTcpSocket::ConnectedState)
        {
        socket.write(message.toUtf8());
        }
}
void  clientNetwork::onReadyRead()
{
    QByteArray allData = socket.readAll();
    QJsonDocument jsDoc = QJsonDocument::fromJson(allData);
    if (!jsDoc.isNull() && jsDoc.isObject())
    {
        // QJsonObject allData = jsDoc.object();
        loadClientFromDb(jsDoc);
        loadDeliveryFromDb(jsDoc);
        loadMenuFromDb(jsDoc);
        loadRestaurantFromDb(jsDoc);
        loadOrderFromDb(jsDoc);
        loadOrderedFoodsFromDb(jsDoc);
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
        identity.setId(obj["id"].toInt());

        auto Cptr = QSharedPointer<Customer>::create(identity);
        DataStore::instance().addClient(Cptr);
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
        identity.setId(obj["id"].toInt());

        Score score;
        score.addScore(obj["score"].toDouble());
        score.setCounter(obj["score_counter"].toInt());
        identity.setScore(score);

        MyTime time;
        time.setTime(obj["time"].toString());
        identity.setTime(time);

        auto Rptr = QSharedPointer<Restaurant>::create();
        Rptr->setIdentity(identity);
        DataStore::instance().addRestaurant(Rptr);
    }
}

void clientNetwork::loadMenuFromDb(QJsonDocument doc)
{
    QJsonObject root = doc.object();
    QJsonArray menuArray = root["menus"].toArray();
    for (auto val : menuArray)
    {
        QJsonObject obj = val.toObject();
        QSharedPointer<Food> f = nullptr;

        if (obj["type"].toString() == "salad")
            f = QSharedPointer<Food>::create(obj["name"].toString(), obj["ingredients"].toString(), obj["capacity"].toInt(), obj["price"].toDouble(), obj["id"].toInt() , obj["restaurant_id"].toInt());
        else if (obj["type"].toString() == "drinks")
            f = QSharedPointer<Food>::create(obj["name"].toString(), obj["ingredients"].toString(), obj["capacity"].toInt(), obj["price"].toDouble(), obj["id"].toInt() , obj["restaurant_id"].toInt());
        else if (obj["type"].toString() == "dessert")
            f = QSharedPointer<Food>::create(obj["name"].toString(), obj["ingredients"].toString(), obj["capacity"].toInt(), obj["price"].toDouble(), obj["id"].toInt() , obj["restaurant_id"].toInt());
        else if (obj["type"].toString() == "iranifood")
            f = QSharedPointer<Food>::create(obj["name"].toString(), obj["ingredients"].toString(), obj["capacity"].toInt(), obj["price"].toDouble(), obj["id"].toInt() , obj["restaurant_id"].toInt());
        else if (obj["type"].toString() == "fastfood")
            f = QSharedPointer<Food>::create(obj["name"].toString(), obj["ingredients"].toString(), obj["capacity"].toInt(), obj["price"].toDouble(), obj["id"].toInt() , obj["restaurant_id"].toInt());

        if (f)
            DataStore::instance().addFood(f);
    }
}

void clientNetwork::loadOrderFromDb(QJsonDocument doc)
{
    QJsonObject root = doc.object();
    QJsonArray ordersArray = root["orders"].toArray();
    for (auto val : ordersArray)
    {
        QJsonObject obj = val.toObject();
        auto Optr = QSharedPointer<order>::create();
        Optr->setId(obj["id"].toInt());
        Optr->setClientId(obj["client_id"].toInt());
        Optr->setRestaurantId(obj["restaurant_id"].toInt());
        Optr->setDeliveryId(obj["delivery_id"].toInt());
        Optr->setOrderTime(obj["order_time"].toString());
        Optr->setReachedTime(obj["reached_time"].toString());
        Optr->setStatus(obj["status"].toString());
        DataStore::instance().addOrder(Optr);
    }
}

void clientNetwork::loadDeliveryFromDb(QJsonDocument doc)
{
    QJsonObject root = doc.object();
    QJsonArray deliveryArray = root["delivery"].toArray();
    for (auto val : deliveryArray)
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
        identity.setId(obj["id"].toInt());

        auto Dptr = QSharedPointer<delivery>::create(identity);
        DataStore::instance().addDelivery(Dptr);
    }
}
void clientNetwork::loadOrderedFoodsFromDb(QJsonDocument doc)
{
    QJsonObject root = doc.object();
    QJsonArray orderedArray = root["ordered_foods"].toArray();
    for (auto val : orderedArray)
    {
        QJsonObject obj = val.toObject();
        auto Optr = QSharedPointer<orderedFood>::create();
        Optr->setId(obj["id"].toInt());
        Optr->setOrderId(obj["order_id"].toInt());
        Optr->setMenuId(obj["menu_id"].toInt());
        Optr->setQuantity(obj["quantity"].toInt());
        DataStore::instance().addOrderedFood(Optr);
    }
}
