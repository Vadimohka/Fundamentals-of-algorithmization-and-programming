
#include "elements.h"

void Elements::setN(int x)
{
    n = x;
    calculatepoints();
    update();
}

int Elements::getN()
{
    return n;
}

void Elements::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    for (int i = 0; i < n; ++i){
        if(i == SearchedRect){
            painter->setBrush(Qt::blue);
            QRectF recc(i * (sceneWidht / n), sceneHeight-palki[i], (long double)(sceneWidht) / n, palki[i]);
            painter->drawRect(recc);
            continue;
        }
        painter->setBrush(Qt::red);
        QRectF recc(i * (sceneWidht / n), sceneHeight-palki[i], (long double)(sceneWidht) / n, palki[i]);
        painter->drawRect(recc);
    }
}

void Elements::calculatepoints()
{
    palki.clear();
    width = sceneWidht / n;
    for (int i = 0; i < n; ++i)
    {
        palki.push_back(rand() % 300 + 35);
    }
}

QRectF Elements::boundingRect() const
{
    return QRectF(10,10,10,10);
}

Elements::Elements(){}
