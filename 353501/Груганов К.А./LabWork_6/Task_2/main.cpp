#include "mainwindow.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QScreen>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setWindowTitle("Task 2");

    QScreen *screen = QApplication::screens().at(0);
    int sWidth = screen->size().width();
    int sHeight = screen->size().height();
    int width = w.width();
    int height = w.height();
    int centerX = (sWidth - width) / 2;
    int centerY = (sHeight - height) / 2;
    w.move(centerX, centerY);

    w.show();
    return a.exec();
}
