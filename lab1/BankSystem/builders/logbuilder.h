#ifndef LOGBUILDER_H
#define LOGBUILDER_H

#include "builder.h"
#include "entities/log.h"

class LogBuilder : public Builder<Log>
{
public:
    LogBuilder();

    void setData(int, int, int);
    void setTime(int, int);
    void setAction(QString);
};

#endif // LOGBUILDER_H
