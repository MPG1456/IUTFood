#ifndef RESTAURANTDB_H
#define RESTAURANTDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

#include "restaurant.h"

class RestaurantDB : public QObject
{
    Q_OBJECT
private:
    QString connectionName;
public:
    RestaurantDB(const QString &connName, QObject *parent = nullptr);

    Q_INVOKABLE bool usernameExist(QString username);
    Q_INVOKABLE bool addUser(QString username , QString password, QString restaurantName , QString country ,QString city ,long long int postalcode , QString homeAddress ,QString homePhone ,QString bio, bool isAvailable);
    Q_INVOKABLE bool deleteUser(QString username);
    // Q_INVOKABLE void printAllUsers();

};

#endif // RESTAURANTDB_H
