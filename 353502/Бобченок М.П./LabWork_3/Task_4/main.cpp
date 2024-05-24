#include <QApplication>
#include <QPushButton>
#include <iostream>
#include "qt/main_window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto *mainWindow = new main_window();
    mainWindow->setWindowState(Qt::WindowFullScreen);
    mainWindow->show();
    return QApplication::exec();
}
