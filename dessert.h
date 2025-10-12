#ifndef DESSERT_H
#define DESSERT_H

#include "food.h"

class Dessert : public Food
{
    friend QDataStream &operator<<(QDataStream &out, const Dessert &dessert);
    friend QDataStream &operator>> (QDataStream &in, Dessert &dessert);

public:
    Dessert() = default;
    Dessert(QString name, QString ingredients, int capacity, double price ,int id , int restaurant_id);
    void setType(QString newType = "NULL");
};

#endif // DESSERT_H
