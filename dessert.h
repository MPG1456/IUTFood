#ifndef DESSERT_H
#define DESSERT_H

#include "food.h"

class Dessert : public Food
{
public:
    Dessert(QString name, QString ingredients, int capacity, double price);
    void setName(QString newName = "NULL") override;
};

#endif // DESSERT_H
