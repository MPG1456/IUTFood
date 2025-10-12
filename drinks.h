#ifndef DRINKS_H
#define DRINKS_H

#include "food.h"

class Drinks : public Food
{
    friend QDataStream &operator<< (QDataStream &out, const Drinks &drinks);
    friend QDataStream &operator>> (QDataStream &in, Drinks &drinks);
public:
    Drinks() = default;
    Drinks(QString name, QString ingredients, int capacity, double price , int id , int restaurant_id);
    void setType(QString newType = "NULL");
};
#endif // DRINKS_H
