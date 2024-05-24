#include <QApplication>
#include "mainwindow/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    mainwindow w;
    w.setWindowState(Qt::WindowFullScreen);
    w.show();
    return QApplication::exec();
}
