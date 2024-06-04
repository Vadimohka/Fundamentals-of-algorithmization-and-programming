#ifndef UFLOID_H
#define UFLOID_H
#include <QVector>
#include <QString>
#include <iostream>
#include <limits>
#include <QDebug>

class UFloid
{
public:
    UFloid();
    void initializeNext(const QVector<QVector<int> > &graph, QVector<QVector<int> > &next);
    void floydWarshall(const QVector<QVector<int> > &graph, QVector<QVector<int> > &dist, QVector<QVector<int> > &next);
    // QVector<int> getPath(const QVector<QVector<int> > &next, int i, int j);
    void printDistances(const QVector<QVector<int> > &dist);
    QVector<int> getPath(const QVector<QVector<int> > &next, int start, int end);
private:
    const int INF  = std::numeric_limits<int>::max();

};

#endif // UFLOID_H
