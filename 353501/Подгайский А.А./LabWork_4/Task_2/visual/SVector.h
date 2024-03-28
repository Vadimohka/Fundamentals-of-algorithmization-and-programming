#ifndef SVECTOR
#define SVECTOR

#include <QVector>
#include <QObject>


class SVector :  public QObject, public QVector<long> {
    Q_OBJECT


public:
    SVector() = default;
    SVector(const SVector& vect);
    SVector(const SVector& vect, size_t beg, size_t end);

    void sigSet(size_t i, long val);
    void sigSwap(size_t i, size_t j);
    long  operator[] (size_t i) const;
    long&  operator[] (size_t i);

signals:
    void elementChanged(size_t);
    
};

#endif