#include <QApplication>
#include <QPushButton>
#include <iostream>
#include "../headers/mainwindow.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    MainWindow main_window(nullptr);
    main_window.show();
    return QApplication::exec();
}
