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

    connect(ui->pushButton, &QPushButton::clicked, this,
        &MainWindow::initArray);

        
    connect(ui->toMedian, &QPushButton::clicked, this,
        &MainWindow::ToMedian);
}

QString MainWindow::toString(QVector<int> arr, bool toMedian)
{

    QString str;
    for (int i = 0; i < arr.size(); i++)
    {
        if(i % 10 == 0){
            str.append("\n");
        }
        if(!toMedian){
            if(i % 3 == 0 && i != 0){
                str.append(" | ");            
            }
        }

        str.append(QString::number(arr[i]) + ", ");
    }
    str.remove(str.length() - 2, 2);
    return str;
}

void MainWindow::initArray()
{
    size = ui->spinBox->value();
    array.clear();


    for (int i = 0; i < size; i++)
    {
        array.push_back((int)rand() % size);
    }

    QString arrayStr = toString(array, false);
    ui->arrayLabel->setText(arrayStr);
}

void MainWindow::printArray(QVector<int> &arr, int N)
{
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
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
        }  
    }  
 
    swap(arr[i+1], arr[high]);
    return (i + 1);  
    /////////////////////////
}

// The Quicksort function Implement

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

void MainWindow::ToMedian()
{
    median.clear();
    ui->label->clear();


    int i = 0;
    for (; i < array.size(); i += 3)
    {
        if (i + 3 < array.size())
        {
            quickSort(array, i, i + 2);
            median.push_back(array[i + 1]);
        }

    }

    if (i == array.size() + 1)
    {
        median.push_back((array[i - 3] + array[i - 2]) / 2);
    }
    else if (i == array.size() + 2)
    {
        median.push_back(array[i - 3]);
    }

    QString medianStr = toString(median, true);
    ui->label->setText(medianStr);
}