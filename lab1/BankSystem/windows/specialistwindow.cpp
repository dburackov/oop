#include "specialistwindow.h"
#include "ui_specialistwindow.h"

SpecialistWindow::SpecialistWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SpecialistWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("BankSystem: Specialist");
    this->setFixedSize(1000, 650);
}

SpecialistWindow::~SpecialistWindow()
{
    delete ui;
}

