// mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    arrayInput = new QLineEdit(this);
    arrayDisplay = new QLabel(this);

    QPushButton *sortInterpolationButton = new QPushButton("Interpolation Sort", this);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(new QLabel("Input Array (space separated):", this));
    layout->addWidget(arrayInput);
    layout->addWidget(new QLabel("Sorted Array:", this));
    layout->addWidget(arrayDisplay);
    layout->addWidget(sortInterpolationButton);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(sortInterpolationButton, &QPushButton::clicked, this, &MainWindow::on_sortInterpolationButton_clicked);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::updateArrayDisplay() {
    QStringList list;
    for (int num : array) {
        list << QString::number(num);
    }
    arrayDisplay->setText(list.join(" "));
}

void MainWindow::interpolationSort(QVector<int>& arr) {
    int n = arr.size();
    QString sortedArrays; // String to store all intermediate results
    sortedArrays += "Initial array: " + QString::number(arr[0]);
    for (int i = 1; i < n; ++i) {
        sortedArrays += " " + QString::number(arr[i]); // Add array elements to the string
    }
    sortedArrays += "\n"; // Add newline to separate the initial array

    for (int i = 0; i < n - 1; ++i) {
        int key = arr[i];
        int left = 0, right = i;
        int mid;
        while (left <= right) {
            if (arr[right] == arr[left]) {
                mid = left; // Avoid division by zero
            } else {
                mid = left + (right - left) * (i - left) / (arr[right] - arr[left]);
            }
            if (arr[mid] < key)
                left = mid + 1;
            else if (arr[mid] > key)
                right = mid - 1;
            else
                break;
        }
        for (int j = i; j > left; --j)
            arr[j] = arr[j - 1];
        arr[left] = key;

        // Add the current state of the array to the string
        sortedArrays += "Step " + QString::number(i + 1) + ": ";
        sortedArrays += QString::number(arr[0]);
        for (int j = 1; j <= i + 1; ++j) {
            sortedArrays += " " + QString::number(arr[j]);
        }
        sortedArrays += "\n";
    }

    // Update QLabel text
    arrayDisplay->setText(sortedArrays);
}

int MainWindow::binpow(int digit, int power, int mod) {
    int result = 1;
    while (power > 0) {
        if (power & 1) {
            result = (result * digit) % mod;
        }
        digit = (digit * digit) % mod;
        power >>= 1;
    }
    return result;
}

void MainWindow::on_sortInterpolationButton_clicked() {
    QString input = arrayInput->text();
    QStringList numbers = input.split(" ", Qt::SkipEmptyParts);

    array.clear();
    for (const QString& number : numbers) {
        array.append(number.toInt());
    }

    interpolationSort(array);

    // Find the index of an element raised to the power of the length of the array modulo the array size
    int index = binpow(array.size(), 2, array.size());
    qDebug() << "Index: " << index;
}
