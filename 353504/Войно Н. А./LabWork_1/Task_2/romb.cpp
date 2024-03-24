#include "romb.h"

romb::romb() {}

void romb::draw(QGraphicsScene *scene, int width, int height, int a, int &h)
{
    h = sqrt(3) * width;
    QPointF p1(0, h / 2);
    QPointF p2(width, 0);
    QPointF p3(2 * width, h / 2);
    QPointF p4(width, h);
    QPolygonF rhomb;
    rhomb << p1 << p2 << p3 << p4;
    QGraphicsPolygonItem *figure = new QGraphicsPolygonItem(rhomb);
    QGraphicsEllipseItem *point = new QGraphicsEllipseItem(figure->boundingRect().center().x(), figure->boundingRect().center().y(), 3, 3);
    point->setBrush(Qt::blue);
    scene->addItem(point);
    scene->addItem(figure);
}

void romb::getParametrs(int &side1, int &side2, int &side3, int a)
{
    bool ok;
    side1 = QInputDialog::getInt(this, tr("Введите стороны ромба"), tr("Сторона:"), 100, 0, 10000, 1, &ok);
}

void romb::perSquareMasse(int width, int height, int a)
{
    double perimetr = 4 * width;
    double square = width * height;
    emit sendPerimetr(perimetr);
    emit sendSquare(square);
}
