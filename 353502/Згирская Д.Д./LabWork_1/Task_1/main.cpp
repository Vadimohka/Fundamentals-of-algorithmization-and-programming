#include "widget.h"
#include "movingrectangle.h"
#include "ship.h"
#include "flagok.h"

#include <QApplication>
#include <QPushButton>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget* window = new Widget;

    Flagok *flag = new Flagok(window);

    Ship *ship = new Ship(window);

    Widget* layer = new Widget(window);

    QPushButton *buttonUp = new QPushButton("^", layer);

    QLabel *title= new QLabel(window);

    title->setStyleSheet("QLabel { color : red; font-size : 24px}");

    title->setText("Titanic");

    title->setGeometry(450, 450, title->width(), title->height());

    layer->setGeometry(725,325,50,50);

    buttonUp->setGeometry(0,0,50,50);

    window->setMaximumSize(800,600);
    window->setMinimumSize(800,600);

    Flagok::connect(buttonUp, SIGNAL(pressed()), flag, SLOT(MoveRectangle()));

    Flagok::connect(buttonUp, SIGNAL(released()), flag, SLOT(StopMove()));

    window->show();

    return a.exec();
}
