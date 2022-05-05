#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QDialog>

#include "controllers/clientcontroller.h"

namespace Ui {
class ClientWindow;
}

class ClientWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ClientWindow(QWidget *parent = nullptr);
    ~ClientWindow();

private slots:
    void on_createBillButton_clicked();

    void on_topupButton_clicked();

    void on_withdrawButton_clicked();

    void on_transferButton_clicked();

    void on_blockButton_clicked();

    void on_unblockButton_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_depositsRefresh_clicked();

    void on_CreateDepositButton_clicked();

    void on_withdrawDepositButton_clicked();

    void on_createCreditButton_clicked();

    void on_creditPaymentButton_clicked();

private:
    void refreshBills();
    void refreshDeposits();
    void refreshCredits();

private:
    Ui::ClientWindow *ui;
    ClientController *controller;

};

#endif // CLIENTWINDOW_H
