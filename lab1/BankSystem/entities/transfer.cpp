#include "transfer.h"
#include "banksystem.h"

Transfer::Transfer(long long sender, long long receiver, double amount)
{
    senderId = sender;
    receiverId = receiver;
    transferAmount = amount;
}

void Transfer::execute()
{
    BankSystem *bankSystem = BankSystem::getInstance();

    int senderIndex = 0;
    for (auto senderBill : bankSystem->bills) {
        if (senderBill.id == senderId) {
            int receiverIndex = 0;
            for (auto receiverBill : bankSystem->bills) {
                if (receiverBill.id == receiverId) {
                    if (senderBill.status == Active && receiverBill.status == Active
                            && senderBill.finance >= transferAmount)
                    {
                        bankSystem->bills[senderIndex].finance -= transferAmount;
                        bankSystem->bills[receiverIndex].finance += transferAmount;
                        bankSystem->logs.push_back(Log(QString("transfer(sum: %1) from (id: %2) to (id: %3)").arg(
                                                           QString::number(transferAmount), QString::number(senderId), QString::number(receiverId))));
                    }
                    break;
                }
                ++receiverIndex;
            }
            break;
        }
        ++senderIndex;
    }

}
