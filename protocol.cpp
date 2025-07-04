#include "protocol.h"

QDataStream &operator<<(QDataStream &out, const PersonIdentity &personIdentity)
{
    out << personIdentity.username;
    out << personIdentity.password;
    out << personIdentity.firstName;
    out << personIdentity.lastName;
    out << personIdentity.age;
    out << personIdentity.phoneNumber;
    out << personIdentity.address;
    return out;
}
QDataStream &operator>>(QDataStream &in, PersonIdentity &personIdentity)
{
    in >> personIdentity.username;
    in >> personIdentity.password;
    in >> personIdentity.firstName;
    in >> personIdentity.lastName;
    in >> personIdentity.age;
    in >> personIdentity.phoneNumber;
    in >> personIdentity.address;
    return in;
}

QDataStream &operator>>(QDataStream &in, Address &address)
{
    in >> address.country;
    in >> address.city;
    in >> address.homeAddress;
    in >> address.homeAddress;
    in >> address.postalCode;
    return in;
}
QDataStream &operator<<(QDataStream &out, const Address &address)
{
    out << address.country;
    out << address.city;
    out << address.homeAddress;
    out << address.homePhone;
    out << address.postalCode;
    return out;
}

QDataStream &operator<<(QDataStream &out, const Customer &customer)
{
    out << static_cast<const Person &>(customer);
    return out;
}
QDataStream &operator>>(QDataStream &in, Customer &customer)
{
    in >> static_cast<Person &>(customer);
    return in;
}

void serializeFood(QDataStream &out, const Food &food)
{
    out << food.name;
    out << food.type;
    out << food.ingredients;
    out << food.capacity;
    out << food.price;
}
void deserializeFood(QDataStream &in, Food &food)
{
    in >> food.name;
    in >> food.type;
    in >> food.ingredients;
    in >> food.capacity;
    in >> food.price;
}

QDataStream &operator<< (QDataStream &out, const Dessert &dessert)
{
    serializeFood(out, dessert);
    return out;
}
QDataStream &operator>> (QDataStream &in, Dessert &dessert)
{
    deserializeFood(in, dessert);
    return in;
}

QDataStream &operator<< (QDataStream &out, const Drinks &drinks)
{
    serializeFood(out, drinks);
    return out;
}
QDataStream &operator>> (QDataStream &in, Drinks &drinks)
{
    deserializeFood(in, drinks);
    return in;
}

void serializeMainDish(QDataStream &out, const MainDish &dish)
{
    qDebug() << "test";
    serializeFood(out, dish);
}
void deserializeMainDish(QDataStream &in, MainDish &dish)
{
    deserializeFood(in, dish);
}

QDataStream &operator<< (QDataStream &out, const FastFood &fastfood)
{
    serializeMainDish(out, fastfood);
    return out;
}
QDataStream &operator>> (QDataStream &in, FastFood &fastfood)
{
    deserializeMainDish(in, fastfood);
    return in;
}

QDataStream &operator<< (QDataStream &out, const IraniFood &iranifood)
{
    serializeMainDish(out, iranifood);
    return out;
}
QDataStream &operator>> (QDataStream &in, IraniFood &iranifood)
{
    deserializeMainDish(in, iranifood);
    return in;
}

QDataStream &operator<<(QDataStream &out, const Menu &menu)
{
    out << menu.menu;
    return out;
}
QDataStream &operator>>(QDataStream &in, Menu &menu)
{
    in >> menu.menu;
    return in;
}

QDataStream &operator<<(QDataStream &out, const MyTime &time)
{
    out << time.myTime;
    return out;
}
QDataStream &operator>>(QDataStream &in, MyTime &time)
{
    in >> time.myTime;
    return in;
}

QDataStream &operator<<(QDataStream &out, const Person &person)
{
    out << person.myIdentity;
    return out;
}
QDataStream &operator>>(QDataStream &in, Person &person)
{
    PersonIdentity newId;
    in >> newId;
    person.setIdentity(newId);
    return in;
}

QDataStream &operator<< (QDataStream &out, const Restaurant &restaurant)
{
    out << restaurant.myIdentity;
    out << restaurant.myMenu;
    return out;
}
QDataStream& operator>> (QDataStream &in, Restaurant &restaurant)
{
    in >> restaurant.myIdentity;
    in >> restaurant.myMenu;
    return in;
}

QDataStream &operator<< (QDataStream &out, const RestaurantIdentity &identity)
{
    out << identity.username;
    out << identity.password;
    out << identity.name;
    out << identity.bio;
    out << identity.address;
    out << identity.score;
    out << identity.time;
    out << identity.isAvailable;
    return out;
}
QDataStream &operator>> (QDataStream &in, RestaurantIdentity &identity)
{
    in << identity.username;
    in << identity.password;
    in << identity.name;
    in << identity.bio;
    in << identity.address;
    in << identity.time;
    in << identity.score;
    in << identity.isAvailable;
    return in;
}

QDataStream &operator<< (QDataStream &out, const Salad &salad)
{
    serializeFood(out, salad);
    return out;
}
QDataStream &operator>> (QDataStream &in, Salad &salad)
{
    deserializeFood(in, salad);
    return in;
}

QDataStream &operator<< (QDataStream &out, const Score &score)
{
    out << score.myScore;
    out << score.counter;
    return out;
}
QDataStream &operator>> (QDataStream &in, Score &score)
{
    in >> score.myScore;
    in >> score.counter;
    return in;
}































