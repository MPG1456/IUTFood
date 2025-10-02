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
class MyServer: public QTcpServer
{
    Q_OBJECT
public:
    MyServer(QObject *parent = nullptr);
private:
    void incomingConnection(qintptr socketDescriptor);
    QHash <QTcpSocket* , QString> roles;

private slots:
    void onReadyRead();
    void onDisconnected();
};

#endif // MYSERVER_H
