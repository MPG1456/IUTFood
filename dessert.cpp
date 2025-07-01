#include "dessert.h"

Dessert::Dessert(QString name, QString ingredients, int capacity, double price) : Food(name, ingredients, capacity, price)
{
    this->setName();
}

void Dessert::setName(QString newName)
{
    if(newName == "NULL")
        name = "Dessert";
    else
        name = newName;
}
