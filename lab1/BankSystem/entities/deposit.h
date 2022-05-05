#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QTime>

class Deposit
{
public:
    Deposit();

    void update();

    long long id;
    long long owner;
    double finance;
    double stake;
    int term;
    int startTime;
    bool active;
};

#endif // DEPOSIT_H
