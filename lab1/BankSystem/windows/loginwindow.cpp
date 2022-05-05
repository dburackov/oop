#include "loginwindow.h"
#include "ui_loginwindow.h"

#include "clientwindow.h"
#include "operatorwindow.h"
#include "managerwindow.h"
#include "specialistwindow.h"
#include "adminwindow.h"
#include "banksystem.h"
#include "entities/log.h"

#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>

LoginWindow::LoginWindow(QWidget *parent) : QDialog(parent), ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("BankSystem: Login");
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_signInPushButton_clicked()
{
    BankSystem * bankSystem = BankSystem::getInstance();

    for (auto user : bankSystem->users) {
        if (user.email == ui->emailLineEdit->text() && user.password == ui->passwordLineEdit->text()) {
            hide();
            bankSystem->logs.push_back(Log(QString("user(id:%1) has been login").arg(user.id)));
            bankSystem->activeUser = user;
            if (user.role == Client) {
                ClientWindow w;
                w.exec();
            } else if (user.role == Operator) {
                OperatorWindow w;
                w.exec();
            } else if (user.role == Manager) {
                ManagerWindow w;
                w.exec();
            } else if (user.role == Specialist) {
                SpecialistWindow w;
                w.exec();
            } else if (user.role == Admin) {
                AdminWindow w;
                w.exec();
            }
            return;
        }
    }
    ui->errorMessage->setText("Wrong email or password.");
}


void LoginWindow::on_createAccountPushButton_clicked()
{
    hide();
    emit showRegistrationWindow();
}

