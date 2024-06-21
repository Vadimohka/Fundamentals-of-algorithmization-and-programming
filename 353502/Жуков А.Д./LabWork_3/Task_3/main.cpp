#include "t3win.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    T3Win w;
    w.show();
    return a.exec();
}
