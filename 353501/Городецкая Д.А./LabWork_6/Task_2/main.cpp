#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setStyleSheet("background-color: #000000;");
    // a.setStyleSheet("QWidget { color: #000000; }");
    w.show();
    return a.exec();
}
