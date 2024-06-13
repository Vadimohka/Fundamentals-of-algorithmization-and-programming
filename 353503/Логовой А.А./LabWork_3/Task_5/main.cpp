#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication apllication(argc, argv);
    MainWindow window;
    window.show();
    return QApplication::exec();
}
