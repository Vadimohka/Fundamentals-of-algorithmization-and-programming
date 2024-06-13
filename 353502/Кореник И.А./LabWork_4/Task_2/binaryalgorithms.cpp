#include "binaryalgorithms.h"

BinaryAlgorithms::BinaryAlgorithms() {}

int BinaryAlgorithms::binSearch(QVector<int> *a, int num, QHBoxLayout* arrayVisualization)
{
    int l = 0;
    int r = a->size() - 1;
    int mid = (l + r) / 2;

    while(r - l > 1){
        if (a->at(mid) > num)
            r = mid;
        else
            l = mid;
        mid = (r + l) / 2;
        if (arrayVisualization != nullptr){
            qobject_cast<NumberVisual*>(arrayVisualization->itemAt(mid)->widget())->setColor(Qt::red);
            QCoreApplication::processEvents();
            QThread::msleep(300);
            qobject_cast<NumberVisual*>(arrayVisualization->itemAt(mid)->widget())->setColor(Qt::green);
        }
    }

    if (a->at(l) == num) return l;

    return -1;
}

long long BinaryAlgorithms::binPow(int a, int n, int p)
{
    if (n == 0) return 1;

    long long res = binPow(a, n / 2, p);

    if (n % 2 == 0) return res * res % p;

    return res * res % p * a % p;
}
