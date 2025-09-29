#ifndef CLIENTDB_H
#define CLIENTDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class ClientDB : public QObject
{
    Q_OBJECT
private:
    QString connectionName;
public:
    ClientDB(const QString &connName, QObject *parent = nullptr);
    Q_INVOKABLE bool usernameExist(QString username);
    Q_INVOKABLE bool addUser(QString username , QString password , QString firstName ,QString lastName ,int age , QString country ,QString city ,int postalCode , QString homeAddress ,QString homePhone ,QString phoneNumber);
    Q_INVOKABLE bool deleteUser(QString username);
    // Q_INVOKABLE void printAllUsers();
};
#endif // CLIENTDB_H
