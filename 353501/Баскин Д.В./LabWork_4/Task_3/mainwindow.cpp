#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString toString(Vector<int>& vec)
{
    QString str;
    for (unsigned long long i = 0; i < vec.size(); ++i)
    {
        str += QString::number(vec[i]);
        str.push_back('\n');
    }
    return str;
}

void qsort(Vector<int> &array, int left, int right)
{
    int l = left, r = right;
    int mid = array[(l + r) / 2];
    while (l <= r)
    {
        while (array[l] < mid)
        {
            l++;
        }
        while (array[r] > mid)
        {
            r--;
        }
        if (l <= r)
        {
            std::swap(array[l++], array[r--]);
        }
    }
    if (left < r)
    {
        qsort(array, left, r);
    }
    if (right > l)
    {
        qsort(array, l, right);
    }
}

void MainWindow::Generate()
{
    for(int i = 0; i < rand() % 201 + 10; i++)
    {
        sequence.push_back(rand() % 201 - 100);
    }
}

void MainWindow::on_pushButton_clicked()
{
    sequence.clear();
    ui->textBrowser->clear();
    Generate();
    ui->textBrowser->append(toString(sequence));
    ToMedian();
}

void MainWindow::ToMedian()
{
    result.clear();
    ui->textBrowser_2->clear();

    unsigned long long i = 0;
    for (; i < sequence.size(); i += 3)
    {
        if (i + 3 < sequence.size())
        {
            qsort(sequence, i, i + 2);
            result.push_back(sequence[i + 1]);
        }
    }

    if (i == sequence.size() + 1)
    {
        result.push_back((sequence[i - 3] + sequence[i - 2]) / 2);
    }
    else if (i == sequence.size() + 2)
    {
        result.push_back(sequence[i - 3]);
    }

    ui->textBrowser_2->append(toString(result));
}

