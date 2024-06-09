#include "sorter.h"

Sorter::Sorter(std::vector<int> &arr)
{
    _arr = arr;
}

void Sorter::interpolationSort()
{
    std::vector<int> segmentSize;
    int lastElementIndex = _arr.size() - 1;
    segmentSize.push_back(lastElementIndex);

    while (!segmentSize.empty()) {
        int currentSize = segmentSize.back();
        segmentSize.pop_back();
        int startIndex = lastElementIndex - currentSize;
        int minValue = _arr[startIndex];
        int maxValue = _arr[startIndex];

        for (int i = startIndex + 1; i < lastElementIndex; i++) {
            if (_arr[i] < minValue) {
                minValue = _arr[i];
            }
            else if (_arr[i] > maxValue) {
                maxValue = _arr[i];
            }
        }

        if (minValue == maxValue) {
            lastElementIndex -= currentSize;
        }
        else {
            int bucketIndex = 0;
            std::vector<std::vector<int>> buckets(currentSize);
            for (int i = startIndex; i < lastElementIndex; i++) {
                bucketIndex = static_cast<int>(((_arr[i] - minValue) / static_cast<double>(maxValue - minValue)) * (currentSize - 1));
                buckets[bucketIndex].push_back(_arr[i]);
            }

            for (int i = 0; i < currentSize; i++) {
                if (!buckets[i].empty()) {
                    for (int j = 0; j < buckets[i].size(); j++) {
                        _arr[startIndex++] = buckets[i][j];
                        QTimer::singleShot(100, &loop, SLOT(quit()));
                        loop.exec();
                        update();
                    }
                    segmentSize.push_back(buckets[i].size());
                }
            }
        }
    }
}

void Sorter::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setBrush(Qt::darkGreen);
    painter->setPen(Qt::black);
    for (int i = 0; i < _arr.size() - 1; ++i)
    {
        painter->drawRect(-300 + 10 * i, 250 - _arr[i], 10, _arr[i]);
    }
}

QRectF Sorter::boundingRect() const
{
    return QRectF(-300, -250, 600, 500);
}

unsigned long long Sorter::binpow(unsigned long long k, unsigned long long n, unsigned long long m) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 1) {
        return (binpow(k, n - 1, m) * k) % m;
    }
    else {
        unsigned long long b = binpow(k, n / 2, m) % m;
        return (b * b) % m;
    }
}

int Sorter::binSearch(int n, int find)
{
    int l = 0;
    int r = n - 1;
    while(l <= r)
    {
        int m = l + (r - l) / 2;
        if (find == _arr[m])
        {
            return m;
        }
        else if (find < _arr[m])
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return -1;
}
