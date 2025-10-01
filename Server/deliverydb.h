#ifndef DELIVERYDB_H
#define DELIVERYDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class DeliveryDB : public QObject
{
    Q_OBJECT
private:
    QString connectionName;
public:
    DeliveryDB();

    Q_INVOKABLE bool usernameExist(QString username);
    Q_INVOKABLE bool addUser(QString username , QString password , QString firstName ,QString lastName ,int age , QString country ,QString city ,long long int postalCode , QString homeAddress ,QString homePhone ,QString phoneNumber);
    Q_INVOKABLE bool deleteUser(QString username);
    // Q_INVOKABLE void printAllUsers();

};


#endif // DELIVERYDB_H
