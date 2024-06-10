#ifndef COIN_H
#define COIN_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>

class Coin : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Coin(QObject *parent = 0);
    ~Coin();

signals:

public slots:

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int color;
};


#endif // COIN_H
