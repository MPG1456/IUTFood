#ifndef RESTAURANTDB_H
#define RESTAURANTDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class RestaurantDB : public QObject
{
    Q_OBJECT
private:
    QString connectionName;
public:
    RestaurantDB();

    Q_INVOKABLE bool usernameExist(QString username);
    Q_INVOKABLE bool addRestaurant(QString username , QString password ,QString restaurantName , QString country ,QString city ,long long int postalcode , QString homeAddress ,QString homePhone ,QString bio , QString phoneNumber , QString time , QString score="0" , QString score_counter="0");
    Q_INVOKABLE bool deleteUser(QString username);
    // Q_INVOKABLE void printAllUsers();

};

#endif // RESTAURANTDB_H
