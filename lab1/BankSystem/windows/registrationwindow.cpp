#include "registrationwindow.h"
#include "ui_registrationwindow.h"

#include "builders/userbuilder.h"
#include "banksystem.h"

RegistrationWindow::RegistrationWindow(QWidget *parent) : QDialog(parent), ui(new Ui::RegistrationWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("BankSystem: Registration");
}

RegistrationWindow::~RegistrationWindow()
{
    delete ui;
}


void RegistrationWindow::on_signInPushButton_clicked()
{
    this->hide();
    emit showLoginWindow();
}

void RegistrationWindow::on_signUpPushBotton_clicked()
{
    BankSystem *bankSystem = BankSystem::getInstance();

    if (ui->email->text().isEmpty()
        || ui->password->text().isEmpty()
        || ui->name->text().isEmpty()
        || ui->passport->text().isEmpty()
        || ui->phone->text().isEmpty())
    {
        ui->errorMessage->setText("All fields must be filled.");
    } else {
        UserBuilder builder;
        builder.setId(Id::getNewId());
        builder.setEmail(ui->email->text());
        builder.setPassword(ui->password->text());
        builder.setName(ui->name->text());
        builder.setPhoneNumber(ui->phone->text());
        builder.setPassportNumber(ui->passport->text());

        bankSystem->registrationRequests.push_back(*builder.getResult());

        bankSystem->logs.push_back(Log(QString("new user \"%1\" registrated in the system").arg(ui->name->text())));

        this->hide();
        emit showLoginWindow();
    }
}

