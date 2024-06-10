#ifndef MOUTH_H
#define MOUTH_H

#include <QGraphicsItem>
#include <QMainWindow>
#include <QObject>
#include <QPainter>
#include <QWidget>
#include "movingellips.h"

class Mouth : public MovingEllips
{
    Q_OBJECT
public:
    Mouth(QRectF mouth = QRectF(0,0,0,0),QColor color = QColor(Qt::red));
    ~Mouth(){};
private:
    bool was_click = false;
public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option,QWidget * widget = nullptr) override;

public slots:
    void action_transform() override;
    void slotTransform();
};

#endif // MOUTH_H
