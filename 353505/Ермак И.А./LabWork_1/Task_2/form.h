#ifndef FORM_H
#define FORM_H

#include <QColor>
#include <QGraphicsObject>
#include <QPainter>

class form : public QGraphicsObject
{
    Q_OBJECT
public:
    form();
    int angleDecreas();
    int angleIncreas();
public slots:
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
protected:
    int positionX;
    int positionY;
    int angle;
    QColor PenColor;
    QColor BrushColor;
};

#endif // FORM_H
