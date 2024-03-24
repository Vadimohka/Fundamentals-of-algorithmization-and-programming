#include "circle.h"

//circle::circle(){}

void circle::draw(QGraphicsScene *scene, int width, int height, int a, int &h)
{
    QGraphicsEllipseItem *figure = new QGraphicsEllipseItem(0, 0, width * 2, width * 2);
    scene->addItem(figure);

    scene->addLine(width, 0, width, width * 2);
    scene ->addLine(0, width, width * 2, width);
}

void circle::getParametrs(int &side1, int &side2, int &side3, int a)
{
    bool ok;
    side1 = QInputDialog::getInt(this, tr("Введите радиус:"), tr("Радиус:"), 100, 0, 10000, 1, &ok);
}

void circle::perSquareMasse(int width, int height, int a)
{
    double perimetr = 2 * 3.1416 * width;
    double square = 3.1416 * width * width;
    emit sendPerimetr(perimetr);
    emit sendSquare(square);
}
