#include <QApplication>

#include "Headers/Widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("Widget");
    Widget *widget = new Widget();
    QPalette pal;
    pal.setColor(QPalette::Active, QPalette::Window, QColor(8, 191, 78, 255));
    widget->setPalette(pal);
    widget->showFullScreen();
    return QApplication::exec();
}
