#ifndef SALAD_H
#define SALAD_H

#include "food.h"

class Salad : public Food
{
    friend QDataStream &operator<<(QDataStream &out, const Salad &salad);
    friend QDataStream &operator>>(QDataStream &in, Salad &salad);

public:
    Salad() = default;
    Salad(QString name, QString ingredients, int capacity, double price ,int id , int restaurant_id);
    void setType(QString newType = "NULL");
};

#endif // SALAD_H
