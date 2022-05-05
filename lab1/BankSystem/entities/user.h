#ifndef USER_H
#define USER_H

#include "userrole.h"
#include "entities/credit.h"
#include "entities/deposit.h"

#include <QString>
#include <vector>

class User
{
public:
    User();

    long long id;
    QString email;
    QString password;
    QString name;
    QString phoneNumber;
    QString passportNumber;
    UserRole role;

private:


};

#endif // USER_H
