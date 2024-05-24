#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication k(argc, argv);
    MainWindow w;
    w.show();
    return k.exec();
}
