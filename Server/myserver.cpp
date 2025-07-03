#include "myserver.h"

MyServer::MyServer(QObject *parent) : QTcpServer(parent) {}

void MyServer::startServer()
{
    connect(this, SIGNAL(QTcpServer::newConnection()), this, SLOT(MyServer::handleNewConnection()));

    if(!this->listen(QHostAddress::Any, 1234))
        qDebug() << "Server Could not be found!";
    else
        qDebug() << "Server started! Listening for multiple connections on port 1234...";
}

void MyServer::handleNewConnection()
{
    QTcpSocket *clientSocket = this->nextPendingConnection();
    if(!clientSocket)
        return;
    else
        qDebug() << "New client connectd: " << clientSocket->peerAddress().toString();

    myPendings.insert(clientSocket);

    connect(clientSocket, SIGNAL(QTcpSocket::readyRead()), this, SLOT(MyServer::handleClientIdentification()));
    connect(clientSocket, SIGNAL(QTcpSocket::disconnected()), this, SLOT(MyServer::clientDisconnected()));
}

void MyServer::handleClientIdentification()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket *>(sender());
    if(!clientSocket)
        return;

    QByteArray data = clientSocket->readAll().trimmed();

    if(data == "Restaurant")
    {
        myRestaurants.insert(clientSocket);
        myPendings.remove(clientSocket);

        disconnect(clientSocket, SIGNAL(QTcpSocket::readyRead()), this, SLOT(MyServer::handleClientIdentification));
        connect(clientSocket, SIGNAL(QTcpSocket::readyRead()), this, SLOT(MyServer::readRestaurantsData()));
        qDebug() << "Identification successful. New restaurant: " << clientSocket->peerAddress().toString();

        disconnect(clientSocket, SIGNAL(QTcpSocket::disconnected()), this, SLOT(MyServer::handleClientIdentification));
        connect(clientSocket, SIGNAL(QTcpSocket::disconnected()), this, SLOT(MyServer::restaurantDisconnected()));
    }
    else if(data == "Customer")
    {
        myCustomers.insert(clientSocket);
        myPendings.remove(clientSocket);

        disconnect(clientSocket, SIGNAL(QTcpSocket::readyRead()), this, SLOT(MyServer::handleClientIdentification));
        connect(clientSocket, SIGNAL(QTcpSocket::readyRead()), this, SLOT(MyServer::readCustomersData()));
        qDebug() << "Identification successful. New customer: " << clientSocket->peerAddress().toString();

        disconnect(clientSocket, SIGNAL(QTcpSocket::disconnected()), this, SLOT(MyServer::handleClientIdentification));
        connect(clientSocket, SIGNAL(QTcpSocket::disconnected()), this, SLOT(MyServer::customerDisconnected()));
    }
    else if(data == "Delivery")
    {
        myDeliveries.insert(clientSocket);
        myPendings.remove(clientSocket);

        disconnect(clientSocket, SIGNAL(QTcpSocket::readyRead()), this, SLOT(MyServer::handleClientIdentification));
        connect(clientSocket, SIGNAL(QTcpSocket::readyRead()), this, SLOT(MyServer::readDeliveriesData()));
        qDebug() << "Identification successful. New delivery: " << clientSocket->peerAddress().toString();

        disconnect(clientSocket, SIGNAL(QTcpSocket::disconnected()), this, SLOT(MyServer::handleClientIdentification));
        connect(clientSocket, SIGNAL(QTcpSocket::disconnected()), this, SLOT(MyServer::deliveryDisconnected()));
    }
    else
    {
        myPendings.remove(clientSocket);
        qDebug() << "Client sent invalid identification. Disconnection from host.";
        clientSocket->disconnectFromHost();
        return;
    }


}

// void MyServer::readRestaurantsData()
// {

// }

// void MyServer::readCustomersData()
// {

// }

// void MyServer::readDeliveriesData()
// {

// }

void MyServer::clientDisconnected()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket *>(sender());
    if(!clientSocket)
        return;

    myPendings.remove(clientSocket);
    clientSocket->deleteLater();
    qDebug() << "Client disconnectd: " << clientSocket->peerAddress().toString();
}

void MyServer::restaurantDisconnected()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket *>(sender());
    if(!clientSocket)
        return;

    myRestaurants.remove(clientSocket);
    clientSocket->deleteLater();
    qDebug() << "Restaurant disconnectd: " << clientSocket->peerAddress().toString();
}

void MyServer::customerDisconnected()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket *>(sender());
    if(!clientSocket)
        return;

    myCustomers.remove(clientSocket);
    clientSocket->deleteLater();
    qDebug() << "Cutomer disconnectd: " << clientSocket->peerAddress().toString();
}

void MyServer::deliveryDisconnected()
{
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket *>(sender());
    if(!clientSocket)
        return;

    myDeliveries.remove(clientSocket);
    clientSocket->deleteLater();
    qDebug() << "Delivery disconnectd: " << clientSocket->peerAddress().toString();
}





