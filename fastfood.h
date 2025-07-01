#ifndef FASTFOOD_H
#define FASTFOOD_H

#include "maindish.h"

class FastFood : public MainDish
{
public:
    FastFood(QString name, QString ingredients, int capacity, double price);
    void setDishType(QString newDishType = "NULL") override;
};
#endif // FASTFOOD_H
