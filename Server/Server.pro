QT = core
QT += core network
QT += sql
QT += core network sql

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        clientdb.cpp \
        deliverydb.cpp \
        menudb.cpp \
        orderedfooddb.cpp \
        restaurantdb.cpp \
        main.cpp \
        myserver.cpp \
        orderdb.cpp \
        address.cpp \
        customer.cpp \
        datastore.cpp \
        delivery.cpp \
        dessert.cpp \
        drinks.cpp \
        fastfood.cpp \
        food.cpp \
        iranifood.cpp \
        maindish.cpp \
        menu.cpp \
        mytime.cpp \
        order.cpp \
        orderedfood.cpp \
        person.cpp \
        personidentity.cpp \
        restaurant.cpp \
        restaurantidentity.cpp \
        salad.cpp \
        score.cpp


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += $$PWD/../

HEADERS += \
    clientdb.h \
    deliverydb.h \
    menudb.h \
    myserver.h \
    orderedfooddb.h \
    restaurantdb.h \
    orderdb.h \
    address.h \
    clientnetwork.h \
    customer.h \
    datastore.h \
    delivery.h \
    dessert.h \
    drinks.h \
    fastfood.h \
    food.h \
    iranifood.h \
    maindish.h \
    menu.h \
    mytime.h \
    order.h \
    orderedfood.h \
    person.h \
    personidentity.h \
    restaurant.h \
    restaurantidentity.h \
    salad.h \
    score.h

RESOURCES += \
    database.qrc
