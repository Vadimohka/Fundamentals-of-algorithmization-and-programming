#pragma once

#include <QWidget>
#include <QSlider>
#include <QLabel>
#include <QGraphicsItem>

class Slider : public QWidget {

    Q_OBJECT

public:
    Slider(QWidget *parent = 0);

private:
    QSlider *sldr;
    QLabel *label;
};
