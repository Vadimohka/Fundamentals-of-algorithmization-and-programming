#include <QtWidgets>
#include "mainwindow.h"

int main (int argc, char** argv) {
    QApplication app(argc, argv);

    auto *q = new ApplicationWindow;

    q->show();

    QApplication::exec();
}
