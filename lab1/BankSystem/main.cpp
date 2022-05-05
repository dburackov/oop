#include <QApplication>

#include "banksystem.h"
#include "database.h"
#include "windows/loginwindow.h"
#include "windows/registrationwindow.h"

//to delete
#include "windows/adminwindow.h"
#include "windows/managerwindow.h"
//to delete end

#include <QDebug>

#include "windows/adminwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginWindow loginWindow;
    RegistrationWindow registrationWindow;

    QObject::connect(&loginWindow, &LoginWindow::showRegistrationWindow, &registrationWindow, &RegistrationWindow::show);
    QObject::connect(&registrationWindow, &RegistrationWindow::showLoginWindow, &loginWindow, &LoginWindow::show);

    loginWindow.show();

    //AdminWindow aw;
    //aw.show();
    //ManagerWindow mw;
    //mw.show();

    a.exec();

    Database::getInstance()->save(BankSystem::getInstance());

    return 0;
}
