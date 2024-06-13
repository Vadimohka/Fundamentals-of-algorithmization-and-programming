#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;

    QPalette palette;
    palette.setColor(QPalette::Window,Qt::white);
    palette.setColor(QPalette::Button,Qt::lightGray);
    palette.setColor(QPalette::ButtonText,Qt::black);

    w.setAutoFillBackground(true);
    w.setPalette(palette);


    w.show();
    return app.exec();
}
