#include "mover.h"

Mover::Mover() {}

void Mover::Move(QStack<QGraphicsRectItem *> ster[],
                int num1, int num2)
{
    QTimeLine *timeLine = new QTimeLine(500);
    timeLine->setFrameRange(0, 100);
    QGraphicsItemAnimation *animation = new QGraphicsItemAnimation;

    animation->setTimeLine(timeLine);
    animation->setItem(ster[num1].top());

    animation->setPosAt(0, ster[num1].top()->pos());
    animation->setPosAt(0.3333, ster[num1].top()->pos() +
                                    QPointF(0, -440 + 20 * ster[num1].size()));
    animation->setPosAt(0.6666, ster[num1].top()->pos() +
                                    QPointF(350 * (num2 - num1), -440 + 20 * ster[num1].size()));
    animation->setPosAt(1, ster[num1].top()->pos() +
                               QPointF(350 * (num2 - num1), -20 * (ster[num2].size() - ster[num1].size() + 1)));
    ster[num2].push(ster[num1].top());
    ster[num1].pop();

    timeLine->start();
}
