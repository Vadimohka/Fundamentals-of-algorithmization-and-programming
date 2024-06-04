#include <QApplication>

#include "mainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    auto q = new mainWindow;
    q->setWindowState(Qt::WindowFullScreen);
    q->resize(800, 500);
    q->show();

    return QApplication::exec();
}
