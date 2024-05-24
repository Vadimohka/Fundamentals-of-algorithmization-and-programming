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

    connect(ui->pushButton, &QPushButton::clicked, this,
            &MainWindow::initArray);

    connect(ui->sortButton, &QPushButton::clicked, this,
            &MainWindow::startSort);

    connect(ui->search, &QPushButton::clicked, this,
            &MainWindow::startSearch);
}

void MainWindow::startSort(){
    interpolationSort(array, 0, size);
    wasSorted = true;
    printArray(array, size);
}

void MainWindow::startSearch(){
    if(wasSorted){
        index = binarySearch(0, size - 1, ui->searchSpinBox->value());
        int value = ui->searchSpinBox->value();
        ui->resultLabel->setText(QString::number(binpow(index, size, value)));
    }
    else{
        ui->searchLabel->setText("Array unsorted");
    }

    if(index == -1){
        ui->searchLabel->setText("No such index");
        visualize();
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

int MainWindow::binpow(int digit, int power, int mod) {
  if(power == 0) return 1;
  
  if(power % 2 == 1) {
    return digit * binpow(digit, power - 1, mod) % mod;
  } else {
    int temp = binpow(digit, power / 2, mod);
    return temp * temp % mod;
  }
}

void MainWindow::interpolationSort(std::vector<int>& arr, int start, int size)
{
    int min = arr[start];
    int max = arr[start];
    
    for (int i = start + 1; i < start + size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        } else if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    if (min != max) {
        std::vector<std::vector<int>> bucket(size, std::vector<int>());
        int interpolation = 0;
        
        for (int i = start; i < start + size; i++) {
            interpolation = ((arr[i] - min) / (max - min)) * (size - 1);
            bucket[interpolation].push_back(arr[i]);
        }
        
        int idx = start;
        
        for (int i = 0; i < size; i++) {
            if (bucket[i].size() > 1) {
                interpolationSort(bucket[i], 0, bucket[i].size()); // Рекурсия
            }
            
            for (int j = 0; j < bucket[i].size(); j++) {
                arr[idx++] = bucket[i][j];
            }
            if(i == size - 1){
                visualize(arr);  
            }
        }
    }
}

void MainWindow::printArray(std::vector<int> &arr, int N)
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
    wasSorted = false;
    visualize();
}

void MainWindow::visualize(std::vector<int>& array)
{

    scene->clear();

    float rectW = scene->width() / size;
    for (int i = 0; i < array.size(); i++)
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


