#ifndef CIRCLE_H
#define CIRCLE_H

#pragma once
#include<QWidget>

class Circle : public QWidget {
protected:
    qreal x;
    qreal y;
    qreal r;

public:
    explicit Circle(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event) override;
    void draw(QPainter *painter);
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // CIRCLE_H
