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
QVector<long long> MainWindow::calculatemedians(QVector<long long> a)
{
    QVector<long long> answer;
    int i = 0;
    for (; i < a.size(); i += 3)
    {
        if (i + 3 < a.size())
        {
            quickSort(a, i, i + 2);
            answer.push_back(a[i + 1]);
        }

    }

    if (i == a.size() + 1)
    {
        answer.push_back((a[i - 3] + a[i - 2]) / 2);
    }
    else if (i == a.size() + 2)
    {
        answer.push_back(a[i - 3]);
    }
    return answer;
}

void MainWindow::quickSort(QVector<long long> &palki, int low, int high)
{
    if (low < high) {
        int pi = partition(palki, low, high);

        quickSort(palki, low, pi - 1);
        quickSort(palki, pi + 1, high);
    }
}

int MainWindow::partition(QVector<long long> &palki, int low, int high)
{
    int pivot = palki[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (palki[j] <= pivot) {
            ++i;
            palki.swapItemsAt(i, j);
        }
    }

    palki.swapItemsAt(i + 1, high);
    return i + 1;
}

void MainWindow::on_elemnumspinBox_valueChanged(int arg1)
{
    QVector<long long> a(arg1);
    a.clear();
    for (int i = 0; i < arg1; i++)
    {
        a.push_back((int)rand() % 100);
    }
    QVector<long long> b = calculatemedians(a);
    QString array,output;
    for(long long x : a){
        array += QString::number(x);
        array += " ";
    }
    for(long long x : b){
        output += QString::number(x);
        output += " ";
    }
    ui->arrayoutput->setText(array);
    ui->mediansoutput->setText(output);
}

