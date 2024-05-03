#ifndef SHAPE_H
#define SHAPE_H

#include <QGraphicsObject>
#include <QTimer>
#include <QPainter>

class Shape : public QGraphicsObject
{
    Q_OBJECT

public:
    Shape(QGraphicsItem *parent = nullptr);
    virtual void resizeTriangle1(qreal side);
    virtual void resizeTriangle2(qreal side);
    virtual void resizeTriangle3(qreal side);
    virtual void resizeRectW(qreal newwidth);
    virtual void resizeRectH(qreal newHieght);
    virtual void resSide(qreal newside);
    virtual void numberApexes(int apexes);
    virtual void changeRadius1(double spinrad1);
    virtual void changeRadius2(double spinrad2);
    void setCenter(const QPointF &center);
    virtual qreal area();
    virtual qreal perimeter();
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
    void rotate(qreal x, qreal y, qreal angle);
    void scale(qreal x, qreal y, qreal scaleFactor);
    void zoomIn();
    void zoomOut();
    void cnetermovex(double x);
    void cnetermovey(double y);
    void rotateclockwise();
    void unticlockwise();
    virtual void change_side(double newside);
    virtual void changeangle(double newangle);
    QRectF boundingRect() const override;
    virtual void addPoint(const QPointF& point);
    
    qreal moveX;
    qreal moveY;
    qreal m_scaleFactor = 1.0; 
    qreal rotatecenterx = 0;
    qreal rotatecentery= 0;
    qreal rotate_angle = 0;
    qreal centX = 0;
    qreal centY =0;
    qreal radius1;
    qreal radius2;
    qreal side;
    qreal angle;
    qreal sideH;
    qreal apexes_numH;
    bool center_connected = true;

protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void timerEvent(QTimerEvent *event) override;

private:
    QPointF m_center;
    QTimer m_timer;

protected:
    
    QVector<QPointF> points;
    QVector<qreal> pointsx;
    QVector<qreal> pointsy;

    
};

#endif // SHAPE_H
