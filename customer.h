#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <person.h>

class Customer:public Person
{
    friend QDataStream &operator<<(QDataStream &out, const Customer &customer);
    friend QDataStream &operator>>(QDataStream &in, Customer &customer);

public:
    Customer() = default;
    Customer(PersonIdentity newPersonIdentity);

};
#endif // CUSTOMER_H
