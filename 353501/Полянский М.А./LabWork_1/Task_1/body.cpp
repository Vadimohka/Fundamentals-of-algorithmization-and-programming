#include "body.h"
#include <QPainter>

Body::Body(int x, int y, int width, int height, QGraphicsItem *parent)
    : QGraphicsItem(parent),
      m_x(x),
      m_y(y),
      m_width(width),
      m_height(height),
      m_rotation(0)
{
    
    setPos(m_x, m_y);
}

QRectF Body::boundingRect() const
{
    return QRectF(0, 0, m_width, m_height); // 0 , 0
}

void Body::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    rotationCenter = QPointF(m_x+m_width-100, m_y+ m_height+75);
    painter->translate(rotationCenter);
    painter->rotate(m_rotation);
    painter->translate(-rotationCenter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setBrush(Qt::yellow);
    painter->drawRect(0, 0, m_width, m_height);
    
    
}

void Body::rotate(){
    
    if(m_rotation<=80 && m_rotation>=0){
        m_rotation+=10;
        
    }
    update();
    
    
}
void Body::rotateDown() {
    if (m_rotation > 0 && m_rotation <= 90) {
        m_rotation -= 10;
        
    }
    update();
}