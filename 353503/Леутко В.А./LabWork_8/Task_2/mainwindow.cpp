#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , heap (new HeapArray())
{
    ui->setupUi(this);

    ui->heapTreeView->setModel(new QStandardItemModel());
    ui->heapTreeView->setHeaderHidden(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete heap;
}

QStandardItem* MainWindow::createItemForNode(const HeapArray& heap, int index, const QString& position) {
    if (index >= static_cast<int>(heap.heap.size())) {
        return nullptr;
    }

    QString label;
    if (position.isEmpty()) {
        label = QString::number(heap.heap[index]) + " (root)";
    } else {
        label = QString::number(heap.heap[index]) + " (" + position + ")";
    }

    QStandardItem* item = new QStandardItem(label);

    int leftIndex = heap.leftChild(index);
    int rightIndex = heap.rightChild(index);

    QStandardItem* leftChild = createItemForNode(heap, leftIndex, "left");
    if (leftChild) {
        item->appendRow(leftChild);
    }

    QStandardItem* rightChild = createItemForNode(heap, rightIndex, "right");
    if (rightChild) {
        item->appendRow(rightChild);
    }

    return item;
}

void MainWindow::updateHeapView() {
    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->heapTreeView->model());
    model->clear();

    QStandardItem* rootItem = createItemForNode(*heap, 0, "");
    if (rootItem) {
        model->appendRow(rootItem);
    }
    ui->heapTreeView->expandAll();
}


void MainWindow::on_insertBtn_clicked()
{
    int key = ui->keySpinBox->value();
    heap->insert(key);
    updateHeapView();
}

void MainWindow::on_extractMaxBtn_clicked()
{
    int maxKey = heap->extractMax();
    if (maxKey == -1) {
        QMessageBox::warning(this, "Error", "Heap is empty, cannot extract max.");
    } else {
        updateHeapView();
    }
}

void MainWindow::on_getMaxBtn_clicked()
{
    int maxKey = heap->getMax();
    if (maxKey == -1) {
        QMessageBox::warning(this, "Error", "Heap is empty, cannot get max.");
    } else {
        QMessageBox::information(this, "Max Key", QString::number(maxKey));
    }
}

void MainWindow::on_isEmptyBtn_clicked()
{
    if (heap->isEmpty()) {
        QMessageBox::information(this, "Heap Status", "Heap is empty.");
    } else {
        QMessageBox::information(this, "Heap Status", "Heap is not empty.");
    }
}
