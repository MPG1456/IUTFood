#include "menufunctions.h"

MenuFunctions::MenuFunctions(Menu &newMenu) : myMenu(newMenu)
{}

void MenuFunctions::addFood(QVariant newFood)
{
    int index = searchFood(newFood);
    if(index != -1)
    {
        qDebug() << "This food already exists in the menu";
        return;
    }

    myMenu.menu.removeAt(index);
}

void MenuFunctions::deleteFood(QVariant newFood)
{
    int index = searchFood(newFood);
    if(index == -1)
    {
        qDebug() << "This Food doesn't exist!";
        return;
    }
    myMenu.menu.remove(index);
}

int MenuFunctions::searchFood(QVariant newFood)
{
    for(int i = 0; i < myMenu.menu.size(); ++i)
        if(myMenu.menu[i] == newFood)
            return i;

    return -1;
}
