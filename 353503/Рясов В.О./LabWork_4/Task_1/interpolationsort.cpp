#include "interpolationsort.h"

void InterpolationSort::interpolationSort(QVector<int> &arr,
                                          QVector<QGraphicsRectItem *> &rects,
                                          int sceneHeight,
                                          int maxNumber,
                                          int sceneWidth,
                                          int msleepTime,
                                          QGraphicsScene *scene)
{
    int start = 0;
    int size = arr.size();
    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        } else if (arr[i] > max) {
            max = arr[i];
        }
    }
    if (min != max) {
        QVector<QVector<int>> bucket(size);
        int interpolation = 0;
        for (int i = 0; i < size; i++) {
            interpolation = static_cast<int>(((arr[i] - min) / (max - min)) * (size - 1));
            bucket[interpolation].push_back(arr[i]);
        }
        for (int i = 0; i < size; i++) {
            if (bucket[i].size() > 1) {
                interpolationSort(bucket[i],
                                  rects,
                                  sceneHeight,
                                  maxNumber,
                                  sceneWidth,
                                  msleepTime,
                                  scene);
            }
            for (int j : bucket[i]) {
                arr[start] = j;
                rects[start]->setBrush(Qt::red);
                scene->update();
                QApplication::processEvents();
                QThread::msleep(msleepTime);

                rects[start]->setBrush(Qt::gray);
                scene->update();
                QApplication::processEvents();
                QThread::msleep(msleepTime);

                updateRectsAndText(arr, rects, sceneHeight, maxNumber, sceneWidth, start, start);
                start++;
            }
        }
    }
}

void InterpolationSort::updateRectsAndText(QVector<int> &arr,
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
