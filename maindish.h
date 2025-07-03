#ifndef MAINDISH_H
#define MAINDISH_H

#include "food.h"

class IraniFood;
class FastFood;

class MainDish : public Food
{
    friend IraniFood;
    friend FastFood;

    friend void serializeMainDish(QDataStream &out, const MainDish &dish);
    friend void deserializeMainDish(QDataStream &in, MainDish &dish);

private:
    QString dishType;

public:
    MainDish() = default;
    MainDish(QString name, QString ingredients, int capacity, double price);
    void setType(QString newType = "NULL") override;
    virtual void setDishType(QString newMainDish = "NULL") = 0;
};

#endif // MAINDISH_H
