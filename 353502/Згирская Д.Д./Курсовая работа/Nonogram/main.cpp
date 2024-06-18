#include "Headers/widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    //QPalette pal = QPalette();

// set black background
// Qt::black / "#000000" / "black"
    /*pal.setColor(QPalette::Window, Qt::black);

    w.setAutoFillBackground(true);
    w.setPalette(pal);*/

    w.setWindowState(Qt::WindowFullScreen);
    w.show();
    return a.exec();
}
