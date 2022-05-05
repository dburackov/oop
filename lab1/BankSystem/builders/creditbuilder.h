#ifndef CREDITBUILDER_H
#define CREDITBUILDER_H


#include "builder.h"
#include "entities/credit.h"

class CreditBuilder : public Builder<Credit>
{
public:
    CreditBuilder();

    void setId(long long);
    void setOwner(long long);
    void setFinance(double);
    void setStake(double);
    void setTerm(int);

};

#endif // CREDITBUILDER_H
