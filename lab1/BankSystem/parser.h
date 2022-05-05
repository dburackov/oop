#ifndef PARSER_H
#define PARSER_H

#include "entities/user.h"
#include "entities/log.h"
#include "entities/bill.h"
#include "entities/deposit.h"
#include "entities/credit.h"

#include <QSqlQuery>

class Parser
{
public:
    Parser(QSqlQuery *q);

    User userQuery();
    Log logQuery();
    Bill billQuery();
    Deposit depositQuery();
    Credit creditQuery();

private:
    QSqlQuery *query;
};

#endif // PARSER_H
