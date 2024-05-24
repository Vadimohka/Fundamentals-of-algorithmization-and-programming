#include "bubblesort.h"

void BubbleSort::bubbleSort(QVector<int> &arr,
                            QVector<QGraphicsRectItem *> &rects,
                            QVector<QGraphicsTextItem *> &textNumbers,
                            int sceneHeight,
                            int maxNumber,
                            int sceneWidth,
                            int msleepTime,
                            QGraphicsScene *scene)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            rects[j]->setBrush(Qt::red);
            rects[j + 1]->setBrush(Qt::red);
            scene->update();
            QApplication::processEvents();
            QThread::msleep(msleepTime);

            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                std::swap(rects[j], rects[j + 1]);
                std::swap(textNumbers[j], textNumbers[j + 1]);
                updateRectsAndText(arr,
                                   rects,
                                   textNumbers,
                                   sceneHeight,
                                   maxNumber,
                                   sceneWidth,
                                   j,
                                   j + 1);
            }

            rects[j]->setBrush(Qt::gray);
            rects[j + 1]->setBrush(Qt::gray);
            scene->update();
            QApplication::processEvents();
            QThread::msleep(msleepTime);
        }
    }
}

void BubbleSort::updateRectsAndText(QVector<int> &arr,
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
