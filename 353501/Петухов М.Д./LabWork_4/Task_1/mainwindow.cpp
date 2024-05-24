#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpressionValidator>
#include <iostream>
#include <QGraphicsRectItem>
#include <QThread>
#include <chrono>
#include <thread>

using namespace std;

MainWindow::MainWindow() : ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    scene = new QGraphicsScene();

    ui->graphicsView->setScene(scene);

    scene->setSceneRect(QRectF(0, 0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20));

    size = array.size();

    ui->sortButton->hide();
    ui->mergeSortButton->hide();
    ui->quickSortButton->hide();
    ui->search->hide();

    connect(ui->pushButton, &QPushButton::clicked, this,
            &MainWindow::initArray);

    connect(ui->sortButton, &QPushButton::clicked, this,
            &MainWindow::startHeapSort);
    connect(ui->mergeSortButton, &QPushButton::clicked, this,
            &MainWindow::startMergeSort);
    connect(ui->quickSortButton, &QPushButton::clicked, this,
            &MainWindow::startQuickSort);
    connect(ui->search, &QPushButton::clicked, this,
            &MainWindow::startSearch);
}

void MainWindow::startSearch(){
    int index = -2;
    if(wasSorted){
        index = binarySearch(0, size - 1, ui->searchSpinBox->value());
    }
    else{
        ui->searchLabel->setText("Array unsorted");
    }

    if(index == -1){
        ui->searchLabel->setText("No such index");
        visualize();
    }
}

void MainWindow::printArray(QVector<int> &arr, int N)
{
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
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
        rect->setBrush(QBrush(Qt::white)); // Установка красного цвета
        arrayRect.push_back(rect);
    }
    visualize();
    ui->sortButton->show();
    ui->mergeSortButton->show();
    ui->quickSortButton->show();
    ui->search->show();
    wasSorted = false;
    printArray(array, size);
}

void MainWindow::visualize()
{

    scene->clear();

    float rectW = scene->width() / size;
    for (int i = 0; i < size; i++)
    {
        QBrush brush = Qt::white;
        QPen pen;
        pen.setColor(Qt::black);


        scene->addRect(i * rectW, 0, rectW, array[i] * 3, pen, brush);
    }

    QThread::msleep(50);
    QCoreApplication::processEvents();

    scene->update();
}

void MainWindow::visualize(int ind1toSwap, int ind2toSwap)
{

    scene->clear();

    float height = scene->height();


    float rectW = scene->width() / size;
    for (int i = 0; i < size; i++)
    {
        QBrush brush = Qt::white;
        QPen pen;
        pen.setColor(Qt::black);
        if (i == ind1toSwap || i == ind2toSwap)
        {
            brush = Qt::red;
        }
        scene->addRect(i * rectW, 0, rectW, array[i] * 3, pen, brush);
    }
    QThread::msleep(50);
    QCoreApplication::processEvents();

    scene->update();
}

void MainWindow::heapify(QVector<int> &arr, int N, int i)
{

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int l = 2 * i + 1;

    // right = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest
    // so far
    if (r < N && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        // swap(arrayRect[i], arrayRect[largest]);

        visualize(i, largest);

        // Recursively heapify the affected
        // sub-tree
        MainWindow::heapify(arr, N, largest);
    }
}

// Main function to do heap sort            O(nlogn)
void MainWindow::heapSort()
{

    // Build heap (rearrange array)
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);

    // One by one extract an element
    // from heap
    for (int i = size - 1; i > 0; i--)
    {

        // Move current root to end
        swap(array[0], array[i]);
        // swap(arrayRect[0], arrayRect[i]);

        visualize(0, i);

        // call max heapify on the reduced heap
        heapify(array, i, 0);
    }

    visualize();
}

void MainWindow::startHeapSort(){
    auto startTime = std::chrono::high_resolution_clock::now();
    blockButtons();
    heapSort();
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    auto heapSortTime = duration.count();    
    ui->label->setText(QString::number(heapSortTime) + "ms");
    unblockButtons();
    wasSorted = true;
}


//nlogn
void MainWindow::merge(QVector<int> &arr, int const left, int const mid, int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }

    visualize();

    delete[] leftArray;
    delete[] rightArray;
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void MainWindow::mergeSort(QVector<int> &arr, int const begin, int const end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void MainWindow::blockButtons(){
    ui->pushButton->setEnabled(false);
    ui->sortButton->setEnabled(false);
    ui->mergeSortButton->setEnabled(false);
    ui->quickSortButton->setEnabled(false);
    ui->search->setEnabled(false);
}

void MainWindow::unblockButtons(){
    ui->pushButton->setEnabled(true);
    ui->sortButton->setEnabled(true);
    ui->mergeSortButton->setEnabled(true);
    ui->quickSortButton->setEnabled(true);
    ui->search->setEnabled(true);
}

void MainWindow::startMergeSort()
{
    auto startTime = std::chrono::high_resolution_clock::now();
    blockButtons();
    mergeSort(array, 0, size - 1);
    visualize();
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    auto mergeSortTime = duration.count();    
    ui->label->setText(QString::number(mergeSortTime) + "ms");
    unblockButtons();
    wasSorted = true;
}

void MainWindow::startQuickSort()
{
    if(!wasSorted){
        auto startTime = std::chrono::high_resolution_clock::now();
        blockButtons();
        quickSort(array, 0, size - 1);
            visualize();
        auto endTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
        auto quickSortTime = duration.count();    
        ui->label->setText(QString::number(quickSortTime) + "ms");
        unblockButtons();
        wasSorted = true;
    }
}

int MainWindow::partition(QVector<int> &arr, int low, int high)
{
    ////////////////////////////
   int pivot = arr[high]; // pivot element  
    int i = (low - 1);  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(arr[i], arr[j]);
            visualize(i, j);
        }  
    }  
 
    swap(arr[i+1], arr[high]);
    visualize(i+1, high);
    return (i + 1);  
    /////////////////////////
}

// The Quicksort function Implement
//n^2
//nlogn
void MainWindow::quickSort(QVector<int> &array, int low, int high)
{
  if (low < high) {
      
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on righ of pivot
    int pi = partition(array, low, high);

    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);

    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);

  }
}

int MainWindow::binarySearch(int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
        visualize(m, - 1);
        // Check if x is present at mid
        if (array[m] == x)
            return m;
 
        // If x greater, ignore left half
        if (array[m] < x)
            l = m + 1;
 
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
 
    // If we reach here, then element was not present
    return -1;
}