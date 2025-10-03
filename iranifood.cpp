#include "iranifood.h"

IraniFood::IraniFood(QString name, QString ingredients, int capacity, double price ,int id) : MainDish(name, ingredients, capacity, price , id)
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
