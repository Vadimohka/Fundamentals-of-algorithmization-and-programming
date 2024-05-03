#ifndef GRAPH_H
#define GRAPH_H

#include<QPainter>
#include<QApplication>

class Graph
{
public:
    Graph(int *a,long long size);
    Graph();
    void draw(QPainter *p);
    void set(int *a, long long size);
    void paint(int l, int r, int m);
    void paint(int ind);
private:
    int *array=nullptr;
    int *color=nullptr;
    long long array_size,max_element,min_element;
    long double scale;
    bool not_to_draw;
    const short max_height=430-2,max_weight=1700-2; // -2 for some boundaries of our graph
};

#endif // GRAPH_H
