#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QDesktopWidget dw;
    int x = dw.width() * 0.5;
    int y = dw.height() * 0.5;

    w.move((x - w.width() / 2), (y - w.height() / 2));

    w.show();
    return a.exec();
}
