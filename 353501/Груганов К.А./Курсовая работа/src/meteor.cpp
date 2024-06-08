#include "meteor.h"

Meteor::Meteor()
{
    hitDamage = 60;
    m_totalTime = 0;
    speed = QRandomGenerator::global()->bounded(150, 220);
    m_rotSpeed = (float)QRandomGenerator::global()->bounded(3, 30) / 10;
    QPixmap pixmap;
    int pid = QRandomGenerator::global()->bounded(0, 3);

    if(pid == 0)
    {
        pixmap = QPixmap(":/img/meteor-01-l.png").scaled(QSize(90, 90),
                                                         Qt::KeepAspectRatio, Qt::SmoothTransformation);

    }
    else if (pid == 1)
    {
        pixmap = QPixmap(":/img/meteor-01-m.png").scaled(QSize(60, 60),
                                                         Qt::KeepAspectRatio, Qt::SmoothTransformation);
    }
    else
    {
        pixmap = QPixmap(":/img/meteor-01-s.png").scaled(QSize(40, 40),
                                                         Qt::KeepAspectRatio, Qt::SmoothTransformation);
    }
    setPixmap(pixmap);
    setTransformOriginPoint(boundingRect().center());
}


void Meteor::Update(float dt)
{
    if(pos().y() > scene()->height())
    {
        Destroy();
    }

    setPos(pos() + QPointF(0, speed * dt));
    m_totalTime += dt;

    qreal targetAngle = qRadiansToDegrees(m_totalTime * m_rotSpeed);
    setRotation(targetAngle);
}
