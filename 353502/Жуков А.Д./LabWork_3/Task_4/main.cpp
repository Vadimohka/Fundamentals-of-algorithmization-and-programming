#include "t4win.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    T4Win w;
    w.show();
    return a.exec();
}
