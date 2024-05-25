#include "setmapgrid.h"

namespace view {

SetMapGrid::SetMapGrid(const QSize &size) : _size(size) {
    setFlag(ItemHasNoContents);
    createSetMapGrid();
}

void SetMapGrid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    Q_UNUSED(painter);
}

QRectF SetMapGrid::boundingRect() const {
    return QRectF(0, 0, _size.width(), _size.height());
}

void SetMapGrid::reDrawPath() {
    for (auto i = _cells.begin(); i != _cells.end(); ++i) {
        (*i)->update();
    }
}

void SetMapGrid::createSetMapGrid() {
    qreal size = _size.height() / 9;

    for (U_INT i = 0; i < 16; i++) {
        for (U_INT j = 0; j < 9; j++) {
            SetMapCell *cell = new SetMapCell(this, size, model::Position{i, j}, SetMapCell::Type::Free);
            cell->setPos(i * size, j * size);
            _cells.push_back(cell);
            connect(cell, &SetMapCell::pressed, this, &SetMapGrid::selectCell);
        }
    }
}

void SetMapGrid::selectCell(SetMapCell *cell) {
    for (auto c : _cells) {
        if (c->isSelected()) {
            c->setSelected(false);
        }
    }

    if (cell != nullptr) {
        cell->setSelected(true);
        emit cellPressed(cell->pos());
    }
}

model::Position SetMapGrid::getSelectedCellPosition() const {
    model::Position p;

    for (auto c : _cells) {
        if (c->isSelected()) {
            p = c->getPos();
        }
    }

    return p;
}

void SetMapGrid::addCell(const model::Position &pos, SetMapCell::Type type) {
    for (auto c : _cells) {
        if (c->getPos() == pos) {
            if ((type == SetMapCell::Type::Start && pos.x == 0) ||    // Se start solo a sinistra
                (type == SetMapCell::Type::Finish && pos.x == 15) ||  // se finish solo a destra
                (type != SetMapCell::Type::Start &&
                 type != SetMapCell::Type::Finish &&
                 type != SetMapCell::Type::Free &&
                 type != SetMapCell::Type::Blocked &&
                 pos.x != 0 &&
                 pos.x != 15) ||  // Se path di mezzo solo in mezzo
                type == SetMapCell::Type::Free ||
                type == SetMapCell::Type::Blocked) {
                c->setType(type);
            } else {
                // Nothing to do
            }
        }
    }
    reDrawPath();
}

void SetMapGrid::clearAll() {
    for (auto c : _cells) {
        c->setType(SetMapCell::Type::Free);
    }
}

const std::vector<SetMapCell *> *SetMapGrid::getCells() const {
    const std::vector<SetMapCell *> *temp = &_cells;

    return temp;
}

}  // namespace view
