#ifndef ENEMY_H
#define ENEMY_H
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QTimer>
#include <QDebug>

class Enemy : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Enemy(QGraphicsItem * target, QObject *parent = 0);
    ~Enemy();
    void pause();

signals:
    void signalCheckGameOver();

public slots:

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    qreal angle;
    int steps;
    int countForSteps;
    QTimer      *timer;
    QGraphicsItem * target;

private slots:
    void slotGameTimer();
};
#endif // ENEMY_H
