#ifndef SOLVE_H
#define SOLVE_H
#include<QVector>
#include<QDebug>
class Median
{
private:
    int i1=0;
    int j1=0;
    QVector<double>a;
public:
    void solution();
    int partition( QVector<double>,int , int , double );

    void sorting_q(QVector<double>,int ,int );
};

#endif // SOLVE_H
