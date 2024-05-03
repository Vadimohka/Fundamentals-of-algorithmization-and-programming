#include "shape.h"

Shape::Shape(QPointF point, QWidget *parent){
    //this->setFlag(ItemIsMovable);

    this->SetStarterPoint(mapFromScene(point));
    this->SetEndPoint(mapFromScene(point)); 
}

QRectF Shape::boundingRect() const{
    qreal width = qAbs(GetEndPoint().x() - GetStarterPoint().x());
    qreal heigh = qAbs(GetEndPoint().y() - GetStarterPoint().y());

    return QRectF((GetEndPoint().x() > GetStarterPoint().x() ? GetStarterPoint().x() : GetEndPoint().x()) - 5,
                  (GetEndPoint().y() > GetStarterPoint().y() ? GetStarterPoint().y() : GetEndPoint().y()) - 5,
                  width + 10, heigh + 10);
}

// Geters
QPointF Shape::GetStarterPoint() const
{
    return StarterPoint;
}
QPointF Shape::GetEndPoint() const
{
    return EndPoint;
}
qreal Shape::GetScale() const
{
    return scaled;
}
qreal Shape::GetRotation() const
{
    return rotated;
}


// Seters
void Shape::SetStarterPoint(QPointF point)
{
    StarterPoint = mapFromScene(point);
    qreal width = qAbs(GetEndPoint().x() - GetStarterPoint().x());
    qreal heigh = qAbs(GetEndPoint().y() - GetStarterPoint().y());

    this->update((GetEndPoint().x() > GetStarterPoint().x() ? GetStarterPoint().x() : GetEndPoint().x()) - 5,
                 (GetEndPoint().y() > GetStarterPoint().y() ? GetStarterPoint().y() : GetEndPoint().y()) - 5,
                 width + 10, heigh + 10);
}
void Shape::SetEndPoint(QPointF point)
{
    EndPoint = mapFromScene(point);
    qreal width = qAbs(GetEndPoint().x() - GetStarterPoint().x());
    qreal heigh = qAbs(GetEndPoint().y() - GetStarterPoint().y());

    this->update((GetEndPoint().x() > GetStarterPoint().x() ? GetStarterPoint().x() : GetEndPoint().x()) - 5,
                 (GetEndPoint().y() > GetStarterPoint().y() ? GetStarterPoint().y() : GetEndPoint().y()) - 5,
                 width + 10, heigh + 10);
}
void Shape::SetScale(qreal scale_on)
{
    scaled += scale_on;
}
void Shape::SetRotate(qreal rotate_on)
{
    rotated += rotate_on;
}

void Shape::UpdateInfo_(qreal scale)
{
    this->square *= scale * scale;
    this->perimetr *= scale;
}





