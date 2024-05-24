//
// Created by darina on 4/10/24.
//

#ifndef TASK4_TOWERSBASE_H
#define TASK4_TOWERSBASE_H

#include <QGraphicsObject>
#include <QWidget>
#include <QPainter>

class TowersBase: public QGraphicsObject{

public:
    explicit TowersBase();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

private:

protected:


};


#endif //TASK4_TOWERSBASE_H
