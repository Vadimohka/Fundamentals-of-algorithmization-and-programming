#include "hexagon.h"

void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if (!vertices.empty()) {
        painter->drawLine(vertices[0], vertices.back());
        for (int i=1; i<vertices.size(); i++) {
            painter->drawLine(vertices[i], vertices[i-1]);
        }
    }
}

void Hexagon::mousePressEvent(QGraphicsSceneMouseEvent *mouse)
{
    updateInfo();
    emit printSquare(square);
    emit printPerimetr(perimetr);
    emit printCentre(centre);
    if (status == 1) {
        centre=mouse->pos();
        double angle = 0;
        for (int i=0; i<6; i++) {
            vertices.push_back({mouse->pos().x() + cos(angle) * radius, mouse->pos().y() + sin(angle) * radius});
            angle += M_PI / 3;
        }
        status=2;
    }
    if (status == 2) { defaultDist = dist(mouse->pos(), centre); }
    if (status == 4) {
        vertices.clear();
    }
    if (status == 5) {
        defaultVector = {mouse->pos().x() - centre.x(), mouse->pos().y() - centre.y()};
    }
    mousePress=mouse->pos();
    emit isSceneUpdate();
}

void Hexagon::mouseMoveEvent(QGraphicsSceneMouseEvent *mouse)
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
        for (int i=0; i<6; i++) {
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

void Hexagon::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouse)
{
    updateInfo();
    Q_UNUSED(mouse);
    if (status == 1) status = 0;
}


void Hexagon::updateSquare() {
    if (vertices.size()!=6) return;
    square = 3 * qSqrt(3) / 2 * dist(vertices[0], vertices[1]) * dist(vertices[0], vertices[1]);
}
