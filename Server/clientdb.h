#ifndef CLIENTDB_H
#define CLIENTDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
class ClientDB : public QObject
{
    Q_OBJECT
private:
    QString connectionName;
public:
    ClientDB();
    Q_INVOKABLE bool usernameExist(QString username);
    Q_INVOKABLE bool addUser(QString username , QString password , QString firstName ,QString lastName ,int age , QString country ,QString city ,int postalCode , QString homeAddress ,QString homePhone ,QString phoneNumber);
    Q_INVOKABLE bool deleteUser(QString username);
    QJsonDocument dbToJson();
    // Q_INVOKABLE void printAllUsers();
};
#endif // CLIENTDB_H
