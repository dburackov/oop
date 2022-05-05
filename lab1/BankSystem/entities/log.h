#ifndef LOG_H
#define LOG_H

#include <QString>
#include <QDate>
#include <QTime>

class Log
{
public:
    Log();
    Log(QString);

    QString action;
    QDate date;
    QTime time;
};

#endif // LOG_H
