#include <QApplication>
#include <iostream>
#include "headers/mainwindow.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    MainWindow main_window;
    main_window.show();
    if (const char* env = std::getenv("LANG")) {
        std::cout << env;
    }
    return QApplication::exec();
}
