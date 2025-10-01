#ifndef ORDERED_FOODS_H
#define ORDERED_FOODS_H
#include <QObject>

class ordered_foods:public QObject
{
    Q_OBJECT
public:
    ordered_foods(QObject *parent = nullptr);
    // Q_INVOKABLE bool usernameExist(QString username);
    Q_INVOKABLE bool addOrderedFood(int order_id , int menu_id ,int quantity);
};

#endif // ORDERED_FOODS_H
