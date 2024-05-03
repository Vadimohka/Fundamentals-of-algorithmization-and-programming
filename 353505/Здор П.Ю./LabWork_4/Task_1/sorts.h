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
    void sorting_q(QVector <QGraphicsRectItem*>,double *,int,int,QGraphicsView*,QGraphicsScene*);

    int partition(QVector <QGraphicsRectItem*>,double*,int,int,double,QGraphicsView*,QGraphicsScene*);
  //  void heap_sort();
    //void merge_sort();
};

#endif // SORTS_H
