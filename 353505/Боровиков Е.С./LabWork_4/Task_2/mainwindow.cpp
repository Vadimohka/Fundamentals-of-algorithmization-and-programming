#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::makeBtnsActive(bool status) {
    ui->setBtn->setEnabled(status);
    ui->mergeBtn->setEnabled(status);
    ui->heapBtn->setEnabled(status);
    ui->quickBtn->setEnabled(status);
    ui->interpolBtn->setEnabled(status);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    _mainLayout(new QGridLayout(this)),
    ui(new Ui::MainWindow),
    _table(new ArrayTable(this)),
    _visualizer(new SortVisualizer(this)),
    _sorts(new VSort())
{
    ui->setupUi(this);

    connect(ui->heapBtn, SIGNAL(clicked(bool)), SLOT(slotHeapSort()));
    connect(ui->setBtn, SIGNAL(clicked(bool)), SLOT(slotSetArray()));
    connect(ui->mergeBtn, SIGNAL(clicked(bool)), SLOT(slotMergeSort()));
    connect(ui->quickBtn, SIGNAL(clicked(bool)), SLOT(slotQuickSort()));
    connect(ui->interpolBtn, SIGNAL(clicked(bool)), SLOT(slotInterpolationSort()));

    connect(_sorts, SIGNAL(startComparison(int*, int*)), _visualizer, SLOT(slotSetComparison(int*, int*)));
    connect(_sorts, SIGNAL(finishComparison(int*, int*)), _visualizer, SLOT(slotEndComparison(int*, int*)));
    connect(_sorts, SIGNAL(swapping(int*, int*)), _visualizer, SLOT(slotSwapElements(int*, int*)));
    connect(_sorts, SIGNAL(changing(int*, int)), _visualizer, SLOT(slotChangeElement(int*, int)));
    connect(_sorts, SIGNAL(finish()), _visualizer, SLOT(slotEndSorting()));
    connect(_sorts, SIGNAL(finish()), SLOT(slotFinish()));

    _mainLayout->addWidget(_table, 0, 0, 2, 1);
    _mainLayout->addWidget(_visualizer, 0, 1, 2, 2);
    _mainLayout->addWidget(ui->horizontalLayoutWidget, 2, 0, 1, 3);
    ui->centralwidget->setLayout(_mainLayout);
}

MainWindow::~MainWindow() {
    delete ui;
    delete _sorts;
}

void MainWindow::slotSetArray() {
    _array = _table->array();
    _size = _table->arrSize();
    _visualizer->InitByArray(_array, _size);
}

void MainWindow::slotMergeSort() {
    makeBtnsActive(false);
    _table->setReadOnly(true);
    slotSetArray();
    _sorts->Merge(_array, _size);
}

void MainWindow::slotHeapSort() {
    makeBtnsActive(false);
    _table->setReadOnly(true);
    slotSetArray();
    _sorts->Heap(_array, _size);
}

void MainWindow::slotQuickSort() {
    makeBtnsActive(false);
    _table->setReadOnly(true);
    slotSetArray();
    _sorts->Quicks(_array, _size);
}

void MainWindow::slotInterpolationSort() {
    makeBtnsActive(false);
    _table->setReadOnly(true);
    slotSetArray();
    _sorts->Interpolation(_array, _size);
}

void MainWindow::slotFinish() {
    makeBtnsActive(true);
    _table->setArray(_array, _size);
    _table->setReadOnly(false);
}
