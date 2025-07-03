#ifndef FOOD_H
#define FOOD_H

#include <QString>
#include <QDataStream>

class Dessert;
class Drinks;
class Salad;
class MainDish;

class MenuFunctions;

class Food
{
    friend class Dessert;
    friend class Salad;
    friend class Drinks;
    friend class MainDish;

    friend class MenuFunctions;

    friend void serializeFood(QDataStream &out, const Food &food);
    friend void deserializeFood(QDataStream &in, Food &food);

private:
    QString name;
    QString type;
    QString ingredients;
    int capacity;
    double price;

public:
    Food() = default;
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
