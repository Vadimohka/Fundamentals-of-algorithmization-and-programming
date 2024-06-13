#include "MainWindow.h"

#include <QApplication>

constexpr short WIDTH = 800;
constexpr short HEIGHT = 600;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(WIDTH, HEIGHT);
    w.show();
    return a.exec();
}
