#include "draw.h"

Draw::Draw(qreal x1, qreal  y1, QGraphicsItem* parent): QGraphicsPolygonItem(parent){

    Point.setX(x1);
    Point.setY(y1);
    draw << Point << QPoint(Point.x() + 1 , Point.y() + 1);
    setPolygon(draw);

}

void Draw::mousePressEvent(QGraphicsSceneMouseEvent* event) {

    setFlag(QGraphicsItem::ItemIsMovable);

}
void Draw::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {
    Point.setX((event -> scenePos()).x());
    Point.setY((event -> scenePos()).y());

    draw << Point;
    setPolygon(draw);

}
void Draw::mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {
    Point = QPointF();

    setFlag(QGraphicsItem::ItemIsMovable);
}
