#ifndef MOVING_ELLIPSE_H
#define MOVING_ELLIPSE_H

#include <QWidget>
#include <QPainter>
#include <QTimer>

class MovingEllipse : public QWidget {
    Q_OBJECT

public:
    MovingEllipse(QWidget* parent = nullptr);
    void moveEllipse(int dx, int dy);

protected:
    void paintEvent(QPaintEvent* event) override;

protected:
    int x;
    int y;
    int width;
    int height;
};

#endif // MOVING_ELLIPSE_H
