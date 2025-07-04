#include "restaurantdb.h"

RestaurantDB::RestaurantDB(const QString &connName, QObject *parent) : QObject(parent), connectionName(connName)
{}

bool RestaurantDB::usernameExist(QString username)
{
    QSqlDatabase db = QSqlDatabase::database(connectionName);
    QSqlQuery query(db);

    query.prepare("SELECT * FROM restaurant WHERE username = ?");
    query.addBindValue(username);
    if(query.exec()&& query.next())
        return true;
    else
        return false;
}

bool RestaurantDB::addUser(QString username , QString password, QString restaurantName , QString country ,QString city ,long long int postalcode , QString homeAddress ,QString homePhone ,QString bio, bool isAvailable)
{
    if (usernameExist(username))
        return false;

    QSqlDatabase db = QSqlDatabase::database(connectionName);
    QSqlQuery query(db);
    query.prepare("INSERT INTO restaurant (username , password , restaurantName , country , city , postalCode , homeAddress , homePhone , bio, isAvailable) VALUES (? , ? ,? , ? ,? , ? ,? , ? ,? ,?)");
    query.addBindValue(username);
    query.addBindValue(password);
    query.addBindValue(restaurantName);
    query.addBindValue(country);
    query.addBindValue(city);
    query.addBindValue(postalcode);
    query.addBindValue(homeAddress);
    query.addBindValue(homePhone);
    query.addBindValue(bio);
    query.addBindValue(isAvailable);
    return query.exec();
}
bool RestaurantDB::deleteUser(QString username)
{
    if(!usernameExist(username))
        return false;

    QSqlDatabase db = QSqlDatabase::database(connectionName);
    QSqlQuery query(db);
    query.prepare("DELETE FROM restaurant WHERE username = ?");
    query.addBindValue(username);
    return query.exec();
}
