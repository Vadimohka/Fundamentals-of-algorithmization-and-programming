#include "view/hud/modal.h"

#include <QCursor>
#include <QPainter>

namespace view {

Modal::Modal(const QSize &size, bool closeOnClick) : _closeOnClick(closeOnClick), _size(size) {
    setZValue(9999);
    setAcceptHoverEvents(true);

    QPixmap pixmap = QPixmap(":/assets/images/pointers/pointer.png");
    setCursor(QCursor(pixmap.scaled(32, 32)));
}

QRectF Modal::boundingRect() const {
    return QRectF(0, 0, _size.width(), _size.height());
}

void Modal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QBrush brush(QColor::fromRgb(0, 0, 0, 200));

    painter->setPen(Qt::NoPen);
    painter->setBrush(brush);

    painter->drawRect(0, 0, _size.width(), _size.height());

    paintContent(painter, option, widget);
}

void Modal::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event)

    if (_closeOnClick) {
        emit close();
    }
}

}  // namespace view
