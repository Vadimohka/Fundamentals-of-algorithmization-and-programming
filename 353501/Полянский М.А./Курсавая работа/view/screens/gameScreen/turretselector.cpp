#include "view/screens/gameScreen/turretselector.h"

#include <QCursor>
#include <QPainter>

namespace view {

TurretSelector::TurretSelector() {
    setFlag(QGraphicsItem::ItemIsFocusable);
    setZValue(100);
    setVisible(false);

    QPixmap pixmap = QPixmap(":/assets/images/pointers/pointer.png");
    setCursor(QCursor(pixmap.scaled(32, 32)));

    weakTurretSelector = new PopupSelectorItem(this, ":/assets/images/turrets/weak-turret.png", true);
    weakTurretSelector->setPos(10, 10);
    connect(weakTurretSelector, &PopupSelectorItem::pressed, this, [=]() { emit turretSelected(model::TurretType::WeakTurret); });
    connect(weakTurretSelector, &PopupSelectorItem::hoverEnter, this, [=]() { emit turretHovered(model::TurretType::WeakTurret); });
    connect(weakTurretSelector, &PopupSelectorItem::hoverLeave, this, &TurretSelector::turretHoverLeave);

    mitraTurretSelector = new PopupSelectorItem(this, ":/assets/images/turrets/mitra-turret.png", true);
    mitraTurretSelector->setPos(110, 10);
    connect(mitraTurretSelector, &PopupSelectorItem::pressed, this, [=]() { emit turretSelected(model::TurretType::MitraTurret); });
    connect(mitraTurretSelector, &PopupSelectorItem::hoverEnter, this, [=]() { emit turretHovered(model::TurretType::MitraTurret); });
    connect(mitraTurretSelector, &PopupSelectorItem::hoverLeave, this, &TurretSelector::turretHoverLeave);

    granadeTurretSelector = new PopupSelectorItem(this, ":/assets/images/turrets/granade-turret.png", true);
    granadeTurretSelector->setPos(210, 10);
    connect(granadeTurretSelector, &PopupSelectorItem::pressed, this, [=]() { emit turretSelected(model::TurretType::GranadeTurret); });
    connect(granadeTurretSelector, &PopupSelectorItem::hoverEnter, this, [=]() { emit turretHovered(model::TurretType::GranadeTurret); });
    connect(granadeTurretSelector, &PopupSelectorItem::hoverLeave, this, &TurretSelector::turretHoverLeave);

    comboTurretSelector = new PopupSelectorItem(this, ":/assets/images/turrets/combo-turret.png", true);
    comboTurretSelector->setPos(310, 10);
    connect(comboTurretSelector, &PopupSelectorItem::pressed, this, [=]() { emit turretSelected(model::TurretType::ComboTurret); });
    connect(comboTurretSelector, &PopupSelectorItem::hoverEnter, this, [=]() { emit turretHovered(model::TurretType::ComboTurret); });
    connect(comboTurretSelector, &PopupSelectorItem::hoverLeave, this, &TurretSelector::turretHoverLeave);

    splitTurretSelector = new PopupSelectorItem(this, ":/assets/images/turrets/split-turret.png", true);
    splitTurretSelector->setPos(410, 10);
    connect(splitTurretSelector, &PopupSelectorItem::pressed, this, [=]() { emit turretSelected(model::TurretType::SplitTurret); });
    connect(splitTurretSelector, &PopupSelectorItem::hoverEnter, this, [=]() { emit turretHovered(model::TurretType::SplitTurret); });
    connect(splitTurretSelector, &PopupSelectorItem::hoverLeave, this, &TurretSelector::turretHoverLeave);

    slowTimeTurretSelector = new PopupSelectorItem(this, ":/assets/images/turrets/slowtime-turret.png", true);
    slowTimeTurretSelector->setPos(510, 10);
    connect(slowTimeTurretSelector, &PopupSelectorItem::pressed, this, [=]() { emit turretSelected(model::TurretType::SlowTimeTurret); });
    connect(slowTimeTurretSelector, &PopupSelectorItem::hoverEnter, this, [=]() { emit turretHovered(model::TurretType::SlowTimeTurret); });
    connect(slowTimeTurretSelector, &PopupSelectorItem::hoverLeave, this, &TurretSelector::turretHoverLeave);
}

QRectF TurretSelector::boundingRect() const {
    return QRectF(0, 0, 600, 100);
}

void TurretSelector::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(5);

    painter->setPen(pen);
    painter->setBrush(QBrush(QColor::fromRgb(70, 70, 70)));
    painter->drawRect(0, 0, 600, 100);
}

void TurretSelector::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event);

    // To prevent clicks below
}

void TurretSelector::updateAvailability(U_INT gameCredits) {
    weakTurretSelector->setAvailability(gameCredits >= model::turretTypes.at(model::TurretType::WeakTurret).cost);
    mitraTurretSelector->setAvailability(gameCredits >= model::turretTypes.at(model::TurretType::MitraTurret).cost);
    granadeTurretSelector->setAvailability(gameCredits >= model::turretTypes.at(model::TurretType::GranadeTurret).cost);
    comboTurretSelector->setAvailability(gameCredits >= model::turretTypes.at(model::TurretType::ComboTurret).cost);
    splitTurretSelector->setAvailability(gameCredits >= model::turretTypes.at(model::TurretType::SplitTurret).cost);
    slowTimeTurretSelector->setAvailability(gameCredits >= model::turretTypes.at(model::TurretType::SlowTimeTurret).cost);
}

void TurretSelector::focusOutEvent(QFocusEvent *event) {
    Q_UNUSED(event);

    emit losedFocusSignal();
}

}  // namespace view
