#include "salad.h"

Salad::Salad(QString name, QString ingredients, int capacity, double price) : Food(name, ingredients, capacity, price)
{
    this->setType();
}

void Salad::setType(QString newType)
{
    if(newType == "NULL")
        type = "Salad";
    else
        type = newType;
}
