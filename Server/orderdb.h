#ifndef ORDERDB_H
#define ORDERDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class orderdb:public QObject
{
    Q_OBJECT
public:
    orderdb(QObject *parent = nullptr);
    // Q_INVOKABLE bool usernameExist(QString username);
    Q_INVOKABLE bool addOrder(int client_id , int restaurant_id , int delivery_id ,QString order_time , QString reached_time ,  QString status);
    // Q_INVOKABLE bool deleteUser(QString username);
};

#endif // ORDERDB_H
