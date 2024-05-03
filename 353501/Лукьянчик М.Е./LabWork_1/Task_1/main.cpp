#include "plane.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Plane play;
    play.show();
    return a.exec();
}
