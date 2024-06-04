#include <QApplication>
#include <QPushButton>
#include "Date.h"
#include "mainwindow.h"
#include <iostream>
#include <QDebug>
#include <QFileDialog>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto *mainWindow = new mainwindow();
    mainWindow->show();
    return QApplication::exec();
}
