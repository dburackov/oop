#ifndef CLIENTCONTROLLER_H
#define CLIENTCONTROLLER_H


#include "banksystem.h"

class ClientController
{
public:
    ClientController();

    void createBill(double value);
    void topup(long long id, double value);
    void withdraw(long long id, double value);
    void transfer(long long sender, long long receiver, double amount);
    void block(long long id);
    void unblock(long long id);
    void freeze(long long id);
    void unfreeze(long long id);

    void createDeposit(double finance, double stake, int term);
    void withdrawDeposit(long long id, long long bill);

    void createCredit(double finance, double stake, int term);
    void paymentCredit(long long id, long long bill, double amount);

private:
    BankSystem *bankSystem;
};

#endif // CLIENTCONTROLLER_H
