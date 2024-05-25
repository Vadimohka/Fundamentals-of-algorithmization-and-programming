#include "view/hud/iconbutton.h"

#include <QPainter>
#include <QStyleOptionGraphicsItem>

namespace view {

IconButton::IconButton(const QString &imagePath, const QString &hoverImagePath)
    : _imagePath(imagePath), _hoverImagePath(hoverImagePath) {
    setAcceptHoverEvents(true);

    QPixmap pixmap = QPixmap(":/assets/images/pointers/pointer-interactive.png");
    setCursor(QCursor(pixmap.scaled(32, 32)));
}

QRectF IconButton::boundingRect() const {
    return QRectF(0, 0, 100, 100);
}

void IconButton::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(widget);

    if (option->state & QStyle::State_MouseOver) {
        QPixmap pixmap = QPixmap(_hoverImagePath);
        painter->drawPixmap(QRect(2, 2, 96, 96), pixmap);
    } else {
        QPixmap pixmap = QPixmap(_imagePath);
        painter->drawPixmap(QRect(2, 2, 96, 96), pixmap);
    }
}

void IconButton::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event);

    emit pressed();
}

void IconButton::changeImages(const QString &imagePath, const QString &hoverImagePath) {
    _imagePath = imagePath;
    _hoverImagePath = hoverImagePath;
}

}  // namespace view
