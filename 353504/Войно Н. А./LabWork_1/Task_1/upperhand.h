#ifndef UPPERHAND_H
#define UPPERHAND_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QTimer>
#include <QPropertyAnimation>
#include <QGraphicsItem>
#include <unistd.h>
#include "move_rec.h"

class upperhand: public Move_rec
{
    Q_OBJECT
public:
    upperhand(QWidget* parent = nullptr);
    virtual void salute();
    virtual void returnSalute();
    void timer();
protected:
    void paintEvent(QPaintEvent*) override;
};

#endif // UPPERHAND_H
