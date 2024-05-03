#include <QApplication>
#include <QTableWidget>
#include <QHeaderView>

#include "mainwindow.h"

/// check .pro
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    return app.exec();
}
