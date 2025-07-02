#include "mytime.h"

MyTime::MyTime()
{
    QTimeZone myZone("Asia/Tehran");
    QDateTime current = QDateTime::currentDateTime(myZone);
    myTime = current.toString();
}

QString MyTime::getTime()
{
    return myTime;
}

void MyTime::setTime(QString newTime)
{
    myTime = newTime;
}
