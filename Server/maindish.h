#ifndef MAINDISH_H
#define MAINDISH_H

#include "food.h"

class IraniFood;
class FastFood;

class MainDish : public Food
{
    friend IraniFood;
    friend FastFood;


private:
    QString dishType;

public:
    MainDish() = default;
    MainDish(QString name, QString ingredients, int capacity, double price ,int id , int restaurant_id);
    void setType(QString newType = "NULL");
    virtual void setDishType(QString newMainDish = "NULL") = 0;
};

#endif // MAINDISH_H
