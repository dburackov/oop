QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    factory.cpp \
    figures/ellipsis.cpp \
    figures/figure.cpp \
    figures/line.cpp \
    figures/polygon.cpp \
    figures/polyline.cpp \
    figures/rectangle.cpp \
    main.cpp \
    scene.cpp \
    view.cpp

HEADERS += \
    factory.h \
    figures/Polyline.h \
    figures/ellipsis.h \
    figures/figure.h \
    figures/line.h \
    figures/polygon.h \
    figures/rectangle.h \
    scene.h \
    view.h

FORMS += \
    view.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
