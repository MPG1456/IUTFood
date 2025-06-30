#ifndef PERSONIDENTITY_H
#define PERSONIDENTITY_H

#include <QString>
#include "address.h"

class PersonIdentity
{
private:
    QString username;
    QString password;
    QString firstName;
    QString lastName;
    QString phoneNumber;
    int age;
    Address address;

public:
    PersonIdentity(QString newUsername, QString newPassword, QString newFirstName, QString newLastName, QString newPhoneNumber, int newAge, Address newAddress);
    QString getUsername();
    void setUsername(QString newUsername);
    QString getPassword();
    void setPassword(QString newPassword);
    QString getFirstName();
    void setFirstName(QString newFirstName);
    QString getLastName();
    void setLastName(QString newLastName);
    QString gePhoneNumber();
    void setPhoneNumber(QString newPhoneNumber);
    int getAge();
    void setAge(int newAge);
    Address getAddress();
    void setAddress(Address newAddress);
};

#endif // PERSONIDENTITY_H
