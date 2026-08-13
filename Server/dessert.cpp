#include "dessert.h"

Dessert::Dessert(QString name, QString ingredients, int capacity, double price ,int id , int restaurant_id) : Food(name, ingredients, capacity, price ,id ,restaurant_id)
{
    this->setType();
}

void Dessert::setType(QString newType)
{
    if(newType == "NULL")
        type = "Dessert";
    else
        type = newType;
}
