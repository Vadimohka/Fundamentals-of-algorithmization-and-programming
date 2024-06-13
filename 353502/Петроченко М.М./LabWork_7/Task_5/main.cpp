//
// Created by acryoz on 26.05.24.
//
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    MainWindow main_window;
    main_window.show();
    return QApplication::exec();
}
