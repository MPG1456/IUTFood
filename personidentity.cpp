#include "personidentity.h"

PersonIdentity::PersonIdentity(QString newUsername, QString newPassword,
                               QString newFirstName, QString newLastName,
                               QString newPhoneNumber, int newAge) : username(newUsername), password(newPassword),
                                                                    firstName(newFirstName), lastName(newLastName),
                                                                    phoneNumber(newPhoneNumber), age(newAge)
{}

QString PersonIdentity::getUsername()
{
    return username;
}

void PersonIdentity::setUsername(QString newUsername)
{
    this->username = newUsername;
}

QString PersonIdentity::getPassword()
{
    return password;
}

void PersonIdentity::setPassword(QString newPassword)
{
    this->password = newPassword;
}

QString PersonIdentity::getFirstName()
{
    return firstName;
}

void PersonIdentity::setFirstName(QString newFirstName)
{
    this->firstName = newFirstName;
}

QString PersonIdentity::getLastName()
{
    return lastName;
}

void PersonIdentity::setLastName(QString newLastName)
{
    this->lastName = newLastName;
}

QString PersonIdentity::gePhoneNumber()
{
    return phoneNumber;
}

void PersonIdentity::setPhoneNumber(QString newPhoneNumber)
{
    this->phoneNumber = newPhoneNumber;
}

int PersonIdentity::getAge()
{
    return age;
}

void PersonIdentity::setAge(int newAge)
{
    this->age = newAge;
}
