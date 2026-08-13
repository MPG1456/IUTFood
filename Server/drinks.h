#ifndef DRINKS_H
#define DRINKS_H

#include "food.h"

class Drinks : public Food
{
public:
    Drinks() = default;
    Drinks(QString name, QString ingredients, int capacity, double price , int id , int restaurant_id);
    void setType(QString newType = "NULL");
};
#endif // DRINKS_H
