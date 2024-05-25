#include "view/screens/setMapScreen/cellselector.h"

#include <QCursor>
#include <QPainter>

#include "view/hud/popupselectoritem.h"

namespace view {

CellSelector::CellSelector() {
    setFlag(QGraphicsItem::ItemIsFocusable);
    setVisible(false);

    QPixmap pixmap = QPixmap(":/assets/images/pointers/pointer.png");
    setCursor(QCursor(pixmap.scaled(32, 32)));

    PopupSelectorItem *freeCell = new PopupSelectorItem(this, ":/assets/images/tiles/free-tile.png");
    freeCell->setPos(10, 10);
    connect(freeCell, &PopupSelectorItem::pressed, this, [=]() { emit cellSelected(SetMapCell::Type::Free); });

    PopupSelectorItem *blockedCell = new PopupSelectorItem(this, ":/assets/images/tiles/blocked-tile.png");
    blockedCell->setPos(110, 10);
    connect(blockedCell, &PopupSelectorItem::pressed, this, [=]() { emit cellSelected(SetMapCell::Type::Blocked); });

    PopupSelectorItem *startCell = new PopupSelectorItem(this, ":/assets/images/tiles/left-start-tile.png");
    startCell->setPos(210, 10);
    connect(startCell, &PopupSelectorItem::pressed, this, [=]() { emit cellSelected(SetMapCell::Type::Start); });

    PopupSelectorItem *finishCell = new PopupSelectorItem(this, ":/assets/images/tiles/right-end-tile.png");
    finishCell->setPos(310, 10);
    connect(finishCell, &PopupSelectorItem::pressed, this, [=]() { emit cellSelected(SetMapCell::Type::Finish); });

    PopupSelectorItem *orizzCell = new PopupSelectorItem(this, ":/assets/images/tiles/horizontal-tile.png");
    orizzCell->setPos(410, 10);
    connect(orizzCell, &PopupSelectorItem::pressed, this, [=]() { emit cellSelected(SetMapCell::Type::Orizz); });

    PopupSelectorItem *vertCell = new PopupSelectorItem(this, ":/assets/images/tiles/vertical-tile.png");
    vertCell->setPos(10, 110);
    connect(vertCell, &PopupSelectorItem::pressed, this, [=]() { emit cellSelected(SetMapCell::Type::Vert); });

    PopupSelectorItem *sxupCell = new PopupSelectorItem(this, ":/assets/images/tiles/top-left-tile.png");
    sxupCell->setPos(110, 110);
    connect(sxupCell, &PopupSelectorItem::pressed, this, [=]() { emit cellSelected(SetMapCell::Type::SxUp); });

    PopupSelectorItem *dxupCell = new PopupSelectorItem(this, ":/assets/images/tiles/top-right-tile.png");
    dxupCell->setPos(210, 110);
    connect(dxupCell, &PopupSelectorItem::pressed, this, [=]() { emit cellSelected(SetMapCell::Type::DxUp); });

    PopupSelectorItem *sxdwCell = new PopupSelectorItem(this, ":/assets/images/tiles/bottom-left-tile.png");
    sxdwCell->setPos(310, 110);
    connect(sxdwCell, &PopupSelectorItem::pressed, this, [=]() { emit cellSelected(SetMapCell::Type::SxDw); });

    PopupSelectorItem *dxdwCell = new PopupSelectorItem(this, ":/assets/images/tiles/bottom-right-tile.png");
    dxdwCell->setPos(410, 110);
    connect(dxdwCell, &PopupSelectorItem::pressed, this, [=]() { emit cellSelected(SetMapCell::Type::DxDw); });
}

QRectF CellSelector::boundingRect() const {
    return QRectF(0, 0, 500, 200);
}

void CellSelector::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(5);

    painter->setPen(pen);
    painter->setBrush(QBrush(QColor::fromRgb(70, 70, 70)));
    painter->drawRect(0, 0, 500, 200);
}

void CellSelector::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event);

    // To prevent clicks below
}

void CellSelector::focusOutEvent(QFocusEvent *event) {
    Q_UNUSED(event);
    emit losedFocusSignal();
}

}  // namespace view
