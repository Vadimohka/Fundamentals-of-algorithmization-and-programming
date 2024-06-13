#include <QApplication>
#include "../headers/mainwindow.h"
#include "../headers/figure.h"


int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    MainWindow mainwindow;
    mainwindow.show();
    return QApplication::exec();
}
