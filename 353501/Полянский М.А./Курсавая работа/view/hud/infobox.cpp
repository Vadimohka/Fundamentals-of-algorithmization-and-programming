#include "view/hud/infobox.h"

#include <QPainter>

namespace view {

InfoBox::InfoBox(const QString &imagePath, const QString &text) : _imagePath(imagePath), _text(text) {}

QRectF InfoBox::boundingRect() const {
    return QRectF(0, 0, 250, 84);
}

void InfoBox::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPixmap pixmap = QPixmap(_imagePath);
    painter->drawPixmap(QRect(0, 0, 80, 80), pixmap);

    QFont font = painter->font();
    font.setPixelSize(40);
    font.setFamily("Press Start 2P");
    painter->setFont(font);

    QPen pen = QPen(QColor::fromRgb(180, 180, 180));
    painter->setPen(pen);

    painter->drawText(QRect(100, 5, 160, 84), Qt::AlignVCenter, _text);
}

void InfoBox::setText(const QString &text) {
    _text = text;
}

}  // namespace view
