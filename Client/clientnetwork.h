#ifndef CLIENTNETWORK_H
#define CLIENTNETWORK_H

#include <QObject>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
class clientNetwork: public QObject
{
    Q_OBJECT
public:
    clientNetwork(QObject *parent = nullptr);
    Q_INVOKABLE void sendData(const QString& message);
    void loadClientFromDb(QJsonDocument doc);
    void loadRestaurantFromDb(QJsonDocument doc);
    void loadMenuFromDb(QJsonDocument doc);
    void loadOrderFromDb(QJsonDocument doc);
    void loadDeliveryFromDb(QJsonDocument doc);
    void loadOrderedFoodsFromDb(QJsonDocument doc);
private:
    QTcpSocket socket;
private slots:
    void onReadyRead();
};

#endif // CLIENTNETWORK_H
