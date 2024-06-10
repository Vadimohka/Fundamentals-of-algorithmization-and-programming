#include "black_eye.h"
#define eye 20

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;
static long double DegToRad = 180 / Pi;

static qreal normalizeAngle(qreal angle)
{
    while (angle < 0)
        angle += TwoPi;
    while (angle > TwoPi)
        angle -= TwoPi;
    return angle;
}
Black_eye::Black_eye(QRectF ellips , QColor color) :
    MovingEllips(nullptr,ellips,color)
{
    setRotation(0);
    target = QPointF(0,0);
}
void Black_eye::set_center(QPointF center)
{
    this->center = center;
}
void Black_eye::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(get_color());
    painter->setBrush(get_color());
    painter->drawEllipse(get_x(),this->get_y(),this->get_width(),this->get_height());// iris

    painter->setPen(Qt::black);
    painter->setBrush(Qt::black);
    painter->drawEllipse(this->get_Rect().center().x()-eye/2,this->get_Rect().center().y()-eye/2,eye,eye);//black dot


    //painter->setBrush(Qt::NoBrush);
    // painter->drawRect(319,233,30,30);
}

// QRectF Black_eye::boundingRect() const
// {
//      return QRectF(x+3,y+3,width,height);
//     //return QRectF(ellips.center().x()-eye/2-3,ellips.center().y()-eye/2-3,width,height);
// }
void Black_eye::slotTarget(QPointF point)
{
    target = point;
    QLineF lineToTarget(QPointF(get_Rect().center().x() - eye / 2 ,get_Rect().center().y() - eye / 2 ), mapFromScene(target));
    if(lineToTarget.length() > 70)
    {
        qreal angleToTarget;
        angleToTarget = acos(lineToTarget.dx() / lineToTarget.length());
        if (lineToTarget.dy() < 0)
            angleToTarget = TwoPi - angleToTarget;
        angleToTarget = normalizeAngle((Pi - angleToTarget) + Pi / 2);

        if (angleToTarget >= 0 && angleToTarget < Pi)
        {
            // Rotate left
            setRotation(rotation() - angleToTarget * DegToRad);

        }
        else if (angleToTarget <= TwoPi && angleToTarget > Pi)
        {
            // Rotate right
            setRotation(rotation() - (angleToTarget - TwoPi ) * DegToRad );
        }
        setTransformOriginPoint(center.x(),center.y());
    }
}
void Black_eye::action_transform()
{
    visible();
}

void Black_eye::action_move(QPointF pn)
{
    slotTarget(pn);
}

void Black_eye::visible()
{
    isOpen ? this->hide() : this->show();
    isOpen = !isOpen;
}
