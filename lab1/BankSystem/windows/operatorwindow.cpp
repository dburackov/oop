#include "operatorwindow.h"
#include "ui_operatorwindow.h"

OperatorWindow::OperatorWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OperatorWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("BankSyste: Operator");
    this->setFixedSize(1000, 650);


}

OperatorWindow::~OperatorWindow()
{
    delete ui;
}

