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

    friend QDataStream &operator<< (QDataStream &out, const Menu &menu);
    friend QDataStream &operator>> (QDataStream &in, Menu &menu);

private:
    QVector<QSharedPointer<Food>> menu;
public:
    Menu() = default;
    Menu(const Menu &other);
    Menu &operator=(const Menu &other);
    // void showMenu();
};

#endif // MENU_H
