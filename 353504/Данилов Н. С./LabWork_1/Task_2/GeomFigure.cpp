#include "GeomFigure.h"
GeomFigure::GeomFigure(): countofangles(0){}

void GeomFigure::Draw(QPainter *pr)
{
    QPolygonF polyg;
    for(int i = 0; i<countofangles; i++)
    {
        polyg << angles[i];
    }
    pr->drawPolygon(polyg);
    pr->drawEllipse(center, 3,3);
}

void GeomFigure::SetCenter(int x, int y)
{
    for(int i =0; i<countofangles; i++)
    {
        angles[i].setX(angles[i].x() + x -this->center.x());
        angles[i].setY(angles[i].y() + y - this->center.y());
    }
    this->center.setX(x);
    this->center.setY(y);
}

void GeomFigure::CountCenter()
{
    int tmp_x = 0, tmp_y = 0;
    for(int i =0; i<countofangles; i++)
    {
        tmp_x += angles[i].x();
        tmp_y += angles[i].y();
    }
    this->center.setX(tmp_x / (countofangles ? countofangles : 1));
    this->center.setY(tmp_y / (countofangles ? countofangles : 1));
}

void GeomFigure::SetWidth(int w)
{
    this->a = w;
}

void GeomFigure::SetHeight(int h)
{
    this->b = h;
}

QPointF GeomFigure::GetCenter(){
    return center; 
}

void GeomFigure::Rotate(double angle)
{
    for(int i = 0; i<countofangles; i++)
    {
        double newx = (angles[i].x() - center.x())*cos(angle) - (angles[i].y() - center.y())*sin(angle) + center.x();
        double newy = (angles[i].y() - center.y())*cos(angle) + (angles[i].x() - center.x())*sin(angle) + center.y();
        angles[i].setX(newx);
        angles[i].setY(newy);
    }
}

void GeomFigure::Resize(bool big)
{
    for(int i = 0; i<countofangles; i++)
    {
        if (big){

            double newx = angles[i].x() + (angles[i].x() - center.x()) * 0.01;
            double newy = angles[i].y() + (angles[i].y() - center.y()) * 0.01;
            angles[i].setX(newx);
            angles[i].setY(newy);
        } else {
            double newx = angles[i].x() - (angles[i].x() - center.x()) * 0.01;
            double newy = angles[i].y() - (angles[i].y() - center.y()) * 0.01;
            angles[i].setX(newx);
            angles[i].setY(newy);
        }
    }
}

QVector<QPointF> GeomFigure::GetPolyg()
{
    return angles;
}

void GeomFigure::SetPolyg(QVector<QPointF> a)
{
    angles = a;
}

int GeomFigure::GetCountOfAngles()
{
    return countofangles;
}

int GeomFigure::GetWidth()
{
    return a;
}

int GeomFigure::GetHeight()
{
    return b;
}

void GeomFigure::CountS()
{
    double temp = 0;

    for(int i = 0; i<countofangles - 1; i++)
    {
        temp+= ( (angles[i].x() * angles[i + 1].y()) - (angles[i + 1].x() * angles[i].y()) )/2;
    }
    temp += ( (angles[countofangles - 1].x() * angles[0].y()) - (angles[0].x() * angles[countofangles - 1].y()) )/2;
    this->S = fabs(temp);
}

void GeomFigure::CountP()
{
    double temp = 0;
    for(int i = 1; i<countofangles; i++)
    {
        temp += sqrt((angles[i-1].x() - angles[i].x())*(angles[i-1].x() - angles[i].x()) + (angles[i-1].y() - angles[i].y())*(angles[i-1].y() - angles[i].y()));
    }
    temp += sqrt((angles[0].x() - angles[countofangles-1].x())*(angles[0].x() - angles[countofangles-1].x()) + (angles[0].y() - angles[countofangles-1].y())*(angles[0].y() - angles[countofangles-1].y()));

    this->P = temp;
}

double GeomFigure::GetS()
{
    return S;
}

double GeomFigure::GetP()
{
    return P;
}

void GeomFigure::PlusAng()
{
    ++countofangles;
}
