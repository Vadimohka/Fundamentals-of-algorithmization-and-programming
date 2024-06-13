#include "shape.h"

int Shape::sostoyanie = 0;
QString Shape::shapeNow = " ";

void Shape::setSostoyanie(int newSostoyanie)
{
    sostoyanie = newSostoyanie;
}

void Shape::setShapeNow(const QString &newShapeNow)
{
    shapeNow = newShapeNow;
}

QString Shape::getShapeNow()
{
    return shapeNow;
}

void Shape::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit newItem(this, shapeNow);

    emit centerSignal(getScenePosition());

    emit squareSignal(squareOfShape());

    emit perimetrSignal(perimetrOfShape());

    if (sostoyanie == -1)
    {
        emit deleteItem(this);
    }
    if (sostoyanie == 1)
    {
        previous = event->scenePos();
        setCenterOfShapeNow(scenePos());
        defaultDistance = sqrt((previous.x() - centerOfShape.x()) * (previous.x() - centerOfShape.x()) + (previous.y() - centerOfShape.y()) * (previous.y() - centerOfShape.y()));
        if (shapeNow == "triangle")setDefaultDistanceForTriangle();
    }
    if (sostoyanie == 3)
    {
        emit mouseHasAlreadyClicked(event->scenePos());
    }
}

void Shape::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    emit squareSignal(squareOfShape());

    emit perimetrSignal(perimetrOfShape());

    if (sostoyanie == 0)
    {
        setPositionOfTheShape(event->pos());
        emit centerSignal(getScenePosition());
        setCenterOfShapeNow(scenePos());
    }
    if (sostoyanie == 1)
    {
        emit mousePosition(event->scenePos());
    }
}

void Shape::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

}

void Shape::rotatingFunction(QPointF now)
{
    QPointF o = centerOfShape;
    QPointF extra = QPointF(previous.y() - o.y() + o.x(), o.y() + o.x() - previous.x());

    qreal x1 = now.x() - o.x(),
        y1 = now.y() - o.y(),
        x2 = previous.x() - o.x(),
        y2 = previous.y() - o.y(),
        d1 = sqrt(x1*x1 + y1*y1),
        d2 = sqrt(x2*x2 + y2*y2),
        mul = x1*x2 + y1*y2,
        ans = (mul / d1) / d2;
    qreal xx1 = now.x() - o.x(),
        yy1 = now.y() - o.y(),
        xx2 = extra.x() - o.x(),
        yy2 = extra.y() - o.y(),
        dd1 = sqrt(xx1*xx1 + yy1*yy1),
        dd2 = sqrt(xx2*xx2 + yy2*yy2),
        mull = xx1*xx2 + yy1*yy2,
        anss = (mull / dd1) / dd2;

    qreal angle1 = (acos(ans)*180)/3.1416,
          angle2 = (acos(anss)*180)/3.1416;

    qreal angle = (angle2 > 90 ? 360-angle1 : angle1);
    angle = -angle;
    setTransformOriginPoint(boundingRect().center());
    setRotation(angle);
    update();
    emit updateShape();
}

void Shape::setDefaultDistanceForTriangle() {}

void Shape::setDefaultDistance(qreal newDefaultDistance)
{
    defaultDistance = newDefaultDistance;
}

void Shape::setCenterOfShapeNow(QPointF center)
{
    centerOfShape = center;
}

void Shape::setPositionOfTheShape(QPointF pos)
{
    setPos(mapToScene(pos));
}

QPointF Shape::getScenePosition()
{
    return scenePos();
}

void Shape::reinterpret(qreal parametr1, qreal parametr2)
{
    Q_UNUSED(parametr1);
    Q_UNUSED(parametr2);
}

Shape::Shape()
{
    connect(this, &Shape::mousePosition, this, &Shape::rotatingFunction);
    connect(this, &Shape::mousePosition, this, &Shape::resizeShape);
}




