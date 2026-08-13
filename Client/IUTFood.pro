QT = core
QT += quick
QT += quickcontrols2
QT += sql

CONFIG += c++17 cmdline

SOURCES += \
        clientrequest.cpp \
        clientnetwork.cpp \
        main.cpp \

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
    ../Server/ClientRequest.h \
    clientnetwork.h \

DISTFILES +=

    
