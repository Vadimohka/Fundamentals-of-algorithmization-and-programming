#pragma once

#include <QtWidgets>
#include "rect.h"

class figureView : public QWidget, private Rect {
public:
    explicit figureView(QWidget *pobj = nullptr);
protected:
    void paintEvent(QPaintEvent* pe);

private:
    QPointF *f = new QPointF;
};
