#ifndef FOOD_H
#define FOOD_H

#include <QString>

class Food
{
private:
    QString name;
    QString type;
    QString ingredients;
    int capacity;
    double price;

public:
    Food(QString newName, QString newIngredients, int newCapacity, double newPrice);
    QString getName();
    virtual void setName(QString newName = "NULL") = 0;
    QString getType();
    void setType(QString newType);
    QString getIngredients();
    void setIngredients(QString newIngredients);
    int getCapacity();
    void setCapacity(int newCapacity);
    double getPrice();
    void setPrice(double newPrice);
};

#endif // FOOD_H
