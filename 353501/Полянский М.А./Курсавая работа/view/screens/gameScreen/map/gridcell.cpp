#include "view/screens/gameScreen/map/gridcell.h"

#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

namespace view {

GridCell::GridCell(
    QGraphicsItem *parent,
    const model::Position &gridPosition,
    qreal size,
    GridCellType type,
    PathGridCellTile tile)
    : QGraphicsItem(parent),
      _gridPosition(gridPosition),
      _size(size),
      _type(type),
      _tile(tile),
      _selected(false) {
    if (type == GridCellType::Free) {
        setAcceptHoverEvents(true);
        updateCursor();
    }
}

QRectF GridCell::boundingRect() const {
    return QRectF(0, 0, _size, _size);
}

void GridCell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(widget);

    QString imagePath;

    switch (_type) {
        case GridCellType::Free:
            imagePath = ":/assets/images/tiles/free-tile.png";

            if (option->state & QStyle::State_MouseOver || _selected) {
                imagePath = ":/assets/images/tiles/free-tile-pressed.png";
            }
            break;
        case GridCellType::Path:
            switch (_tile) {
                case PathGridCellTile::Horizontal:
                default:
                    imagePath = ":/assets/images/tiles/horizontal-tile.png";
                    break;
                case PathGridCellTile::Vertical:
                    imagePath = ":/assets/images/tiles/vertical-tile.png";
                    break;
                case PathGridCellTile::TopRight:
                    imagePath = ":/assets/images/tiles/top-right-tile.png";
                    break;
                case PathGridCellTile::TopLeft:
                    imagePath = ":/assets/images/tiles/top-left-tile.png";
                    break;
                case PathGridCellTile::BottomRight:
                    imagePath = ":/assets/images/tiles/bottom-right-tile.png";
                    break;
                case PathGridCellTile::BottomLeft:
                    imagePath = ":/assets/images/tiles/bottom-left-tile.png";
                    break;
            }
            break;
        case GridCellType::PathStart:
            switch (_tile) {
                case PathGridCellTile::Left:
                default:
                    imagePath = ":/assets/images/tiles/left-start-tile.png";
                    break;
                case PathGridCellTile::Right:
                    imagePath = ":/assets/images/tiles/right-start-tile.png";
                    break;
                case PathGridCellTile::Top:
                    imagePath = ":/assets/images/tiles/top-start-tile.png";
                    break;
                case PathGridCellTile::Bottom:
                    imagePath = ":/assets/images/tiles/bottom-start-tile.png";
                    break;
            }
            break;
        case GridCellType::PathEnd:
            switch (_tile) {
                case PathGridCellTile::Left:
                default:
                    imagePath = ":/assets/images/tiles/left-end-tile.png";
                    break;
                case PathGridCellTile::Right:
                    imagePath = ":/assets/images/tiles/right-end-tile.png";
                    break;
                case PathGridCellTile::Top:
                    imagePath = ":/assets/images/tiles/top-end-tile.png";
                    break;
                case PathGridCellTile::Bottom:
                    imagePath = ":/assets/images/tiles/bottom-end-tile.png";
                    break;
            }
            break;
        case GridCellType::Blocked:
            imagePath = ":/assets/images/tiles/blocked-tile.png";
            break;
        case GridCellType::Occupied:
            imagePath = ":/assets/images/tiles/occupied-tile.png";

            if (option->state & QStyle::State_MouseOver || _selected) {
                imagePath = ":/assets/images/tiles/occupied-tile-pressed.png";
            }
            break;
    }

    QPixmap pixmap = QPixmap(imagePath);
    painter->drawPixmap(QRect(0, 0, _size, _size), pixmap);
}

void GridCell::updateCursor() {
    QPixmap pixmap;
    if (_type == GridCellType::Free) {
        pixmap = QPixmap(":/assets/images/pointers/pointer-turret-place.png");
    } else if (_type == GridCellType::Occupied) {
        pixmap = QPixmap(":/assets/images/pointers/pointer-turret-remove.png");
    } else {
        pixmap = QPixmap(":/assets/images/pointers/pointer.png");
    }

    setCursor(QCursor(pixmap.scaled(32, 32)));
}

void GridCell::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event);

    if (_type == GridCellType::Free || _type == GridCellType::Occupied) {
        emit pressed(this);
    }
}

void GridCell::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    Q_UNUSED(event);

    emit hoverEnter();
}

void GridCell::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    Q_UNUSED(event);

    emit hoverLeave();
}

bool GridCell::isSelected() const {
    return _selected;
}

void GridCell::setSelected(bool selected) {
    _selected = selected;
}

void GridCell::setType(GridCellType type) {
    _type = type;
    updateCursor();
}

GridCellType GridCell::getType() const {
    return _type;
}

model::Position GridCell::getGridPosition() const {
    return _gridPosition;
}

}  // namespace view
