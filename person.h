#ifndef PERSON_H
#define PERSON_H

#include "personidentity.h"
#include <QObject>
class Person :public QObject
{
    Q_OBJECT
    // friend QDataStream &operator<<(QDataStream &out, const Person &person);
    // friend QDataStream &operator>>(QDataStream &in, Person &person);
private:
    PersonIdentity myIdentity;

public:
    Person() = default;
    Person(PersonIdentity newIdentity);
    PersonIdentity getIdentity();
    void setIdentity(PersonIdentity newIdentity);
};

#endif // PERSON_H
