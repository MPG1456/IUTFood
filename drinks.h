#ifndef DRINKS_H
#define DRINKS_H

#include "food.h"

class Drinks : public Food
{
public:
    Drinks(QString name, QString ingredients, int capacity, double price);
    void setType(QString newType = "NULL") override;
};
#endif // DRINKS_H
