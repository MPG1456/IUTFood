#include "mytime.h"

MyTime::MyTime()
{
    QTimeZone myZone("Asia/Tehran");
    QDateTime current = QDateTime::currentDateTime(myZone);
    myTime = current.toString("yyyy-MM-dd hh:mm::ss");
}

MyTime::MyTime(const MyTime &newTime)
{
    this->myTime = newTime.myTime;
}

QString MyTime::getTime()
{
    return myTime;
}

void MyTime::setTime(QString newTime)
{
    myTime = newTime;
}
