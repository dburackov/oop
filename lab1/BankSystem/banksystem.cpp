#include "banksystem.h"
#include "database.h"

BankSystem::BankSystem()
{
    Database::getInstance()->load(this);
}

BankSystem::~BankSystem()
{

}

BankSystem *BankSystem::getInstance()
{
    static BankSystem *instance = new BankSystem();
    return instance;
}
