#ifndef VIEW_GRIDCELL_H_
#define VIEW_GRIDCELL_H_

#include <QGraphicsItem>

#include "model/position.h"
#include "view/screens/gameScreen/map/gridcelltype.h"

namespace view {

enum class PathGridCellTile {
    Horizontal,
    Vertical,
    TopRight,
    TopLeft,
    BottomRight,
    BottomLeft,
    Top,
    Right,
    Left,
    Bottom
};

class GridCell : public QObject, public QGraphicsItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

   private:
    model::Position _gridPosition;
    qreal _size;
    GridCellType _type;
    PathGridCellTile _tile;
    bool _selected;

    void updateCursor();

   protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

   public:
    GridCell(
        QGraphicsItem *parent,
        const model::Position &gridPosition,
        qreal size,
        GridCellType type = GridCellType::Free,
        PathGridCellTile tile = PathGridCellTile::Horizontal);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    bool isSelected() const;
    void setSelected(bool selected);

    void setType(GridCellType type);

    GridCellType getType() const;
    model::Position getGridPosition() const;

   signals:
    void pressed(GridCell *cell);
    void hoverEnter();
    void hoverLeave();
};

}  // namespace view

#endif
