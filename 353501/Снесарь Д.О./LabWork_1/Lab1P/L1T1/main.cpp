#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QRect availableGeometry = QApplication::primaryScreen()->availableGeometry();
    w.setGeometry(availableGeometry);
    w.show();
    return a.exec();
}
