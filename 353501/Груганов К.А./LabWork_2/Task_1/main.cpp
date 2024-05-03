#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Task 1");
    w.setFixedSize(1000,700);
    w.show();
    return a.exec();
}
