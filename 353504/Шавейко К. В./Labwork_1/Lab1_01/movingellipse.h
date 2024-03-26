#ifndef MOVINGELLIPSE_H
#define MOVINGELLIPSE_H

#include <QGraphicsEllipseItem>
#include <QGraphicsObject>
#include <QObject>
#include <QPainter>
#include <QApplication>
#include <QMainWindow>
#include <QDockWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGraphicsRectItem>

class movingellipse : public QGraphicsObject
{
    Q_OBJECT
public:
    movingellipse();
    void pop();

    QRectF boundingRect() const {
        return QRectF(0, 0, 300, 500);
    }


    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // MOVINGELLIPSE_H
