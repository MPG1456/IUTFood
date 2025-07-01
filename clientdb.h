#ifndef CLIENTDB_H
#define CLIENTDB_H
#include <QObject>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>
class clientdb:public QObject
{
    Q_OBJECT
private:
    QSqlDatabase redb;
public:
    clientdb(QObject *parent = nullptr );
    Q_INVOKABLE bool usernameexist(QString username);
    Q_INVOKABLE bool deleteuser(QString username);
    Q_INVOKABLE bool adduser(QString username , QString password , QString firstname ,QString lastname ,int age , QString country ,QString city ,long long int postalcode , QString homeaddress ,QString homephone ,QString phonenumber );
};
#endif // CLIENTDB_H
