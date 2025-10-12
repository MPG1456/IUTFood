#include "orderedfooddb.h"

#include "menudb.h"
#include "qcoreapplication.h"
#include "QDir"

ordered_foods::ordered_foods(QObject *parent)
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
            CREATE TABLE IF NOT EXISTS ordered_foods (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                order_id      INTEGER NOT NULL,
                menu_id       INTEGER NOT NULL,
                quantity      INTEGER NOT NULL,
               FOREIGN KEY(order_id) REFERENCES orders(id),
               FOREIGN KEY(menu_id) REFERENCES menu(id)
            )
        )");
        if (!ok)
        {
            qDebug() << "Failed to (re)create table:" << q.lastError().text();
        }
    }
}
bool ordered_foods::addOrderedFood(int order_id , int menu_id ,int quantity)
{
    QSqlDatabase db = QSqlDatabase::database("main_connection");
    QSqlQuery query(db);
    query.prepare("INSERT INTO ordered_foods (order_id , menu_id , quantity) VALUES ( ? , ? , ?) ");
    query.addBindValue(order_id);
    query.addBindValue(menu_id);
    query.addBindValue(quantity);
    return query.exec();
}
QJsonDocument ordered_foods::dbToJson()
{
    QJsonArray array;
    QSqlDatabase db = QSqlDatabase::database("main_connection");
    QSqlQuery query(db);

    if(query.exec("SELECT * FROM ordered_foods"))
    {
        while(query.next())
        {
            QJsonObject obj;
            obj["id"] = query.value("id").toInt();
            obj["order_id"] = query.value("order_id").toInt();
            obj["menu_id"] = query.value("menu_id").toInt();
            obj["quantity"] = query.value("quantity").toInt();

            array.append(obj);
        }
    }
    else
    {
        qDebug() << "Failed to fetch ordered_foods data:" << query.lastError().text();
    }

    return QJsonDocument(array);
}
