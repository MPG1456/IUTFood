#include "clientdb.h"
#include<QCoreApplication>
#include<QDebug>
clientdb::clientdb(QObject *parent)
{
    redb = QSqlDatabase::addDatabase("QSQLITE");
    redb.setDatabaseName(QCoreApplication::applicationDirPath()+"/clien.db");
    if(!redb.open())
    {
        qDebug()<<"failed to open";
    }
    if(redb.isOpen())
    {
        qDebug()<<"open";
    }
    else
    {
        qDebug()<<"close";

    }
}
bool clientdb::usernameexist(QString username)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM client WHERE username = ?");
    query.addBindValue(username);
    if(query.exec()&& query.next())
    {
        return true;
    }
    return false;
}
bool clientdb::deleteuser(QString username)
{
    QSqlQuery query;
    query.prepare("DELETE FROM client WHERE username = ?");
    query.addBindValue(username);
    return query.exec();
}
bool clientdb::adduser(QString username , QString password , QString firstname ,QString lastname ,int age , QString country ,QString city ,long long int postalcode , QString homeaddress ,QString homephone ,QString phonenumber )
{
    if (usernameexist(username))
    {
        return false;
    }
    QSqlQuery query;
    query.prepare("INSERT INTO client ( username , password , firstname , lastname , age , country , city , postalcode , homeaddress , homephone , phonenumber) VALUES ( ? , ? , ? , ? ,? , ? , ? , ? , ? , ? , ? ) " );
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
    if (!query.exec()) {
        qDebug() << "Add user failed:" << query.lastError().text();
        return false;
    }
    return true;
}

