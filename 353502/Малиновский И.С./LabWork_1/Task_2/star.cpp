#include "star.h"

void Star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    qDebug() << "YES";
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if (!vertices.empty()) {
        painter->drawLine(vertices[0], vertices.back());
        for (int i=1; i<vertices.size(); i++) {
            painter->drawLine(vertices[i], vertices[i-1]);
        }
    }
}

void Star::mousePressEvent(QGraphicsSceneMouseEvent *mouse)
{
    updateInfo();
    emit printSquare(square);
    emit printPerimetr(perimetr);
    emit printCentre(centre);
    qDebug() << "Press OK";
    if (status == 1) {
        centre=mouse->pos();
        double angle = 0;
        for (int i=0; i<verticesNum; i++) {
            if (i%2==0) { vertices.push_back({mouse->pos().x() + cos(angle) * describedRadius, mouse->pos().y() + sin(angle) * describedRadius}); }
            else { vertices.push_back({mouse->pos().x() + cos(angle) * inscribedRadius, mouse->pos().y() + sin(angle) * inscribedRadius}); }
            angle += 2 * M_PI / verticesNum;
        }
        status=2;
    }
    if (status == 2) { defaultDist = dist(mouse->pos(), centre); }
    if (status == 4) { vertices.clear(); }
    if (status == 5) {
        defaultVector = {mouse->pos().x() - centre.x(), mouse->pos().y() - centre.y()};
    }
    mousePress=mouse->pos();
    emit isSceneUpdate();
}

void Star::mouseMoveEvent(QGraphicsSceneMouseEvent *mouse)
{
    updateInfo();
    emit printSquare(square);
    emit printPerimetr(perimetr);
    emit printCentre(centre);
    if (status == 2) {
        resizeFigure(mouse);
        emit isSceneUpdate();
    }
    if (status == 3) {
        for (int i=0; i<verticesNum; i++) {
            vertices[i] += mouse->pos() - mousePress;
        }
        centre+=mouse->pos() - mousePress;
        mousePress=mouse->pos();
        emit isSceneUpdate();
    }
    if (status == 5) {
        rotateFigure(mouse);
    }
}

void Star::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouse)
{
    Q_UNUSED(mouse);
    if (status == 1) status = 0;
}

void Star::updateSquare() {
    if (vertices.size() != verticesNum) return;
    double s1 = dist(vertices.back(), vertices[0]), s2=dist(vertices[0], vertices[1]), s3=dist(vertices[1], vertices.back()), p = (s1 + s2 + s3) / 2;
    square = qSqrt(p*(p-s1)*(p-s2)*(p-s3))*verticesNum;
}
