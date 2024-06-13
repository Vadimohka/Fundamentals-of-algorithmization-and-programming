#include "widget.h"

#include <QApplication>
#include <QPalette>
#include <QLabel>
#include <QPushButton>
#include <QShortcut>
#include "ballon.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget* w = new Widget;

    QTimer* timer = new QTimer(w);
    timer->setInterval(100);

    Ellipse* ellipse = new Ellipse(w);
    Ballon* ballon = new Ballon(ellipse);

    Widget* pult = new Widget(w);
    pult->setGeometry(500, 400, 150, 150);

    QPushButton* pop = new QPushButton("pop", pult);
    pop->setGeometry(50, 50, 50, 50);

    QWidget* bach = new QWidget(w);
    bach->setGeometry(0, 0, 400, 400);
    QPalette pal;
    QPixmap pic("/home/lidskae/Downloads/pngimg.com - explosion_PNG101079 (1).png");
    pic = pic.scaled(bach->size(), Qt::IgnoreAspectRatio);
    pal.setBrush(bach->backgroundRole(), pic);
    bach->setAutoFillBackground(true);
    bach->setPalette(pal);

    QTimer* babach = new QTimer(w);
    babach->setInterval(100);

    bach->hide();

    QPushButton* right = new QPushButton("right", pult);
    right->setGeometry(100, 50, 50, 50);

    QPushButton* down = new QPushButton("down", pult);
    down->setGeometry(50, 100, 50, 50);


    QPushButton* up = new QPushButton("up", pult);
    up->setGeometry(50, 0, 50, 50);
    QPushButton* left = new QPushButton("left", pult);
    left->setGeometry(0, 50, 50, 50);
    QObject::connect(left, SIGNAL(clicked()), ellipse, SLOT(moveLeft()));
    QObject::connect(right, SIGNAL(clicked()), ellipse, SLOT(moveRight()));
    QObject::connect(up, SIGNAL(clicked()), ellipse, SLOT(moveUp()));
    QObject::connect(down, SIGNAL(clicked()), ellipse, SLOT(moveDown()));

    QObject::connect(pop, &QPushButton::clicked, ballon, &Ballon::boom);
    QObject::connect(pop, &QPushButton::clicked, bach, &QWidget::show);
   // QObject::connect(pop, &QPushButton::clicked, babach, &QTimer::start);
    QObject::connect(babach, &QTimer::timeout, bach, &QWidget::hide);



   // QObject::connect(left, SIGNAL(clicked()), timer, SLOT(start()));
    //QObject::connect(left, SIGNAL(relaesed()), timer, SLOT(stop()));
    //QObject::connect(timer, SIGNAL(timeout()), ellipse, SLOT(moveLeft()));

    w->show();
    return a.exec();
}
