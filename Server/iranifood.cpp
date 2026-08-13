#include "iranifood.h"

IraniFood::IraniFood(QString name, QString ingredients, int capacity, double price ,int id , int restaurant_id) : MainDish(name, ingredients, capacity, price , id ,restaurant_id)
{
    setDishType();
}
void IraniFood::setDishType(QString newDishType)
{
    if(newDishType == "NULL")
        dishType = "Irani Food";
    else
        dishType = newDishType;
}
