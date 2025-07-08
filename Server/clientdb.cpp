// #include "clientdb.h"

// ClientDB::ClientDB(const QString &connName, QObject *parent) : QObject(parent), connectionName(connName)
// {}

// bool ClientDB::usernameExist(QString username)
// {
//     QSqlDatabase db = QSqlDatabase::database(connectionName);
//     QSqlQuery query(db);

//     query.prepare("SELECT * FROM client WHERE username = ?");
//     query.addBindValue(username);
//     if(query.exec()&& query.next())
//         return true;
//     else
//         return false;
// }

// bool ClientDB::addUser(QString username , QString password , QString firstName ,QString lastName ,int age , QString country ,QString city ,QString postalCode , QString homeAddress ,QString homePhone ,QString phoneNumber)
// {
//     if (usernameExist(username))
//         return false;

//     QSqlDatabase db = QSqlDatabase::database(connectionName);
//     QSqlQuery query(db);
//     query.prepare("INSERT INTO client ( username , password , firstName , lastName , age , country , city , postalCode , homeAddress , homePhone , phoneNumber) VALUES ( ? , ? , ? , ? ,? , ? , ? , ? , ? , ? , ? ) ");
//     query.addBindValue(username);
//     query.addBindValue(password);
//     query.addBindValue(firstName);
//     query.addBindValue(lastName);
//     query.addBindValue(age);
//     query.addBindValue(country);
//     query.addBindValue(city);
//     query.addBindValue(postalCode);
//     query.addBindValue(homeAddress);
//     query.addBindValue(homePhone);
//     query.addBindValue(phoneNumber);
//     return query.exec();
// }
// bool ClientDB::deleteUser(QString username)
// {
//     if(!usernameExist(username))
//         return false;

//     QSqlDatabase db = QSqlDatabase::database(connectionName);
//     QSqlQuery query(db);
//     query.prepare("DELETE FROM client WHERE username = ?");
//     query.addBindValue(username);
//     return query.exec();
// }
