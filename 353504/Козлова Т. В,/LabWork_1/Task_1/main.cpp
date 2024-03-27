#include <QApplication>

#include "mywidget.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MyWIdget widget;
    widget.show();
    return app.exec();
}
