#include <QCoreApplication>
#include "clientdb.h"
#include "restaurantdb.h"
#include "menudb.h"
#include "orderdb.h"
#include "ordered_foods.h"
#include "deliverydb.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ClientDB client;
    client.addUser("sobhan", "1234", "Ali", "Rezayi", 20, "Iran", "Tehran", 12345, "Valiasr St", "021111111", "091200000");
    RestaurantDB restaurantDB;
    restaurantDB.addRestaurant("resuser" , "12345" , "KFC","iran" ,"Tehran",111111, "11111111111","322225" , "Fast Food" ,"09111111111" , "111/11/11");
    menudb menuDB;
    menuDB.addMenu(1, "Pizza", "Cheese, Tomato", "FastFood", 1, 250.0);
    orderdb orderDB;
    orderDB.addOrder(1, 1, 1, "2025-09-30 12:00", "2025-09-30 12:30", "Pending");
    ordered_foods orderedFoods;
    orderedFoods.addOrderedFood(1, 1, 2);

    return a.exec();
}
