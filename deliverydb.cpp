#include "deliverydb.h"
#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QStandardPaths>

deliverydb::deliverydb(QObject *parent)
{
    redb = QSqlDatabase::addDatabase("QSQLITE");

    QString dataLocation = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);

    // Create the directory if it doesn't exist.
    QDir dataDir(dataLocation);
    if(!dataDir.exists())
    {
        dataDir.mkpath("."); // <- this one creates the path if it doesn't exist
    }

    QString dbPath = dataDir.absoluteFilePath("deliverydb.db");
    redb.setDatabaseName(dbPath);

    qDebug() << "Attempting to open database file at: " << dbPath;

    if(!QFile::exists(dbPath))
    {
        qDebug() << "File doesn't exist in the chosen path. It will copy it from resources.";
        QFile::copy("F:/Projects/AP/Final Term/IUTFood/deliverydb.db", dbPath); // ATTENITION: change this path to your directory
    }

    if(!redb.open())
    {
        qDebug()<<"Failed to open";
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

    return query.exec();
}



