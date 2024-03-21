#ifndef FIGURES_H
#define FIGURES_H
#include <QtWidgets>

class figure{

    virtual void move_figure();
    virtual void updCenter();
public:
    figure();
    virtual void reset(bool sp);
    virtual void findSquare();
    virtual void findPerimetr();
    virtual void draw(QPainter *);
    virtual void setP(QMouseEvent *);
    void SetAngle(int ang);
    void MousePressing(QMouseEvent *);
    void MouseMoving(QMouseEvent *);
    void MouseMovePressing(QMouseEvent *);
    void MouseMoveMoving(QMouseEvent *);
    void SizeEdit();
    double P=0,S=0;
    QPointF center;
    bool showpoint;
    void SizeEdit(bool Minus);
    void resize();
    virtual void DrawP(QPainter *);
    int act=0;//0-draw,1-move,2-rot,3-siz
private:
protected:
    double size=1,last_size=1;
    double degree=0;
    QVector <QPointF> points;
    QPoint MouseMoveNow,MouseMovePress,MousePress,MouseNow;

};

#endif // FIGURES_H
