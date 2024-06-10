#include <QApplication>

#include "widget.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Widget widget;
    widget.setMinimumSize(1000,600);
    widget.showFullScreen();
    return QApplication::exec();
}
