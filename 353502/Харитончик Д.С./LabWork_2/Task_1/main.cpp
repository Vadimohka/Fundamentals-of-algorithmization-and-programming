#include <QApplication>
#include "mainWindow/mainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    auto *m = new mainWindow();

    m->setWindowState(Qt::WindowFullScreen);
    m->rootDir = argv[0];
    m->show();

    return QApplication::exec();
}