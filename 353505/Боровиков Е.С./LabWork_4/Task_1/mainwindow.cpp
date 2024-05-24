#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLayout>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    _table(new ArrayTable),
    _timer(new QElapsedTimer)
{
    ui->setupUi(this);
    ui->verticalLayout->addWidget(_table);
    ui->centralwidget->setLayout(ui->verticalLayout);

    connect(_table, SIGNAL(arrayChanged()), SLOT(slotArrayChanged()));
    connect(ui->BinarySearchPushButton, SIGNAL(clicked(bool)), SLOT(slotBinarySearch()));
    connect(ui->HeapSortPushButton, SIGNAL(clicked(bool)), SLOT(slotHeapSort()));
    connect(ui->MergeSortPushButton, SIGNAL(clicked(bool)), SLOT(slotMergeSort()));
    connect(ui->QuickSortPushButton, SIGNAL(clicked(bool)), SLOT(slotQuickSort()));
    connect(ui->InterpolationSortPushButton, SIGNAL(clicked(bool)), SLOT(slotInterpolationSort()));

    _array[0] = 0;
    ui->searchSpinBox->setMinimum(INT_MIN);
    ui->searchSpinBox->setMaximum(INT_MAX);
}

MainWindow::~MainWindow() {
    delete ui;
    delete[] _array;
}

void MainWindow::slotArrayChanged() {
    auto newArray = _table->array();
    auto newSize = _table->arrSize();

    if (newSize > _capacity) {
        _array = new int[newSize];
        _capacity = newSize;
    }
    _arrSize = newSize;

    for (int i = 0; i < newSize; ++i) {
        _array[i] = newArray[i];
    }
}

void MainWindow::slotMergeSort() {
    _timer->start();
    Sort::Merge(_array, _arrSize);
    endSort(_timer->elapsed());
}

void MainWindow::slotHeapSort() {
    _timer->start();
    Sort::Heap(_array, _arrSize);
    endSort(_timer->elapsed());
}

void MainWindow::slotQuickSort() {
    _timer->start();
    Sort::Quick(_array, _arrSize);
    endSort(_timer->elapsed());
}

void MainWindow::slotInterpolationSort() {
    _timer->start();
    Sort::Interpolation(_array, _arrSize);
    endSort(_timer->elapsed());
}

void MainWindow::sendWarning() const {
    QMessageBox::critical(nullptr, "Stack Overflow", "The stack is on the verge of overflowing with "
                                                         + QString::number(Sort::maxFunctionsRunning())
                                                         + " functions already on it. The sorting process has been halted to prevent overflow.");
}

void MainWindow::setEnable(bool status) {
    ui->BinarySearchPushButton->setEnabled(status);
    ui->HeapSortPushButton->setEnabled(status);
    ui->InterpolationSortPushButton->setEnabled(status);
    ui->MergeSortPushButton->setEnabled(status);
    ui->QuickSortPushButton->setEnabled(status);
    ui->searchSpinBox->setEnabled(status);
    _table->setReadOnly(!status);
}

void MainWindow::startSort() {
    setEnable(false);
}

void MainWindow::endSort(int timeSpot) {
    ui->timeLineEdit->setText(QString::number(timeSpot) + QString(" ms"));
    _table->setArray(_array, _arrSize);
    setEnable(true);
}

void MainWindow::slotBinarySearch() {
    ui->indexLineEdit->setText(QString::number(Search::Binsearch(_array, _arrSize, ui->searchSpinBox->value())));
}
