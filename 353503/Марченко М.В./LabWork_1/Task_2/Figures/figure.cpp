#include "figure.h"
#include "qgraphicssceneevent.h"
#include <QPainter>

Figure::Figure(QPointF point, QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    // Устанавливаем стартовую координату для отрисовки фигуры
    this->setStartPoint(mapFromScene(point));
    this->setEndPoint(mapFromScene(point));
    /* Подключаем сигнал изменения координат к слоту запуска обновления содержимого объекта
     * Сигнал и слот присутствуют в базовом классе
     * */
    connect(this, &Figure::pointChanged, this, &Figure::updateFigure);

    // Необязательно, перемещаемый
    setFlags(ItemIsMovable | ItemIsSelectable | ItemSendsGeometryChanges | ItemSendsScenePositionChanges);
    setAcceptHoverEvents(true);
}

Figure::~Figure()
{

}

QRectF Figure::boundingRect() const
{
    /* Возвращаем область, в которой лежит фигура.
     * Обновляемая область зависит от стартовой точки отрисовки и от конечной точки
     * */
    return QRectF((endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) - 5,
                  (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) - 5,
                  qAbs(endPoint().x() - startPoint().x()) + 10,
                  qAbs(endPoint().y() - startPoint().y()) + 10);
}

void Figure::updateFigure()
{
    // Вызываем обновление области, в которой лежит фигура
    this->update((endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) - 5,
                 (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) - 5,
                 qAbs(endPoint().x() - startPoint().x()) + 10,
                 qAbs(endPoint().y() - startPoint().y()) + 10);
}

void Figure::setStartPoint(const QPointF point)
{
    m_startPoint = mapFromScene(point);
    emit pointChanged();
}

void Figure::setEndPoint(const QPointF point)
{
    m_endPoint = mapFromScene(point);
    emit pointChanged();
}

long double Figure::GetArea()
{
    return 0;
}

long double Figure::GetPerimeter()
{
    return 0;
}

void Figure::setScale(qreal delta)
{
    QTransform transform;
    transform.translate(m_centerPoint.x(), m_centerPoint.y());
    transform.scale(delta, delta);
    transform.translate(-m_centerPoint.x(), -m_centerPoint.y());

    m_startPoint = transform.map(m_startPoint);
    m_endPoint = transform.map(m_endPoint);

    setTransform(transform, true);

    m_centerPoint = centerPoint();
    update();
}

QPointF Figure::startPoint() const
{
    return m_startPoint;
}

QPointF Figure::endPoint() const
{
    return m_endPoint;
}

QPointF Figure::centerPoint() const
{
    return m_centerPoint;
}

void Figure::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::RightButton){
        cursorOffset = pos() - event->scenePos();
        isMoving = true;
    }
}

void Figure::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(isMoving && (event->buttons() & Qt::RightButton)){
        QPointF newPosition = event->scenePos() + cursorOffset; // ? координаты
        setPos(newPosition);
        setCursor(Qt::ClosedHandCursor);
    }
}

void Figure::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::RightButton){
        isMoving = false;
        setCursor(Qt::ArrowCursor);
    }
}

void Figure::mouseHoverEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(Qt::OpenHandCursor);
    Q_UNUSED(event);
}

bool Figure::contains(const QPointF &point) const
{
   // qreal size = qMax(qAbs(endPoint().x() - startPoint().x()), qAbs(endPoint().y() - startPoint().y()));
    //QRectF rect(startPoint(), QSizeF(size, size));

    //return rect.contains(point);
}



