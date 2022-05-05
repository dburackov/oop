#include "billbuilder.h"


BillBuilder::BillBuilder()
{

}

void BillBuilder::setId(long long value)
{
    product->id = value;
}

void BillBuilder::setOwnew(long long value)
{
    product->owner = value;
}

void BillBuilder::setFinance(double value)
{
    product->finance = value;
}

void BillBuilder::setStatus(BillStatus value)
{
    product->status = value;
}
