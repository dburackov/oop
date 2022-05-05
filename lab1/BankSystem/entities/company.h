#ifndef COMPANY_H
#define COMPANY_H

#include <string>

#include "id.h"
#include "companytype.h"

class Company
{
public:
    Company();

    long long id;
    CompanyType type;
    std::string name;
    long long payerAccountNumber;
    long long bankIdentificationNumber;
    std::string adress;

private:

};

#endif // COMPANY_H
