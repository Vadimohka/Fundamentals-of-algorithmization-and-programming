#include "view/hud/errormodal.h"

#include <QPainter>

namespace view {

ErrorModal::ErrorModal(const QString &text, const QSize &size) : Modal(size, true), _text(text) {}

void ErrorModal::paintContent(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPainter *p = painter;
    p->setRenderHint(QPainter::Antialiasing);

    QFont font = painter->font();
    font.setPixelSize(20);
    font.setFamily("Press Start 2P");
    font.setBold(true);
    QPen pen(Qt::red, 8);
    p->setPen(pen);
    painter->setFont(font);

    int height = 500;
    int width = 1300;

    QFontMetrics fontMetric(font);

    width = qMax(300, fontMetric.boundingRect(_text).width());
    height = 15 + 100 + 30 + fontMetric.height() + 15;

    QString text = _text;

    if (width + 80 > 1300) {  // divide stringa in 2
        int s = _text.split(" ").size() / 2;
        QStringList list = _text.split(" ");
        list[s] += "\n";
        text = list.join(" ");
        list = text.split("\n");
        width = qMax(fontMetric.boundingRect(list[0]).width(), fontMetric.boundingRect(list[1]).width());
        height += fontMetric.height();
    }

    painter->setBrush(Qt::black);
    painter->drawRoundedRect(QRectF((_size.width() / 2) - (width / 2 + 40), (_size.height() / 2) - (height / 2), width + 80, height), 10, 10);
    painter->setBrush(Qt::transparent);

    pen.setColor(Qt::white);
    painter->setPen(pen);
    painter->drawText(QRectF(_size.width() / 2 - (width / 2), _size.height() / 2 - (height / 2) + 45, width, height), Qt::AlignCenter, text);

    font.setPixelSize(50);
    painter->setFont(font);

    painter->drawText(QRectF(_size.width() / 2 - 150, _size.height() / 2 - (height / 2) + 15, 300, 100), Qt::AlignCenter, "ERROR");
}

}  // namespace view
