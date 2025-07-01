#ifndef MAINDISH_H
#define MAINDISH_H

#include "food.h"

class MainDish : public Food
{
private:
    QString dishType;
public:
    MainDish(QString name, QString ingredients, int capacity, double price);
    void setType(QString newType = "NULL") override;
    virtual void setDishType() = 0;
};

#endif // MAINDISH_H
