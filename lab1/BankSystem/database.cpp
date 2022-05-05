#include "database.h"
#include "parser.h"

#include <QDebug>
#include <QSqlError>

Database::Database()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./../db/BankSystem.db");
    db.open();

    query = QSqlQuery(db);
}


Database *Database::getInstance()
{
    static Database instance;
    return &instance;
}

void Database::load(BankSystem *bankSystem)
{
    Parser parser(&query);

    query.exec("SELECT * FROM users");
    while (query.next()) {
        bankSystem->users.push_back(parser.userQuery());
    }

    query.exec("SELECT * FROM logs");
    while (query.next()) {
        bankSystem->logs.push_back(parser.logQuery());
    }

    query.exec("SELECT * FROM regrequests");
    while (query.next()) {
        bankSystem->registrationRequests.push_back(parser.userQuery());
    }

    query.exec("SELECT * FROM bills");
    while (query.next()) {
        bankSystem->bills.push_back(parser.billQuery());
    }

    query.exec("SELECT * FROM deposits");
    while (query.next()) {
        bankSystem->deposits.push_back(parser.depositQuery());
    }

    query.exec("SELECT * FROM credits");
    while (query.next()) {
        bankSystem->credits.push_back(parser.creditQuery());
    }

    query.exec("SELECT * FROM creditsreq");
    while (query.next()) {
        bankSystem->creditRequests.push_back(parser.creditQuery());
    }
}


void Database::save(BankSystem *bankSystem)
{
    query.exec("DELETE FROM users");
    query.exec("DELETE FROM logs");
    query.exec("DELETE FROM regrequests");
    query.exec("DELETE FROM bills");
    query.exec("DELETE FROM deposits");
    query.exec("DELETE FROM credits");
    query.exec("DELETE FROM creditsreq");

    for (auto user : bankSystem->users) {
        query.prepare("INSERT INTO users VALUES (:id, :email, :password, :name, :phone, :passport, :role);");
        query.bindValue(":id", QString::number(user.id));
        query.bindValue(":email", user.email);
        query.bindValue(":password", user.password);
        query.bindValue(":name", user.name);
        query.bindValue(":phone", user.phoneNumber);
        query.bindValue(":passport", user.passportNumber);
        query.bindValue(":role", QString::number(user.role));
        query.exec();
    }

    for (auto log : bankSystem->logs) {
        query.prepare("INSERT INTO logs VALUES (:day, :month, :year, :hour, :minute, :action);");
        int day, year, month;
        log.date.getDate(&year, &month, &day);
        query.bindValue(":day", QString::number(day));
        query.bindValue(":month", QString::number(month));
        query.bindValue(":year", QString::number(year));
        query.bindValue(":hour", QString::number(log.time.hour()));
        query.bindValue(":minute", QString::number(log.time.minute()));
        query.bindValue(":action", log.action);
        query.exec();
    }

    for (auto user : bankSystem->registrationRequests) {
        query.prepare("INSERT INTO regrequests VALUES (:id, :email, :password, :name, :phone, :passport, :role);");
        query.bindValue(":id", QString::number(user.id));
        query.bindValue(":email", user.email);
        query.bindValue(":password", user.password);
        query.bindValue(":name", user.name);
        query.bindValue(":phone", user.phoneNumber);
        query.bindValue(":passport", user.passportNumber);
        query.bindValue(":role", QString::number(user.role));
        query.exec();
    }

    for (auto bill : bankSystem->bills) {
        query.prepare("INSERT INTO bills VALUES (:id, :owner, :finance, :status);");
        query.bindValue(":id", QString::number(bill.id));
        query.bindValue(":owner", QString::number(bill.owner));
        query.bindValue(":finance", QString::number(bill.finance));
        query.bindValue(":status", QString::number(bill.status));
        query.exec();
    }

    for (auto deposit : bankSystem->deposits) {
        query.prepare("INSERT INTO deposits VALUES (:id, :owner, :finance, :stake, :term, :start, :active);");
        query.bindValue(":id", QString::number(deposit.id));
        query.bindValue(":owner", QString::number(deposit.owner));
        query.bindValue(":finance", QString::number(deposit.finance));
        query.bindValue(":stake", QString::number(deposit.stake));
        query.bindValue(":term", QString::number(deposit.term));
        query.bindValue(":start", QString::number(deposit.startTime));
        query.bindValue(":active", QString::number(deposit.active));
        query.exec();
    }

    for (auto credit : bankSystem->credits) {
        query.prepare("INSERT INTO credits VALUES (:id, :owner, :finance, :stake, :term);");
        query.bindValue(":id", QString::number(credit.id));
        query.bindValue(":owner", QString::number(credit.owner));
        query.bindValue(":finance", QString::number(credit.finance));
        query.bindValue(":stake", QString::number(credit.stake));
        query.bindValue(":term", QString::number(credit.term));
        query.exec();
    }

    for (auto credit : bankSystem->creditRequests) {
        query.prepare("INSERT INTO creditsreq VALUES (:id, :owner, :finance, :stake, :term);");
        query.bindValue(":id", QString::number(credit.id));
        query.bindValue(":owner", QString::number(credit.owner));
        query.bindValue(":finance", QString::number(credit.finance));
        query.bindValue(":stake", QString::number(credit.stake));
        query.bindValue(":term", QString::number(credit.term));
        query.exec();
    }
}

const QSqlDatabase &Database::getdb() const &
{
    return db;
}
