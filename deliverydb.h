#ifndef DELIVERYDB_H
#define DELIVERYDB_H
#include <QObject>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>
class deliverydb:public QObject
{
    Q_OBJECT
private:
    QSqlDatabase redb;
public:
    deliverydb(QObject *parent = nullptr );
    Q_INVOKABLE bool usernameexist(QString username);
    Q_INVOKABLE bool deleteuser(QString username);
    Q_INVOKABLE bool adduser(QString username , QString password , QString firstname ,QString lastname ,int age , QString country ,QString city ,long long int postalcode , QString homeaddress ,QString homephone ,QString phonenumber );
};

#endif // DELIVERYDB_H
