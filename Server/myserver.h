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

#include "protocol.h"
#include "clientdb.h"
#include "deliverydb.h"
#include "restaurantdb.h"

class MyServer : public QTcpServer
{
    Q_OBJECT

public:
    enum ClientType
    {
        Restaurant,
        Customer,
        Delivery
    };
    Q_ENUM(ClientType);

    explicit MyServer(QObject *parent = nullptr);
    void setupDatabase(QSqlDatabase &db, const QString &connectionName, const QString &dbFileName);
    void startServer();

private slots:
    void handleNewConnection();
    void handleClientIdentification();
    void clientDisconnected();
    void customerDisconnected();
    void restaurantDisconnected();
    void deliveryDisconnected();
    void readCustomersData();
    void readRestaurantsData();
    void readDeliveriesData();

private:
    void sendMessageToClient(QTcpSocket *socket, MessageType type, const QVariant &payload = QVariant());

    QSqlDatabase clientDb;
    QSqlDatabase restaurantDb;
    QSqlDatabase deliveryDb;

    ClientDB* m_clientDbManager;
    RestaurantDB* m_restaurantDbManager;
    DeliveryDB* m_deliveryDbManager;

    QSet<QTcpSocket *> myCustomers;
    QSet<QTcpSocket *> myDeliveries;
    QSet<QTcpSocket *> myRestaurants;
    QSet<QTcpSocket *> myPendings;
};

#endif // MYSERVER_H
