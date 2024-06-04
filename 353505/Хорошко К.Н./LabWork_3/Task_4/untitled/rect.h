#ifndef RECT_H
#define RECT_H

#include <QObject>
#include <QGraphicsItem>
#include <QColor>
#include <QRandomGenerator>
#include <QPainter>
#include <QWidget>

class Rect : public QWidget
{
    Q_OBJECT
public:
    Rect(int x, int y, int w, int h);
    void paintEvent(QPaintEvent *event) override;
    QColor randomColor();
    void setSize(int x, int y, int w, int h);
    int X();
    int Y();
    int W();
    int H();

private:
    int x;
    int y;
    int w;
    int h;
    QColor myColor;
};

#endif // RECT_H
