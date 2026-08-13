#ifndef IRANIFOOD_H
#define IRANIFOOD_H

#include "maindish.h"

class IraniFood : public MainDish
{
public:
    IraniFood() = default;
    IraniFood(QString name, QString ingredients, int capacity, double price ,int id , int restaurant_id);
    void setDishType(QString newDishType = "NULL") override;
};
#endif // IRANIFOOD_H
