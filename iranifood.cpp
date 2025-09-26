#include "iranifood.h"

IraniFood::IraniFood(QString name, QString ingredients, int capacity, double price) : MainDish(name, ingredients, capacity, price)
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
