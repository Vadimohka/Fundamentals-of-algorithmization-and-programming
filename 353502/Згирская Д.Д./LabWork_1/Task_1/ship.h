#ifndef SHIP_H
#define SHIP_H

#include <QWidget>
#include <QPainter>
#include <QPoint>

class Ship : public QWidget
{
    Q_OBJECT

public:
    explicit Ship(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);

signals:
};

#endif // SHIP_H
