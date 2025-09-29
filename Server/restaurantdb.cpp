#include "restaurantdb.h"
#include "qcoreapplication.h"
#include "QDir"
RestaurantDB::RestaurantDB(const QString &connName, QObject *parent) : QObject(parent), connectionName(connName)
{
    if (!QSqlDatabase::contains("main_connection"))
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "main_connection");
        QString path = QCoreApplication::applicationDirPath();
        QString dbPath = path + "/appdb.db";
        QDir pathtemp;
        if (!pathtemp.exists(path))
        {
            qDebug() << "moshkel masir!" << path;
        }
        qDebug()<<path;
        db.setDatabaseName(dbPath);
        if (!db.open())
        {
            qDebug() << "db didn't open!" << db.lastError().text();
            return;
        }
        QSqlQuery q(db);
        bool ok = q.exec(R"(
            CREATE TABLE IF NOT EXISTS restaurant (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                username   TEXT NOT NULL COLLATE NOCASE,
                password   TEXT NOT NULL COLLATE NOCASE,
                restaurantname       TEXT NOT NULL COLLATE NOCASE,
                bio        TEXT NOT NULL COLLATE NOCASE,
                country     TEXT NOT NULL COLLATE NOCASE,
                city        TEXT NOT NULL COLLATE NOCASE,
                postalcode  INTEGER NOT NULL COLLATE NOCASE,
                homeAddress        TEXT NOT NULL COLLATE NOCASE,
                homePhone       TEXT NOT NULL COLLATE NOCASE,
                phoneNumber     TEXT NOT NULL COLLATE NOCASE,
                time            TEXT NOT NULL COLLATE NOCASE,
                score           TEXT NOT NULL COLLATE NOCASE,
                score_counter       TEXT NOT NULL COLLATE NOCASE
            )
        )");
        if (!ok)
        {
            qDebug() << "Failed to (re)create table:" << q.lastError().text();
        }
    }
}
bool RestaurantDB::usernameExist(QString username)
{
    QSqlDatabase db = QSqlDatabase::database("main_connection");
    QSqlQuery query(db);

    query.prepare("SELECT * FROM restaurant WHERE username = ?");
    query.addBindValue(username);
    if(query.exec()&& query.next())
        return true;
    else
        return false;
}

bool RestaurantDB::addUser(QString username , QString password , QString restaurantName , QString country ,QString city ,long long int postalcode , QString homeAddress ,QString homePhone ,QString bio , QString phoneNumber , QString time , QString score , QString score_counter)
{
    if (usernameExist(username))
        return false;

    QSqlDatabase db = QSqlDatabase::database("main_connection");
    QSqlQuery query(db);
    query.prepare("INSERT INTO restaurant (username , password , restaurantname , bio  , country , city , postalcode , homeAddress , homePhone , phoneNumber , time , score , score_counter) VALUES (? , ? ,? , ? ,? , ? ,? , ? ,? ,? ,? ,? , ?)");
    query.addBindValue(username);
    query.addBindValue(password);
    query.addBindValue(restaurantName);
    query.addBindValue(bio);
    query.addBindValue(country);
    query.addBindValue(city);
    query.addBindValue(postalcode);
    query.addBindValue(homeAddress);
    query.addBindValue(homePhone);
    query.addBindValue(phoneNumber);
    query.addBindValue(time);
    query.addBindValue(score);
    query.addBindValue(score_counter);
    return query.exec();
}
bool RestaurantDB::deleteUser(QString username)
{
    if(!usernameExist(username))
        return false;

    QSqlDatabase db = QSqlDatabase::database("main_connection");
    QSqlQuery query(db);
    query.prepare("DELETE FROM restaurant WHERE username = ?");
    query.addBindValue(username);
    return query.exec();
}
