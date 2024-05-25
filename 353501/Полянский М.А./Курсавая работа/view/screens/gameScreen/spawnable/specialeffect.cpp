#include "view/screens/gameScreen/spawnable/specialeffect.h"

#include <QPainter>

namespace view {

SpecialEffect::SpecialEffect(QGraphicsItem *parent, const QPointF &startingPos, qreal distance)
    : QGraphicsItem(parent), _distance(distance), currentSize(QSize(0, 0)), currentStep(1), speed(30) {
    setPos(startingPos.x() - distance, startingPos.y() - distance);

    deltaSize = 1.0 / speed * distance * 2;
}

QRectF SpecialEffect::boundingRect() const {
    return QRectF(0, 0, _distance * 2, _distance * 2);
}

void SpecialEffect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPen pen(Qt::SolidLine);
    pen.setColor(QColor::fromRgb(0, 0, 0, ((1.0 + speed) - currentStep) / (1.0 + speed) * 255.0));
    pen.setWidth(2);
    painter->setPen(pen);

    qreal finalRadius = _distance;

    painter->drawEllipse(
        QRect(
            finalRadius - currentSize.width() / 2,
            finalRadius - currentSize.height() / 2,
            currentSize.width(),
            currentSize.height()));
}

bool SpecialEffect::tick() {
    // Calculate next size
    currentSize.setWidth(currentSize.width() + deltaSize);
    currentSize.setHeight(currentSize.height() + deltaSize);

    if (currentStep == speed + 1) {
        // Return true if finished
        return true;
    }

    currentStep++;
    update();

    return false;
}

}  // namespace view
