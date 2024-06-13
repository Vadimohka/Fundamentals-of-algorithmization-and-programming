#include "sortvisualizer.h"
#include <sort.h>
#include <mainwindow.h>
#include <sorttheard.h>
#include <ui_mainwindow.h>
#include <QGraphicsScene>
#include <magicnumbers.h>

SortVisualizer::SortVisualizer(QGraphicsView* view, QWidget *parent) : QGraphicsView(parent),
    view(view), scene(new QGraphicsScene(this))
{
    view->setScene(scene);
}

void SortVisualizer::visualizeSort(int* arr, int size)
{
    drawArray(arr, size);
    SortThread* sortThread = new SortThread(arr, size);
    connect(sortThread, SIGNAL(arrayUpdated(int* , int)), this, SLOT(updateArray(int* , int)));
    sortThread->start();
}

void SortVisualizer::drawArray(int* arr, int size)
{
    view->setSceneRect(0, 0, view->width() - 3 , view->height() - SIZE_SCENE);

    clearScene();
    int barWidth = view->width() / size;

    for(int i = 0; i < size; i++)
    {
        QGraphicsRectItem* bar = new QGraphicsRectItem(i * barWidth, view->height() - arr[i], barWidth, arr[i]);

        bar->setBrush(QBrush(Qt::black));
        bars.push_back(bar);
        scene->addItem(bar);
    }
}

void SortVisualizer::clearScene()
{
    view->scene()->clear();
    bars.clear();
    view->scene()->update();
}

void SortVisualizer::shuffle(int* arr, int size)
{
    for(int i{}; i< size; ++i){
        arr[i] = QRandomGenerator::global()->bounded(0, MAX_ELEMENT);
    }
    for(int i{} ; i < size; ++i){
        qSwap(arr[i], arr[QRandomGenerator::global()->bounded(0, size)]);
    }
}

void SortVisualizer::updateArray(int* arr,int size)
{
    for (int i = 0; i < size; i++)
    {
        qreal barWidth = bars[i]->rect().width();
        bars[i]->setRect(i * barWidth, view->height(), barWidth, -arr[i]);
        scene->update();
    }
    scene->update();
}

void SortVisualizer::binarySearch(int* arr, int size, int target)
{
    int left = 0;
    int right = size - 1;
    int mid{};
    int foundIndex = -1;

    while (left <= right && foundIndex == -1) {
        mid = left + (right - left) / 2;
        MainWindow::skip(SKIP);
        QGraphicsRectItem* midBar = bars[mid];
        midBar->setBrush(QBrush(Qt::red));
        scene->update();

        if (arr[mid] == target) {
            foundIndex = mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    drawArray(arr,size);
    if (foundIndex != -1) {
        QGraphicsRectItem* foundBar = bars[foundIndex];
        foundBar->setBrush(QBrush(Qt::green));
        scene->update();
        QMessageBox::about(nullptr, "Find element in binary pow equals: ", QString::number(binpow(foundIndex, SIZE, arr[foundIndex])));
    }
    else if(foundIndex == -1){
        QMessageBox::about(nullptr, "Don't find", "No number you find on array");
    }
}
void SortVisualizer::interpolationSearch(int* arr, int size, int target)
{
    int left = 0;
    int right = size - 1;
    int foundIndex = -1;

    while (left <= right && foundIndex == -1) {
        int range = arr[right] - arr[left];
        if (range == 0) {
            if (arr[left] == target){
                foundIndex = left;
            }
            break;
        }

        int pos = left + ((target - arr[left]) * (right - left)) / range;
        MainWindow::skip(SKIP*3);
        QGraphicsRectItem* posBar = bars[pos];
        posBar->setBrush(QBrush(Qt::red));
        scene->update();

        if (arr[pos] == target) {
            foundIndex = pos;
        }
        else if (arr[pos] < target) {
            left = pos + 1;
        }
        else {
            right = pos - 1;
        }
    }

    drawArray(arr, size);
    if (foundIndex != -1) {
        QGraphicsRectItem* foundBar = bars[foundIndex];
        foundBar->setBrush(QBrush(Qt::green));
        scene->update();
         QMessageBox::about(nullptr, "Find element in binary pow equals: ", QString::number(binpow(foundIndex, SIZE, arr[foundIndex])));
    } else {
        QMessageBox::about(nullptr, "Don't find", "No number you find in the array");
    }
}
