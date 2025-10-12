#include "deliverydb.h"
#include "qcoreapplication.h"
#include "QDir"
DeliveryDB::DeliveryDB()
{
    QSqlDatabase db;
    if (!QSqlDatabase::contains("main_connection"))
    {
        db = QSqlDatabase::addDatabase("QSQLITE", "main_connection");
        QString path = QCoreApplication::applicationDirPath();
        QString dbPath = path + "/appdb.db";
        db.setDatabaseName(dbPath);
    }
    else
    {
        db = QSqlDatabase::database("main_connection");
    }

    if (!db.open())
    {
        qDebug() << "db didn't open!" << db.lastError().text();
        return;
    }

    QSqlQuery q(db);
    bool ok = q.exec(R"(
        CREATE TABLE IF NOT EXISTS delivery (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            username   TEXT NOT NULL COLLATE NOCASE,
            password   TEXT NOT NULL COLLATE NOCASE,
            firstname   TEXT NOT NULL COLLATE NOCASE,
            lastname    TEXT NOT NULL COLLATE NOCASE,
            country     TEXT NOT NULL COLLATE NOCASE,
            city        TEXT NOT NULL COLLATE NOCASE,
            postalcode  INTEGER NOT NULL COLLATE NOCASE,
            homeAddress        TEXT NOT NULL COLLATE NOCASE,
            homePhone       TEXT NOT NULL COLLATE NOCASE,
            phoneNumber       TEXT NOT NULL COLLATE NOCASE,
            age         INTEGER NOT NULL COLLATE NOCASE
        )
    )");
    if (!ok)
    {
        qDebug() << "Failed to (re)create table:" << q.lastError().text();
    }
}


bool DeliveryDB::usernameExist(QString username)
{
    QSqlDatabase db = QSqlDatabase::database("main_connection");
    QSqlQuery query(db);

    query.prepare("SELECT * FROM delivery WHERE username = ?");
    query.addBindValue(username);
    if(query.exec()&& query.next())
        return true;
    else
        return false;
}
bool DeliveryDB::addUser(QString username , QString password , QString firstname ,QString lastname ,int age , QString country ,QString city ,long long int postalCode , QString homeAddress ,QString homePhone ,QString phoneNumber)
{
    if (usernameExist(username))
        return false;

    QSqlDatabase db = QSqlDatabase::database("main_connection");
    QSqlQuery query(db);
    query.prepare("INSERT INTO delivery ( username , password , firstname , lastname , age , country , city , postalcode , homeAddress , homePhone , phoneNumber) VALUES ( ? , ? , ? , ? ,? , ? , ? , ? , ? , ? , ? ) ");
    query.addBindValue(username);
    query.addBindValue(password);
    query.addBindValue(firstname);
    query.addBindValue(lastname);
    query.addBindValue(age);
    query.addBindValue(country);
    query.addBindValue(city);
    query.addBindValue(postalCode);
    query.addBindValue(homeAddress);
    query.addBindValue(homePhone);
    query.addBindValue(phoneNumber);
    return query.exec();
}
bool DeliveryDB::deleteUser(QString username)
{
    if(!usernameExist(username))
        return false;

    QSqlDatabase db = QSqlDatabase::database("main_connection");
    QSqlQuery query(db);
    query.prepare("DELETE FROM delivery WHERE username = ?");
    query.addBindValue(username);
    return query.exec();
}
QJsonDocument DeliveryDB::dbToJson()
{
    QJsonArray array;
    QSqlDatabase db = QSqlDatabase::database("main_connection");
    QSqlQuery query(db);

    if(query.exec("SELECT * FROM delivery"))
    {
        while(query.next())
        {
            QJsonObject obj;
            obj["id"] = query.value("id").toInt();
            obj["username"] = query.value("username").toString();
            obj["password"] = query.value("password").toString();
            obj["firstname"] = query.value("firstname").toString();
            obj["lastname"] = query.value("lastname").toString();
            obj["country"] = query.value("country").toString();
            obj["city"] = query.value("city").toString();
            obj["postalcode"] = query.value("postalcode").toLongLong();
            obj["homeAddress"] = query.value("homeAddress").toString();
            obj["homePhone"] = query.value("homePhone").toString();
            obj["phoneNumber"] = query.value("phoneNumber").toString();
            obj["age"] = query.value("age").toInt();

            array.append(obj);
        }
    }
    else
    {
        qDebug() << "Failed to fetch delivery data:" << query.lastError().text();
    }

    return QJsonDocument(array);
}
