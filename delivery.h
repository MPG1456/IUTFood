#ifndef DELIVERY_H
#define DELIVERY_H
#include "person.h"
#include <QObject>
class delivery: public Person
{
    Q_OBJECT
public:
    delivery(PersonIdentity newIdentity);
    delivery()=default;
    // void setIdentity(PersonIdentity newIdentity);
private:
    PersonIdentity myIdentity;
};

#endif // DELIVERY_H
