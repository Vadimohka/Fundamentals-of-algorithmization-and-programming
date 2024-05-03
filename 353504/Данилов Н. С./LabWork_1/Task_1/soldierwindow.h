#pragma once

#include <QtWidgets>
#include "figurewindow.h"

class soldierWindow :  public figureWindow{
public:
    explicit soldierWindow(QWidget *pobj = nullptr);
protected:
    void paintEvent(QPaintEvent* pe);
private:
    QPointF *f = new QPointF;
};
