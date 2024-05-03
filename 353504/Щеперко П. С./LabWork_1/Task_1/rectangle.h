#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QGraphicsItem>
#include <QSize>

class Rectangle : public QWidget
{
    Q_OBJECT
public:
    Rectangle(QWidget* parent = nullptr);
    void moveLeft();
    void moveRight();
protected:
    void paintEvent(QPaintEvent *) override;
private:
    int x_;
};

#endif // RECTANGLE_H
