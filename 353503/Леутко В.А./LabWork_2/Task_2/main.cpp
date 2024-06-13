#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto *w = new MainWindow();
    w->setWindowState(Qt::WindowFullScreen);
    w->projectDirectory = argv[0];
    w->show();
    return a.exec();
}


