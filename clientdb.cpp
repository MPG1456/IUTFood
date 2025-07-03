#include "clientdb.h"
#include <QCoreApplication>
#include <QDebug>
#include <QStandardPaths>
#include <QDir>

clientdb::clientdb(QObject *parent)
{
    redb = QSqlDatabase::addDatabase("QSQLITE");

    QString dataLocation = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir dataDir(dataLocation);
    if(!dataDir.exists())
    {
        dataDir.mkpath(".");
    }

    QString dbPath = dataDir.absoluteFilePath("clientdb2.db");
    redb.setDatabaseName(dbPath);

    qDebug() << "Attempting to open database file at: " << dbPath;

    if(!QFile::exists(dbPath))
    {
        qDebug() << "File doesn't exist in the chosen path. It will copy it from resources.";
        QFile::copy("F:/Projects/AP/Final Term/IUTFood/clientdb2.db", dbPath); // ATTENITION: change this path to your directory
    }


    if(!redb.open())
    {
        qDebug()<<"Failed to open";
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

bool clientdb::adduser(QString username , QString password , QString firstname ,QString lastname ,int age , QString country ,QString city ,QString postalcode , QString homeaddress ,QString homephone ,QString phonenumber )
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

    return query.exec();
}

