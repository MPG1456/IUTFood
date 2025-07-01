QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

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
        salad.cpp

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
    salad.h
