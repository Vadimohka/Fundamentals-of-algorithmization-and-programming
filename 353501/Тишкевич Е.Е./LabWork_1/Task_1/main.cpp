#include "mainwindow.h"
#include <baloon.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QScreen>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow window;
    QRect availableGeometry = QApplication::primaryScreen()->availableGeometry();
    window.setGeometry(availableGeometry);
    window.show();

    return a.exec();
}
