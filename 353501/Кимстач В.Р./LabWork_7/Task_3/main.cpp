#include "mainwindow.h"

#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    mainwindow mainWindow;
    mainWindow.show();
    return app.exec();
}
