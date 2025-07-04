#include "menu.h"

// Menu::showMenu();

Menu::Menu(const Menu &other)
{
    for(int i = 0; i < other.menu.size(); ++i)
        this->menu[i] = other.menu[i];
}

Menu &Menu::operator=(const Menu &other)
{
    for(int i = 0; i < other.menu.size(); ++i)
        this->menu[i] = other.menu[i];

    return *this;
}
