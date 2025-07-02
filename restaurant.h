#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "menu.h"
#include "restaurantidentity.h"
#include "menufunctions.h"

class Restaurant
{
private:
    Menu myMenu;
    RestaurantIdentity myIdentity;
    MenuFunctions myFunctions;

public:
    Restaurant(QString newUsername, QString newPassword, QString newName, QString newBio, Address &newAddress, MyTime &newTime, Score &newScore);
    // void showAllRestaurants() -> This one has to be added when the UI complete.
};

#endif // RESTAURANT_H
