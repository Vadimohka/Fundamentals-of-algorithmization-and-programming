#ifndef GRAPH_H
#define GRAPH_H

#include<QPainter>
#include<QApplication>
#include<vector>
#include<QThread>

class Graph
{
public:
    Graph(int *a,long long size);
    Graph();
    void draw(QPainter *p);
    void set(std::vector<int>a);
    void paint(int l, int r, int m);
    void paint(int ind);
private:
    std::vector<int>b;
    int *color=nullptr;
    long long max_element,min_element;
    long double scale;
    bool not_to_draw;
    const short max_height=430-2,max_weight=1700-2; // -2 for some boundaries of our graph
};

#endif // GRAPH_H
