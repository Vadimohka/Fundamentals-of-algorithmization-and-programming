#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setOverrideCursor(Qt::ArrowCursor);
    MainWindow w;
    w.show();
    return a.exec();
}
