#ifndef SALAD_H
#define SALAD_H

#include "food.h"

class Salad : public Food
{

public:
    Salad() = default;
    Salad(QString name, QString ingredients, int capacity, double price ,int id , int restaurant_id);
    void setType(QString newType = "NULL");
};

#endif // SALAD_H
