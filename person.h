#ifndef PERSON_H
#define PERSON_H

#include "personidentity.h"

class Person
{
private:
    PersonIdentity myIdentity;

public:
    Person(PersonIdentity newIdentity);
    PersonIdentity getIdentity();
    void setIdentity(PersonIdentity newIdentity);
};

#endif // PERSON_H
