//
// Created by dmitry on 10.2.24.
//

#ifndef FIRST_FLAG_H
#define FIRST_FLAG_H
#include <QWidget>
#include <QPainter>
#include <QPushButton>
#include <QTimer>
#include <QVBoxLayout>

class Flag :
        public QWidget
{
    Q_OBJECT;
public:
    Flag(QWidget *parent = nullptr);
    ~Flag();
    int ypos1 = 30, ypos2 = 50, ypos3 = 70;
    QTimer *upTimer;
    QTimer *downTimer;

    signals:
    void isDown();
    void isUp();
protected:
    void paintEvent(QPaintEvent *event) override;

public slots:
    void timerSlotUp();
    void timerSlotDown();
    void repaintUpp();
    void repaintDown();
};



#endif //FIRST_FLAG_H
