#ifndef CLIENTNETWORK_H
#define CLIENTNETWORK_H

#include <QObject>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include "customer.h"
#include "personidentity.h"
#include "person.h"
#include "address.h"
#include "delivery.h"
#include "dessert.h"
#include "drinks.h"
#include "fastfood.h"
#include "food.h"
#include "iranifood.h"
#include "maindish.h"
#include "menu.h"
#include "menufunctions.h"
#include "restaurant.h"
#include "salad.h"
#include "score.h"
#include "order.h"
class clientNetwork: public QObject
{
    Q_OBJECT
public:
    clientNetwork(QObject *parent = nullptr);
    void sendData(const QString& message);
    void loadClientFromDb(QJsonDocument doc);
    void loadRestaurantFromDb(QJsonDocument doc);
    void loadMenuFromDb(QJsonDocument doc);
    void loadOrderFromDb(QJsonDocument doc);
    void loadDeliveryFromDb(QJsonDocument doc);
private:
    QTcpSocket socket;
private slots:
    void onReadyRead();
};

#endif // CLIENTNETWORK_H
