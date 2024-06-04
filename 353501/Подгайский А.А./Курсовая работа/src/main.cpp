#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    ae::MainWindow* mw = ae::MainWindow::getInstance();
    mw->show();
    int res = QApplication::exec();
    ae::MainWindow::releaseInstance();
    return res;
}
