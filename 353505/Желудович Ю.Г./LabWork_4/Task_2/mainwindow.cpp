#include "mainwindow.h"
#include "./ui_mainwindow.h"

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

long long MainWindow::binpow(int digit, int powder, int mod)
{
    int result = 1;
    while (powder > 0)
    {
        if (powder & 1)
        {
            result = (result * digit) % mod;
        }
        digit = (digit * digit) % mod;
        powder >>= 1;
    }
    return result;
}

void MainWindow::interpolationSort(std::vector<int>& arr)
{
    std::vector<int> divideSize;
    int end = static_cast<int>(arr.size());
    divideSize.push_back(end);
    while (!divideSize.empty())
    {
        int size = divideSize.back();
        divideSize.pop_back();
        int start = end - size;
        int min = arr[start];
        int max = arr[start];
        for (int i = start + 1; i < end; i++)
        {
            if (arr[i] < min)
            {
                min = arr[i];
            }
            else if (arr[i] > max)
            {
                max = arr[i];
            }
        }
        if (min == max)
        {
            end -= size;
        }
        else
        {
            int p = 0;
            std::vector<std::vector<int>> bucket(size);

            for (int i = start; i < end; i++)
            {
                p = static_cast<int>(((arr[i] - min) / static_cast<double>(max - min)) * (size - 1));
                bucket[p].push_back(arr[i]);
            }
            for (int i = 0; i < size; i++)
            {
                if (!bucket[i].empty())
                {
                    for (int j = 0; j < bucket[i].size(); j++)
                    {
                        arr[start++] = bucket[i][j];
                        printArray(arr);
                    }
                    divideSize.push_back(bucket[i].size());
                }
            }
        }
    }
}

void MainWindow::printArray(std::vector<int>& vec)
{
    QString str;
    for (auto v : vec)
    {
        str += QString::number(v) + " ";
    }
    str += "\n";
    ui->listWidget->addItem(str);
}

void MainWindow::on_lineEdit_Elements_returnPressed()
{
    ui->listWidget->clear();
    bool Ok = true;
    int n = ui->lineEdit_Elements->text().toInt(&Ok);
    if(!Ok || n <= 0 || n > 1000)
    {
        QMessageBox::warning(nullptr,"Error","Incorrect input!");
        return;
    }
    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i)
    {
        vec.at(i) = QRandomGenerator::global()->bounded(0,10);
    }
    interpolationSort(vec);
    long long ans = binpow(n,vec.at(0),197);
    ui->label_pow->setText(QString::number(ans));
}
