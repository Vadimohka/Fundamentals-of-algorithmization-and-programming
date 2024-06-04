//
// Created by volodya-petarda on 3/10/24.
//

#ifndef RISOVALKA_BASE_FIGURE_H
#define RISOVALKA_BASE_FIGURE_H


#include <QGraphicsObject>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QRectF>

class base_figure : public QGraphicsObject {
Q_OBJECT
public slots:

    void rotateLeft();

    void rotateRight();

protected:
    int num = 1;
    std::pair <qreal, qreal> *n_verts;
    qreal x_pos, y_pos, scaled_x, scaled_y;
public:
    base_figure();

    qreal getPerimetr();

    qreal getS();

    void moveLeft();

    void moveRight();

    void moveUp();

    void moveDown();

    void rotate(qreal ang);

    void setScaled(qreal x, qreal y);

    void setFigurePos(qreal x, qreal y);

    [[nodiscard]] QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

};


#endif //RISOVALKA_BASE_FIGURE_H
