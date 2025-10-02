#include "myserver.h"
MyServer::MyServer(QObject *parent):QTcpServer(parent)
{
    if (!listen(QHostAddress::Any, 1234))
    {
        qDebug()<<"server is not listening!";
    }
    else
    {
        qDebug()<<"serverz is listening!";
    }
}
void MyServer::incomingConnection(qintptr socketDescriptor)
{
    QTcpSocket *socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket , &QTcpSocket::readyRead , this , &MyServer::onReadyRead);
    connect(socket , &QTcpSocket::disconnected , this , &MyServer::onDisconnected);
    roles[socket] = "unknown";
    qDebug()<<"new connection!";
}
void MyServer::onReadyRead()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    QString data = QString::fromUtf8(socket->readAll()).trimmed();
    if (roles[socket] == "unknown")
    {
        if (data.startsWith("role:"))
        {
            QString role = data.section(":",1);
            roles[socket] = role;
            qDebug()<<"role is ok!";
        }
        else
        {
            qDebug()<<"role is not ok!";
        }
    }
    else
    {
        QString role = roles[socket];
        if (role == "CLIENT") {
            socket->write("Hello Client!\n");
        } else if (role == "RESTAURANT") {
            socket->write("Hello Restaurant!\n");
        } else if (role == "DELIVERY") {
            socket->write("Hello Delivery!\n");
        } else if (role == "ADMIN") {
            socket->write("Hello Admin!\n");
        }
    }
}
void MyServer::onDisconnected()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    roles.remove(socket);
    socket->deleteLater();
}
