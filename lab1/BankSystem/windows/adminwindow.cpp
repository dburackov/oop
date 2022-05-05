#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "database.h"
#include "banksystem.h"

AdminWindow::AdminWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);

    this->setFixedSize(1000, 650);
    this->setWindowTitle("BankSystem: Admin");

    model = new QSqlTableModel(this, Database::getInstance()->getdb());
    model->setTable("logs");
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();

    refresh();
}

AdminWindow::~AdminWindow()
{
    delete ui;
    delete model;
}

void AdminWindow::refresh()
{
    Database::getInstance()->save(BankSystem::getInstance());
    model->select();
    ui->tableView->resizeColumnsToContents();
}


