#include "sorter.h"
#include <qapplication.h>
#include <qbrush.h>
#include <qcontainerfwd.h>
#include <qcoreapplication.h>
#include <qgraphicsscene.h>
#include <qnamespace.h>
#include <qpalette.h>
#include <qpen.h>
#include <qpoint.h>
#include <qthread.h>
#include <algorithm>


int Sorter::speed = 0;

void Sorter::setSpeed(int speed) { speed = 100 - speed * 10; }

double Sorter::interpolationSort(QVector<int> *array, QGraphicsScene *scene) {
    int size = array->size();
    
    int min = *std::min_element(array->begin(), array->end());
    int max = *std::max_element(array->begin(), array->end());

    if (min != max) {
        QVector<QVector<int>> bucket(size);
        int interpolation = 0;
        for (int i = 0; i < size; ++i) {
            interpolation = std::floor((((*array)[i] - min) / static_cast<double>(max - min)) * (size - 1));
            bucket[interpolation].push_back((*array)[i]);
        }

        int index = 0;
        for (int i = 0; i < size; ++i) {
            if (bucket[i].size() > 1) {
                interpolationSort(&bucket[i], scene);
            }
            for (int elem : bucket[i]) {
                (*array)[index++] = elem;
                visualize(array, scene, index - 1);
            }
        }
    }

    return 0;
}

int Sorter::binarySearch(QVector<int> *array, QGraphicsScene *scene, int target) {
    int left = 0;
    int right = array->size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        visualize(array, scene, -1, -1, mid);

        if (array->at(mid) == target) {
            return mid;
        } else if (array->at(mid) < target) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }

    return -1;
}

void Sorter::visualize(QVector<int> *array, QGraphicsScene *scene, int swap_i, int swap_j, int mid){
    double scene_W = 914;
    double scene_H = 410;

    double column_W = scene_W / array->size();
    int max = *std::max_element(array->begin(), array->end());
    double k = (double)scene_H / (double)max;

    scene->clear();
    for (int i = 0; i < array->size(); i++) {
        double column_H = array->at(i) * k;
        double x = -(scene_W / 2) + (i * column_W);
        double y = -(scene_H / 2) + (scene_H - column_H);

        QGraphicsRectItem *columnItem = new QGraphicsRectItem;

        columnItem->setRect(QRectF(0, 0, column_W, column_H ));
        columnItem->setPos(x, y);
        columnItem->setPen(QPen(Qt::black, 1));
        
        if (i == swap_i || i == swap_j) {
            columnItem->setBrush(Qt::red);
        } else if (i == mid) {
            columnItem->setBrush(Qt::blue);
        } else {
            columnItem->setBrush(Qt::white);
        }

        scene->addItem(columnItem);
    }

    QThread::msleep(speed);
    QCoreApplication::processEvents();
}

long long Sorter::binpow(int digit, int power, int mod){
    if (power == 0)
        return 1;

    if (power % 2 == 1)
        return (binpow(digit, power - 1, mod) * digit) % mod;
    else
        return (binpow(digit, power / 2, mod) * binpow(digit, power / 2, mod)) % mod;
}