#ifndef SORTER_H
#define SORTER_H

#include <QGraphicsRectItem>
#include <QtSwap>
#include <QPainter>
#include <QEventLoop>
#include <QTimer>

class Sorter : public QGraphicsRectItem
{
public:
    Sorter(std::vector<int> &arr);
    std::vector<int> _arr;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    void interpolationSort(std::vector<int> &arr);
    void interpolationSort();
    QEventLoop loop;
    unsigned long long binpow(unsigned long long k, unsigned long long n, unsigned long long m);
    int binSearch(int n, int find);
};

#endif // SORTER_H
