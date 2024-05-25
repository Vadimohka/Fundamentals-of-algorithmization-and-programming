#ifndef VIEW_GAMETITLE_H_
#define VIEW_GAMETITLE_H_

#include <QGraphicsItem>

namespace view {

class GameTitle : public QGraphicsItem {
   public:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

}  // namespace view

#endif