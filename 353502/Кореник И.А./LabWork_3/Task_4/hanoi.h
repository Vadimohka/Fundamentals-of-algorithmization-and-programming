#ifndef HANOI_H
#define HANOI_H
#include <QVector>
class Hanoi
{
public:
    Hanoi(int);

    void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod);

    QVector<QString*>movements;

    void solve(int);
private:
    int n;


   // QVector<char[2]>solve(int n);




};

#endif // HANOI_H
