#include "view/screens/gameScreen/map/gridfield.h"

#include <QGraphicsScene>

#include "view/screens/gameScreen/spawnable/bullet.h"
#include "view/screens/gameScreen/spawnable/granade.h"

namespace view {

GridField::GridField(
    const QSize &size,
    const vector<model::PathCell> &path,
    const vector<model::Position> &blockedCells)
    : _size(size),
      _path(path),
      _blockedCells(blockedCells) {
    setFlag(ItemHasNoContents);

    createGameGrid();
}

QRectF GridField::boundingRect() const {
    return QRectF(0, 0, _size.width(), _size.height());
}

void GridField::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    Q_UNUSED(painter);
}

void GridField::createGameGrid() {
    qreal size = _size.height() / 9;

    // Path Cells
    // ========================================================================
    for (auto i = _path.begin(); i != _path.end(); i++) {
        GridCell *cell;

        if (i == _path.begin()) {
            // First cell
            PathGridCellTile tile;

            switch (i->to) {
                case model::Direction::Left:
                    tile = PathGridCellTile::Right;
                    break;
                case model::Direction::Up:
                    tile = PathGridCellTile::Bottom;
                    break;
                case model::Direction::Right:
                    tile = PathGridCellTile::Left;
                    break;
                case model::Direction::Down:
                    tile = PathGridCellTile::Top;
                    break;
            }

            cell = new GridCell(this, i->getPosition(), size, GridCellType::PathStart, tile);
        } else if (i == _path.end() - 1) {
            // Last cell
            PathGridCellTile tile;

            switch (i->from) {
                case model::Direction::Left:
                    tile = PathGridCellTile::Right;
                    break;
                case model::Direction::Up:
                    tile = PathGridCellTile::Bottom;
                    break;
                case model::Direction::Right:
                    tile = PathGridCellTile::Left;
                    break;
                case model::Direction::Down:
                    tile = PathGridCellTile::Top;
                    break;
            }

            cell = new GridCell(this, i->getPosition(), size, GridCellType::PathEnd, tile);
        } else {
            // Medium cell
            PathGridCellTile tile;

            switch (i->from) {
                case model::Direction::Left:
                    switch (i->to) {
                        case model::Direction::Up:
                            tile = PathGridCellTile::TopLeft;
                            break;
                        case model::Direction::Right:
                            tile = PathGridCellTile::Horizontal;
                            break;
                        case model::Direction::Down:
                            tile = PathGridCellTile::BottomLeft;
                            break;
                        default:
                            // Nope
                            break;
                    }
                    break;
                case model::Direction::Up:
                    switch (i->to) {
                        case model::Direction::Left:
                            tile = PathGridCellTile::TopLeft;
                            break;
                        case model::Direction::Right:
                            tile = PathGridCellTile::TopRight;
                            break;
                        case model::Direction::Down:
                            tile = PathGridCellTile::Vertical;
                            break;
                        default:
                            // Nope
                            break;
                    }
                    break;
                case model::Direction::Right:
                    switch (i->to) {
                        case model::Direction::Left:
                            tile = PathGridCellTile::Horizontal;
                            break;
                        case model::Direction::Up:
                            tile = PathGridCellTile::TopRight;
                            break;
                        case model::Direction::Down:
                            tile = PathGridCellTile::BottomRight;
                            break;
                        default:
                            // Nope
                            break;
                    }
                    break;
                case model::Direction::Down:
                    switch (i->to) {
                        case model::Direction::Left:
                            tile = PathGridCellTile::BottomLeft;
                            break;
                        case model::Direction::Up:
                            tile = PathGridCellTile::Vertical;
                            break;
                        case model::Direction::Right:
                            tile = PathGridCellTile::BottomRight;
                            break;
                        default:
                            // Nope
                            break;
                    }
                    break;
            }

            cell = new GridCell(this, i->getPosition(), size, GridCellType::Path, tile);
        }

        cell->setPos(i->x * size, i->y * size);
    }

    // Blocked Cells
    // ========================================================================
    for (auto i = _blockedCells.begin(); i != _blockedCells.end(); i++) {
        GridCell *cell = new GridCell(this, *i, size, GridCellType::Blocked);
        cell->setPos(i->x * size, i->y * size);
    }

    // Free Cells
    // ========================================================================
    bool isFree = true;

    for (U_INT i = 0; i < 16; i++) {
        for (U_INT j = 0; j < 9; j++) {
            isFree = true;

            for (auto pathCell : _path) {
                if (pathCell.x == i && pathCell.y == j) {
                    isFree = false;
                    break;
                }
            }

            for (auto blockedCell : _blockedCells) {
                if (blockedCell.x == i && blockedCell.y == j) {
                    isFree = false;
                    break;
                }
            }

            if (isFree) {
                GridCell *cell = new GridCell(this, model::Position{i, j}, size, GridCellType::Free);
                interactiveCells.push_back(cell);
                connect(cell, &GridCell::pressed, this, &GridField::selectCell);
                cell->setPos(i * size, j * size);
            }
        }
    }
}

