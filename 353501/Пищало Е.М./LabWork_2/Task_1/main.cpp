#include "mainwindow.h"
#include "date.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Date");
    w.show();
    return a.exec();
}
