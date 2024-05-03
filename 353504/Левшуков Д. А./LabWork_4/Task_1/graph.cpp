#include "graph.h"

Graph::Graph(int *a, long long size)
{
    set(a,size);
}

Graph::Graph()
{
    array_size=0;
}

void Graph::draw(QPainter *p)
{
    //qDebug()<<"draw1";
    if(not_to_draw)return;
    //qDebug()<<"draw2";
    long double pos=1;
    //qDebug()<<array_size<<" array:";
    QPen pen;

    for(int i=0;i<array_size;i++,pos+=3)
    {
        if(color[i]==0)
        {
            pen.setColor(Qt::white);
        }
        if(color[i]==1)//bounds
        {
            pen.setColor(Qt::green);
        }
        if(color[i]==2)//mid
        {
            pen.setColor(Qt::blue);
        }
        if(color[i]==3)//found
        {
            pen.setColor(Qt::red);
        }

        //qDebug()<<array[i];
        p->setPen(pen);
        p->drawLine(pos,1,pos,(array[i]-min_element)/scale);
    }
}

void Graph::set(int *a, long long size)
{
    array=a;
    array_size=size;


    not_to_draw=false;

    if(array_size>max_weight/3+max_weight%3)
    {
        not_to_draw=true;
        qDebug()<<"Too many elements in array ["<<array_size<<"] > "<<max_weight;
        return;
    }

    //free(color);
    color=(int *)malloc(size*sizeof(int));
    for(int i=0;i<size;i++)
    {
        color[i]=0;
    }

    max_element=a[0];
    min_element=a[0];
    for(int i=0;i<size;i++)
    {
        max_element=std::max(max_element,(long long)a[i]);
        min_element=std::min(min_element,(long long)a[i]);
    }

    scale=((long double)max_element-(long double)min_element)/(long double)max_height;
    qDebug()<<"MIN:"<<min_element<<" MAX:"<<max_element;
    qDebug()<<"SCALE: "<<std::to_string(scale);
}

void Graph::paint(int l,int r,int m)
{
    if(not_to_draw)return;
    for(int i=0;i<array_size;i++)
        color[i]=0;
    for(;l<=r;l++)
        color[l]=1;
    color[m]=2;
}
void Graph::paint(int ind)
{

    if(not_to_draw)return;
    for(int i=0;i<array_size;i++)
        color[i]=0;
    if(ind==-1488)return;
    color[ind]=3;
}

