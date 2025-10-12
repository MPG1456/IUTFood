#include "maindish.h"

MainDish::MainDish(QString name, QString ingredients, int capacity, double price ,int id , int restaurant_id) : Food(name, ingredients, capacity, price ,id ,restaurant_id) , dishType("NULL")
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
