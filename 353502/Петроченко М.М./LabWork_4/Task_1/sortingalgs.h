//
// Created by acryoz on 6.4.24.
//

#ifndef LAB4_SRC_SORTINGALGS_H_
#define LAB4_SRC_SORTINGALGS_H_

#include <QObject>
#include <QTextStream>

class Sorting : public QObject {
    Q_OBJECT
   public:
    Sorting();
    void quickSort(int*, int, int);
    void heapSort(int*, int);
    void mergeSort(int*, int, int);
    void interpolationSort(QVector<int>&);
    void clear();
    QVector<int> kthOrder(QVector<int>&, int, int);
    QString getLogs();
    QVector<QVector<int>> splitInMs(QVector<int>&, int);
   signals:
    void changed(int from, int to);

   private:
    void toArr(QVector<int>, int*);
    void heapify(int*, int, int);
    void buildHeap(int*, int);
    void merge(int*, int, int, int);
    int partition(int*, int, int);
    int partition(QVector<int>&, int, int);
    void print(int*, int);
    int interpolation_step = 1;
    QString interpolation_sort_log;
    QTextStream* text_stream;
};
#endif  //LAB4_SRC_SORTINGALGS_H_
