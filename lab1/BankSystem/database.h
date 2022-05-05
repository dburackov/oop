#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include "banksystem.h"

class Database
{
public:
    Database(Database &) = delete;
    void operator=(const Database &) = delete;
    static Database *getInstance();


    void load(BankSystem *bankSystem);
    void save(BankSystem *bankSystem);

    const QSqlDatabase &getdb() const &;
    QSqlDatabase &getdb() && = delete;

private:
    Database();
    QSqlDatabase db;
    QSqlQuery query;
};

#endif // DATABASE_H
