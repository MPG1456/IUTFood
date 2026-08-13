#include "order.h"

void order::setId(int id)
{
    this->id = id;
}
void order::setClientId(int id)
{
    this->client_id =id;
}
void order::setRestaurantId(int id)
{
    this->restaurant_id =id;
}
void order::setDeliveryId(int id)
{
    this->delivery_id = id;
}
void order::setStatus(QString status)
{
    this->status = status;
}
void order::setReachedTime(QString reached_time)
{
    this->reached_time = reached_time;
}
void order::setOrderTime(QString order_time)
{
    this->order_time = order_time;
}
