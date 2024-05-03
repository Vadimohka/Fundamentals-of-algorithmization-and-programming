#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setMinimumSize(w.size());
    w.setWindowTitle("Ведомости абитуриентов");
    w.show();
    return a.exec();
}
