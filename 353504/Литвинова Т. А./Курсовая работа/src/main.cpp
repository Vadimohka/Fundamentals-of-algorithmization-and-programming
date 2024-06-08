#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    try {
        MainWindow w;
        w.setWindowTitle("Добро пожаловать!");
        w.show();
        return a.exec();
    } catch (const std::exception &e) {
        qCritical() << "Произошло исключение:" << e.what();
        return 1;
    }
}
