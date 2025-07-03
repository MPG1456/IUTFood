#ifndef MENU_H
#define MENU_H

#include "food.h"
#include <QSet>

class MenuFunctions;

class Menu
{
    friend class MenuFunctions;

private:
    QSet<Food *> menu;

public:
    // void showMenu();
};

#endif // MENU_H
