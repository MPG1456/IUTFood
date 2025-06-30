#include "address.h"

Address::Address(QString newCountry, QString newCity,
                 QString newHomeAddress, QString newHomePhone,
                 long long int newPostalCode) : country(newCountry), city(newCity),
    homeAddress(newHomeAddress), homePhone(newHomePhone),
    postalCode(newPostalCode)
{}

QString Address::getCountry()
{
    return country;
}

void Address::setCountry(QString newCountry)
{
    this->country = newCountry;
}

QString Address::getCity()
{
    return city;
}

void Address::setCity(QString newCity)
{
    this->city = newCity;
}

QString Address::getHomeAddress()
{
    return homeAddress;
}

void Address::setHomeAddress(QString newHomeAddress)
{
    this->homeAddress = newHomeAddress;
}

QString Address::getHomePhone()
{
    return homePhone;
}

void Address::setHomePhone(QString newHomePhone)
{
    this->homePhone = newHomePhone;
}

long long int Address::getPostalCode()
{
    return postalCode;
}

void Address::setPostalCode(long long int newPostalCode)
{
    this->postalCode = newPostalCode;
}
