#ifndef PERSON_H
#define PERSON_H

#include "personidentity.h"
#include <QObject>
class Person :public QObject
{
    Q_OBJECT
private:
    PersonIdentity myIdentity;

public:
    Person() = default;
    Person(PersonIdentity newIdentity);
    PersonIdentity getIdentity();
    void setIdentity(PersonIdentity newIdentity);
};

#endif // PERSON_H
