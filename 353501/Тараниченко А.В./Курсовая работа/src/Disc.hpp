#ifndef DISC_HPP
#define DISC_HPP

#include <QObject>
#include <QGraphicsEllipseItem>

class Disc : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
protected:
    QPointF end_;
    bool animationHaveFinish_;

public:
    void setEnd(QPointF end);

public slots:
    void moveDisc();

signals:
    void animationHaveFinish();
};

#endif // DISC_HPP
