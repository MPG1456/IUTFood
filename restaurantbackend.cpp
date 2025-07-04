#include "restaurantbackend.h"

#include <QDataStream>
#include <QVariant>

RestaurantBackend::RestaurantBackend(QObject *parent) : QObject(parent)
{
    m_socket = new QTcpSocket(this);

    connect(m_socket, &QTcpSocket::connected, this, &RestaurantBackend::onConnected);
    connect(m_socket, &QTcpSocket::disconnected, this, &RestaurantBackend::onDisconnected);
    connect(m_socket, &QTcpSocket::readyRead, this, &RestaurantBackend::onReadyRead);
    connectToServer();
}

void RestaurantBackend::connectToServer()
{
    qDebug() << "Attempting to connect to server...";
    m_socket->connectToHost(QHostAddress::LocalHost, 1234);
}

void RestaurantBackend::onConnected()
{
    qDebug() << "Successfully connected to server. Sending identification.";
    sendInitialIdentification();
}

void RestaurantBackend::sendInitialIdentification()
{
    if (!m_socket->isOpen()) return;
    m_socket->write("Restaurant");
}

void RestaurantBackend::onDisconnected()
{
    qDebug() << "Disconnected from server.";
}

void RestaurantBackend::signIn(const QString &username, const QString &password)
{
    if (!m_socket->isOpen()) {
        qDebug() << "Socket is not open!";
        return;
    }


    Restaurant rIdentity;
    rIdentity.getIdentity().setUsername(username);
    rIdentity.getIdentity().setPassword(password);

    QByteArray dataBlock;
    QDataStream out(&dataBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_8);

    out << MessageType::sendRestaurantSignIn << QVariant::fromValue(rIdentity);

    m_socket->write(dataBlock);
}

void RestaurantBackend::onReadyRead()
{
    QDataStream in(m_socket);
    in.setVersion(QDataStream::Qt_6_8);

    while (!in.atEnd()) {
        MessageType type;
        QVariant payload;
        in >> type >> payload;

        switch(type)
        {
        case MessageType::serverRespondSuccess:
        {
            qDebug() << "Server success:" << payload.toString();
            emit signInSucceeded();
            break;
        }
        case MessageType::serverRespondFailure:
        {
            QString reason = payload.toString();
            qDebug() << "Server failure:" << reason;
            emit signInFailed();
            break;
        }
        }
    }
}
