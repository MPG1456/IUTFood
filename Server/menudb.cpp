#include "menudb.h"
#include "qcoreapplication.h"
#include "QDir"

menudb::menudb()
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
        QSqlQuery pragma(db);
        if (!pragma.exec("PRAGMA foreign_keys = ON"))
        {
            qDebug() << "Failed to enable foreign keys:" << pragma.lastError().text();
        }
        QSqlQuery q(db);
        bool ok = q.exec(R"(
            CREATE TABLE IF NOT EXISTS menu (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                restaurant_id INTEGER NOT NULL,
                name       TEXT NOT NULL COLLATE NOCASE,
                ingredients   TEXT NOT NULL COLLATE NOCASE,
                type   TEXT NOT NULL COLLATE NOCASE,
                capacity    INTEGER NOT NULL,
                price   REAL NOT NULL,
               FOREIGN KEY(restaurant_id) REFERENCES restaurant(id)
            )
        )");
        if (!ok)
        {
            qDebug() << "Failed to (re)create table:" << q.lastError().text();
        }
    }
}
bool menudb::addMenu(int restaurant_id , QString name ,QString ingredients , QString type ,  int capacity , double price)
{
    QSqlDatabase db = QSqlDatabase::database("main_connection");
    QSqlQuery query(db);
    query.prepare("INSERT INTO menu (restaurant_id , name , ingredients , type , capacity , price) VALUES ( ? , ? , ? , ? ,? , ?) ");
    query.addBindValue(restaurant_id);
    query.addBindValue(name);
    query.addBindValue(ingredients);
    query.addBindValue(type);
    query.addBindValue(capacity);
    query.addBindValue(price);
    return query.exec();
}
QJsonDocument menudb::dbToJson()
{
    QJsonArray array;
    QSqlDatabase db = QSqlDatabase::database("main_connection");
    QSqlQuery query(db);

    if(query.exec("SELECT * FROM menu"))
    {
        while(query.next())
        {
            QJsonObject obj;
            obj["id"] = query.value("id").toInt();
            obj["restaurant_id"] = query.value("restaurant_id").toInt();
            obj["name"] = query.value("name").toString();
            obj["ingredients"] = query.value("ingredients").toString();
            obj["type"] = query.value("type").toString();
            obj["capacity"] = query.value("capacity").toInt();
            obj["price"] = query.value("price").toDouble();

            array.append(obj);
        }
    }
    else
    {
        qDebug() << "Failed to fetch menu data:" << query.lastError().text();
    }

    return QJsonDocument(array);
}
