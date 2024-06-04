#ifndef RECT_H
#define RECT_H
#include<QGraphicsRectItem>
class recta : public QGraphicsRectItem
{
private:
    int x=0;
    int y=0;
    int h=0;
    int w=0;
public:
    recta(int,int,int,int);
    QGraphicsRectItem create(int,int);
};

#endif // RECT_H
