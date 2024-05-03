#ifndef STAR_EIGHT_H
#define STAR_EIGHT_H


#include <QObject>
#include <QGraphicsItem>
#include <figure.h>

class Star_Eight : public Figure
{
    Q_OBJECT
public:
    explicit Star_Eight(QPointF point, QObject *parent = nullptr);
    QColor myColor = randomColor();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QVector<QPointF> points;
};

#endif // STAR_EIGHT_H
