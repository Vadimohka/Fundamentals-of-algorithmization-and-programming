//
// Created by dmitry on 4.2.24.
//
#pragma once
#include <QApplication>
#include <MainWindow.h>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow *window = new MainWindow;

    window->setFixedSize(500,500);
    window->show()  ;
    return app.exec();
}