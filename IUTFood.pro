QT = core
QT += quick
QT += quickcontrols2
QT += sql

CONFIG += c++17 cmdline

SOURCES += \
        address.cpp \
        clientnetwork.cpp \
        customer.cpp \
        datastore.cpp \
        delivery.cpp \
        dessert.cpp \
        drinks.cpp \
        fastfood.cpp \
        food.cpp \
        iranifood.cpp \
        main.cpp \
        maindish.cpp \
        menu.cpp \
        menufunctions.cpp \
        mytime.cpp \
        order.cpp \
        person.cpp \
        personidentity.cpp \
        protocol.cpp \
        restaurant.cpp \
        restaurantidentity.cpp \
        salad.cpp \
        score.cpp

resources.files = \
    main.qml \
    restaurantsignup.qml \
    clientsignup.qml \
    restaurantsignin.qml \
    deliverysignin.qml \
    deliverysignup.qml \
    clientpanel.qml \
    restaurantpanel.qml \
    adminpanel.qml \
    orderhistory.qml \
    filterpage.qml \
    Ordertracking.qml \
    shoppingcart.qml \
    admincroud.qml \
    acceptrestaurant.qml \
    Orderstatus.qml \
    deliverypanel.qml \
    changemenu.qml \
    restaurantpreview.qml \
    menu.qml \
    deliverystatus.qml

resources.prefix = /$${TARGET}
RESOURCES += resources \
    images.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
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
    menufunctions.h \
    mytime.h \
    order.h \
    person.h \
    personidentity.h \
    protocol.h \
    restaurant.h \
    restaurantidentity.h \
    salad.h \
    score.h

DISTFILES +=

SUBDIRS += \
    Server/Server.pro \
    Server/Server.pro \
    Server/Server.pro \
    Server/Server.pro

