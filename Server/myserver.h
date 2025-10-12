#ifndef MYSERVER_H
#define MYSERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QSet>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QCoreApplication>
#include <QDebug>
#include <QStandardPaths>
#include <QDir>
#include <QObject>
#include <QHash>
#include "clientdb.h"
#include "deliverydb.h"
#include "orderdb.h"
#include "restaurantdb.h"
#include "menudb.h"
#include "orderedfooddb.h"
class MyServer: public QTcpServer
{
    Q_OBJECT
public:
    MyServer(QObject *parent = nullptr);
    QJsonDocument handleClientSignUp(QJsonObject obj);
    QJsonDocument handleDeliverySignUp(QJsonObject obj);
    QJsonDocument handleRestaurantSignUp(QJsonObject obj);

private:
    void incomingConnection(qintptr socketDescriptor);
    QHash <QTcpSocket* , QString> roles;
    ClientDB clientDataBase;
    RestaurantDB restaurantDataBase;
    menudb menuDataBase;
    orderdb orderDataBase;
    DeliveryDB deliveryDataBase;
    ordered_foods orderedDataBase;
private slots:
    void onReadyRead();
    void onDisconnected();
};

#endif // MYSERVER_H
