#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QApplication>
#include <QGraphicsObject>
#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QTimer>
#include <QKeyEvent>

class HEROE : public QObject, public QGraphicsItem {
    Q_OBJECT
public:
    explicit HEROE(QObject *parent = 0);
    ~HEROE();
        QKeyEvent* currentKeyEvent = 0;

signals:
    void keyPressed(QKeyEvent *event);
        void signalCheckItem(QGraphicsItem *item);

public slots:

    void keyPressEvent(QKeyEvent *e);
        void mySlot();


protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    qreal angle;
    int steps;
    int countForSteps;
};

#endif // PLAYER_H
