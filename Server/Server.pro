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
        ordered_foods.cpp \
        restaurantdb.cpp \
        main.cpp \
        myserver.cpp \
        orderdb.cpp
        # ../protocol.cpp \
        # ../address.cpp \
        # ../mytime.cpp \
        # ../score.cpp \
        # ../menu.cpp \
        # ../person.cpp \
        # ../personidentity.cpp \
        # ../restaurant.cpp \
        # ../restaurantidentity.cpp \
        # ../customer.cpp \
        # ../dessert.cpp \
        # ../drinks.cpp \
        # ../salad.cpp \
        # ../fastfood.cpp \
        # ../iranifood.cpp \
        # ../food.cpp \
        # ../maindish.cpp \
        # ../menufunctions.cpp

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
    ordered_foods.h \
    restaurantdb.h \
    orderdb.h

RESOURCES += \
    database.qrc
