#include "deliverydb.h"
#include<QCoreApplication>
#include<QDebug>
deliverydb::deliverydb(QObject *parent)
{
    redb = QSqlDatabase::addDatabase("QSQLITE");
    redb.setDatabaseName(QCoreApplication::applicationDirPath()+"/deliverydb.db");
    if(!redb.open())
    {
        qDebug()<<"failed to open";
    }
}
bool deliverydb::usernameexist(QString username)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM delivery WHERE username = ?");
    query.addBindValue(username);
    if(query.exec()&& query.next())
    {
        return true;
    }
    return false;
}
bool deliverydb::deleteuser(QString username)
{
    QSqlQuery query;
    query.prepare("DELETE FROM delivery WHERE username = ?");
    query.addBindValue(username);
    return query.exec();
}
bool deliverydb::adduser(QString username , QString password , QString firstname ,QString lastname ,int age , QString country ,QString city ,long long int postalcode , QString homeaddress ,QString homephone ,QString phonenumber )
{
    if (usernameexist(username))
    {
        return false;
    }
    QSqlQuery query;
    query.prepare("INSERT INTO delivery (username , password , firstname , lastname ,age , country , city , postalcode , homeaddress , homephone , phonenumber) VALUES (? , ? ,? , ? ,? , ? ,? , ? ,? ,? , ?)");
    query.addBindValue(username);
    query.addBindValue(password);
    query.addBindValue(firstname);
    query.addBindValue(lastname);
    query.addBindValue(age);
    query.addBindValue(country);
    query.addBindValue(city);
    query.addBindValue(postalcode);
    query.addBindValue(homeaddress);
    query.addBindValue(homephone);
    query.addBindValue(phonenumber);
    qDebug()<<"you're not brave!men are brave";
    return query.exec();
}



