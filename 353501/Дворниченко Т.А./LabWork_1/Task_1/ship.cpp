#include "ship.h"

Ship::Ship(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent) : Rectangle(x,  y,  width,  height,  parent)
{

}

void Ship::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Создание объекта QPainter

    // Установка цвета пера и заливки
    // Создание объекта QPainter

    // Установка цвета пера и заливки
    painter->setPen(Qt::darkRed);
    painter->setBrush(Qt::darkRed);

    // Задание координат и размеров прямоугольника
    int x = 100;  // Координата X
    int y = 150;  // Координата Y
    int width = 200;  // Ширина
    int height = 50; // Высота

    // Рисование прямоугольника
    painter->drawRect(150, 195, 100, 25);

    // Рисование прямоугольника
    painter->drawRect(x, y, width, height);
    // Рисование вертикальной линии на прямоугольнике
    painter->setPen(Qt::blue);


    int leftLineX = x;  // Координата X левой стороны прямоугольника
    int leftLineY1 = y;  // Координата Y начала линии
    int leftLineY2 = y - height*2;  // Координата Y конца линии

    painter->drawLine(leftLineX, leftLineY1, leftLineX, leftLineY2);
}
