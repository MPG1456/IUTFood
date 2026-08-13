#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <person.h>

class Customer:public Person
{

public:
    Customer() = default;
    Customer(PersonIdentity newPersonIdentity);

};
#endif // CUSTOMER_H
