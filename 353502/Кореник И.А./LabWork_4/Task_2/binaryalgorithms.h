#ifndef BINARYALGORITHMS_H
#define BINARYALGORITHMS_H
#include <QVector>
#include <QHBoxLayout>
#include "numbervisual.h"
#include "QCoreApplication"
#include <QThread>
class BinaryAlgorithms
{
public:
    BinaryAlgorithms();

    static int binSearch(QVector<int>*a, int num, QHBoxLayout* arrayVisualization = nullptr);

    static long long binPow(int a, int n, int p);
};

#endif // BINARYALGORITHMS_H
