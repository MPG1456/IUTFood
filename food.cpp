#include "food.h"

Food::Food(QString newName, QString newIngredients,
           int newCapacity, double newPrice) : name(newName), type("NULL"),
                                               ingredients(newIngredients), capacity(newCapacity),
                                               price(newPrice)
{}

QString Food::getName()
{
    return name;
}

void Food::setName(QString newName)
{
    this->name = newName;
}

QString Food::getType()
{
    return type;
}

QString Food::getIngredients()
{
    return ingredients;
}

void Food::setIngredients(QString newIngredients)
{
    this->ingredients = newIngredients;
}

int Food::getCapacity()
{
    return capacity;
}

void Food::setCapacity(int newCapacity)
{
    this->capacity = newCapacity;
}

double Food::getPrice()
{
    return price;
}

void Food::setPrice(double newPrice)
{
    this->price = newPrice;
}




