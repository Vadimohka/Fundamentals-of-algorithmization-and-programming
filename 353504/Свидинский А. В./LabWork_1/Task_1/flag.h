#ifndef FLAG_H
#define FLAG_H

#include <QMainWindow>
#include <QWidget>
#include "movingrectangle.h"

class Flag : public MovingRectangle
{
    Q_OBJECT
public:
    Flag(QWidget *parent = nullptr);
    void raiseFlag();
    void lowerFlag();
protected:
    void paintEvent(QPaintEvent *) override;
};

#endif // FLAG_H
