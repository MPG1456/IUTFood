#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuickControls2/QQuickStyle>
#include"restaurantdb.h"
#include"clientdb.h"
#include"deliverydb.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickStyle::setStyle("Material");
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/IUTFood/main.qml"));
    qmlRegisterType<restaurantdb>("restdb" ,  1,0, "Restaurantbatabse");
    qmlRegisterType<clientdb>("clidb" ,  1,0, "Clientdatbase");
    qmlRegisterType<deliverydb>("delivdb" ,  1,0, "Deliverydatbase");
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
