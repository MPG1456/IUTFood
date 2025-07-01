#include "drinks.h"

Drinks::Drinks() {}
Drinks::Drinks(QString name, QString ingredients, int capacity, double price) : Food(name, ingredients, capacity, price)
{
    this->setType();
}

void Drinks::setType(QString newType)
{
    if(newType == "NULL")
        type = "Drinks";
    else
        type = newType;
}
