#include "binsearch.h"

void BinSearch::binsearch(QVector<int> &arr,
                          int digit,
                          QVector<QGraphicsRectItem *> &rects,
                          QGraphicsScene *scene,
                          int msleepTime)
{
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Обновляем цвет прямоугольников
        rects[left]->setBrush(Qt::red);
        rects[right]->setBrush(Qt::red);
        rects[mid]->setBrush(Qt::red);
        scene->update();
        QApplication::processEvents();
        QThread::msleep(msleepTime);

        if (arr[mid] == digit) {
            // Нашли искомый элемент
            rects[mid]->setBrush(Qt::green);
            scene->update();
            QApplication::processEvents();
            return;
        }

        // Восстанавливаем цвет прямоугольников
        rects[left]->setBrush(Qt::gray);
        rects[right]->setBrush(Qt::gray);
        rects[mid]->setBrush(Qt::gray);
        scene->update();
        QApplication::processEvents();

        if (arr[mid] < digit) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // Если мы здесь, значит, искомый элемент не найден
    for (int i = 0; i < arr.size(); i++) {
        rects[i]->setBrush(Qt::gray);
    }
    scene->update();
    QApplication::processEvents();
}
