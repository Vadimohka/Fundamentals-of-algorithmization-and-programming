#ifndef VIEW_STANDARDBUTTON_H_
#define VIEW_STANDARDBUTTON_H_

#include <QGraphicsItem>

namespace view {

class StandardButton : public QObject, public QGraphicsItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

   private:
    QString _text;
    int _width;

   protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

   public:
    StandardButton(const QString &text, int width = 300, QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

   signals:
    void pressed();
};

}  // namespace view

#endif
