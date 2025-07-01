#ifndef IRANIFOOD_H
#define IRANIFOOD_H

#include "maindish.h"

class IraniFood : public MainDish
{
public:
    IraniFood(QString name, QString ingredients, int capacity, double price);
    void setDishType(QString newDishType = "NULL") override;
};
#endif // IRANIFOOD_H
