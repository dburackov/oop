#ifndef BILLBUILDER_H
#define BILLBUILDER_H


#include "builder.h"
#include "entities/bill.h"

class BillBuilder : public Builder<Bill>
{
public:
    BillBuilder();

    void setId(long long);
    void setOwnew(long long);
    void setFinance(double);
    void setStatus(BillStatus);
};

#endif // BILLBUILDER_H
