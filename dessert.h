#ifndef DESSERT_H
#define DESSERT_H

#include "food.h"

class Dessert : public Food
{
    friend QDataStream &operator<<(QDataStream &out, const Dessert &dessert);
    friend QDataStream &operator>> (QDataStream &in, Dessert &dessert);

public:
    Dessert() = default;
    Dessert(QString name, QString ingredients, int capacity, double price);
    void setType(QString newType = "NULL") override;
};

#endif // DESSERT_H
