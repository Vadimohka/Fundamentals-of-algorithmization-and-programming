#include "mainwindow.h"

#include <QApplication>

#include "vector.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    Vector<int> vector ;
    Vector<int> vector1 (4);

    std::vector<int> vec (10);

    vector.push_back(10);

    qDebug() << vector.size();



    return a.exec();
}
