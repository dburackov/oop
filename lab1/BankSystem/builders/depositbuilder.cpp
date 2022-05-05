#include "depositbuilder.h"

DepositBuilder::DepositBuilder()
{

}

void DepositBuilder::setId(long long value)
{
    product->id = value;
}


void DepositBuilder::setOwner(long long value)
{
    product->owner = value;
}


void DepositBuilder::setFinance(double value)
{
    product->finance = value;
}


void DepositBuilder::setStake(double value)
{
    product->stake = value;
}


void DepositBuilder::setTerm(int value)
{
    product->term = value;
}


void DepositBuilder::setStartTime(int value)
{
    product->startTime = value;
}

void DepositBuilder::setActive(bool value)
{
    product->active = value;
}
