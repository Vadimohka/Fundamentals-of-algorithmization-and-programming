#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::addElement);
    connect(ui->popButton, &QPushButton::clicked, this, &MainWindow::removeElement);
    connect(ui->heapifyButton, &QPushButton::clicked, this, &MainWindow::heapifyArray);
    connect(ui->getTopButton, &QPushButton::clicked, this, &MainWindow::getTop);
    connect(ui->emptyButton, &QPushButton::clicked, this, &MainWindow::isEmptyHeap);
    connect(ui->clearButton, &QPushButton::clicked, this, &MainWindow::clearHeap);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addElement()
{
    QString text = ui->lineEdit1->text();

    // Проверяем, не пуст ли текст
    if (!text.isEmpty())
    {
        // Преобразуем текст в число и добавляем его в кучу
        int value = text.toInt();
        m_heap.push(value);
        updateTreeWidget();
    }
    else
    {
        // Если lineEdit1 пуст, выводим сообщение об ошибке
        QMessageBox::warning(this, "Ошибка ввода", "Поле ввода не может быть пустым.");
    }

    // Очищаем lineEdit1
    ui->lineEdit1->clear();
}

void MainWindow::removeElement()
{
    if (!m_heap.empty()) {
        m_heap.pop();
        updateTreeWidget();
    }
}

void MainWindow::heapifyArray()
{
    ui->treeWidget->clear();
    m_heap.clear();

    QStringList values = ui->lineEdit->text().split(" ", Qt::SkipEmptyParts);
    QVector<int> arr;
    bool ok;
    foreach (const QString &value, values) {
        int num = value.toInt(&ok);
        if (ok) {
            arr.push_back(num);
        } else {
            QMessageBox::warning(this, "Ошибка", "Вводите только целые числа и пробелы.");
            return;
        }
    }


    m_heap.heapify(arr.data(), arr.size());
    updateTreeWidget();
    ui->lineEdit->clear();

}

void MainWindow::getTop()
{
    if (!m_heap.empty()) {
        ui->label->setText(QString::number(m_heap.top()));
    } else {
        ui->label->setText("Heap is empty");
    }
}

void MainWindow::isEmptyHeap() {
    if (m_heap.empty()) {
        ui->label->setText("Heap is empty");
    } else {
        ui->label->setText("Heap is not empty");
    }
}

void MainWindow::clearHeap()
{
    m_heap.clear();
    ui->treeWidget->clear();
}

void MainWindow::updateTreeWidget() {
    ui->treeWidget->clear();
    updateTreeWidgetRecursive(ui->treeWidget->invisibleRootItem(), 0, m_heap);
}

void MainWindow::updateTreeWidgetRecursive(QTreeWidgetItem* parent, int index, const HeapArray<int>& heap) {
    if (index >= heap.size()) {
        return;
    }

    QTreeWidgetItem* item = new QTreeWidgetItem(parent);
    item->setText(0, QString::number(heap[index]));

    int left = 2 * index + 1;
    int right = 2 * index + 2;

    updateTreeWidgetRecursive(item, left, heap);
    updateTreeWidgetRecursive(item, right, heap);
}
