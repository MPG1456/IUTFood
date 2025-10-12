#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuickControls2/QQuickStyle>
#include <QQmlContext>
#include "datastore.h"
#include "clientnetwork.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickStyle::setStyle("Material");
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/IUTFood/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl)
        {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    DataStore &datastore = DataStore::instance();
    // qDebug()<<datastore.clients[0]->getIdentity().getUsername();
    clientNetwork clientSide;
    qmlRegisterSingletonInstance<clientNetwork>("Network", 1, 0, "Network", &clientSide);
    qmlRegisterSingletonInstance<DataStore>("DataStore", 1, 0, "DataStore", &datastore);
    engine.load(url);
    return app.exec();
}
