// custom.h
#ifndef CUSTOM_H
#define CUSTOM_H

#include "shape.h"
class Custom : public Shape
{
public:
    Custom();
    ~Custom();
    int drawMode;
    void mouseMoving(QMouseEvent *p)override;
    void paint(QPainter *p) override;
    void clearPoints();
    void brushComboBox(QWidget *parent, QComboBox *comboBox);
    QColor color=Qt::white;
    int penWidth=3;
};

#endif // CUSTOM_H
