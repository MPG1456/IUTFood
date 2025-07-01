#ifndef SALAD_H
#define SALAD_H

#include "food.h"

class Salad : public Food
{
public:
    Salad(QString name, QString ingredients, int capacity, double price);
    void setType(QString newType = "NULL") override;
};

#endif // SALAD_H
