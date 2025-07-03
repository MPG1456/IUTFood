#ifndef MENUFUNCTIONS_H
#define MENUFUNCTIONS_H

#include "food.h"
#include "menu.h"
#include <QDebug>

class MenuFunctions
{
private:
    Menu &myMenu;

public:
    MenuFunctions(Menu &newMenu);
    void addFood(Food *newFood);
    void deleteFood(Food *newFood);
    Food * searchFood(Food *newFood);
    // void editFood(); I don't think this part is neccessary. Just delete a food and add a new one.
};

#endif // MENUFUNCTIONS_H
