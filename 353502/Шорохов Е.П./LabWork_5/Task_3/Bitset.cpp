#include <QApplication>
#include "QMainWindow"
#include <QPushButton>
#include <QLocale>
#include "MainWindow/MainWindow.h"
#include "map"
#include "bitset/Bitset.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto *button = new QPushButton;
    button->show();
    bitset<5> y;
    y.set();
    qDebug() <<  y.test(2);
    return QApplication::exec();
}

