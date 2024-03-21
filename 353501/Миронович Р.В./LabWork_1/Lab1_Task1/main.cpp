#include <QApplication>
#include "MyWidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyWidget widget;
    widget.setFixedSize(700, 700);
    widget.setWindowTitle("Task1Lab1");

    widget.show();
    return app.exec();
}
