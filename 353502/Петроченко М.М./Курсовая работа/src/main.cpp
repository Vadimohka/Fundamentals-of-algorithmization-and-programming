#include <QApplication>
#include <QPushButton>

#include "mainwindow.h"
#include "startmenu.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    MainWindow main_window(nullptr);
    return QApplication::exec();
}
