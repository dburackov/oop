#ifndef OPERATORWINDOW_H
#define OPERATORWINDOW_H

#include <QDialog>

namespace Ui {
class OperatorWindow;
}

class OperatorWindow : public QDialog
{
    Q_OBJECT

public:
    explicit OperatorWindow(QWidget *parent = nullptr);
    ~OperatorWindow();

private:
    Ui::OperatorWindow *ui;
};

#endif // OPERATORWINDOW_H