void GridField::selectCell(GridCell *cell) {
    for (auto c : interactiveCells) {
        if (c->isSelected()) {
            c->setSelected(false);
        }
    }

    if (cell != nullptr) {
        GridCellType cellType = cell->getType();
        model::Position cellPosition = cell->getGridPosition();

        if (cellType == GridCellType::Occupied) {
            // If cell is occupied remove it
            for (auto i = turrets.begin(); i != turrets.end(); i++) {
                if ((*i)->getGridPosition() == cellPosition) {
                    cell->setType(GridCellType::Free);
                    disconnect(cell, &GridCell::hoverEnter, nullptr, nullptr);
                    disconnect(cell, &GridCell::hoverLeave, nullptr, nullptr);
                    scene()->removeItem(*i);
                    turrets.erase(i);
                    break;
                }
            }
        } else {
            // If the cell is free simply select it
            cell->setSelected(true);
        }

        emit cellPressed(cellType, cellPosition);
    }
}

void GridField::turretsAttack(const vector<SP<model::Turret>> &attackingTurrets, const vector<EnemyItem *> &enemies) {
    for (auto turret : attackingTurrets) {
        // Find associated TurretItem
        for (auto turretItem : turrets) {
            if (turretItem->hasTurretData(turret)) {
                // Attack
                turretItem->attack(enemies);
            }
        }
    }
}

void GridField::addTurretItem(const SP<model::Turret> &turret, model::TurretType turretType) {
    // Set cell as occupied
    for (auto cell : interactiveCells) {
        if (cell->getGridPosition() == turret->getPosition()) {
            cell->setType(GridCellType::Occupied);
            connect(cell, &GridCell::hoverEnter, this, [=]() { emit turretHovered(turretType, cell->getGridPosition()); });
            connect(cell, &GridCell::hoverLeave, this, &GridField::turretHoverLeave);
            break;
        }
    }

    // Create turret
    TurretItem *turretItem = new TurretItem(this, turret, turretType, 96);  // TODO: fix all cell sizes (dynamics)
    turrets.push_back(turretItem);
    connect(turretItem, &TurretItem::spawnBullet, this, &GridField::spawnBullet);
    connect(turretItem, &TurretItem::spawnGranade, this, &GridField::spawnGranade);
    connect(turretItem, &TurretItem::spawnSpecialEffect, this, &GridField::spawnSpecialEffect);

    // For hover fix
    emit turretHoverLeave();
}

model::Position GridField::getSelectedCellPosition() const {
    for (auto c : interactiveCells) {
        if (c->isSelected()) {
            return c->getGridPosition();
        }
    }
    // Shouldn't get here
    return model::Position{9999, 9999};
}

void GridField::tick() {
    // Move projectiles
    auto i = projectiles.begin();
    while (i != projectiles.end()) {
        if ((*i)->move()) {
            // Spawn granade explosion
            if (dynamic_cast<Granade *>(*i)) {
                emit spawnGranadeExplosion((*i)->pos());
            }

            scene()->removeItem(*i);
            i = projectiles.erase(i);
        } else {
            i++;
        }
    }

    // Tick special effects
    auto j = specialEffects.begin();
    while (j != specialEffects.end()) {
        if ((*j)->tick()) {
            scene()->removeItem(*j);
            j = specialEffects.erase(j);
        } else {
            j++;
        }
    }
}

void GridField::spawnBullet(const QPointF &startingPos, const QPointF &endingPos) {
    Bullet *bullet = new Bullet(this, startingPos, endingPos);
    projectiles.push_back(bullet);
}

void GridField::spawnGranade(const QPointF &startingPos, const QPointF &endingPos) {
    Granade *granade = new Granade(this, startingPos, endingPos);
    projectiles.push_back(granade);
}

void GridField::spawnSpecialEffect(const QPointF &startingPos, qreal distance) {
    SpecialEffect *specialEffect = new SpecialEffect(this, startingPos, distance);
    specialEffects.push_back(specialEffect);
}

}  // namespace view
