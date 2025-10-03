#ifndef DATASTORE_H
#define DATASTORE_H

#include <QObject>
#include <QVector>
#include "customer.h"
#include "delivery.h"
#include "restaurant.h"
#include "order.h"
#include "food.h"

class DataStore : public QObject
{
    Q_OBJECT
public:
    DataStore() = default;
    static DataStore& instance()ک
    QVector <Customer> cllients;
    QVector <Restaurant> restaurants;
    QVector <delivery> deliverys;
    QVector <Food*> foods;
    QVector <order> orders;
};

#endif // DATASTORE_H
