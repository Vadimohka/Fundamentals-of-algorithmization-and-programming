#include "MainWindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    heapArray = new HeapArray();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_Button_clicked()
{
    bool ok;
    int value = ui->input_LineEdit->text().toInt(&ok);
    if (ok) {
        heapArray->insert(value);
        updateTreeDisplay();
    } else {
        ui->input_LineEdit->setText("Invalid input");
    }
}

void MainWindow::on_showMaxValue_Button_clicked() {
    if (heapArray->getSize() == 0) {
        ui->input_LineEdit->setText("Heap is empty");
    }
    else {
        int maxValue = heapArray->getMax();
        ui->input_LineEdit->setText(QString::number(maxValue));
    }
}

void MainWindow::updateTreeDisplay()
{
    ui->treeWidget->clear();
    if (heapArray->isEmpty()) {
        return;
    }

    QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget);
    root->setText(0, QString::number(heapArray->getMax()));
    addNodeToTree(root, 0);
    ui->treeWidget->addTopLevelItem(root);
}

void MainWindow::addNodeToTree(QTreeWidgetItem *parent, int index)
{
    std::vector<int> heap = heapArray->getHeap();
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap.size()) {
        QTreeWidgetItem *leftChild = new QTreeWidgetItem();
        leftChild->setText(0, QString::number(heap[left]));
        parent->addChild(leftChild);
        addNodeToTree(leftChild, left);
    }

    if (right < heap.size()) {
        QTreeWidgetItem *rightChild = new QTreeWidgetItem();
        rightChild->setText(0, QString::number(heap[right]));
        parent->addChild(rightChild);
        addNodeToTree(rightChild, right);
    }
}

