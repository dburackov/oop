#include "logbuilder.h"

LogBuilder::LogBuilder()
{

}

void LogBuilder::setData(int day, int month, int year)
{
    product->date.setDate(year, month, day);
}

void LogBuilder::setTime(int hour, int minute)
{
    product->time.setHMS(hour, minute, 0);
}

void LogBuilder::setAction(QString value) {
    product->action = value;
}
