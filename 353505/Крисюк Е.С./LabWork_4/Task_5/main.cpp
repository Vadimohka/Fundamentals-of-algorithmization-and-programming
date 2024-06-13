#include "mainwindow.h"

#include <QApplication>

#include "vector.h"
#include <vector>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Vector<int> vector (3);
    Vector<int> vector1 (4);

    std::vector<int> vec (10);



    return a.exec();
}
