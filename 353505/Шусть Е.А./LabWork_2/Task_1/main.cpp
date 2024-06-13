#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    auto *q = new mainWindow();

    q->setWindowState(Qt::WindowFullScreen);
    q->projDir = argv[0];
    q->show();

    return QApplication::exec();
}
