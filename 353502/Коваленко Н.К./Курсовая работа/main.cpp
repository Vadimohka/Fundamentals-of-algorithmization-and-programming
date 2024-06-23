#include <QApplication>
#include "mainwindow.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QGraphicsScene>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    //слой - пустое окно
    QWidget *window = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(window);
    //виджет - меню
    MainWindow *menu = new MainWindow;
    layout->addWidget(menu);

    //цвет фона
    const QPalette palet(QColorConstants::Black);
    window->setPalette(palet);
    window->setAutoFillBackground(true);

    //показ слоя - пустого окна
    window->showMaximized();


    //MainWindow v;
    //v.showMaximized();

    //View w;
    //w.scale(1.5,1.5);


    return a.exec();
}
