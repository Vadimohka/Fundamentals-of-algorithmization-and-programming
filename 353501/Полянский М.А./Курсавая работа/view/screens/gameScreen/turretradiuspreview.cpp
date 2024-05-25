#include "view/screens/gameScreen/turretradiuspreview.h"

#include <QPainter>

namespace view {

TurretRadiusPreview::TurretRadiusPreview() : _radius(1) {
    setOpacity(0.3);
    setZValue(99);  // TODO: set costants in external file
}

QRectF TurretRadiusPreview::boundingRect() const {
    // Bounding rect is max radius (TEMP: 4)
    return QRectF(0, 0, 96 * 9, 96 * 9);
}

void TurretRadiusPreview::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);

    painter->setPen(Qt::NoPen);
    painter->setBrush(brush);

    painter->drawRect(0, 0, 96 * (_radius * 2 + 1), 96 * (_radius * 2 + 1));
}

void TurretRadiusPreview::setRadius(U_INT radius) {
    _radius = radius;
}

}  // namespace view
