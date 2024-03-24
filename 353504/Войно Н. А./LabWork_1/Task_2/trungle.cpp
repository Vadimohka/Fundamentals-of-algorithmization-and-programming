#include "trungle.h"

trungle::trungle() {}

void trungle::draw(QGraphicsScene *scene, int width, int height, int a, int &h)
{
    if(proverka(width, height, a))
    {
        return ;
    }

    QPointF p1(0, 0);
    QPointF p2(width, 0);
    QPointF p3((height*height - a*a + width*width) / (2*width), sqrt(height*height - ((height*height - a*a + width*width) / (2*width)) * ((height*height - a*a + width*width) / (2*width))));

    int x =(0 + width + (height*height - a*a + width*width) / (2*width)) / 3.0;
    int y = (0 + 0 + sqrt(height*height - ((height*height - a*a + width*width) / (2*width)) * ((height*height - a*a + width*width) / (2*width)))) / 3.0;
    QPolygonF triangle;
    triangle << p1 << p2 << p3;
    QGraphicsPolygonItem *figure = new QGraphicsPolygonItem(triangle);
    QGraphicsEllipseItem *point = new QGraphicsEllipseItem(x, y, 3, 3);
    scene->addItem(point);
    scene->addItem(figure);
}

void trungle::getParametrs(int &side1, int &side2, int &side3, int a)
{
    bool ok;
    side1 = QInputDialog::getInt(this, tr("Введите стороны треугольника"), tr("Сторона 1:"), 100, 0, 10000, 1, &ok);
    side2 = QInputDialog::getInt(this, tr("Введите стороны треугольника"), tr("Сторона 2:"), 100, 0, 10000, 1, &ok);
    side3 = QInputDialog::getInt(this, tr("Введите стороны треугольника"), tr("Сторона 3:"), 100, 0, 10000, 1, &ok);
}

void trungle::perSquareMasse(int width, int height, int a)
{
    double perimetr = width + height + a;
    double poluPerimetr = perimetr / 2.0;
    double square = sqrt(poluPerimetr * (poluPerimetr - width) * (poluPerimetr - height) * (poluPerimetr - a));
    emit sendPerimetr(perimetr);
    emit sendSquare(square);
}

bool trungle::proverka(int side1, int side2, int side3)
{
    if (!((side1 + side2 > side3) && ( side3 + side2 > side1) && (side1 + side3  > side2)))
    {
        QMessageBox::critical(nullptr, "Ошибка", "Такой треугольник не существует!");
        return 1;
    }
    else {
        return 0;
    }
}
