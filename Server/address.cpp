#include "address.h"

Address::Address(QString newCountry, QString newCity,
                 QString newHomeAddress, QString newHomePhone,
                 int newPostalCode) : country(newCountry), city(newCity),
    homeAddress(newHomeAddress), homePhone(newHomePhone),
    postalCode(newPostalCode)
{}

Address::Address(const Address &copyAddress)
{
    this->country = copyAddress.country;
    this->city = copyAddress.city;
    this->homeAddress = copyAddress.homeAddress;
    this->homePhone = copyAddress.homePhone;
    this->postalCode = copyAddress.postalCode;
}
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



Address &Address::operator= (const Address &other)
{
    if (this != &other) {
        this->country = other.country;
        this->city = other.city;
        this->homeAddress = other.homeAddress;
        this->homePhone = other.homePhone;
        this->postalCode = other.postalCode;
    }
    return *this;
}
