#ifndef WINDOW_H
#define WINDOW_H

#include "MovingRectangle.h"

class Window : public MovingRectangle
{
public:
    Window(QWidget *parent = nullptr);
    bool isOpenWin;
    void togglew();
protected:
    void paintEvent(QPaintEvent *) override;
    void paintEvent1(QPaintEvent *);
};


#endif // WINDOW_H
