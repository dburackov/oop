#include "clientwindow.h"
#include "ui_clientwindow.h"

#include "banksystem.h"

ClientWindow::ClientWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientWindow)
{
    ui->setupUi(this);

    this->setFixedSize(1000, 650);
    this->setWindowTitle("BankSystem: Client");

    controller = new ClientController();


    refreshBills();
    refreshDeposits();
    refreshCredits();
}

ClientWindow::~ClientWindow()
{
    delete ui;
}


void ClientWindow::refreshBills()
{
    BankSystem *bankSystem = BankSystem::getInstance();

    std::vector<Bill> bills;
    for (auto bill : bankSystem->bills) {
        if (bill.owner == bankSystem->activeUser.id) {
            bills.push_back(bill);
        }
    }

    ui->billsTable->setRowCount(bills.size());
    ui->billsTable->setColumnCount(3);
    ui->billsTable->setHorizontalHeaderLabels(QStringList() << "ID" << "Finance" << "Status");
    ui->billsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    for (int i = 0; i < ui->billsTable->rowCount(); ++i) {
        QTableWidgetItem *item0 = new QTableWidgetItem(QString("%1").arg(bills[i].id));
        ui->billsTable->setItem(i, 0, item0);

        QTableWidgetItem *item1 = new QTableWidgetItem(QString("%1").arg(bills[i].finance));
        ui->billsTable->setItem(i, 1, item1);

        QString status = "Active";
        if (bills[i].status == Frozen) {
            status = "Frozen";
        } else if (bills[i].status == Blocked) {
            status = "Blocked";
        }
        QTableWidgetItem *item2 = new QTableWidgetItem(QString("%1").arg(status));
        ui->billsTable->setItem(i, 2, item2);
    }
}


void ClientWindow::refreshDeposits() {
    BankSystem *bankSystem = BankSystem::getInstance();

    for (int i = 0; i < bankSystem->deposits.size(); ++i) {
        bankSystem->deposits[i].update();
    }

    std::vector<Deposit> deposits;
    for (auto deposit : bankSystem->deposits) {
        if (deposit.owner == bankSystem->activeUser.id) {
            deposits.push_back(deposit);
        }
    }

    ui->depositsTable->setRowCount(deposits.size());
    ui->depositsTable->setColumnCount(5);
    ui->depositsTable->setHorizontalHeaderLabels(QStringList() << "ID" << "Finance" << "Stake" << "Term" << "Status");
    ui->depositsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    for (int i = 0; i < ui->depositsTable->rowCount(); ++i) {
        QTableWidgetItem *item0 = new QTableWidgetItem(QString("%1").arg(deposits[i].id));
        ui->depositsTable->setItem(i, 0, item0);

        QTableWidgetItem *item1 = new QTableWidgetItem(QString("%1").arg(deposits[i].finance));
        ui->depositsTable->setItem(i, 1, item1);

        QTableWidgetItem *item2 = new QTableWidgetItem(QString("%1").arg(deposits[i].stake));
        ui->depositsTable->setItem(i, 2, item2);

        QTableWidgetItem *item3 = new QTableWidgetItem(QString("%1").arg(deposits[i].term));
        ui->depositsTable->setItem(i, 3, item3);

        QString status = "Active";
        if (!deposits[i].active) {
            status = "Done";
        }
        QTableWidgetItem *item4 = new QTableWidgetItem(QString("%1").arg(status));
        ui->depositsTable->setItem(i, 4, item4);
    }
}

void ClientWindow::refreshCredits()
{
    BankSystem *bankSystem = BankSystem::getInstance();

    std::vector<Credit> credits;
    for (auto credit : bankSystem->credits) {
        if (credit.owner == bankSystem->activeUser.id) {
            credits.push_back(credit);
        }
    }

    ui->creditsTable->setRowCount(credits.size());
    ui->creditsTable->setColumnCount(2);
    ui->creditsTable->setHorizontalHeaderLabels(QStringList() << "ID" << "Need to pay");
    ui->creditsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    for (int i = 0; i < ui->creditsTable->rowCount(); ++i) {
        QTableWidgetItem *item0 = new QTableWidgetItem(QString("%1").arg(credits[i].id));
        ui->creditsTable->setItem(i, 0, item0);

        QTableWidgetItem *item1 = new QTableWidgetItem(QString("%1").arg(credits[i].finance));
        ui->creditsTable->setItem(i, 1, item1);
    }
}


