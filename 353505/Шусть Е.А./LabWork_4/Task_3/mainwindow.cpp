#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generateVec(QList<int> &vec)
{
    int size = QRandomGenerator::global()->bounded(10,20);
    for (int i = 0; i < size; ++i)
    {
        vec.push_back(QRandomGenerator::global()->bounded(0,20));
    }
}

void MainWindow::printArray(QList<int>& vec)
{
    QString str;
    for (auto v : vec)
    {
        str += QString::number(v) + "   ";
    }
    str += "\n";
    ui->listWidget->addItem(str);
}

void MainWindow::MedianVec(QList<int> &vec)
{
    QList<int> res;
    int sum = 0;
    QList<int> temp;
    for (int i = 0; i < vec.size(); ++i)
    {
        sum += vec.at(i);
        temp.push_back(vec.at(i));
        if((i+1) % 3 == 0)
        {
           res.push_back(MedianOfTree(temp));
           sum = 0;
           temp.clear();
        }
        else if(i == vec.size() - 1)
        {
            res.push_back(sum / (vec.size() % 3));
            sum = 0;
        }
    }
    printArray(res);
}

int MainWindow::MedianOfTree(QList<int> vec)
{
    int a = vec.at(0);
    int b = vec.at(1);
    int c = vec.at(2);

    if (a > b) std::swap(a, b);

    if (a > c) std::swap(a, c);

    return std::min(b, c);
}

void MainWindow::on_pushButton_clicked()
{
    ui->listWidget->clear();
    //QList<int> vec{ 1, 5, 1, 4, 5, 6, 2, 1, 3, 4, 4, 4, 5, 7};
    QList<int> vec;
    generateVec(vec);
    printArray(vec);
    MedianVec(vec);
}

