#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->start_btn, SIGNAL(clicked()), this, SLOT(start()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculateMedian(QVector<int> &array)
{
    QList<int> result;
    QVector<int> tempArray;

    for (int i = 0; i < array.size(); ++i)
    {
        tempArray.append(array[i]);

        if ((i + 1) % 3 == 0)
        {
            int median = findMedianOfThree(tempArray);
            result.append(median);
            tempArray.clear();
        }
        else if (i == array.size() - 1)
        {
            int sum = 0;
            for (int j = 0; j < tempArray.size(); ++j)
            {
                sum += tempArray[j];
            }
            result.append(sum / tempArray.size());
        }
    }

    printArr(result);
}


int MainWindow::findMedianOfThree(QVector<int> &array)
{
    int a = array.at(0);
    int b = array.at(1);
    int c = array.at(2);

    if ((a > b) != (a > c))
        return a;
    else if ((b > a) != (b > c))
        return b;
    else
        return c;
}

void MainWindow::printArr(QVector<int> &array)
{
    QString str;
    str = "Result array: \n";
    for (auto item : array)
    {
        str += QString::number(item) + "   ";
    }
    str += "\n";
    ui->listWidget->addItem(str);
}

void MainWindow::start()
{
    ui->listWidget->clear();
    initializeArray();
    QString startArray;
    startArray = "Start array: \n";
    for (int i = 0; i < array.size(); ++i) {
        startArray += QString::number(array.at(i)) + "   ";
        if ((i + 1) % 3 == 0) startArray += "|   ";
    }
    startArray += "\n";
    ui->listWidget->addItem(startArray);

    calculateMedian(array);
}


void MainWindow::initializeArray()
{
    array.clear();
    int arraySize = QRandomGenerator::global()->bounded(15, 30);
    for (int i = 0; i < arraySize; ++i) {
        array.append(QRandomGenerator::global()->bounded(0, 50));
    }
}




