#ifndef MOVINGRECTANGLE_H
#define MOVINGRECTANGLE_H

#include <QWidget>
#include <QPainter>
#include <QRect>
#include <QPoint>
#include <QApplication>
#include <QTimer>

class MovingRectangle : public QWidget
{
    Q_OBJECT
public:
    explicit MovingRectangle(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent * event) override;

protected slots:
    void MoveRectangle();

    void StopMove();

    void Up();
protected:
    QTimer *timer = new QTimer;
};

#endif // MOVINGRECTANGLE_H
