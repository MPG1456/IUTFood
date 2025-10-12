#include "restaurant.h"

Restaurant::Restaurant(RestaurantIdentity newIdentity):myIdentity(newIdentity)
{
}


void Restaurant::setIdentity(RestaurantIdentity newIdentity)
{
    this->myIdentity = newIdentity;
}
RestaurantIdentity Restaurant::getIdentity()
{
    return myIdentity;
}
