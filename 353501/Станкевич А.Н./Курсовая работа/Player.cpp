#include "Player.h"
#include "qgraphicsscene.h"
#include <QGuiApplication>
#include <QKeySequence>



HEROE::HEROE(QObject *parent):
    QObject(parent), QGraphicsItem()
{
    angle = 15;
    setRotation(angle);
    steps = 1;
    countForSteps = 0;
}
HEROE::~HEROE()
{

}
QRectF HEROE::boundingRect() const
{
    return QRectF(-25, -40, 50, 80);
}


void HEROE::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon polygon;
    polygon <<QPoint(0,-20) << QPoint(25, 40) << QPoint(-25, 40);
    painter->setBrush(Qt::black);
    painter->drawPolygon(polygon);
    Q_UNUSED(option);
    Q_UNUSED(widget);

}

void HEROE::keyPressEvent(QKeyEvent *e)
{
    if(e->key()==Qt::Key_Left)
    {
        angle -=10;
        setRotation(angle);
    }
    if(e->key()==Qt::Key_Right)
    {
        angle +=10;
        setRotation(angle);
    }
    if(e->key()==Qt::Key_Up)
    {
        setPos (mapToParent(0, -5));
    }
    if(e->key()==Qt::Key_Down){
        setPos (mapToParent(0, 5));
    }

    if(this->x() - 10 < -250){
        this->setX(-240);
    }
    if(this->x() + 10 > 250){
        this->setX(240);
    }

    if(this->y() - 10 < -250){
        this->setY(-240);
    }
    if(this->y() + 10 > 250){
        this->setY(240);
    }
    QList<QGraphicsItem *> foundItems = scene()->items(QPolygonF() << mapToScene(0, 0)<< mapToScene(-20, -20)<< mapToScene(20, -20));
    foreach (QGraphicsItem *item, foundItems) {
        if (item == this)
            continue;
        emit signalCheckItem(item);
    }
}

void HEROE::mySlot()
{
    if (currentKeyEvent){
    keyPressEvent(currentKeyEvent);
    }
}
