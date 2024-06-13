//
// Created by acryoz on 15.05.24.
//
#include <QApplication>
#include <QPushButton>
#include "src2/mainwindow.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    MainWindow main_window;
    main_window.show();
    return QApplication::exec();
}
