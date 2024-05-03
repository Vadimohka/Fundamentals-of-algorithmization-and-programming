#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QVector<int> testik;
    w.show();
    return a.exec();
}
