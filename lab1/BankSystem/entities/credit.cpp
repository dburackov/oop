#include "credit.h"

Credit::Credit()
{

}

void Credit::calc()
{
    finance += (finance * stake * term * 30 / 365) / 100;
}
