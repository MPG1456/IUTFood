#include "restaurantdb.h"
#include<QCoreApplication>
#include<QDebug>
restaurantdb::restaurantdb(QObject *parent)
{
    redb = QSqlDatabase::addDatabase("QSQLITE");
    redb.setDatabaseName(QCoreApplication::applicationDirPath()+"/restaurantdb.db");
    if(!redb.open())
    {
        qDebug()<<"failed to open";
    }
}
bool restaurantdb::usernameexist(QString username)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM restaurant WHERE username = ?");
    query.addBindValue(username);
    if(query.exec()&& query.next())
    {
        return true;
    }
    return false;
}
bool restaurantdb::deleteuser(QString username)
{
    QSqlQuery query;
    query.prepare("DELETE FROM restaurant WHERE username = ?");
    query.addBindValue(username);
    return query.exec();
}
bool restaurantdb::adduser(QString username , QString password , QString name ,QString restaurantname , QString country ,QString city ,long long int postalcode , QString homeadress ,QString homephone ,QString bio )
{
    if (usernameexist(username))
    {
        return false;
    }
    QSqlQuery query;
    query.prepare("INSERT INTO restaurant (username , password , name , restaurantname , country , city , postalcode , homeadress , homephone , bio) VALUES (? , ? ,? , ? ,? , ? ,? , ? ,? ,?)");
    query.addBindValue(username);
    query.addBindValue(password);
    query.addBindValue(name);
    query.addBindValue(restaurantname);
    query.addBindValue(country);
    query.addBindValue(city);
    query.addBindValue(postalcode);
    query.addBindValue(homeadress);
    query.addBindValue(homephone);
    query.addBindValue(bio);
    qDebug()<<"here i am";
    return query.exec();
}
// void restaurantdb::printAllUsers()
// {
//     QSqlQuery query("SELECT * FROM restaurant");
//     while (query.next()) {
//         QString username = query.value("username").toString();
//         QString name = query.value("name").toString();
//         QString city = query.value("city").toString();
//         QString restaurantname = query.value("restaurantname").toString();
//         qDebug() << "User:" << username << ", Name:" << name << ", City:" << city<<"rest"<<restaurantname;
//     }
// }
