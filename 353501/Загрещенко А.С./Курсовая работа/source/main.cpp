#include "mainwindow.h"
#include "qgameboard.h"


#include<iostream>
#include<time.h>
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    srand(time(NULL));

    QGameBoard gameBoard;
    gameBoard.show();

    return a.exec();
}
