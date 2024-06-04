#include <QVector>
#include <qcontainerfwd.h>
#include <qgraphicsscene.h>
#include <qgraphicsitem.h>
#include <qpoint.h>
#include <qthread.h>

class Sorter{
public:
    Sorter(QVector<int> *array, QGraphicsScene *scene);

    void quickSort(int start, int end);
    void heapSort(int N);
    void mergeSort(int left, int right);

    int binarySearch(int target);

    void visualize(int swap_i = -1, int swap_j = -1, int mid = -1);
    void setSpeed(int speed);

    double getTime(int sortIndex);

private:
    QVector<int> *array;
    QGraphicsScene *scene;
    QVector<QGraphicsRectItem *> columns;
    
    double scene_W;
    double scene_H;
    int speed;

    double quickSortTime;
    double heapSortTime;
    double mergeSortTime;

    int partition(int start, int end);
    void heapify(int N, int i);
    void merge(int left, int mid, int right);
};