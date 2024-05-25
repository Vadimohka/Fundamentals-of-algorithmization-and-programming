#include "view/hud/gametitle.h"

#include <QPainter>

namespace view {

QRectF GameTitle::boundingRect() const {
    return QRectF(0, 0, 1200, 200);
}

void GameTitle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QFont font = painter->font();
    font.setPixelSize(44);
    font.setFamily("Press Start 2P");
    painter->setFont(font);

    painter->setPen(Qt::white);

    painter->drawText(QRect(0, 0, 1200, 110), Qt::AlignHCenter | Qt::AlignBottom, "tower dejense project");

    font.setPixelSize(30);
    painter->setFont(font);

    painter->drawText(QRect(0, 130, 1200, 40), Qt::AlignHCenter, "by Mike Polyanksi");
}

}  // namespace view
