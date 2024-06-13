#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

auto main(int argc, char *argv[]) -> int
{
    const QApplication application(argc, argv);
    MainWindow window;
    window.show();
    return application.exec();
}
