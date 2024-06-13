#include "figure.h"

QRectF Figure::boundingRect() const
{
    if (status == 1) { return {0, 0, BIG_NUM, BIG_NUM}; }
    if (vertices.empty()) { return {0, 0, 0, 0}; }
    double minX = BIG_NUM, minY = BIG_NUM, maxX = 0, maxY = 0, verticesSize=vertices.size();
    for (int i=0; i<verticesSize; i++) {
        minX=qMin(minX, vertices[i].x());
        minY=qMin(minY, vertices[i].y());
        maxX=qMax(maxX, vertices[i].x());
        maxY=qMax(maxY, vertices[i].y());
    }
    return {minX, minY, maxX-minX, maxY-minY};
}

void Figure::updatePerimetr()
{
    perimetr=dist(vertices[0], vertices.back());
    for (int i=1; i<vertices.size(); i++) {
        perimetr+=dist(vertices[i], vertices[i-1]);
    }
}

void Figure::updateCentre()
{
    int verticesSize=vertices.size();
    double sumX=0, sumY=0;
    for (int i=0; i<verticesSize; i++) {
        sumX+=vertices[i].x();
        sumY+=vertices[i].y();
    }
    centre={sumX/verticesSize, sumY/verticesSize};
}

void Figure::updateInfo()
{
    if (vertices.empty()) return;
    updateSquare();
    updatePerimetr();
    updateCentre();
    emit isSceneUpdate();
}

double Figure::dist(QPointF point1, QPointF point2)
{
    return qSqrt((point1.x()-point2.x())*(point1.x()-point2.x()) + (point1.y()-point2.y())*(point1.y()-point2.y()));
}

void Figure::resizeFigure(QGraphicsSceneMouseEvent* mouse)
{
    int verticesNum=vertices.size();
    for (int i=0; i<verticesNum; i++) qDebug() << vertices[i];
    qDebug() << centre;
    QVector <QPointF> defaultVertices = vertices;
    for (int i=0; i<vertices.size(); i++) {
        double x = defaultVertices[i].x() - centre.x(), y = defaultVertices[i].y() - centre.y();
        if (dist(mouse->pos(), centre) < defaultDist) {
            x*=LESS;
            y*=LESS;
        }
        else {
            x*=MORE;
            y*=MORE;
        }
        vertices[i] = {centre.x() + x, centre.y() + y};
    }
    defaultDist = dist(mouse->pos(), centre);
}

double Figure::angle(QPair<double, double> a, QPair<double, double> b)
{
    double angle = ((a.first * b.first) + (a.second * b.second)) / (qSqrt(a.first * a.first + a.second * a.second) * qSqrt(b.first * b.first + b.second * b.second));
    return qAcos(angle);
}

double Figure::calcAngle(QPair<double, double> a, QPair<double, double> b)
{
    double ang=angle(a, b);
    double xNormal = a.first * cos(M_PI / 2) - a.second * sin(M_PI / 2), yNormal = a.second * cos(M_PI / 2) + a.first * sin(M_PI / 2);
    double angleNormal = angle(b, {xNormal, yNormal});
    if (angleNormal > M_PI / 2 && ang < M_PI / 2) {
        //SqDebug() << "OK";
        ang = 2 * M_PI - (angleNormal - M_PI / 2);
    }
    else if (ang >= M_PI / 2 && angleNormal > M_PI / 2) {
        ang = 2 * M_PI - ang;
    }
    return ang;
}

void Figure::rotateFigure(QGraphicsSceneMouseEvent *mouse)
{
    int verticesNum = vertices.size();
    double angle = calcAngle(defaultVector, {mouse->pos().x() - centre.x(), mouse->pos().y() - centre.y()});
    for (int i=0; i<verticesNum; i++) {
        double x = vertices[i].x() - centre.x(), y = vertices[i].y() - centre.y();
        vertices[i] = {centre.x() + x * cos(angle) - y * sin(angle), centre.y() + y * cos(angle) + x * sin(angle)};
    }
    defaultVector = {mouse->pos().x() - centre.x(), mouse->pos().y() - centre.y() };
}
