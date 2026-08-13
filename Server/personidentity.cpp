#include "personidentity.h"

PersonIdentity::PersonIdentity(QString newUsername, QString newPassword,
                               QString newFirstName, QString newLastName,
                               QString newPhoneNumber, int newAge,
                               Address newAddress ,int id) : username(newUsername), password(newPassword),
                                                    firstName(newFirstName), lastName(newLastName),
                                                    phoneNumber(newPhoneNumber), age(newAge),address(newAddress)
{
    this->id = id;
}

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

Address PersonIdentity::getAddress()
{
    return address;
}

void PersonIdentity::setAddress(Address newAddress)
{
    this->address = newAddress;
}

PersonIdentity::PersonIdentity(const PersonIdentity &newPersonIdentity)
{
    this->username = newPersonIdentity.username;
    this->password = newPersonIdentity.password;
    this->firstName = newPersonIdentity.firstName;
    this->lastName = newPersonIdentity.lastName;
    this->age = newPersonIdentity.age;
    this->phoneNumber = newPersonIdentity.phoneNumber;
    this->address = newPersonIdentity.address;
}

PersonIdentity &PersonIdentity::operator= (const PersonIdentity &other)
{
    this->username = other.username;
    this->password = other.password;
    this->firstName = other.firstName;
    this->lastName = other.lastName;
    this->age = other.age;
    this->phoneNumber = other.phoneNumber;
    this->address = other.address;
    return *this;
}
void PersonIdentity::setId(int id)
{
    this->id = id;
}
