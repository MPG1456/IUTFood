#include "datastore.h"

DataStore& DataStore::instance()
{
    static DataStore s;
    return s;
}
bool DataStore::checkClientUserPass(QString username , QString password)
{
    for(auto client : clients)
    {
        if (client->getIdentity().getUsername()==username)
        {
            if(client->getIdentity().getPassword()== password)
            {
                qDebug()<<client->getIdentity().getUsername()<<client->getIdentity().getPassword()<<"khoda";
                return true;
            }
        }
    }
    return false;
}
bool DataStore::checkRestaurantUserPass(QString username , QString password)
{
    for (auto restaurant : restaurants)
    {
        if(restaurant->getIdentity().getUsername()==username)
        {
            if(restaurant->getIdentity().getPassword()==password)
            {
                qDebug()<<username<<password;
                return true;
            }
        }
    }
    return false;
}
bool DataStore::checkDeliveryUserPass(QString username , QString password)
{
    for (auto delivery : deliveries)
    {
        if(delivery->getIdentity().getUsername()==username)
        {
            if(delivery->getIdentity().getPassword()==password)
            {
                return true;
            }
        }
    }
    return false;
}
Q_INVOKABLE void DataStore::addClient(QSharedPointer<Customer> newClient)
{
    this->clients.append(newClient);
}
Q_INVOKABLE void DataStore::addRestaurant(QSharedPointer<Restaurant> newRestaurant)
{
    this->restaurants.append(newRestaurant);
}
Q_INVOKABLE void DataStore::addDelivery(QSharedPointer<delivery> newDelivery)
{
    this->deliveries.append(newDelivery);
}
Q_INVOKABLE void DataStore::addFood(QSharedPointer<Food> newFood)
{
    foods.append(newFood);
}
Q_INVOKABLE void DataStore::addOrder(QSharedPointer<order> newOrder)
{
    orders.append(newOrder);
}
Q_INVOKABLE void DataStore::addOrderedFood(QSharedPointer<orderedFood> newOrdered)
{
    ordered_foods.append(newOrdered);
}
