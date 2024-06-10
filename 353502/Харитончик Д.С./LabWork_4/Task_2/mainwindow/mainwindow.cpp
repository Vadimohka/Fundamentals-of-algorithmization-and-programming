#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    verticalLayout = new QVBoxLayout(this);
    inputTextEdit = new QTextEdit(this);
    sortButton = new QPushButton("Sort", this);
    outputTextEdit = new QTextEdit(this);

    setCentralWidget(new QWidget(this));
    centralWidget()->setLayout(verticalLayout);
    verticalLayout->addWidget(inputTextEdit);
    verticalLayout->addWidget(sortButton);
    verticalLayout->addWidget(outputTextEdit);

    connect(sortButton, &QPushButton::clicked, this, &MainWindow::sortArray);
};

MainWindow::~MainWindow()
{
}

void MainWindow::sortArray() {
    QString input = inputTextEdit->toPlainText();
    QStringList nums = input.split(" ", Qt::SkipEmptyParts);
    std::vector<int> arr;
    for (const QString &num: nums)
        arr.push_back(num.toInt());

    interpolationSort(arr);

    outputTextEdit->clear();
    outputTextEdit->append("Отсортированный массив: ");
    for (int num : arr)
        outputTextEdit->append(QString::number(num));
}

void MainWindow::interpolationSort(std::vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int key = arr[i];
        int left = 0, right = i - 1;
        while (left <= right)
        {
            int mid = left + ((key - arr[left]) * (right - left) / (arr[right] - arr[left]));
            if (mid < 0)
                mid = 0;
            if (mid > n - 1)
                mid = n - 1;
            if (arr[mid] < key)
                left = mid + 1;
            else
                right = mid - 1;
        }
        for (int j = i - 1; j >= left; --j)
            arr[j + 1] = arr[j];
        arr[left] = key;
    }
}

int MainWindow::binpow(int a, int b, int m)
{
    a %= m;
    int result = 1;
    while (b > 0)
    {
        if (b % 1)
            result = (result * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return result;
}
