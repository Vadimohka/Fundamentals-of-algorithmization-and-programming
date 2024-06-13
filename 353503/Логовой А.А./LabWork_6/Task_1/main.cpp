#include "mainwindow.h"
#include <QApplication>
#include "Airport.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Airport minsk;
    minsk.id = 12345;
    minsk.altitude = 760.23;
    minsk.isOpen = true;
    strncpy(Airport::name, "CENTRALMOSCOW", sizeof(Airport::name) - 1);
    for(int i = 0; i < TEN; i++) {
        Airport::flights[i] = i+1;
    }
    qDebug() << minsk.printInfo();

    Airport *ptrMinsk = new Airport;
    ptrMinsk->id = 54321;
    ptrMinsk->altitude = 862.32;
    ptrMinsk->isOpen = false;
    strncpy(Airport::name, "MINSK - PI2", sizeof(Airport::name) - 1);
    for(int i = 0; i < TEN; i++) {
        Airport::flights[i] = i+11;
    }
    qDebug() << ptrMinsk->printInfo();

    Airport anotherMinsk;
    Airport &refMinsk = anotherMinsk;
    refMinsk.id = 67890;
    refMinsk.altitude = 963.41;
    refMinsk.isOpen = true;
    strncpy(Airport::name, "MINSK-WORD", sizeof(Airport::name) - 1);
    for(int i = 0; i < TEN; i++) {
        Airport::flights[i] = i+21;
    }
    qDebug() << refMinsk.printInfo();

    MainWindow w;
    w.show();

    delete ptrMinsk;

    return a.exec();
}
