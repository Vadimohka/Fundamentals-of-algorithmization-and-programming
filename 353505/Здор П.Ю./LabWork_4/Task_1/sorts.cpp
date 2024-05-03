#include "sorts.h"

int SortS::partition( QVector <QGraphicsRectItem*> t1,double *a,int low, int high, double pivot, QGraphicsView* graphicsView,QGraphicsScene* scene){
    i1 = low;
    j1 = low;
    while( i1 <= high){
        if(a[i1] > pivot){
            i1++;
        }
        else{
            std::swap(a[i1],a[j1]);

            if(j1!=i1){
                QGraphicsRectItem *cc=new QGraphicsRectItem;
                cc=t1[i1];
                t1[i1]->setPos(t1[j1]->pos().x()-std::abs(j1-i1)*10,t1[i1]->pos().y());
                t1[j1]->setPos(t1[j1]->pos().x()+std::abs(j1-i1)*10,t1[j1]->pos().y());
                cc=t1[i1];
                t1[i1]=t1[j1];
                t1[j1]=cc;
                scene->update();
                scene->update();
                scene->update();
                //timer->stop();



            }
            i1++;
            j1++;
        }
    }
    scene->update();
    return j1-1;
}
void SortS::sorting_q(QVector <QGraphicsRectItem*> t1,double *a,int left,int right, QGraphicsView* graphicsView,QGraphicsScene* scene){

    if(left < right){
        double pvt = a[right];
        int pos = partition(t1,a,left, right, pvt,graphicsView,scene);
       // graphicsView->viewport()->repaint();

        sorting_q(t1,a, left, pos-1,graphicsView,scene);

        sorting_q(t1,a, pos+1, right,graphicsView,scene);


    }


}
