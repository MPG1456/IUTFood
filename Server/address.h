#ifndef ADDRESS_H
#define ADDRESS_H

#include <QString>
#include <QDataStream>

class Address
{

private:
    QString country;
    QString city;
    QString homeAddress;
    QString homePhone;
    long long int postalCode;
public:
    Address() = default;
    Address(QString newCountry, QString newCity, QString newHomeAddress, QString newHomePhone,int newPostalCode);
    Address(const Address &copyAddress);
    Address& operator= (const Address &other);
    QString getCountry();
    void setCountry(QString newCountry);
    QString getCity();
    void setCity(QString newCity);
    QString getHomeAddress();
    void setHomeAddress(QString newHomeAddress);
    QString getHomePhone();
    void setHomePhone(QString newHomePhone);
    long long int getPostalCode();
    void setPostalCode(long long int newPostalCode);
};

#endif // ADDRESS_H
