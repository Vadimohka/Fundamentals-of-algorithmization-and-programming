//
// Created by darina on 3/3/24.
//

#ifndef LAB_MOVINGELLIPSE_H
#define LAB_MOVINGELLIPSE_H


#include <QGraphicsObject>

class movingEllipse: public QGraphicsObject{
public:
    movingEllipse(qint32 x, qint32 y);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    void move(qint32 a, qint32 b);
    void remove();


private:


protected:
    qint32 x_size, y_size;
    qint32 x_pos = 50, y_pos = 75;
    bool on_Scene;

};

#endif //LAB_MOVINGELLIPSE_H
