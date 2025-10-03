#ifndef ORDER_H
#define ORDER_H

#include <QObject>

class order :public QObject
{
    Q_OBJECT
public:
    order()=default;
    void setId(int id);
private:
    int id;

};

#endif // ORDER_H
