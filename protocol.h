// #ifndef PROTOCOL_H
// #define PROTOCOL_H

// #include <QVariant>
// #include <QMetaType>
// #include <QDataStream>

// #include "address.h"
// #include "customer.h"
// #include "dessert.h"
// #include "drinks.h"
// #include "fastfood.h"
// #include "food.h"
// #include "iranifood.h"
// #include "maindish.h"
// #include "menu.h"
// #include "mytime.h"
// #include "person.h"
// #include "personidentity.h"
// #include "restaurant.h"
// #include "restaurantidentity.h"
// #include "salad.h"
// #include "score.h"


// enum class MessageType : quint8
// {
//     sendCustomerSignIn,
//     sendCustomerSignUp,
//     sendCustomerBuyRequest,

//     sendDeliverySignIn,
//     sendDeliverySignUp,
//     sendDeliveryAccept,
//     sendDeliveryDelivered,

//     sendRestaurantSignIn,
//     sendRestaurantSignUp,
//     sendRestaurantMenu
// };

// Q_DECLARE_METATYPE(Address);
// Q_DECLARE_METATYPE(Customer);
// Q_DECLARE_METATYPE(Dessert);
// Q_DECLARE_METATYPE(Drinks);
// Q_DECLARE_METATYPE(FastFood);
// Q_DECLARE_METATYPE(IraniFood);
// Q_DECLARE_METATYPE(MainDish);
// Q_DECLARE_METATYPE(Menu);
// Q_DECLARE_METATYPE(MyTime);
// Q_DECLARE_METATYPE(Person);
// Q_DECLARE_METATYPE(PersonIdentity);
// Q_DECLARE_METATYPE(Restaurant);
// Q_DECLARE_METATYPE(RestaurantIdentity);
// Q_DECLARE_METATYPE(Salad);
// Q_DECLARE_METATYPE(Score);


// QDataStream &operator<<(QDataStream &out, const PersonIdentity &personIdentity);
// QDataStream &operator>>(QDataStream &in, PersonIdentity &personIdentity);

// QDataStream &operator<<(QDataStream &out, const Address &address);
// QDataStream &operator>>(QDataStream &in, Address &address);

// QDataStream &operator<<(QDataStream &out, const Customer &customer);
// QDataStream &operator>>(QDataStream &in, Customer &customer);

// void serializeFood(QDataStream &out, const Food &food);
// void deserializeFood(QDataStream &in, Food &food);

// QDataStream &operator<<(QDataStream &out, const Dessert &dessert);
// QDataStream &operator>>(QDataStream &in, Dessert &dessert);

// QDataStream &operator<<(QDataStream &out, const Drinks &drinks);
// QDataStream &operator>>(QDataStream &in, Drinks &drinks);

// void serializeMainDish(QDataStream &out, const MainDish &dish);
// void deserializeMainDish(QDataStream &in, MainDish &dish);

// QDataStream &operator<<(QDataStream &out, const FastFood &fastfood);
// QDataStream &operator>>(QDataStream &in, FastFood &fastfood);

// QDataStream &operator<<(QDataStream &out, const Menu &menu);
// QDataStream &operator>>(QDataStream &in, Menu &menu);

// QDataStream &operator<<(QDataStream &out, const MyTime &time);
// QDataStream &operator>>(QDataStream &in, MyTime &time);

// QDataStream &operator<<(QDataStream &out, const Person &person);
// QDataStream &operator>>(QDataStream &in, Person &person);

// QDataStream &operator<<(QDataStream &out, const Restaurant &restaurant);
// QDataStream &operator>>(QDataStream &in, Restaurant &restaurant);

// QDataStream &operator<<(QDataStream &out, const RestaurantIdentity &identity);
// QDataStream &operator>>(QDataStream &in, RestaurantIdentity &identity);

// QDataStream &operator<<(QDataStream &out, const Salad &salad);
// QDataStream &operator>>(QDataStream &in, Salad &salad);

// QDataStream &operator<<(QDataStream &out, const Score &score);
// QDataStream &operator>>(QDataStream &in, Score &score);

// #endif // PROTOCOL_H
