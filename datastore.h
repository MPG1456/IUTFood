#ifndef DATASTORE_H
#define DATASTORE_H

#include <QObject>
#include <QVector>
#include "customer.h"
#include "delivery.h"
#include "restaurant.h"
#include "order.h"
#include "food.h"
#include <QSharedPointer>
#include "orderedfood.h"
class DataStore : public QObject
{
    Q_OBJECT
private:
    QVector <QSharedPointer<Customer>> clients;
    QVector <QSharedPointer<Restaurant>> restaurants;
    QVector <QSharedPointer<delivery>> deliveries;
    // QVector <QSharedPointer<Food>> ordered_foods;
    QVector <QSharedPointer<order>> orders;
    QVector <QSharedPointer<Food>> foods;
    QVector <QSharedPointer<orderedFood>> ordered_foods;
public:
    DataStore() = default;
    ~DataStore() = default;
    static DataStore& instance();
    Q_INVOKABLE bool checkClientUserPass(QString username , QString password);
    Q_INVOKABLE bool checkRestaurantUserPass(QString username , QString password);
    Q_INVOKABLE bool checkDeliveryUserPass(QString username , QString password);
    Q_INVOKABLE void addClient(QSharedPointer<Customer> newClient);
    Q_INVOKABLE void addRestaurant(QSharedPointer<Restaurant> newRestaurant);
    Q_INVOKABLE void addDelivery(QSharedPointer<delivery> newDelivery);
    Q_INVOKABLE void addFood(QSharedPointer<Food> newFood);
    Q_INVOKABLE void addOrder(QSharedPointer<order> newOrder);
    Q_INVOKABLE void addOrderedFood(QSharedPointer<orderedFood> newOrdered);
    // Q_INVOKABLE void addMenu(int id , int restaurant_id , QString name , QString ingredients , QString type,);
};

#endif // DATASTORE_H
