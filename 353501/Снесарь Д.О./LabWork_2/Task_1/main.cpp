#include "mainwindow.h"

#include <QApplication>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QRect availableGeometry = QApplication::primaryScreen()->availableGeometry();
    w.setGeometry(availableGeometry);
    w.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //w.setCentralWidget(&w);
    w.show();
    return a.exec();
}
