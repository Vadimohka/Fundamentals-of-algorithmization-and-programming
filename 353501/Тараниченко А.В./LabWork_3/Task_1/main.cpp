#include <QApplication>
#include <QScreen>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Task 1");

    QRect screen = QApplication::screens()[0]->geometry();
    int x = (screen.width() - w.width()) / 2;
    int y = (screen.height() - w.height()) / 2;
    w.move(x, y);

    w.show();
    return a.exec();
}
