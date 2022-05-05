#ifndef USERBUILDER_H
#define USERBUILDER_H

#include "entities/user.h"
#include "builder.h"

class UserBuilder : public Builder<User>
{
public:
    UserBuilder();

    void setId(long long);
    void setName(QString);
    void setEmail(QString);
    void setPassword(QString);
    void setPhoneNumber(QString);
    void setPassportNumber(QString);
    void setRole(UserRole);

private:

};

#endif // USERBUILDER_H