void ClientWindow::on_createBillButton_clicked()
{
    controller->createBill(ui->createBillLineEdit->text().toDouble());
    refreshBills();
}


void ClientWindow::on_topupButton_clicked()
{
    controller->topup(ui->billEditLine->text().toLongLong(), ui->topupLineEdit->text().toDouble());
    refreshBills();
}


void ClientWindow::on_withdrawButton_clicked()
{
    controller->withdraw(ui->billEditLine->text().toLongLong(), ui->withdrawLineEdit->text().toDouble());
    refreshBills();
}


void ClientWindow::on_transferButton_clicked()
{
    controller->transfer(ui->billEditLine->text().toLongLong(), ui->transferToEditLine->text().toLongLong(),
                         ui->transferAmount->text().toLongLong());
    refreshBills();
}


void ClientWindow::on_blockButton_clicked()
{
    controller->block(ui->billEditLine->text().toLongLong());
    refreshBills();
}


void ClientWindow::on_unblockButton_clicked()
{
    controller->unblock(ui->billEditLine->text().toLongLong());
    refreshBills();
}


void ClientWindow::on_pushButton_11_clicked()
{
    controller->freeze(ui->billEditLine->text().toLongLong());
    refreshBills();
}


void ClientWindow::on_pushButton_12_clicked()
{
    controller->unfreeze(ui->billEditLine->text().toLongLong());
    refreshBills();
}


void ClientWindow::on_depositsRefresh_clicked()
{
    refreshDeposits();
}


void ClientWindow::on_CreateDepositButton_clicked()
{
    int term = 0;
    if (ui->deposit3->isChecked()) {
        term = 3;
    }
    if (ui->deposit6->isChecked()) {
        term = 6;
    }
    if (ui->deposit12->isChecked()) {
        term = 12;
    }
    if (ui->deposit24->isChecked()) {
        term = 24;
    }
    if (ui->depositOther->isChecked() && !ui->depositOtherLineEdit->text().isEmpty()) {
        term = ui->depositOtherLineEdit->text().toInt();
    }
    if (term > 0) {
        controller->createDeposit(ui->depositAmount->text().toDouble(),
                                  ui->depositStake->text().toDouble(), term);
    }
    refreshDeposits();
}


void ClientWindow::on_withdrawDepositButton_clicked()
{
    controller->withdrawDeposit(ui->withdrawDepositLineEdit->text().toLongLong(),
                                ui->withdrawBillLineEdit->text().toLongLong());
    refreshDeposits();
    refreshBills();
}


void ClientWindow::on_createCreditButton_clicked()
{
    int term = 0;
    if (ui->credit3->isChecked()) {
        term = 3;
    }
    if (ui->credit6->isChecked()) {
        term = 6;
    }
    if (ui->credit12->isChecked()) {
        term = 12;
    }
    if (ui->credit24->isChecked()) {
        term = 24;
    }
    if (ui->creditOther->isChecked() && !ui->creditOtherLineEdit->text().isEmpty()) {
        term = ui->creditOtherLineEdit->text().toInt();
    }
    if (term > 0) {
        controller->createCredit(ui->creditAmount->text().toDouble(),
                                 ui->creditStake->text().toDouble(), term);
    }
}


void ClientWindow::on_creditPaymentButton_clicked()
{
    controller->paymentCredit(ui->creditId->text().toLongLong(),
                              ui->creditBill->text().toLongLong(),
                              ui->creditAmountPay->text().toDouble());
    refreshCredits();
    refreshBills();
}

