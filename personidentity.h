#ifndef PERSONIDENTITY_H
#define PERSONIDENTITY_H

#include <QString>
#include <QDataStream>
#include "address.h"

class PersonIdentity
{
    friend QDataStream &operator<<(QDataStream &out, const PersonIdentity &person);
    friend QDataStream &operator>>(QDataStream &in, PersonIdentity &person);

private:
    int id;
    QString username;
    QString password;
    QString firstName;
    QString lastName;
    QString phoneNumber;
    int age;
    Address address;

public:
    PersonIdentity() = default;
    PersonIdentity(QString newUsername, QString newPassword, QString newFirstName, QString newLastName, QString newPhoneNumber, int newAge, Address newAddress, int id);
    PersonIdentity(const PersonIdentity &newPersonIdentity);
    PersonIdentity &operator= (const PersonIdentity &other);

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
    void setId(int id);
};

#endif // PERSONIDENTITY_H
