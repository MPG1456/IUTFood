#ifndef IRANIFOOD_H
#define IRANIFOOD_H

#include "maindish.h"

class IraniFood : public MainDish
{
    friend QDataStream &operator<< (QDataStream &out, const IraniFood &iranifood);
    friend QDataStream &operator>> (QDataStream &in, FastFood &iranifood);
public:
    IraniFood() = default;
    IraniFood(QString name, QString ingredients, int capacity, double price);
    void setDishType(QString newDishType = "NULL") override;
};
#endif // IRANIFOOD_H
