#ifndef MENU_H
#define MENU_H

#include "food.h"
#include <QSet>

class Menu
{
private:
    QSet<Food *> menu;
public:
    Menu();
    // showMenu();
};

#endif // MENU_H
