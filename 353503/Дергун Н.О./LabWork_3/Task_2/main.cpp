#include "mainwindow.h"
#include "ackermannfunction.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    AckermannFunction AF;
    return a.exec();
}
