#include "star.h"

Star::Star(QWidget* parent) : Figure(parent) {
    this->setParent(parent);
    points.clear();
}


void Star::setPoints()
{
    points.resize(2 * n);

    double xp = mousePress.x(),
        xn = mouseNow.x(),
        yp = mousePress.y(),
        yn = mouseNow.y();

    double b = (xn - xp) / 2,
        a = (yn - yp) / 2;

    double xc = (xp + xn) / 2,
        yc = (yp + yn) / 2;

    for (int i = 0; i < n; i++) {
        QPointF p_out, p_in;
        p_out = {
            xc - b * qSin(2 * M_PI / n * i),
            yc - a * qCos(2 * M_PI / n * i)
        };

        p_in = {
            xc - b / 2 * qSin(2 * M_PI / n * i + M_PI / n),
            yc - a / 2 * qCos(2 * M_PI / n * i + M_PI / n)
        };

        points[i * 2] = p_out;
        points[i * 2 + 1] = p_in;
    }
    centre = (mousePress + mouseNow) / 2;
}


void Star::calcArea(){
    area = 0;
    for (int i = 0; i <= 2 * n; i++){
        float h = sqrt(pow(points[(i + 1) % (2 * n)].y() - (points[i % (2 * n)].y() + points[(i + 2) % (2 * n)].y()) / 2, 2)
                       + pow(points[(i + 1) % (2 * n)].x() - (points[i % (2 * n)].x() + points[(i + 2) % (2 * n)].x()) / 2, 2));
        float a = sqrt(pow(points[(i + 2) % (2 * n)].x() - points[i % (2 * n)].x(), 2)
                       + pow(points[(i + 2) % (2 * n)].y() - points[i % (2 * n)].y(), 2));
        area += a * h / 2;
    }
}

void Star::calcCentre(){

}


void Star::calcPerimetr(){
    int n = (points.size() + 1) / 2;
    perimetr = sqrt(pow(points[0].x() - points[2 * n - 1].x(), 2) + pow(points[0].y() - points[2 * n - 1].y(), 2));
    for (int i = 0; i < 2 * n - 1; i++){
        perimetr = sqrt(pow(points[i].x() - points[i + 1].x(), 2) + pow(points[i].y() - points[i + 1].y(), 2));
    }
}







