#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <person.h>

class Customer : public Person
{
private:

public:
    Customer(PersonIdentity newPersonIdentity);
};

#endif // CUSTOMER_H
