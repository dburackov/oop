QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    banksystem.cpp \
    builders/billbuilder.cpp \
    builders/creditbuilder.cpp \
    builders/depositbuilder.cpp \
    builders/logbuilder.cpp \
    builders/userbuilder.cpp \
    controllers/clientcontroller.cpp \
    controllers/managercontroller.cpp \
    controllers/operatorcontroller.cpp \
    database.cpp \
    entities/bank.cpp \
    entities/bill.cpp \
    entities/company.cpp \
    entities/credit.cpp \
    entities/deposit.cpp \
    entities/id.cpp \
    entities/log.cpp \
    entities/transfer.cpp \
    entities/user.cpp \
    main.cpp \
    parser.cpp \
    windows/adminwindow.cpp \
    windows/clientwindow.cpp \
    windows/loginwindow.cpp \
    windows/managerwindow.cpp \
    windows/operatorwindow.cpp \
    windows/registrationwindow.cpp \
    windows/specialistwindow.cpp

HEADERS += \
    banksystem.h \
    builders/billbuilder.h \
    builders/builder.h \
    builders/creditbuilder.h \
    builders/depositbuilder.h \
    builders/logbuilder.h \
    builders/userbuilder.h \
    controllers/clientcontroller.h \
    controllers/managercontroller.h \
    controllers/operatorcontroller.h \
    database.h \
    entities/bank.h \
    entities/bill.h \
    entities/billstatus.h \
    entities/companytype.h \
    entities/company.h \
    entities/credit.h \
    entities/deposit.h \
    entities/id.h \
    entities/log.h \
    entities/transfer.h \
    entities/user.h \
    entities/userrole.h \
    parser.h \
    windows/adminwindow.h \
    windows/clientwindow.h \
    windows/loginwindow.h \
    windows/managerwindow.h \
    windows/operatorwindow.h \
    windows/registrationwindow.h \
    windows/specialistwindow.h

FORMS += \
    windows/adminwindow.ui \
    windows/clientwindow.ui \
    windows/loginwindow.ui \
    windows/managerwindow.ui \
    windows/operatorwindow.ui \
    windows/registrationwindow.ui \
    windows/specialistwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
