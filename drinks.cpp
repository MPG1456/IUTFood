#include "drinks.h"

Drinks::Drinks(QString name, QString ingredients, int capacity, double price ,int id) : Food(name, ingredients, capacity, price ,id)
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
