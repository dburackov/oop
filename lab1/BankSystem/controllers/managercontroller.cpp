#include "managercontroller.h"

ManagerController::ManagerController()
{
    bankSystem = BankSystem::getInstance();
}

void ManagerController::registrationConfirm(long long id)
{
    int counter = 0;
    for (auto user : bankSystem->registrationRequests) {
        if (user.id == id) {
            bankSystem->users.push_back(user);
            bankSystem->registrationRequests.erase(bankSystem->registrationRequests.begin() + counter);
            bankSystem->logs.push_back(Log(QString("confirm registration user(id: %1)").arg(
                                               QString::number(id))));
            break;
        }
        ++counter;
    }
}

void ManagerController::registrationReject(long long id)
{
    int counter = 0;
    for (auto user : bankSystem->registrationRequests) {
        if (user.id == id) {
            bankSystem->registrationRequests.erase(bankSystem->registrationRequests.begin() + counter);
            bankSystem->logs.push_back(Log(QString("reject registration user(id: %1)").arg(
                                               QString::number(id))));
            break;
        }
        ++counter;
    }
}

void ManagerController::creditConfirm(long long id)
{
    int counter = 0;
    for (auto credit : bankSystem->creditRequests) {
        if (credit.id == id) {
            bankSystem->credits.push_back(credit);

            for (int i = 0; i < bankSystem->bills.size(); ++i) {
                if (bankSystem->bills[i].owner == credit.owner) {
                    bankSystem->bills[i].finance += credit.finance;
                    break;
                }
            }

            bankSystem->credits.back().calc();
            bankSystem->creditRequests.erase(bankSystem->creditRequests.begin() + counter);
            bankSystem->logs.push_back(Log(QString("confirm credit(id: %1) of user(id: %2)").arg(
                                               id, credit.owner)));
            break;
        }
        ++counter;
    }
}

void ManagerController::creditReject(long long id)
{
    int counter = 0;
    for (auto credit : bankSystem->creditRequests) {
        if (credit.id == id) {
            bankSystem->creditRequests.erase(bankSystem->creditRequests.begin() + counter);
            bankSystem->logs.push_back(Log(QString("reject credit(id: %1) of user(id: %2)").arg(
                                               id, credit.owner)));
            break;
        }
        ++counter;
    }
}
