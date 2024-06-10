#pragma once

#include <QtWidgets>
#include "rect.h"

class carView : public QWidget, private Rect {
public:
    explicit carView(QWidget *pobj = nullptr);
protected:
    void paintEvent(QPaintEvent* pe) override;
private slots:
    void animate();
private:
    QPointF *f = new QPointF;
    bool doorsOpen = false; // переменная для состояния дверей
    bool lightsOn = false; // переменная для состояния фар
};
