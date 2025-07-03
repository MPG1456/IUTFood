#ifndef MYTIME_H
#define MYTIME_H

#include <QDateTime>
#include <QTimeZone>

class MyTime
{
    friend QDataStream &operator<<(QDataStream &out, const MyTime &time);
    friend QDataStream &operator>>(QDataStream &in, MyTime &time);

private:
    QString myTime;
public:
    MyTime();
    MyTime(const MyTime &copyTime);
    QString getTime();
    void setTime(QString newTime);
};

#endif // MYTIME_H
