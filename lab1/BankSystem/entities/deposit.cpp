#include "deposit.h"

Deposit::Deposit()
{
    startTime = QTime::currentTime().minute() * 60 + QTime::currentTime().second();
    active = true;
}

void Deposit::update() {
    int now = QTime::currentTime().minute() * 60 + QTime::currentTime().second();
    if (startTime + term * 2 <= now && active) {
        finance += (finance * stake * term * 30 / 365) / 100;
        active = false;
    }
}
