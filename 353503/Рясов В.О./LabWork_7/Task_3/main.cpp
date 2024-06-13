#include "mainwindow.h"

#include <QApplication>

constexpr short SIZE_W = 800;
constexpr short SIZE_H = 600;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(SIZE_W, SIZE_H);
    w.show();
    return a.exec();
}
