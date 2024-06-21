#include "t1win.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    T1Win w;
    w.show();
    return a.exec();
}
