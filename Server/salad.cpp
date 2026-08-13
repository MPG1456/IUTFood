#include "salad.h"

Salad::Salad(QString name, QString ingredients, int capacity, double price ,int id , int restaurant_id) : Food(name, ingredients, capacity, price ,id , restaurant_id)
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
