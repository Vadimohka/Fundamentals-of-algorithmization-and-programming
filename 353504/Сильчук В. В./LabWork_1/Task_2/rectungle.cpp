#include "rectungle.h"


rectungle::rectungle() {}

void rectungle::draw(QGraphicsScene *scene, int width, int height, int a, int &h){
    QGraphicsRectItem *figure = new QGraphicsRectItem(0, 0, width, height);
    //setRect(0, 0, width, height);
    figure->setBrush(Qt::red);
    //figure->setTransformOriginPoint(figure->boundingRect().center());
    scene->addItem(figure);

    QGraphicsEllipseItem *point = new QGraphicsEllipseItem(width/2 - 2.5, height/2 - 2.5, 3, 3);
    point->setBrush(Qt::blue);
    scene->addItem(point);

}

void rectungle::perSquareMasse( int width, int height, int a){
    double perimetr = (width + height) * 2;
    double square = width *height;
    emit sendPerimetr(perimetr);
    emit sendSquare(square);
}

// void rectungle::centerMasse(QGraphicsScene *scene,int &x, int &y)
// {
// }

void rectungle::getParametrs(int &side1, int &side2, int &side3, int a){
    if (a == 0)
    {
        bool ok;
        side1 = QInputDialog::getInt(this, tr("Введите ширину"), tr("Ширина:"), 100, 0, 10000, 1, &ok);
        side2 = QInputDialog::getInt(this, tr("Введите длину"), tr("Длина:"), 200, 0, 10000, 1, &ok);
    }
    else
    {
        bool ok;
        side1 = QInputDialog::getInt(this, tr("Введите длину стороны:"), tr("Сторона:"), 100, 0, 10000, 1, &ok);
    }
}

