#ifndef MOVINGRECTANGLE_H
#define MOVINGRECTANGLE_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QPropertyAnimation>
#include <QGraphicsItem>
#include <QSize>

class MovingRectangle : public QWidget {

    Q_OBJECT
public:
    MovingRectangle(QWidget* parent = nullptr);
    void moveLeft();
    void moveRight();
protected:
    void paintEvent(QPaintEvent *) override;
private:
    QPropertyAnimation *animation;

};

#endif // MOVINGRECTANGLE_H
