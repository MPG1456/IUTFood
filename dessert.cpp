#include "dessert.h"

Dessert::Dessert(QString name, QString ingredients, int capacity, double price) : Food(name, ingredients, capacity, price)
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
