#ifndef ORDER_H
#define ORDER_H

#include <QObject>

class order :public QObject
{
    Q_OBJECT
public:
    order()=default;
    void setId(int id);
    void setClientId(int id);
    void setRestaurantId(int id);
    void setDeliveryId(int id);
    void setStatus(QString status);
    void setReachedTime(QString reached_time);
    void setOrderTime(QString order_time);
private:
    int id;
    int client_id;
    int restaurant_id;
    int delivery_id;
    QString status;
    QString reached_time;
    QString order_time;

};

#endif // ORDER_H
