#include "menufunctions.h"

MenuFunctions::MenuFunctions(Menu &newMenu) : myMenu(newMenu)
{}

void MenuFunctions::addFood(Food *newFood)
{
    if(searchFood(newFood))
    {
        qDebug() << "This food already exists in the menu";
        return;
    }
    myMenu.menu.insert(newFood);
}

void MenuFunctions::deleteFood(Food *newFood)
{
    if(!searchFood(newFood))
    {
        qDebug() << "This Food doesn't exist!";
        return;
    }
    myMenu.menu.remove(newFood);
}

Food * MenuFunctions::searchFood(Food *newFood)
{
    QSet<Food *>::Iterator it;
    for(const auto &it2 : myMenu.menu)
        if(it2->getName() == newFood->getName())
            return it2;
    return nullptr;
}
