#include "parser.h"

#include "builders/userbuilder.h"
#include "builders/logbuilder.h"
#include "entities/id.h"
#include "entities/userrole.h"
#include "builders/billbuilder.h"
#include "builders/depositbuilder.h"
#include "builders/creditbuilder.h"

Parser::Parser(QSqlQuery *q)
{
    query = q;
}

User Parser::userQuery()
{
    UserBuilder builder;
    builder.setId(query->value(0).toLongLong());
    Id::setId(query->value(0).toLongLong());
    builder.setEmail(query->value(1).toString());
    builder.setPassword(query->value(2).toString());
    builder.setName(query->value(3).toString());
    builder.setPhoneNumber(query->value(4).toString());
    builder.setPassportNumber(query->value(5).toString());
    builder.setRole(UserRole(query->value(6).toInt()));
    return *builder.getResult();
}

Log Parser::logQuery()
{
    LogBuilder builder;
    builder.setData(query->value(0).toInt(), query->value(1).toInt(), query->value(2).toInt());
    builder.setTime(query->value(3).toInt(), query->value(4).toInt());
    builder.setAction(query->value(5).toString());
    return *builder.getResult();
}

Bill Parser::billQuery()
{
    BillBuilder builder;
    builder.setId(query->value(0).toLongLong());
    Id::setId(query->value(0).toLongLong());
    builder.setOwnew(query->value(1).toLongLong());
    builder.setFinance(query->value(2).toDouble());
    builder.setStatus(BillStatus(query->value(3).toInt()));
    return *builder.getResult();
}

Deposit Parser::depositQuery()
{
    DepositBuilder builder;
    builder.setId(query->value(0).toLongLong());
    Id::setId(query->value(0).toLongLong());
    builder.setOwner(query->value(1).toLongLong());
    builder.setFinance(query->value(2).toDouble());
    builder.setStake(query->value(3).toDouble());
    builder.setTerm(query->value(4).toInt());
    builder.setStartTime(query->value(5).toInt());
    builder.setActive(query->value(6).toBool());
    return *builder.getResult();
}

Credit Parser::creditQuery()
{
    CreditBuilder builder;
    builder.setId(query->value(0).toLongLong());
    Id::setId(query->value(0).toLongLong());
    builder.setOwner(query->value(1).toLongLong());
    builder.setFinance(query->value(2).toDouble());
    builder.setStake(query->value(3).toDouble());
    builder.setTerm(query->value(4).toInt());
    return *builder.getResult();
}
