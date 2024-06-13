#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sorter.h"
#include "binsearch.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QTime>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setSpacing(0);

    arrayInput = new QLineEdit(this);
    arrayDisplay = new QLabel(this);

    sortHeapButton = new QPushButton("Heap Sort", this);
    sortQuickButton = new QPushButton("Quick Sort", this);
    sortMergeButton = new QPushButton("Merge Sort", this);
    sortInterpolationButton = new QPushButton("Interpolation Sort", this); // Создание новой кнопки
    searchButton = new QPushButton("Binary Search", this);

    mainLayout->addWidget(new QLabel("Input Array (comma separated):", this));
    mainLayout->addWidget(arrayInput);
    mainLayout->addWidget(new QLabel("Sorted Array:", this));
    mainLayout->addWidget(arrayDisplay);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(sortHeapButton);
    buttonLayout->addWidget(sortQuickButton);
    buttonLayout->addWidget(sortMergeButton);
    buttonLayout->addWidget(sortInterpolationButton); // Добавление новой кнопки в макет
    buttonLayout->addWidget(searchButton);
    mainLayout->addLayout(buttonLayout);

    setCentralWidget(centralWidget);

    connect(sortHeapButton, &QPushButton::clicked, this, &MainWindow::on_sortHeapButton_clicked);
    connect(sortQuickButton, &QPushButton::clicked, this, &MainWindow::on_sortQuickButton_clicked);
    connect(sortMergeButton, &QPushButton::clicked, this, &MainWindow::on_sortMergeButton_clicked);
    connect(sortInterpolationButton, &QPushButton::clicked, this, &MainWindow::on_sortInterpolationButton_clicked); // Подключение новой кнопки к слоту
    connect(searchButton, &QPushButton::clicked, this, &MainWindow::on_searchButton_clicked);
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

void MainWindow::measureSortTime(void (*sortFunc)(QVector<int>&)) {
    QTime timer;
    timer.start();
    sortFunc(array);
    int elapsed = timer.elapsed();
    updateArrayDisplay();
    QMessageBox::information(this, "Sorting Time", QString("Elapsed time: %1 ms").arg(elapsed));
}

void MainWindow::on_sortHeapButton_clicked() {
    QString input = arrayInput->text();
    QStringList numbers = input.split(" ", Qt::SkipEmptyParts);

    array.clear();
    for (const QString& number : numbers) {
        array.append(number.toInt());
    }

    measureSortTime(Sorter::heapSort);
}

void MainWindow::on_sortQuickButton_clicked() {
    QString input = arrayInput->text();
    QStringList numbers = input.split(" ", Qt::SkipEmptyParts);

    array.clear();
    for (const QString& number : numbers) {
        array.append(number.toInt());
    }

    measureSortTime(Sorter::quickSort);
}

void MainWindow::on_sortMergeButton_clicked() {
    QString input = arrayInput->text();
    QStringList numbers = input.split(" ", Qt::SkipEmptyParts);

    array.clear();
    for (const QString& number : numbers) {
        array.append(number.toInt());
    }

    measureSortTime(Sorter::mergeSort);
}

void MainWindow::on_sortInterpolationButton_clicked() {
    QString input = arrayInput->text();
    QStringList numbers = input.split(" ", Qt::SkipEmptyParts);

    array.clear();
    for (const QString& number : numbers) {
        array.append(number.toInt());
    }

    measureSortTime(Sorter::interpolationSort);
}

void MainWindow::on_searchButton_clicked() {
    bool ok;
    int digit = QInputDialog::getInt(this, "Binary Search", "Enter number to search:", 0, INT_MIN, INT_MAX, 1, &ok);
    if (ok) {
        int index = BinSearch::search(array, digit);
        if (index != -1) {
            QMessageBox::information(this, "Search Result", QString("Number %1 found at index %2").arg(digit).arg(index));
        } else {
            QMessageBox::information(this, "Search Result", "Number not found");
        }
    }
}
