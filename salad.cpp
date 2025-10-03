#include "salad.h"

Salad::Salad(QString name, QString ingredients, int capacity, double price ,int id) : Food(name, ingredients, capacity, price ,id)
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
