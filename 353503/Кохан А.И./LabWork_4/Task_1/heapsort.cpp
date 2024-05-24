#include "heapsort.h"

void HeapSort::heapSort(QVector<int> &arr,
                        QVector<QGraphicsRectItem *> &rects,
                        QVector<QGraphicsTextItem *> &textNumbers,
                        int sceneHeight,
                        int maxNumber,
                        int sceneWidth,
                        int msleepTime,
                        QGraphicsScene *scene)
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, rects, textNumbers, sceneHeight, maxNumber, sceneWidth, msleepTime, scene, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        std::swap(rects[0], rects[i]);
        std::swap(textNumbers[0], textNumbers[i]);
        updateRectsAndText(arr, rects, textNumbers, sceneHeight, maxNumber, sceneWidth, 0, i);

        heapify(arr, rects, textNumbers, sceneHeight, maxNumber, sceneWidth, msleepTime, scene, i, 0);
    }
}

void HeapSort::heapify(QVector<int> &arr,
                       QVector<QGraphicsRectItem *> &rects,
                       QVector<QGraphicsTextItem *> &textNumbers,
                       int sceneHeight,
                       int maxNumber,
                       int sceneWidth,
                       int msleepTime,
                       QGraphicsScene *scene,
                       int n,
                       int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        rects[i]->setBrush(Qt::red);
        rects[largest]->setBrush(Qt::red);
        scene->update();
        QApplication::processEvents();
        QThread::msleep(msleepTime);

        std::swap(arr[i], arr[largest]);
        std::swap(rects[i], rects[largest]);
        std::swap(textNumbers[i], textNumbers[largest]);
        updateRectsAndText(arr, rects, textNumbers, sceneHeight, maxNumber, sceneWidth, i, largest);

        scene->update();
        QApplication::processEvents();
        QThread::msleep(msleepTime);

        rects[i]->setBrush(Qt::gray);
        rects[largest]->setBrush(Qt::gray);
        scene->update();
        QApplication::processEvents();
        QThread::msleep(msleepTime);

        heapify(arr,
                rects,
                textNumbers,
                sceneHeight,
                maxNumber,
                sceneWidth,
                msleepTime,
                scene,
                n,
                largest);
    }
}

void HeapSort::updateRectsAndText(QVector<int> &arr,
                                  QVector<QGraphicsRectItem *> &rects,
                                  QVector<QGraphicsTextItem *> &textNumbers,
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
    textNumbers[i]->setPos(rects[i]->rect().center() - textNumbers[i]->boundingRect().center());
    textNumbers[j]->setPos(rects[j]->rect().center() - textNumbers[j]->boundingRect().center());
}
