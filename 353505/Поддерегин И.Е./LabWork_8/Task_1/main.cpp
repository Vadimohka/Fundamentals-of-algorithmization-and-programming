#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication b(argc, argv);
    MainWindow window;
    window.show();
    return b.exec();
}
