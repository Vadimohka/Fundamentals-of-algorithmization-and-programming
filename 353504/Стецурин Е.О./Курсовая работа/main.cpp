#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Dota 2 Drafter");
    w.setWindowIcon(QIcon("D:/BSUIR/Kursovaya/Pictures/Dota2Drafter.jpg"));
    w.show();
    return a.exec();
}
