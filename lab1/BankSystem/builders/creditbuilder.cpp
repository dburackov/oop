#include "creditbuilder.h"

CreditBuilder::CreditBuilder()
{

}

void CreditBuilder::setId(long long value)
{
    product->id = value;
}


void CreditBuilder::setOwner(long long value)
{
    product->owner = value;
}


void CreditBuilder::setFinance(double value)
{
    product->finance = value;
}


void CreditBuilder::setStake(double value)
{
    product->stake = value;
}


void CreditBuilder::setTerm(int value)
{
    product->term = value;
}
