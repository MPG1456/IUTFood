#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QSet>

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
    QSet<QTcpSocket *> myCustomers;
    QSet<QTcpSocket *> myDeliveries;
    QSet<QTcpSocket *> myRestaurants;
    QSet<QTcpSocket *> myPendings;
};

#endif // MYSERVER_H
