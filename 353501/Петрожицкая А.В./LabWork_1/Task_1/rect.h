#include <QGraphicsObject>

class Rect : public QGraphicsObject{
public:
    Rect();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void moveToFirst();
    void moveToSecond();
    void moveToThird();

private slots:


private:
    int x, y, midY, minY, maxY;
    QTimer *timerToFirst,  *timerToSecond,*timerToThird;
};
