#include <QtGui/QApplication>
//#include "widget.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;

    MainWindow w;
    w.show();

    return a.exec();
}
