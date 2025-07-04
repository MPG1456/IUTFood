#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuickControls2/QQuickStyle>
#include "restaurantbackend.h"
#include <QMetaType>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickStyle::setStyle("Material");
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/IUTFood/main.qml"));
    // qmlRegisterType<restaurantdb>("restdb" ,  1,0, "Restaurantbatabse");
    // qmlRegisterType<clientdb>("clidb" ,  1,0, "Clientdatbase");
    // qmlRegisterType<deliverydb>("delivdb" ,  1,0, "Deliverydatbase");
    qmlRegisterType<RestaurantBackend>("Backend", 1, 0, "RestaurantBackend");

    qRegisterMetaType<Restaurant>("Restaurant");

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);
    return app.exec();
}
