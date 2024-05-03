#include "custom.h"
#include "qgraphicsscene.h"
#include "qgraphicsview.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

Line::Line()
{
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsFocusable, true);
}

QRectF Line::boundingRect() const
{
    if (scene() && scene()->views().size() > 0) {
        QGraphicsView *view = scene()->views().first();
        QSize viewSize = view->viewport()->size();

        return QRectF(0, 0, viewSize.width(), viewSize.height());
    } else {
        return QRectF();
    }
}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->setPen(QColor(Qt::blue)); // Устанавливаем синий цвет кисти
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

