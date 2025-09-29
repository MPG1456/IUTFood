#ifndef DELIVERY_H
#define DELIVERY_H
#include "personidentity.h"
#include <QObject>
class delivery: public PersonIdentity
{
    Q_OBJECT
public:
    delivery(QString newUsername, QString newPassword, QString newFirstName, QString newLastName, QString newPhoneNumber, int newAge, Address newAddress);

};

#endif // DELIVERY_H
