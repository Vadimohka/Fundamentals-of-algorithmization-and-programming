#include "tower.h"
#include "qgraphicsscene.h"
#include <QPainter>

Tower::Tower()
{
    // setFlag(GraphicsItemFlag::ItemIsMovable);
}

QRectF Tower::boundingRect() const
{
    return QRectF(0, 0, 15, 170);
}

void Tower::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    painter->setBrush(QColor(226, 226, 226));
    painter->drawRect(0, 0, 15, 170);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Tower::createRing(Ring* newRing)
{
    newRing->setPos(pos().x() - newRing->getWidth() / 2.0 + 7.5, -20 * (stackRings.size() - 5) + 50);
    stackRings.push(newRing);
}

void Tower::popRing()
{
    if(!stackRings.isEmpty()) stackRings.pop();
}

void Tower::addRing(Ring* newRing)
{
    stackRings.push(newRing);
}

void Tower::clear()
{
    for(int i = 0; i < stackRings.size(); i++)
    {
        scene()->removeItem(stackRings[i]);
    }

    if(!stackRings.isEmpty()) stackRings.clear();
}

Ring *Tower::top()
{
    if(!stackRings.isEmpty()) return stackRings.top();
    else return nullptr;
}
