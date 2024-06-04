#include <QApplication>
#include <QPushButton>
#include <cmath>
#include "main_window.h"
#include <iostream>

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    auto *mw = new main_window();
    mw->show();
    return QApplication::exec();
}
