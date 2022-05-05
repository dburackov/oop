#include "log.h"

Log::Log()
{

}

Log::Log(QString str)
{
    action = str;
    date = QDate::currentDate();
    time = QTime::currentTime();
}
