#ifndef RESTAURANTDB_H
#define RESTAURANTDB_H

#include <QObject>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>

class restaurantdb:public QObject
{
    Q_OBJECT
private:
    QSqlDatabase redb;
public:
    restaurantdb(QObject *parent = nullptr );
    Q_INVOKABLE bool usernameexist(QString username);
    Q_INVOKABLE bool deleteuser(QString username);
    // Q_INVOKABLE void printAllUsers();
    Q_INVOKABLE bool adduser(QString username , QString password , QString name ,QString restaurantname , QString country ,QString city ,long long int postalcode , QString homeadress ,QString homephone ,QString bio = "Hi" );
};

#endif // RESTAURANTDB_H
