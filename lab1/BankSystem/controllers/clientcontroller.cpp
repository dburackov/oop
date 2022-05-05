#include "clientcontroller.h"
#include "builders/billbuilder.h"
#include "builders/depositbuilder.h"
#include "builders/creditbuilder.h"
#include "entities/log.h"
#include "entities/transfer.h"

ClientController::ClientController()
{
    bankSystem = BankSystem::getInstance();
}


void ClientController::createBill(double value)
{
    BillBuilder builder;
    builder.setId(Id::getNewId());
    builder.setOwnew(bankSystem->activeUser.id);
    builder.setFinance(value);
    bankSystem->bills.push_back(*builder.getResult());

    bankSystem->logs.push_back(Log(QString("user(id:%1) create bill").arg(bankSystem->activeUser.id)));
}


void ClientController::topup(long long id, double value)
{
    int counter = 0;
    for (auto bill : bankSystem->bills) {
        if (bill.id == id) {
            if (bill.status == Active) {
                bankSystem->bills[counter].finance += value;
                bankSystem->logs.push_back(Log(QString("top up(sum: %1) to bill(id: %2)").arg(
                                                   QString::number(value), QString::number(id))));
            }
            break;
        }
        ++counter;
    }
}


void ClientController::withdraw(long long id, double value)
{
    int counter = 0;
    for (auto bill : bankSystem->bills) {
        if (bill.id == id) {
            if (bill.status == Active) {
                bankSystem->bills[counter].finance -= value;
                bankSystem->logs.push_back(Log(QString("withdraw(sum: %1) from bill(id: %2)").arg(
                                                   QString::number(value), QString::number(id))));
            }
            break;
        }
        ++counter;
    }
}


void ClientController::transfer(long long sender, long long receiver, double amount)
{
    Transfer transfer(sender, receiver, amount);
    transfer.execute();
}


void ClientController::block(long long id)
{
    int counter = 0;
    for (auto bill : bankSystem->bills) {
        if (bill.id == id) {
            bankSystem->bills[counter].status = Blocked;
            bankSystem->logs.push_back(Log(QString("bill(id: %1) has been blocked").arg(
                                               QString::number(id))));
            break;
        }
        ++counter;
    }
}


void ClientController::unblock(long long id)
{
    int counter = 0;
    for (auto bill : bankSystem->bills) {
        if (bill.id == id) {
            bankSystem->bills[counter].status = Active;
            bankSystem->logs.push_back(Log(QString("bill(id: %1) has been unblocked").arg(
                                               QString::number(id))));
            break;
        }
        ++counter;
    }
}


void ClientController::freeze(long long id)
{
    int counter = 0;
    for (auto bill : bankSystem->bills) {
        if (bill.id == id) {
            bankSystem->bills[counter].status = Frozen;
            bankSystem->logs.push_back(Log(QString("bill(id: %1) has been frozen").arg(
                                               QString::number(id))));
            break;
        }
        ++counter;
    }
}

void ClientController::unfreeze(long long id)
{
    int counter = 0;
    for (auto bill : bankSystem->bills) {
        if (bill.id == id) {
            bankSystem->bills[counter].status = Active;
            bankSystem->logs.push_back(Log(QString("bill(id: %1) has been unfrozen").arg(
                                               QString::number(id))));
            break;
        }
        ++counter;
    }
}

void ClientController::createDeposit(double finance, double stake, int term)
{
    DepositBuilder builder;
    builder.setId(Id::getNewId());
    builder.setOwner(bankSystem->activeUser.id);
    builder.setFinance(finance);
    builder.setStake(stake);
    builder.setTerm(term);
    bankSystem->deposits.push_back(*builder.getResult());

    bankSystem->logs.push_back(Log(QString("user(id: %1) create deposit with(sum: %2)").arg(
                                       bankSystem->activeUser.id, finance)));
}

void ClientController::withdrawDeposit(long long id, long long bill)
{
    double finance = 0;
    for (int i = 0; i < bankSystem->deposits.size(); ++i) {
        if (bankSystem->deposits[i].id == id) {
            if (!bankSystem->deposits[i].active) {
                finance = bankSystem->deposits[i].finance;
                bankSystem->deposits.erase(bankSystem->deposits.begin() + i);
            }
            break;
        }
    }
    for (int i = 0; i < bankSystem->bills.size(); ++i) {
        if (bankSystem->bills[i].id == bill) {
            bankSystem->bills[i].finance += finance;
            break;
        }
    }
}

void ClientController::createCredit(double finance, double stake, int term)
{
    CreditBuilder builder;
    builder.setId(Id::getNewId());
    builder.setOwner(bankSystem->activeUser.id);
    builder.setFinance(finance);
    builder.setStake(stake);
    builder.setTerm(term);
    bankSystem->creditRequests.push_back(*builder.getResult());

    bankSystem->logs.push_back(Log(QString("user(id: %1) create credit request with(sum: %2)").arg(
                                       bankSystem->activeUser.id, finance)));
}

void ClientController::paymentCredit(long long id, long long bill, double amount)
{
    for (int i = 0; i < bankSystem->bills.size(); ++i) {
        if (bankSystem->bills[i].id == bill) {
            if (bankSystem->bills[i].finance < amount) {
                return;
            }
            bankSystem->bills[i].finance -= amount;
            break;
        }
    }
    for (int i = 0; i < bankSystem->credits.size(); ++i) {
        if (bankSystem->credits[i].id == id) {
            bankSystem->credits[i].finance -= amount;
            if (bankSystem->credits[i].finance <= 0) {
                bankSystem->credits.erase(bankSystem->credits.begin() + i);
            }
            break;
        }
    }
}
