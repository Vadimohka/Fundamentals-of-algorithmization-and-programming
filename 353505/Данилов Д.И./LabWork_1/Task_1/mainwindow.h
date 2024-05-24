#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QGraphicsItemGroup>
#include <QGraphicsEllipseItem>
#include <QTimer>
#include <QPushButton>
#include <QLineEdit>

class MovingWheel : public QObject, public QGraphicsItemGroup {
    Q_OBJECT
public:
    MovingWheel(QGraphicsItem* parent = nullptr);

public slots:
    void rotate();
    void togglePause();
    void increaseSpeed();
    void decreaseSpeed();
    void updateSpeedDisplay();

public:
    int speed;
    QLineEdit* speedDisplay;
    QPushButton* pauseButton;

private:
    QGraphicsEllipseItem* tire;
    QGraphicsEllipseItem* wheel;
    QTimer* timer;
    bool paused;
};

#endif // MAINWINDOW_H
