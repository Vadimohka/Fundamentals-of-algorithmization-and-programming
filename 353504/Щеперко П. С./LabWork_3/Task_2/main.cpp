#include "mainwindow.h"

#include <QApplication>
#include <stacktrace>

int main(int argc, char *argv[])
{
    qDebug() << std::stacktrace();
    void *ptr = (void *) &main;
    long long *ptr1 = (long long*)ptr;
    qDebug() << ptr << '\n';
    qDebug() << ptr1-1 << '\n';
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
