#include <QApplication>

#include "Headers/MyWidget.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    auto firstWindow = new MyWidget;

    firstWindow->setWindowState(Qt::WindowFullScreen);

    firstWindow->show();

    return QApplication::exec();
}