#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

char Toy::_description[100] = "description of the toy!" ;
int Toy::_sizes[4] = {10,20,30,50};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Toy toy1 = {5, 300.50, "Teddy bear", true};

    Toy toy2;
    toy2._age = 3;
    toy2._price = 150.75;
    toy2._name = "Teddy";
    toy2._isForChildern = false;

    qDebug() << toy1._age << " | " << toy1._price << " | " << toy1._name << " | " << toy1._isForChildern << "\n";
    qDebug()  << toy2._age << " | " << toy2._price << " | " << toy2._name << " | " << toy2._isForChildern << "\n";

    Toy toy4;
    Toy* pToy = &toy4;
    pToy->_age = 7;
    pToy->_price = 500.00;
    pToy->_name =  "drawing kit";
    pToy->_isForChildern = true;

    qDebug() << "By Pointer" << pToy->_age << " | " << pToy->_price << " | " << pToy->_name << " | " << pToy->_isForChildern << "\n";

    Toy& ref = toy4;

    ref._age = 2;
    ref._price = 25.99;
    ref._name = "brush";
    ref._isForChildern = false;

    qDebug() << "By Reference" << ref._age << " | " << ref._price << " | " << ref._name << " | " << (ref._isForChildern ? "Yes" : "NO") << " | " << "\n";

    return a.exec();
}
