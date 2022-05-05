#ifndef BILL_H
#define BILL_H

#include "billstatus.h"

class Bill
{
public:
    Bill();

    long long id;
    long long owner;
    double finance;
    BillStatus status;
};

#endif // BILL_H
