#ifndef SEGMENT_H
#define SEGMENT_H
#include <QGraphicsItem>
#include <QPainter>

class Segment : public QGraphicsItem
{
protected:
    QPoint A = QPoint(0, -50);
    QPoint B = QPoint(0, 0);
public:
    double v = 1;

    Segment();
    QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
private slots:
    void advance(int phase) override;
};

#endif // SEGMENT_H
