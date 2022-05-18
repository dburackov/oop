#include "view.h"
#include "figures/figure.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    View view;
    view.show();
    return a.exec();
}
