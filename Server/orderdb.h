#ifndef ORDERDB_H
#define ORDERDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlRecord>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

class orderdb:public QObject
{
    Q_OBJECT
public:
    orderdb();
    // Q_INVOKABLE bool usernameExist(QString username);
    Q_INVOKABLE bool addOrder(int client_id , int restaurant_id , int delivery_id ,QString order_time , QString reached_time ,  QString status);
    // Q_INVOKABLE bool deleteUser(QString username);
    QJsonDocument dbToJson();
};

#endif // ORDERDB_H
