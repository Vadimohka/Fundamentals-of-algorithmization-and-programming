#include "line.h"
#include "qgraphicsscene.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

Line::Line()
{
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsFocusable, true);
}

QRectF Line::boundingRect() const
{
    // Получаем размеры сцены
    QRectF sceneRect = scene()->sceneRect();

    // Устанавливаем границы линии в пределах размеров сцены
    return QRectF(0, 0, sceneRect.width(), sceneRect.height());
}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->setPen(QPen(Qt::red, 4));
    painter->drawPath(path);
}

void Line::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    if (event->button() == Qt::LeftButton)
    {
        path.moveTo(mapToScene(event->pos()));
        points.clear(); // Очищаем вектор перед началом новой линии
        points.append(mapToScene(event->pos())); // Добавляем начальную точку в вектор
        update();
    }
    QGraphicsItem::mousePressEvent(event);
}

void Line::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    path.lineTo(mapToScene(event->pos()));
    points.append(mapToScene(event->pos())); // Добавляем текущую точку в вектор
    update();
    QGraphicsItem::mouseMoveEvent(event);
}

void Line::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{


    QGraphicsItem::mouseReleaseEvent(event);
}
