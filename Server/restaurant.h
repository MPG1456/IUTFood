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
    // MenuFunctions myFunctions;

public:
    Restaurant() = default;
    Restaurant(RestaurantIdentity newIdentity);
    // void showAllRestaurants() -> This one has to be added when the UI complete.
    void setIdentity(RestaurantIdentity newIdentity);
    RestaurantIdentity getIdentity();
};

#endif // RESTAURANT_H
