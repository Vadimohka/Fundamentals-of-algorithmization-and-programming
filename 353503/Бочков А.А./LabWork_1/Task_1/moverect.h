#ifndef MOVERECT_H
#define MOVERECT_H

class moverect
{
protected:
    int x,y,width,height;
public:
    int gety();
    void set(int, int, int, int);
    void movedown();
    void moveup();
};

#endif // MOVERECT_H
