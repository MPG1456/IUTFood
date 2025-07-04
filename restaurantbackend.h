#ifndef RESTAURANTBACKEND_H
#define RESTAURANTBACKEND_H

#include <QObject>
#include <QTcpSocket>

#include "protocol.h"

class RestaurantBackend : public QObject
{
    Q_OBJECT

public:
    explicit RestaurantBackend(QObject *parent = nullptr);

    Q_INVOKABLE void signIn(const QString &username, const QString &password);

signals:
    void signInSucceeded();
    void signInFailed();

private slots:
    void onReadyRead();
    void onConnected();
    void onDisconnected();

private:
    void connectToServer();
    void sendInitialIdentification();
    QTcpSocket *m_socket;
};

#endif // RESTAURANTBACKEND_H
