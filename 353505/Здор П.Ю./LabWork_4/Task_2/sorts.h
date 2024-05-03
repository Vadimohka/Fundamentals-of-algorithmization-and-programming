#ifndef SORTS_H
#define SORTS_H
#include<QGraphicsRectItem>
#include<QGraphicsScene>
#include<QVector>
#include<QGraphicsView>
class SortS
{
private:
    int i1=0;
    int j1=0;
public:
    int partition( double *,int , int , double );

    void sorting_q(double *,int ,int );

};

#endif // SORTS_H
