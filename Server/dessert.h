#ifndef DESSERT_H
#define DESSERT_H

#include "food.h"

class Dessert : public Food
{

public:
    Dessert() = default;
    Dessert(QString name, QString ingredients, int capacity, double price ,int id , int restaurant_id);
    void setType(QString newType = "NULL");
};

#endif // DESSERT_H
