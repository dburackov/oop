#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();

private:
    void refresh();

private:
    Ui::AdminWindow *ui;
    QSqlTableModel *model;
};

#endif // ADMINWINDOW_H
