#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H

#include <vector>

#include "windows/loginwindow.h"
#include "windows/registrationwindow.h"
#include "entities/user.h"
#include "entities/company.h"
#include "entities/credit.h"
#include "entities/deposit.h"
#include "entities/log.h"
#include "entities/bill.h"

class BankSystem
{
public:
    ~BankSystem();
    BankSystem(BankSystem &) = delete;
    void operator=(const BankSystem &) = delete;
    static BankSystem *getInstance();

    User activeUser;
    std::vector<User> users;
    std::vector<Company> companies;
    std::vector<Credit> credits;
    std::vector<Deposit> deposits;
    std::vector<Bill> bills;
    std::vector<Log> logs;

    std::vector<User> registrationRequests;
    std::vector<Credit> creditRequests;

private:
    BankSystem();
};

#endif // BANKSYSTEM_H
