#include "orderdb.h"
#include "qcoreapplication.h"
#include "QDir"

orderdb::orderdb()
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
            CREATE TABLE IF NOT EXISTS orders (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                client_id       INTEGER NOT NULL COLLATE NOCASE,
                restaurant_id   INTEGER NOT NULL COLLATE NOCASE,
                delivery_id   INTEGER NOT NULL COLLATE NOCASE,
                order_time    TEXT NOT NULL COLLATE NOCASE,
                reached_time   TEXT NOT NULL COLLATE NOCASE,
                status         TEXT NOT NULL COLLATE NOCASE,
                FOREIGN KEY(client_id) REFERENCES client(id),
                FOREIGN KEY(restaurant_id) REFERENCES restaurant(id),
                FOREIGN KEY(delivery_id) REFERENCES delivery(id)
            )
        )");
        if (!ok)
        {
            qDebug() << "Failed to (re)create table:" << q.lastError().text();
        }
    }
}
// bool orderdb::usernameExist(QString username)
// {
//     QSqlDatabase db = QSqlDatabase::database("main_connection");
//     QSqlQuery query(db);

//     query.prepare("SELECT * FROM client WHERE username = ?");
//     query.addBindValue(username);
//     if(query.exec()&& query.next())
//         return true;
//     else
//         return false;
// }

bool orderdb::addOrder(int client_id , int restaurant_id , int delivery_id ,QString order_time , QString reached_time ,  QString status)
{
    QSqlDatabase db = QSqlDatabase::database("main_connection");
    QSqlQuery query(db);
    query.prepare("INSERT INTO orders ( client_id , restaurant_id , delivery_id , order_time , reached_time , status) VALUES ( ? , ? , ? , ? ,? , ?) ");
    query.addBindValue(client_id);
    query.addBindValue(restaurant_id);
    query.addBindValue(delivery_id);
    query.addBindValue(order_time);
    query.addBindValue(reached_time);
    query.addBindValue(status);
    return query.exec();
}
// bool orderdb::deleteUser(QString username)
// {
//     if(!usernameExist(username))
//         return false;

//     QSqlDatabase db = QSqlDatabase::database("main_connection");
//     QSqlQuery query(db);
//     query.prepare("DELETE FROM client WHERE username = ?");
//     query.addBindValue(username);
//     return query.exec();
// }
