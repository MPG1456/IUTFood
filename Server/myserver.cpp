#include "myserver.h"


MyServer::MyServer(QObject *parent) : QTcpServer(parent)
{
    setupDatabase(clientDb, "clientConnection", "clientdb2.db");
    setupDatabase(restaurantDb, "restaurantConnection", "restaurantdb.db");
    setupDatabase(deliveryDb, "deliveryConnection", "deliverydb.db");
}

void MyServer::setupDatabase(QSqlDatabase &db, const QString &connectionName, const QString &dbFileName)
{
    db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    QString dataLocation = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir dataDir(dataLocation);
    if (!dataDir.exists()) {
        dataDir.mkpath(".");
    }

    QString dbPath = dataDir.absoluteFilePath(dbFileName);
    db.setDatabaseName(dbPath);

    qDebug() << "Attempting to open database file at:" << dbPath;

    if (!QFile::exists(dbPath))
    {
        QString sourcePath = QString(":/databases/%1").arg(dbFileName);
        if (QFile::copy(sourcePath, dbPath)) {
            QFile::setPermissions(dbPath, QFile::WriteOwner | QFile::ReadOwner);
            qDebug() << "Database copied successfully from resources.";
        } else {
            qDebug() << "ERROR: Failed to copy database from" << sourcePath;
        }
    }

    if (!db.open()) {
        qDebug() << "Failed to open database:" << db.lastError().text();
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
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if(!socket)
        return;

    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_8);

    while(!in.atEnd())
    {
        MessageType mType;
        QVariant payload;

        in >> mType >> payload;

        switch(mType)
        {
        case MessageType::sendRestaurantSignIn:
            if(payload.canConvert<class Restaurant>())
            {
                class Restaurant newRestaurant = payload.value<class Restaurant>();
                QSqlQuery query(QSqlDatabase::database("restaurantConnection"));
            }

        }
    }
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





