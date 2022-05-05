#ifndef TRANSFER_H
#define TRANSFER_H

#include "id.h"

class Transfer
{
public:
    Transfer(long long, long long, double);

    long long senderId;
    long long receiverId;
    double transferAmount;

    void execute();
};

#endif // TRANSFER_H
