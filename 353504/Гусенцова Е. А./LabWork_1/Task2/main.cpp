#include <QApplication>
#include <QWidget>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    auto w = new mainwindow;
    w->resize(2000, 1600);
    w->show();
    return QApplication::exec();
}
