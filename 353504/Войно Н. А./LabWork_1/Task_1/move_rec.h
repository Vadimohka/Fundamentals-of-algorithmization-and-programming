#ifndef MOVE_REC_H
#define MOVE_REC_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QPropertyAnimation>
#include <QGraphicsItem>

class Move_rec: public QWidget {
    Q_OBJECT
public:
    Move_rec(QWidget* parent = nullptr);
    void left(int distance, int duration);
    void right(int distance, int duration);
protected:
    void paintEvent(QPaintEvent*) override;
};

#endif // MOVE_REC_H
