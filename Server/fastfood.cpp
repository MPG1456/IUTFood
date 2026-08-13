#include "fastfood.h"

FastFood::FastFood(QString name, QString ingredients, int capacity, double price ,int id , int restaurant_id) : MainDish(name, ingredients, capacity, price ,id , restaurant_id)
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


