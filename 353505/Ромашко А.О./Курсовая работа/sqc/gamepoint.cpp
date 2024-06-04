#include "gamepoint.h"
#include <QDebug>

GamePoint::GamePoint(int X,int Y, int Size) {
    x=X;
    y=Y;
    size=Size;
    borderColor = Qt::red;
    gameScene = new GameScene();
}

GamePoint::~GamePoint() {
}

void GamePoint::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(borderColor);
    painter->drawEllipse(x,y,size,size);
}

void GamePoint::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "nu click byl v gamepoint";
    emit clickSignal(this);
    flag=0;
    borderColor = Qt::blue;
    this->update(); // Перерисовываем элемент
    QGraphicsItem::mousePressEvent(event);
}
QRectF GamePoint::boundingRect() const
{
    return QRectF(x,y,size,size);
}

void GamePoint::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    // QGraphicsItem::mouseReleaseEvent(event);
}

void GamePoint::changeBorderColor(Qt::GlobalColor color)
{
    // Изменяем цвет обводки
    //в дальнейшем можно использовать как слот для присваивания картинки или для ПОДСВЕТА АЛГОРИТМОВ

}
