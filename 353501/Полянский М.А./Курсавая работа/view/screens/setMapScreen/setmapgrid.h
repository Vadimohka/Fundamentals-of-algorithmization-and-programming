#ifndef SETMAPGRID_H
#define SETMAPGRID_H

#include <QGraphicsItem>
#include <vector>

#include "app/shortcuts.h"
#include "view/screens/setMapScreen/setmapcell.h"

using std::vector;

namespace view {

class SetMapGrid : public QObject, public QGraphicsItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

   private:
    QSize _size;
    vector<SetMapCell *> _cells;

    void createSetMapGrid();
    void reDrawPath();

   public:
    SetMapGrid(const QSize &size);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    model::Position getSelectedCellPosition() const;
    void clearAll();
    const vector<SetMapCell *> *getCells() const;

    void selectCell(SetMapCell *cell);
    void addCell(const model::Position &pos, SetMapCell::Type type);

   signals:
    void cellPressed(const QPointF &coordinates);
};

}  // namespace view

#endif  // SETMAPGRID_H
