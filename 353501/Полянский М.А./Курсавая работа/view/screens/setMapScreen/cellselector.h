#ifndef VIEW_CELLSELECTOR_H_
#define VIEW_CELLSELECTOR_H_

#include <QGraphicsItem>

#include "view/screens/setMapScreen/setmapcell.h"

namespace view {

class CellSelector : public QObject, public QGraphicsItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

   protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void focusOutEvent(QFocusEvent *event) override;

   public:
    CellSelector();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

   signals:
    void cellSelected(SetMapCell::Type type);
    void losedFocusSignal();
};

}  // namespace view

#endif
