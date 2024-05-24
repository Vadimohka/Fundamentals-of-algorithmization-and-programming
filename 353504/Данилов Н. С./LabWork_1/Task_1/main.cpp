
#include "mainwindow.h"

#include <QApplication>
#include <QMainWindow>
#include <QLabel>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow window;

    window.show();

    return app.exec();
}
