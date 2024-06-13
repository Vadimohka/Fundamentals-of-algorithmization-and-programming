#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <chrono>
#include <QTimer>
#include <QDebug>
#include <QDateTime>

using namespace std;

MainWindow::MainWindow()
    : ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(QRectF(0, 0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20));
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::initArray);
    connect(ui->sortButton, &QPushButton::clicked, this, &MainWindow::heap);
    connect(ui->mergeSortButton, &QPushButton::clicked, this, &MainWindow::merge_go);
    connect(ui->quickSortButton, &QPushButton::clicked, this, &MainWindow::quick);
    connect(ui->search, &QPushButton::clicked, this, &MainWindow::search);
}

void MainWindow::search(){

    int target = ui->searchSpinBox->value();
    int index = binary_search(0, size - 1, target);

    if (index != -1) {
        ui->searchLabel->setText(QString("Found at index %1").arg(index));
        visualize(-1, index);
    } else {
        ui->searchLabel->setText("Element not found");
        visualize();
    }
}

void  MainWindow::printArray (QVector<int>& arr, int n) {
    qDebug() << "Array:" << n << "elements:";
    for (int i = 0; i < n; ++i) {
        qDebug() << arr[i]<< " ";
    }
}

void MainWindow::initArray()
{
    size = ui->spinBox->value();
    array.clear();
    arrayRect.clear();

    float rectW = scene->width() / size;

    for (int i = 0; i < size; i++)
    {
        array.push_back((int)rand() % 200);
        QGraphicsRectItem *rect = new QGraphicsRectItem(rectW * i, 0, rectW, array[i] * 4);
        rect->setBrush(QBrush(Qt::white));
        arrayRect.push_back(rect);
    }
    visualize();
    ui->sortButton->show();
    ui->mergeSortButton->show();
    ui->quickSortButton->show();
    ui->search->show();
    isSorted = false;
    printArray(array, size);
}

void MainWindow::visualize(int ind1toSwap, int ind2toSwap)
{
    scene->clear();

    // вычисляем максимальную высоту прямоугольников
    int maxHeight = 0;
    for (int i = 0; i < array.size(); i++) {
        if (array[i] > maxHeight) {
            maxHeight = array[i];
        }
    }

    const int heightScale = 3;

    // рассчитываем ширину каждого прямоугольника
    int rectWidth = scene->width() / array.size();

    // отрисовываем прямоугольники
    for (int i = 0; i < array.size(); i++) {
        QGraphicsRectItem* rect = new QGraphicsRectItem(i * rectWidth, scene->height() - array[i] * heightScale, rectWidth, array[i] * heightScale);

        if ((ind1toSwap != -1 && i == ind1toSwap) || (ind2toSwap != -1 && i == ind2toSwap)) {
            int hue = (i * 360 / array.size() + QTime::currentTime().msec()) % 360;
            rect->setBrush(QColor::fromHsv(hue, 255, 255));
        } else {
            rect->setBrush(Qt::white);
        }

        scene->addItem(rect);

        // текст с значением элемента массива
        QGraphicsTextItem* textItem = new QGraphicsTextItem(QString::number(array[i]));
        textItem->setPos(i * rectWidth, scene->height() - array[i] * heightScale - 20);
        scene->addItem(textItem);
    }

    QEventLoop loop;
    QTimer::singleShot(50, &loop, &QEventLoop::quit);
    loop.exec();
    scene->update();
}


void MainWindow::heapify(QVector<int> &arr, int N, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int r = 2 * i + 2;
    if (left < N && arr[left] > arr[largest])
        largest = left;
    if (r < N && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        visualize(i, largest);

        MainWindow::heapify(arr, N, largest);
    }
}

void MainWindow::heap_sort()
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);
    for (int i = size - 1; i > 0; i--)
    {
        swap(array[0], array[i]);

        visualize(0, i);
        heapify(array, i, 0);
    }

    visualize();
}

void MainWindow::heap(){
    auto startTime = std::chrono::high_resolution_clock::now();
    heap_sort();
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    auto heapSortTime = duration.count();
    ui->label->setText(QString::number(heapSortTime) + "ms");
    isSorted = true;
}

void MainWindow::merge(QVector<int>& arr, int left, int mid, int right)
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    // временные массивы для левого и правого подмассивов
    QVector<int> leftArray(leftSize), rightArray(rightSize);

    for (int i = 0; i < leftSize; ++i)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < rightSize; ++j)
        rightArray[j] = arr[mid + 1 + j];

    // левый и правый подмассивы обратно в основной массив
    int leftIndex = 0, rightIndex = 0, mergedIndex = left;
    while (leftIndex < leftSize && rightIndex < rightSize)
    {
        if (leftArray[leftIndex] <= rightArray[rightIndex])
            arr[mergedIndex++] = leftArray[leftIndex++];
        else
            arr[mergedIndex++] = rightArray[rightIndex++];

        visualize(leftIndex, rightIndex);
    }

    while (leftIndex < leftSize)
        arr[mergedIndex++] = leftArray[leftIndex++];
    while (rightIndex < rightSize)
        arr[mergedIndex++] = rightArray[rightIndex++];

    visualize();
}

void MainWindow::merge_sort(QVector<int> &arr, int const begin, int const end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    merge_sort(array, begin, mid);
    merge_sort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void MainWindow::merge_go()
{
    auto startTime = std::chrono::high_resolution_clock::now();
    merge_sort(array, 0, size - 1);
    visualize();
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    auto mergeSortTime = duration.count();
    ui->label->setText(QString::number(mergeSortTime) + "ms");
    isSorted = true;
}

void MainWindow::quick()
{
    if(!isSorted){
        auto startTime = std::chrono::high_resolution_clock::now();
        quick_sort(array, 0, size - 1);
        visualize();
        auto endTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
        auto quickSortTime = duration.count();
        ui->label->setText(QString::number(quickSortTime) + "ms");
        isSorted = true;
    }
}

int MainWindow::partition(QVector<int> &arr, int low, int high)
{
    // Выбираем последний элемент массива в качестве опорного (pivot)
    int pivot = arr[high];

    // Инициализируем указатель на первый элемент меньший, чем опорный
    int i = (low - 1);

    // Перебираем элементы от low до high-1
    for (int j = low; j <= high - 1; j++)
    {
        // Если текущий элемент меньше опорного
        if (arr[j] < pivot)
        {
            // Увеличиваем i, чтобы указывать на следующую позицию для вставки элементов меньше опорного
            i++;
            // Меняем местами элементы arr[i] и arr[j]
            swap(arr[i], arr[j]);
            // Визуализируем обмен элементов
            visualize(i, j);
        }
    }

    // После перебора всех элементов, меняем местами элементы arr[i+1] и arr[high] (опорный)
    swap(arr[i+1], arr[high]);
    // Визуализируем обмен элементов
    visualize(i+1, high);

    // Возвращаем индекс, на котором расположен опорный элемент
    return (i + 1);
}

void MainWindow::quick_sort(QVector<int> &array, int low, int high)
{
    if (low < high) {
        int pi = partition(array, low, high);

        quick_sort(array, low, pi - 1);

        quick_sort(array, pi + 1, high);
    }
}


int MainWindow::binary_search(int left, int right, int target)
{
    while (left <= right) {
        int mid = left + (right - left) / 2;
        visualize(mid, -1);
        if (array[mid] == target) {
            return mid;
        }
        if (array[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}
