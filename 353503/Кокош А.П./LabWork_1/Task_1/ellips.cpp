#include "ellips.h"

Ellips::Ellips(QObject *parent)
    : QObject(parent)
    , QGraphicsItem()
    , m_id(countId)
{
    // ellipse = new QGraphicsEllipseItem(-30,-30,60,60,this);
    // ellipse->setBrush(Qt::blue);
    countId++;
}

QRectF Ellips::boundingRect() const
{
    return {0, 0, 0, 0};
};

void Ellips::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    Q_UNUSED(painter);
}

void Ellips::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos()));
}

void Ellips::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void Ellips::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos()));
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}

int Ellips::getId() const
{
    return m_id;
}

int Ellips::countId = 0;

void Ellips::Clicked()
{
    this->deleteLater();
}
