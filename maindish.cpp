#include "maindish.h"

MainDish::MainDish(QString name, QString ingredients, int capacity, double price) : Food(name, ingredients, capacity, price)
{
    this->setType();
}

void MainDish::setType(QString newType)
{
    if(newType == "NULL")
        type = "MainDish";
    else
        type = newType;
}
