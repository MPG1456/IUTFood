#ifndef ORDEREDFOOD_H
#define ORDEREDFOOD_H

#include <QObject>
#include <order.h>

class orderedFood:public order
{
    Q_OBJECT
private:
    int id;
    int order_id;
    int menu_id;
    int quantity;
public:
    orderedFood() =default;
    void setId(int id);
    void setOrderId(int order_id);
    void setMenuId(int menuId);
    void setQuantity(int quantity);
};

#endif // ORDEREDFOOD_H
