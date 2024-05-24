#include "quicksort.h"

void QuickSort::quickSort(QVector<int> &arr,
                          QVector<QGraphicsRectItem *> &rects,
                          QVector<QGraphicsTextItem *> &textNumbers,
                          int sceneHeight,
                          int maxNumber,
                          int sceneWidth,
                          int msleepTime,
                          QGraphicsScene *scene,
                          int low,
                          int high)
{
    if (low < high) {
        int pi = partition(arr,
                           rects,
                           textNumbers,
                           sceneHeight,
                           maxNumber,
                           sceneWidth,
                           msleepTime,
                           scene,
                           low,
                           high);
        quickSort(arr,
                  rects,
                  textNumbers,
                  sceneHeight,
                  maxNumber,
                  sceneWidth,
                  msleepTime,
                  scene,
                  low,
                  pi - 1);
        quickSort(arr,
                  rects,
                  textNumbers,
                  sceneHeight,
                  maxNumber,
                  sceneWidth,
                  msleepTime,
                  scene,
                  pi + 1,
                  high);
    }
}

int QuickSort::partition(QVector<int> &arr,
                         QVector<QGraphicsRectItem *> &rects,
                         QVector<QGraphicsTextItem *> &textNumbers,
                         int sceneHeight,
                         int maxNumber,
                         int sceneWidth,
                         int msleepTime,
                         QGraphicsScene *scene,
                         int low,
                         int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    rects[high]->setBrush(Qt::blue); // Опорный элемент подсвечивается синим цветом
    scene->update();
    QApplication::processEvents();
    QThread::msleep(msleepTime);

    for (int j = low; j <= high - 1; j++) {
        rects[j]->setBrush(Qt::red);
        scene->update();
        QApplication::processEvents();
        QThread::msleep(msleepTime);

        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
            std::swap(rects[i], rects[j]);
            std::swap(textNumbers[i], textNumbers[j]);
            updateRectsAndText(arr, rects, textNumbers, sceneHeight, maxNumber, sceneWidth, i, j);
        }

        rects[j]->setBrush(Qt::gray);
        scene->update();
        QApplication::processEvents();
        QThread::msleep(msleepTime);
    }

    std::swap(arr[i + 1], arr[high]);
    std::swap(rects[i + 1], rects[high]);
    std::swap(textNumbers[i + 1], textNumbers[high]);
    updateRectsAndText(arr, rects, textNumbers, sceneHeight, maxNumber, sceneWidth, i + 1, high);

    rects[high]->setBrush(Qt::gray); // Возвращаем опорному элементу исходный цвет
    scene->update();
    QApplication::processEvents();
    QThread::msleep(msleepTime);

    return (i + 1);
}

void QuickSort::updateRectsAndText(QVector<int> &arr,
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
