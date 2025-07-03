#ifndef RESTAURANTIDENTITY_H
#define RESTAURANTIDENTITY_H

#include <QString>
#include "address.h"
#include "mytime.h"
#include "score.h"

class RestaurantIdentity
{
private:
    QString username;
    QString password;
    QString name;
    QString bio;
    Address address;
    MyTime time;
    Score score;
    bool isAvailable;

public:
    RestaurantIdentity(QString newUsername, QString newPassword, QString newName, QString newBio, Address &newAddress, MyTime &newTime, Score &newScore);
    QString getUsername();
    void setUsername(QString newUsername);
    QString getPassword();
    void setPassword(QString newPassword);
    QString getName();
    void setName(QString newName);
    QString getBio();
    void setBio(QString newBio);
    bool getIsAvailable();
    void setIsAvailable(bool newAvailablity);
};

#endif // RESTAURANTIDENTITY_H
