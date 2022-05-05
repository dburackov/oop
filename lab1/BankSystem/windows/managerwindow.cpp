#include "managerwindow.h"
#include "ui_managerwindow.h"
#include "database.h"

ManagerWindow::ManagerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManagerWindow)
{
    ui->setupUi(this);

    this->setFixedSize(1000, 650);
    this->setWindowTitle("BankSystem: Manager");

    controller = new ManagerController();

    regModel = new QSqlTableModel(this, Database::getInstance()->getdb());
    regModel->setTable("regrequests");
    regModel->select();

    creditsModel = new QSqlTableModel(this, Database::getInstance()->getdb());
    creditsModel->setTable("creditsreq");
    creditsModel->select();

    salaryModel = new QSqlTableModel(this, Database::getInstance()->getdb());
    //creditsModel->setTable("");
    //creditsModel->select();

    ui->registTable->setModel(regModel);
    ui->registTable->hideColumn(0);
    ui->registTable->hideColumn(2);
    ui->registTable->hideColumn(6);
    ui->registTable->resizeColumnsToContents();
    ui->registTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->creditsTable->setModel(creditsModel);
    ui->creditsTable->resizeColumnsToContents();
    ui->creditsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    regModel->select();
    ui->registTable->resizeColumnsToContents();

    creditsModel->select();
    ui->creditsTable->resizeColumnsToContents();
}

ManagerWindow::~ManagerWindow()
{
    delete ui;
    delete regModel;
    delete creditsModel;
    delete salaryModel;
    delete controller;
}


void ManagerWindow::on_regConfirmButton_clicked()
{
    QModelIndex curr(ui->registTable->currentIndex());
    controller->registrationConfirm(regModel->data(curr.sibling(curr.row(), 0)).toLongLong());
    regModel->removeRow(curr.row());
    regModel->select();
}


void ManagerWindow::on_regRejectButton_clicked()
{
    QModelIndex curr(ui->registTable->currentIndex());
    controller->registrationReject(regModel->data(curr.sibling(curr.row(), 0)).toLongLong());
    regModel->removeRow(curr.row());
    regModel->select();
}



void ManagerWindow::on_creditConfirmButton_clicked()
{
    QModelIndex curr(ui->creditsTable->currentIndex());
    controller->creditConfirm(creditsModel->data(curr.sibling(curr.row(), 0)).toLongLong());
    creditsModel->removeRow(curr.row());
    creditsModel->select();
}


void ManagerWindow::on_creditRefectButton_clicked()
{
    QModelIndex curr(ui->creditsTable->currentIndex());
    controller->creditReject(creditsModel->data(curr.sibling(curr.row(), 0)).toLongLong());
    creditsModel->removeRow(curr.row());
    creditsModel->select();
}

