#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    QPainter painter;
    QTimer::singleShot(10000, &w, SLOT(close()));
    return a.exec();
}
