#include "view/screens/gameScreen/modals/lostwonmodal.h"

#include <QPainter>

#include "view/hud/standardbutton.h"

namespace view {

LostWonModal::LostWonModal(model::Game::State lostWon, const QSize &size)
    : Modal(size, false), _lostWon(lostWon) {
    int h = 700;
    int w = 900;

    StandardButton *restartButtoon = new StandardButton("RESTART", 300, this);
    restartButtoon->setPos(
        _size.width() / 2 - w / 2 + 50,
        _size.height() / 2 + h / 2 - 50 - restartButtoon->boundingRect().height());
    connect(restartButtoon, &StandardButton::pressed, this, &LostWonModal::restart);

    StandardButton *menuButton = new StandardButton("MENU", 300, this);
    menuButton->setPos(
        _size.width() / 2 + w / 2 - 50 - menuButton->boundingRect().width(),
        _size.height() / 2 + h / 2 - 50 - menuButton->boundingRect().height());
    connect(menuButton, &StandardButton::pressed, this, &LostWonModal::returnToMenu);
}

void LostWonModal::paintContent(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPainter *p = painter;
    p->setRenderHint(QPainter::Antialiasing);

    QFont font = painter->font();
    font.setPixelSize(30);
    font.setFamily("Press Start 2P");
    font.setBold(true);

    QPen pen(Qt::red, 8);
    if (_lostWon == model::Game::State::Won) {
        pen.setColor(Qt::green);
    }
    p->setPen(pen);

    painter->setFont(font);

    int height = 700;
    int width = 900;

    QFontMetrics fontMetric(font);

    QString title = "YOU LOST";
    QString corps = "Students passed the exams!\n\nIt seems that C++ is easy...";

    if (_lostWon == model::Game::State::Won) {
        title = "YOU WIN";
        corps = "You defeated all students!\n\nC++ is too hard";
    }

    painter->setBrush(Qt::black);
    painter->drawRoundedRect(QRectF((_size.width() / 2) - (width / 2 + 40), (_size.height() / 2) - (height / 2), width + 80, height), 10, 10);
    painter->setBrush(Qt::transparent);

    pen.setColor(Qt::white);
    painter->setPen(pen);
    painter->drawText(QRectF(_size.width() / 2 - (width / 2), _size.height() / 2 - (height / 2) + 45, width, height), Qt::AlignCenter, corps);

    font.setPixelSize(100);
    painter->setFont(font);

    painter->drawText(QRectF(_size.width() / 2 - 450, _size.height() / 2 - (height / 2) + 100, 900, 200), Qt::AlignCenter, title);
}

}  // namespace view
