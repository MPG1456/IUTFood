#include "restaurant.h"

Restaurant::Restaurant(QString newUsername, QString newPassword,
                       QString newName, QString newBio,
                       Address &newAddress, MyTime &newTime,
                       Score &newScore) : myIdentity(newUsername, newPassword, newName, newBio, newAddress, newTime, newScore) , myFunctions(myMenu)
{}


