#ifndef MENU_H
#define MENU_H

#include "food.h"
#include <QSet>
#include <QVector>
#include <QSharedPointer>
// class MenuFunctions;

class Menu
{
    // friend class MenuFunctions;


private:
    QVector<QSharedPointer<Food>> menu;
public:
    Menu() = default;
    Menu(const Menu &other);
    Menu &operator=(const Menu &other);
    // void showMenu();
};

#endif // MENU_H
