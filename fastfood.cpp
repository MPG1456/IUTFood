#include "fastfood.h"

FastFood::FastFood(QString name, QString ingredients, int capacity, double price) : MainDish(name, ingredients, capacity, price)
{
    this->setDishType();
}

void FastFood::setDishType(QString newDishType)
{
    if(newDishType == "NULL")
        dishType = "FastFood";
    else
        dishType = newDishType;
}
