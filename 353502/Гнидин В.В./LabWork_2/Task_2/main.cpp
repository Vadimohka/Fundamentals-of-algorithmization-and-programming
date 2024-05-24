#include <QApplication>
#include <QPushButton>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    mainwindow *mw = new mainwindow();
    mw->show();
    return QApplication::exec();
}
