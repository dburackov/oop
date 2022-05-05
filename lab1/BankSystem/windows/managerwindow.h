#ifndef MANAGERWINDOW_H
#define MANAGERWINDOW_H

#include <QDialog>
#include <QSqlTableModel>

#include "controllers/managercontroller.h"

namespace Ui {
class ManagerWindow;
}

class ManagerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ManagerWindow(QWidget *parent = nullptr);
    ~ManagerWindow();

private:
    void refresh();

private slots:

    void on_regConfirmButton_clicked();

    void on_regRejectButton_clicked();

    void on_creditConfirmButton_clicked();

    void on_creditRefectButton_clicked();

private:
    Ui::ManagerWindow *ui;
    ManagerController *controller;
    QSqlTableModel *regModel;
    QSqlTableModel *creditsModel;
    QSqlTableModel *salaryModel;
};

#endif // MANAGERWINDOW_H
