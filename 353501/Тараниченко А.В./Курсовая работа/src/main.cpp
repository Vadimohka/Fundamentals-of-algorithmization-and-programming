#include "MainWindow.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    srand(time(0));
    QApplication a(argc, argv);
    MainWindow gameWindow;
    gameWindow.show();

    return a.exec();
}
