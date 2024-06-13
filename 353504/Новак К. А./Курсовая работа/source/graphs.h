#ifndef GRAPHS_H
#define GRAPHS_H

class Coords {
public:
    int x;
    int y;
};

class Graph {
public:
    Graph(int capacity, int coords[])
    {
        this->capacity = capacity;
        for (int i = 0, j = 0; i < capacity * 2; ++i, ++j)
        {
            vertexCoord[i].x = coords[j];
            ++j;
            vertexCoord[i].y = coords[j];
        }
    }
    int r = 100;
    int capacity;
    Coords vertexCoord[12];
};




#endif // GRAPHS_H
