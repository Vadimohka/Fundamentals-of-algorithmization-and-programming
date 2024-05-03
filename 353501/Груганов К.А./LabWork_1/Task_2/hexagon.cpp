#include "hexagon.h"

Hexagon::Hexagon()
{

}

Hexagon::Hexagon(double R)
{
    this->R=R;
    this->ptsCount=6;

    pts.push_back(QPointF(this->center.x()+R/2,this->center.y()-(double)(R*sqrt(3)/2)));
    pts.push_back(QPointF(this->center.x()+R,this->center.y()));
    pts.push_back(QPointF(this->center.x()+R/2,this->center.y()+(double)(R*sqrt(3)/2)));
    pts.push_back(QPointF(this->center.x()-R/2,this->center.y()+(double)(R*sqrt(3)/2)));
    pts.push_back(QPointF(this->center.x()-R,this->center.y()));
    pts.push_back(QPointF(this->center.x()-R/2,this->center.y()-(double)(R*sqrt(3)/2)));
}

Hexagon::~Hexagon()
{

}

void Hexagon::updateHexagon(double R)
{
    this->R=R;
    currScale=1;
    pts[0] = QPointF(this->center.x()+R/2,this->center.y()-(double)(R*sqrt(3)/2));
    pts[1] = QPointF(this->center.x()+R,this->center.y());
    pts[2] = QPointF(this->center.x()+R/2,this->center.y()+(double)(R*sqrt(3)/2));
    pts[3] = QPointF(this->center.x()-R/2,this->center.y()+(double)(R*sqrt(3)/2));
    pts[4] = QPointF(this->center.x()-R,this->center.y());
    pts[5] = QPointF(this->center.x()-R/2,this->center.y()-(double)(R*sqrt(3)/2));

    double angle = currAngle * 3.1415 / 180;
    QPointF anchor(center.x(), center.y());
    for (int i = 0; i < ptsCount; i++) {
        double dx = anchor.x() + (pts[i].x() - anchor.x()) * cos(angle) - (pts[i].y() - anchor.y()) * sin(angle);
        double dy = anchor.y() + (pts[i].x() - anchor.x()) * sin(angle) + (pts[i].y() - anchor.y()) * cos(angle);
        pts[i].setX(dx);
        pts[i].setY(dy);
    }
}

int Hexagon::nearestVertex(QPointF point)
{
    double minDist = 1e10;
    int minIndex = -1;

    for (int i = 0; i < ptsCount; ++i) {
        double dist = std::hypot(pts[i].x() - point.x(), pts[i].y() - point.y());
        if (dist < minDist) {
            minDist = dist;
            minIndex = i;
        }
    }

    return minIndex;
}

void Hexagon::moveVertex(int index, QPointF point)
{
    if (index >= 0 && index < ptsCount) {
        pts[index] = point;
    }
}

void Hexagon::resetVertices()
{
        pts[0] = QPointF(this->center.x()+R/2,this->center.y()-(double)(R*sqrt(3)/2));
        pts[1] = QPointF(this->center.x()+R,this->center.y());
        pts[2] = QPointF(this->center.x()+R/2,this->center.y()+(double)(R*sqrt(3)/2));
        pts[3] = QPointF(this->center.x()-R/2,this->center.y()+(double)(R*sqrt(3)/2));
        pts[4] = QPointF(this->center.x()-R,this->center.y());
        pts[5] = QPointF(this->center.x()-R/2,this->center.y()-(double)(R*sqrt(3)/2));
}

void Hexagon::paint(QPainter *p)
{
    Shape::paint(p);
}
