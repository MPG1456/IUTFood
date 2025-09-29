#ifndef MENUDB_H
#define MENUDB_H
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class menudb : public QObject
{
    Q_OBJECT
public:
    menudb(QObject *parent = nullptr);
    // Q_INVOKABLE bool usernameExist(QString username);
    Q_INVOKABLE bool addMenu(int restaurant_id , QString name ,QString ingredients , QString type ,  int capacity , double price);
    // Q_INVOKABLE bool deleteUser(QString username);
};

#endif // MENUDB_H
