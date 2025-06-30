#include "person.h"

Person::Person(PersonIdentity newIdentity) : myIdentity(newIdentity) {}

PersonIdentity Person::getIdentity()
{
    return myIdentity;
}

void Person::setIdentity(PersonIdentity newIdentity)
{
    this->myIdentity = newIdentity;
}
