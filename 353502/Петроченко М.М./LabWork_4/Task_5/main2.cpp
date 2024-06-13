//
// Created by acryoz on 4/26/24.
//
#include <QApplication>
#include <QPushButton>
#include <iostream>
#include "../headers/mainwindow2.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    MainWindow2 main_window(nullptr);
    main_window.show();
    return QApplication::exec();
}
