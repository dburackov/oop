#ifndef MANAGERCONTROLLER_H
#define MANAGERCONTROLLER_H

#include "banksystem.h"

class ManagerController
{
public:
    ManagerController();

    void registrationConfirm(long long);
    void registrationReject(long long);
    void creditConfirm(long long);
    void creditReject(long long);
    void salaryConfirm(long long);
    void salaryReject(long long);


private:
    BankSystem *bankSystem;
};

#endif // MANAGERCONTROLLER_H
