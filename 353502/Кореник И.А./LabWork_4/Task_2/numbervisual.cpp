#include "numbervisual.h"

NumberVisual::NumberVisual(int number)
{
    this->setFixedHeight(number);

    QPalette pal;
    //pal.setColor(QPalette::Window, Qt::green); // Set black background
    pal.setBrush(QPalette::Window, Qt::green);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->show();
}

void NumberVisual::setHight(int number)
{
    this->setFixedHeight(number);
}

void NumberVisual::setColor(Qt::GlobalColor color)
{
    QPalette pal;
    //pal.setColor(QPalette::Window, Qt::green); // Set black background
    pal.setBrush(QPalette::Window, color);
    //this->setAutoFillBackground(true);
    this->setPalette(pal);
}
