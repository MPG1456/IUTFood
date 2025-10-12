#include "clientdb.h"
#include "qcoreapplication.h"
#include "QDir"

ClientDB::ClientDB()
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
            CREATE TABLE IF NOT EXISTS client (
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
}
bool ClientDB::usernameExist(QString username)
{
    QSqlDatabase db = QSqlDatabase::database("main_connection");
    QSqlQuery query(db);

    query.prepare("SELECT * FROM client WHERE username = ?");
    query.addBindValue(username);
    if(query.exec()&& query.next())
        return true;
    else
        return false;
}

bool ClientDB::addUser(QString username , QString password , QString firstname ,QString lastname ,int age , QString country ,QString city ,int postalcode , QString homeAddress ,QString homePhone ,QString phoneNumber)
{
    if (usernameExist(username))
        return false;

    QSqlDatabase db = QSqlDatabase::database("main_connection");
    QSqlQuery query(db);
    query.prepare("INSERT INTO client ( username , password , firstname , lastname , country , city , postalcode , homeAddress , homePhone , phoneNumber , age ) VALUES ( ? , ? , ? , ? ,? , ? , ? , ? , ? , ? , ? ) ");
    query.addBindValue(username);
    query.addBindValue(password);
    query.addBindValue(firstname);
    query.addBindValue(lastname);
    query.addBindValue(country);
    query.addBindValue(city);
    query.addBindValue(postalcode);
    query.addBindValue(homeAddress);
    query.addBindValue(homePhone);
    query.addBindValue(phoneNumber);
    query.addBindValue(age);
    return query.exec();
}
bool ClientDB::deleteUser(QString username)
{
    if(!usernameExist(username))
        return false;

    QSqlDatabase db = QSqlDatabase::database("main_connection");
    QSqlQuery query(db);
    query.prepare("DELETE FROM client WHERE username = ?");
    query.addBindValue(username);
    return query.exec();
}
QJsonDocument ClientDB::dbToJson()
{
    QJsonArray clientsArray;
    QSqlDatabase db = QSqlDatabase::database("main_connection");
    QSqlQuery query(db);

    if (!query.exec("SELECT * FROM client")) {
        qDebug() << "Failed to select clients:" << query.lastError().text();
        return QJsonDocument(clientsArray);
    }

    while (query.next()) {
        QJsonObject clientObj;
        clientObj["id"] = query.value("id").toInt();
        clientObj["username"] = query.value("username").toString();
        clientObj["password"] = query.value("password").toString();
        clientObj["firstname"] = query.value("firstname").toString();
        clientObj["lastname"] = query.value("lastname").toString();
        clientObj["country"] = query.value("country").toString();
        clientObj["city"] = query.value("city").toString();
        clientObj["postalcode"] = query.value("postalcode").toInt();
        clientObj["homeAddress"] = query.value("homeAddress").toString();
        clientObj["homePhone"] = query.value("homePhone").toString();
        clientObj["phoneNumber"] = query.value("phoneNumber").toString();
        clientObj["age"] = query.value("age").toInt();

        clientsArray.append(clientObj);
    }

    return QJsonDocument(clientsArray);
}
