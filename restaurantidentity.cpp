#include "restaurantidentity.h"

RestaurantIdentity::RestaurantIdentity(QString newUsername, QString newPassword,
                                       QString newName, QString newBio,
                                       Address &newAddress, MyTime &newTime,
                                       Score &newScore) : username(newUsername), password(newPassword),
                                                          name(newName), bio(newBio),
                                                          address(newAddress), time(newTime),
                                                          score(newScore)
{
    isAvailable = false;
}

QString RestaurantIdentity::getUsername()
{
    return username;
}

void RestaurantIdentity::setUsername(QString newUsername)
{
    username = newUsername;
}

QString RestaurantIdentity::getPassword()
{
    return password;
}

void RestaurantIdentity::setPassword(QString newPassword)
{
    password = newPassword;
}

QString RestaurantIdentity::getName()
{
    return name;
}

void RestaurantIdentity::setName(QString newName)
{
    name = newName;
}

QString RestaurantIdentity::getBio()
{
    return bio;
}

void RestaurantIdentity::setBio(QString newBio)
{
    bio = newBio;
}

bool RestaurantIdentity::getIsAvailable()
{
    return isAvailable;
}

void RestaurantIdentity::setIsAvailable(bool newAvailablity)
{
    isAvailable = newAvailablity;
}
void RestaurantIdentity::setPhonenumber(QString phoneNumber)
{
    this->phoneNumber = phoneNumber;
}
void RestaurantIdentity::setAddress(Address newAddress)
{
    this->address = newAddress;
}
void RestaurantIdentity::setTime(MyTime& newTime)
{
    this->time = newTime;
}
void RestaurantIdentity::setScore(Score newScore)
{
    score = newScore;
}
