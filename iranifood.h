#ifndef IRANIFOOD_H
#define IRANIFOOD_H

#include "maindish.h"

class IraniFood : public MainDish
{
public:
    IraniFood(QString name, QString ingredients, int capacity, double price);
    void setDishType() override;
};
#endif // IRANIFOOD_H
