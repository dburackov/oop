#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QDialog>

namespace Ui {
class RegistrationWindow;
}

class RegistrationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrationWindow(QWidget *parent = nullptr);
    ~RegistrationWindow();
    void connectLoginWindow();

signals:
    void showLoginWindow();

private slots:
    void on_signInPushButton_clicked();
    void on_signUpPushBotton_clicked();

private:
    Ui::RegistrationWindow *ui;

};

#endif // REGISTRATIONWINDOW_H
