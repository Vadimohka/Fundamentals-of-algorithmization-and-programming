#pragma once
#include <QtWidgets>
#include "mymove.h"

class figureWindow : public QWidget, public mymove
{
public:
    explicit figureWindow(QWidget *pobj = nullptr);
protected:
    void paintEvent(QPaintEvent* pe);

private:
    QPointF *f = new QPointF;
};
