#ifndef FIGURE_H
#define FIGURE_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QPropertyAnimation>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QMessageBox>



class Figure: public QGraphicsObject
{
public:
    Figure();

    virtual float findArea();
    virtual float findPerimeter();
    QPoint getCenter();

    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();

    void rotateRight();
    void rotateLeft();

    void upScale();
    void downScale();

    float getScale();

    void SBMoveX(int x);
    void SBMoveY(int y);

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    bool moving = false;
    QPointF oldPos;

private:
    float scale = 1.0;
    QMouseEvent *mouse;
    QPropertyAnimation *animation;

protected:
    QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

};

#endif // FIGURE_H
