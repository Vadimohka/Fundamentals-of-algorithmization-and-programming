#include "plane.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Plane w;
    w.show();
    return a.exec();
}
