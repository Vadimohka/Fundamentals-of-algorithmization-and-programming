#include <QApplication>
#include <QDebug>

#include "Widget.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Widget *widget = new Widget;
    widget->show();
    return QApplication::exec();
}
