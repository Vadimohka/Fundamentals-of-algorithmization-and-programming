#include "mergesort.h"

void MergeSort::mergeSort(QVector<int> &arr,
                          QVector<QGraphicsRectItem *> &rects,
                          int sceneHeight,
                          int maxNumber,
                          int sceneWidth,
                          int msleepTime,
                          QGraphicsScene *scene,
                          int l,
                          int r)
{
    if (l >= r) {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, rects, sceneHeight, maxNumber, sceneWidth, msleepTime, scene, l, m);
    mergeSort(arr, rects, sceneHeight, maxNumber, sceneWidth, msleepTime, scene, m + 1, r);
    merge(arr, rects, sceneHeight, maxNumber, sceneWidth, msleepTime, scene, l, m, r);
}

void MergeSort::merge(QVector<int> &arr,
                      QVector<QGraphicsRectItem *> &rects,
                      int sceneHeight,
                      int maxNumber,
                      int sceneWidth,
                      int msleepTime,
                      QGraphicsScene *scene,
                      int l,
                      int m,
                      int r)
{
    int i = 0, j = 0, k = 0;
    int n1 = m - l + 1;
    int n2 = r - m;

    QVector<int> L(n1), R(n2);

    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        rects[k]->setBrush(Qt::red);
        scene->update();
        QApplication::processEvents();
        QThread::msleep(msleepTime);

        updateRectsAndText(arr, rects, sceneHeight, maxNumber, sceneWidth, k, k);

        rects[k]->setBrush(Qt::gray);
        scene->update();
        QApplication::processEvents();
        QThread::msleep(msleepTime);

        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    for (int i = l; i <= r; i++) {
        updateRectsAndText(arr, rects, sceneHeight, maxNumber, sceneWidth, i, i);
        rects[i]->setBrush(Qt::gray);
        scene->update();
        QApplication::processEvents();
        QThread::msleep(msleepTime);
    }
}

void MergeSort::updateRectsAndText(QVector<int> &arr,
                                   QVector<QGraphicsRectItem *> &rects,
                                   int sceneHeight,
                                   int maxNumber,
                                   int sceneWidth,
                                   int i,
                                   int j)
{
    int rectHeightI = (arr[i] * sceneHeight / maxNumber);
    int rectHeightJ = (arr[j] * sceneHeight / maxNumber);
    int rectWidth = sceneWidth / arr.size();

    rects[i]->setRect(i * rectWidth, sceneHeight - rectHeightI, rectWidth, rectHeightI);
    rects[j]->setRect(j * rectWidth, sceneHeight - rectHeightJ, rectWidth, rectHeightJ);
}
