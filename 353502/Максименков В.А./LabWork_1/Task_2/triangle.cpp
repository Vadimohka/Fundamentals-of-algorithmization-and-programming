#include "triangle.h"

Triangle::Triangle(QPointF _A, QPointF _B, QPointF _C) : A(_A), B(_B), C(_C) {}


QRectF Triangle::boundingRect() const
{
    QPointF left = ((A.x() <= B.x()) ? (A.x() <= C.x() ? A : C) : (B.x() <= C.x() ? B : C)),
        right = ((A.x() >= B.x()) ? (A.x() >= C.x() ? A : C) : (B.x() >= C.x() ? B : C)),
        up = ((A.y() <= B.y()) ? (A.y() <= C.y() ? A : C) : (B.y() <= C.y() ? B : C)),
        down = ((A.y() >= B.y()) ? (A.y() >= C.y() ? A : C) : (B.y() >= C.y() ? B : C));

    return QRectF(QPointF(left.x(), up.y()), QPointF(right.x(), down.y()));
}


void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawLine(A, B);
    painter->drawLine(B, C);
    painter->drawLine(C, A);

    centerOfShape = mapToScene(QPointF((A.x() + B.x() + C.x())/3, (A.y() + B.y() + C.y())/3));
}


void Triangle::resizeShape(QPointF now)
{
    qreal distance = sqrt((now.x() - boundingRect().center().x()) * (now.x() - boundingRect().center().x()) + (now.y() - boundingRect().center().y()) * (now.y() - boundingRect().center().y()));
    setTransformOriginPoint(boundingRect().center());
    setScale(distance / defaultDistance);
    update();
    emit centerSignal(getScenePosition());
    emit updateShape();
}

void Triangle::setDefaultDistanceForTriangle()
{
    setDefaultDistance(sqrt((previous.x() - boundingRect().center().x()) * (previous.x() - boundingRect().center().x()) + (previous.y() - boundingRect().center().y()) * (previous.y() - boundingRect().center().y())));
}

qreal Triangle::squareOfShape()
{
    qreal side1 = sqrt((A.x() - B.x()) * (A.x() - B.x()) + (A.y() - B.y()) * (A.y() - B.y())),
    side2 = sqrt((C.x() - B.x()) * (C.x() - B.x()) + (C.y() - B.y()) * (C.y() - B.y())),
    side3 = sqrt((A.x() - C.x()) * (A.x() - C.x()) + (A.y() - C.y()) * (A.y() - C.y()));

    qreal p = (side1 + side2 + side3)/2;

    qreal square = sqrt(p*(p - side1)*(p - side2)*(p - side3));
    return square;
}

qreal Triangle::perimetrOfShape()
{
    qreal side1 = sqrt((A.x() - B.x()) * (A.x() - B.x()) + (A.y() - B.y()) * (A.y() - B.y())),
        side2 = sqrt((C.x() - B.x()) * (C.x() - B.x()) + (C.y() - B.y()) * (C.y() - B.y())),
        side3 = sqrt((A.x() - C.x()) * (A.x() - C.x()) + (A.y() - C.y()) * (A.y() - C.y()));

    return side1 + side2 + side3;
}


void Triangle::setCenterOfShapeNow(QPointF center)
{
    centerOfShape = center - QPointF((A.x() + B.x() + C.x())/3, (A.y() + B.y() + C.y())/3);
}


void Triangle::setPositionOfTheShape(QPointF pos)
{
    setPos(mapToScene(pos) - QPointF((A.x() + B.x() + C.x())/3, (A.y() + B.y() + C.y())/3));
}


QPointF Triangle::getScenePosition()
{
    return scenePos() + QPointF((A.x() + B.x() + C.x())/3, (A.y() + B.y() + C.y())/3);
}
