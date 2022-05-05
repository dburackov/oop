#ifndef DEPOSITBUILDER_H
#define DEPOSITBUILDER_H


#include "builder.h"
#include "entities/deposit.h"

class DepositBuilder : public Builder<Deposit>
{
public:
    DepositBuilder();

    void setId(long long);
    void setOwner(long long);
    void setFinance(double);
    void setStake(double);
    void setTerm(int);
    void setStartTime(int);
    void setActive(bool);
};

#endif // DEPOSITBUILDER_H
