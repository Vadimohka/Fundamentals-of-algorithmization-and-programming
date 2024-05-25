#ifndef VIEW_MODAL_H_
#define VIEW_MODAL_H_

#include <QGraphicsItem>

namespace view {

class Modal : public QObject, public QGraphicsItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

   private:
    bool _closeOnClick;

   protected:
    QSizeF _size;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void paintContent(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;

   public:
    Modal(const QSize &size, bool closeOnClick = false);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

   signals:
    void close();
};

}  // namespace view

#endif
