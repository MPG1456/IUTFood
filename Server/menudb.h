#ifndef MENUDB_H
#define MENUDB_H
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlRecord>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

class menudb : public QObject
{
    Q_OBJECT
public:
    menudb();
    // Q_INVOKABLE bool usernameExist(QString username);
    Q_INVOKABLE bool addMenu(int restaurant_id , QString name ,QString ingredients , QString type ,  int capacity , double price);
    // Q_INVOKABLE bool deleteUser(QString username);
    QJsonDocument dbToJson();
};

#endif // MENUDB_H
