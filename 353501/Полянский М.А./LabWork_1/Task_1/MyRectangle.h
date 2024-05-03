#include <QGraphicsRectItem>

class myRectangle : public QGraphicsRectItem {
public:
    myRectangle(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};