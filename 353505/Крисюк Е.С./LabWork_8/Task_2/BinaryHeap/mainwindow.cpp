#include "mainwindow.h"
#include "ui_mainwindow.h"

void expandAllItems(QTreeWidget* treeWidget) {
    QTreeWidgetItemIterator it(treeWidget);
    while (*it) {
        (*it)->setExpanded(true);
        ++it;
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int i = 0; i < 20; ++i) {
        arrHeap.insert(QRandomGenerator::global()->bounded(100));
    }

    displayArrHeap();

    for (int i = 0; i < 20; ++i) {
        listHeap.insert(QRandomGenerator::global()->bounded(100));
    }

    displayListHeap();

    setFixedSize(size());
    setWindowTitle("Бинарная куча");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fillTreeWidgetFromArrHeap(QTreeWidgetItem *item, int i)
{
    if (i >= arrHeap.heap.size()){
        delete item;
        return;
    }


    item->setText(0, QString::number(arrHeap.heap[i]));
    int leftSonNum = 2 * i + 1, rightSonNum = 2 * i + 2;

    if (leftSonNum < arrHeap.heap.size()) {
        QTreeWidgetItem* leftSon = new QTreeWidgetItem(item);
        fillTreeWidgetFromArrHeap(leftSon, leftSonNum);
    }

    if (rightSonNum < arrHeap.heap.size()) {
        QTreeWidgetItem* rightSon = new QTreeWidgetItem(item);
        fillTreeWidgetFromArrHeap(rightSon, rightSonNum);
    }
}

void MainWindow::displayArrHeap()
{
    ui->treeWidgetArrHeap->clear();

    if (arrHeap.heap.size() == 0)
        return;

    QTreeWidgetItem *rootItem = new QTreeWidgetItem(ui->treeWidgetArrHeap);

    fillTreeWidgetFromArrHeap(rootItem, 0);

    ui->treeWidgetArrHeap->addTopLevelItem(rootItem);

    expandAllItems(ui->treeWidgetArrHeap);
}

void MainWindow::fillTreeWidgetFromListHeap(QTreeWidgetItem *item, std::shared_ptr<BinaryHeapList::Node> node)
{
    if (node == nullptr)
        return;

    item->setText(0, QString::number(node->data));

    if (node->leftSon != nullptr) {
        QTreeWidgetItem* leftSon = new QTreeWidgetItem(item);
        fillTreeWidgetFromListHeap(leftSon, node->leftSon);
    }

    if (node->rightSon != nullptr) {
        QTreeWidgetItem* rightSon = new QTreeWidgetItem(item);
        fillTreeWidgetFromListHeap(rightSon, node->rightSon);
    }
}

void MainWindow::displayListHeap()
{
    ui->treeWidgetListHeap->clear();

    if (listHeap.root == nullptr)
        return;

    QTreeWidgetItem *rootItem = new QTreeWidgetItem(ui->treeWidgetListHeap);

    fillTreeWidgetFromListHeap(rootItem, listHeap.root);

    ui->treeWidgetListHeap->addTopLevelItem(rootItem);

    expandAllItems(ui->treeWidgetListHeap);
}

void MainWindow::on_insertInArrHeap_clicked()
{
    arrHeap.insert(ui->spinBox->value());
    displayArrHeap();
}

void MainWindow::on_extractMaxArrHeap_clicked()
{
    int res = arrHeap.extractMax();
    ui->arrHeapLabel->setText(res == INT_MAX ? "Куча пуста!" : QString::number(res));
    displayArrHeap();
}

void MainWindow::on_insertInLisstHeap_clicked()
{
    listHeap.insert(ui->spinBox_2->value());
    displayListHeap();
}

void MainWindow::on_extractMaxListHeap_clicked()
{
    int res = listHeap.extractMax();
    ui->listHeapLabel->setText(res == INT_MAX ? "Куча пуста!" : QString::number(res));
    displayListHeap();
}
