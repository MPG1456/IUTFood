#ifndef FASTFOOD_H
#define FASTFOOD_H

#include "maindish.h"

class FastFood : public MainDish
{

public:
    FastFood() = default;
    FastFood(QString name, QString ingredients, int capacity, double price ,int id , int restaurant_id);
    void setDishType(QString newDishType = "NULL") override;
};
#endif // FASTFOOD_H
