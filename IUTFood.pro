QT = core
QT += quick
QT += quickcontrols2
QT += sql

CONFIG += c++17 cmdline

SOURCES += \
        address.cpp \
        address.cpp \
        customer.cpp \
        dessert.cpp \
        drinks.cpp \
        fastfood.cpp \
        food.cpp \
        iranifood.cpp \
        main.cpp \
        maindish.cpp \
        person.cpp \
        personidentity.cpp \
        personidentity.cpp \
        salad.cpp \
        clientdb.cpp \
        restaurantdb.cpp \
        deliverydb.cpp

resources.files = \
    main.qml \
    adress.qml \
    restaurantsignup.qml \
    clientsignup.qml \
    restaurantsignin.qml \
    deliverysignin.qml \
    deliverysignup.qml

resources.prefix = /$${TARGET}
RESOURCES += resources \
    images.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    address.h \
    address.h \
    customer.h \
    dessert.h \
    drinks.h \
    fastfood.h \
    food.h \
    iranifood.h \
    maindish.h \
    person.h \
    personidentity.h \
    personidentity.h \
    salad.h \
    clientdb.h \
    restaurantdb.h \
    deliverydb.h \

