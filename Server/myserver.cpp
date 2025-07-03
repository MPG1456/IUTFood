#include "myserver.h"
#include <QCoreApplication>
#include <QDebug>
#include <QStandardPaths>
#include <QDir>

MyServer::MyServer(QObject *parent) : QTcpServer(parent)
{
    clientDb = QSqlDatabase::addDatabase("QSQLITE" , "clientconnection");
    restaurantDb = QSqlDatabase::addDatabase("QSQLITE" , "restaurantconnection");
    deliveryDb = QSqlDatabase::addDatabase("QSQLITE" , "deliveryconnection");


    QString dataLocation = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir dataDir(dataLocation);
    if(!dataDir.exists())
    {
        dataDir.mkpath(".");
    }

    QString dbPath = dataDir.absoluteFilePath("clientdb2.db");
    clientDb.setDatabaseName(dbPath);

    qDebug() << "Attempting to open database file at: " << dbPath;

    if(!QFile::exists(dbPath))
    {
        qDebug() << "File doesn't exist in the chosen path. It will copy it from resources.";
        QFile::copy("F:/Projects/AP/Final Term/IUTFood/clientdb2.db", dbPath); // ATTENITION: change this path to your directory
    }

    if(!clientDb.open())
    {
        qDebug()<<"Failed to open";
    }


    QString dataLocationRe = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir dataDirRe(dataLocationRe);
    if(!dataDirRe.exists())
    {
        dataDirRe.mkpath("."); // <- this one creates the path if it doesn't exist
    }

    QString dbPathRe = dataDirRe.absoluteFilePath("restaurantdb.db");
    restaurantDb.setDatabaseName(dbPathRe);

    qDebug() << "Attempting to open database file at: " << dbPathRe;

    if(!QFile::exists(dbPathRe))
    {
        qDebug() << "File doesn't exist in the chosen path. It will copy it from resources.";
        QFile::copy("F:/Projects/AP/Final Term/IUTFood/restaurantdb.db", dbPathRe); // ATTENITION: change this path to your directory
    }

    if(!restaurantDb.open())
    {
        qDebug()<<"failed to open";
    }


    QString dataLocationDe = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);

    // Create the directory if it doesn't exist.
    QDir dataDirDe(dataLocationDe);
    if(!dataDirDe.exists())
    {
        dataDirDe.mkpath("."); // <- this one creates the path if it doesn't exist
    }

    QString dbPathDe = dataDirDe.absoluteFilePath("deliverydb.db");
    deliveryDb.setDatabaseName(dbPathDe);

    qDebug() << "Attempting to open database file at: " << dbPathDe;

    if(!QFile::exists(dbPathDe))
    {
        qDebug() << "File doesn't exist in the chosen path. It will copy it from resources.";
        QFile::copy("F:/Projects/AP/Final Term/IUTFood/deliverydb.db", dbPathDe); // ATTENITION: change this path to your directory
    }

    if(!deliveryDb.open())
    {
        qDebug()<<"Failed to open";
    }
}

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

    connect(clientSocket, &QTcpSocket::readyRead, this, &MyServer::handleClientIdentification);
    connect(clientSocket, &QTcpSocket::disconnected, this, &MyServer::clientDisconnected);
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

        disconnect(clientSocket, &QTcpSocket::readyRead, this, &MyServer::handleClientIdentification);
        connect(clientSocket, &QTcpSocket::readyRead, this, &MyServer::readRestaurantsData);
        qDebug() << "Identification successful. New restaurant: " << clientSocket->peerAddress().toString();

        disconnect(clientSocket, &QTcpSocket::disconnected, this, &MyServer::handleClientIdentification);
        connect(clientSocket, &QTcpSocket::disconnected, this, &MyServer::restaurantDisconnected);
    }
    else if(data == "Customer")
    {
        myCustomers.insert(clientSocket);
        myPendings.remove(clientSocket);

        disconnect(clientSocket, &QTcpSocket::readyRead, this, &MyServer::handleClientIdentification);
        connect(clientSocket, &QTcpSocket::readyRead, this, &MyServer::readCustomersData);
        qDebug() << "Identification successful. New customer: " << clientSocket->peerAddress().toString();

        disconnect(clientSocket, &QTcpSocket::disconnected, this, &MyServer::handleClientIdentification);
        connect(clientSocket, &QTcpSocket::disconnected, this, &MyServer::customerDisconnected);
    }
    else if(data == "Delivery")
    {
        myDeliveries.insert(clientSocket);
        myPendings.remove(clientSocket);

        disconnect(clientSocket, &QTcpSocket::readyRead, this, &MyServer::handleClientIdentification);
        connect(clientSocket, &QTcpSocket::readyRead, this, &MyServer::readDeliveriesData);
        qDebug() << "Identification successful. New delivery: " << clientSocket->peerAddress().toString();

        disconnect(clientSocket, &QTcpSocket::disconnected, this, &MyServer::handleClientIdentification);
        connect(clientSocket, &QTcpSocket::disconnected, this, &MyServer::deliveryDisconnected);
    }
    else
    {
        myPendings.remove(clientSocket);
        qDebug() << "Client sent invalid identification. Disconnection from host.";
        clientSocket->disconnectFromHost();
        return;
    }


}

void MyServer::readRestaurantsData()
{

}

void MyServer::readCustomersData()
{

}

void MyServer::readDeliveriesData()
{

}

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





