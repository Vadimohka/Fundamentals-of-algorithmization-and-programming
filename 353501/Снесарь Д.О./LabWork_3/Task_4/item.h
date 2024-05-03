#ifndef ITEM_H
#define ITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include <QObject>
#include <QTimer>
#include <QDebug>
class Item:  public QObject, public QGraphicsItem
{
Q_OBJECT
public:

    Item(long double x,long double y,long double w,long double h, int number);

    void mB(int n);
    void mC(int n);
    void mA(int n);
private:

    const int difcord = 10;
    int num;
    int n;
    void up();
    double h;
    double w;
    QTimer* timer;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const override;
    void mup();
    void md(int n);
    void ml(double x);
    void mr(double x);
private slots:
    void mDown();
    void lA();
    void rB();
    void lB();
    void rC();
signals:
    void mdFinished();
    void mlFinished();
    void mupFinished();
    void mrFinished();
    void mCFinished();
    void mBFinished();
    void mAFinished();

};

#endif // ITEM_H
