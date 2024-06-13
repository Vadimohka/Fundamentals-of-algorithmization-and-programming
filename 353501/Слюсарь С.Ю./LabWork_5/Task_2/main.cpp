#include <QCoreApplication>
#include <QApplication>
#include <iostream>
#include "mystring.h"
#include "mainwindow.h"

int main(int argc, char** argv) {

    QApplication a(argc, argv);
    MainWindow m;
    m.show();
    return a.exec();


    return 0;
}
