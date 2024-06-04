#ifndef VISUALVECTOR_H
#define VISUALVECTOR_H

#include <QVector>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QGraphicsRectItem>
#include <QDebug>
#include <vector>
#include <QThread>
#include <QTime>
#include <QEventLoop>
#include <QTimer>
#include <QElapsedTimer>
#include <QApplication>
#include <QCoreApplication>
class VisualVector : public QObject
{
   Q_OBJECT
public:
    VisualVector(QGraphicsScene* scene);
    void SetSize(const int n);
    void FillArray();
    void Show();
    void QuickSort(const int left, const int right);
    void MergeSort(const int left, const int right);
    void HeapSort();
    int BinSearch(int n);
    static int op;
    
    const QVector<int>& GetArray();
    int size = 100;
    int GetSize();
private:

    void SetRect(int h, int pos);
    void UnderLine(int index);
   
    void Swap(int index1, int index2);
    void heapify(int n, int i);
    double rectWidth;
    QVector<int> array;
    QVector<QGraphicsRectItem*> visual;
    QGraphicsScene* scene;
    int delay = 50;


};

#endif // VISUALVECTOR_H
