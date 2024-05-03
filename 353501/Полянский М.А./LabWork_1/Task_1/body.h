#include <QGraphicsItem>

class Body : public QGraphicsItem
{
public:
    Body(int x, int y, int width, int height, QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void rotate();
    void rotateDown();


private:
    int m_x;
    int m_y;
    int m_width;
    int m_height;
    qreal m_rotation = 0 ;
    QPointF rotationCenter;
};