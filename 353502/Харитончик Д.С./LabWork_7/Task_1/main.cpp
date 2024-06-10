#include "mainwindows.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindows w;
    w.show();
    return a.exec();
}
