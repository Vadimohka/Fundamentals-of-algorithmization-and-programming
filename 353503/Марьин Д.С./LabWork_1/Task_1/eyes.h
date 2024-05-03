#ifndef EYES_H
#define EYES_H

#include <QGraphicsEllipseItem>
#include <QMainWindow>
#include <QObject>
#include <QPainter>
#include <QWidget>
#include "movingellips.h"

class Eyes : public MovingEllips
{
    Q_OBJECT

public:
    Eyes(QRectF eye_ball = QRectF(0,0,0,0),QColor color = QColor(Qt::white));
    ~Eyes(){};

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option,QWidget * widget = nullptr) override;
private:

   bool isOpen = true;

public slots:
    void slotBlink();//blink action
    virtual void action_transform() override;

};

#endif // EYES_H
