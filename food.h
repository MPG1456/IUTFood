#ifndef FOOD_H
#define FOOD_H

#include <QString>

class Dessert;

class Food
{
    friend class Dessert;
private:
    QString name;
    QString type;
    QString ingredients;
    int capacity;
    double price;

public:
    Food(QString newName, QString newIngredients, int newCapacity, double newPrice);
    QString getName();
    void setName(QString newName);
    QString getType();
    virtual void setType(QString newType = "NULL") = 0;
    QString getIngredients();
    void setIngredients(QString newIngredients);
    int getCapacity();
    void setCapacity(int newCapacity);
    double getPrice();
    void setPrice(double newPrice);
};

#endif // FOOD_H
