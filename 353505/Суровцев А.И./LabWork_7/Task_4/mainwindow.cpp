#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_bnt_regen_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printHashTable(QTableWidget *tableWidget, MyHashTable *hashTable)
{
    auto vec = hashTable->display();
    tableWidget->clear();

    int maxColumnCount = 0;

    for (const auto& row : vec) {
        if (row.size() > maxColumnCount) {
            maxColumnCount = row.size();
        }
    }

    tableWidget->setColumnCount(maxColumnCount);

    for (int j = 0; j < vec.size(); ++j) {
        QVector<int> currentVec = vec[j];
        tableWidget->setRowCount(j + 1);
        for (int i = 0; i < currentVec.size(); ++i) {
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(currentVec[i]));
            tableWidget->setItem(j, i, item);
        }

        for (int i = currentVec.size(); i < maxColumnCount; ++i) {
            QTableWidgetItem *item = new QTableWidgetItem("nan");
            tableWidget->setItem(j, i, item);
        }
    }
}
void MainWindow::on_bnt_printResult_clicked()
{
    int targetValue = ui->spinBox->value();
    clock_t startTime;

    startTime = clock();
    int result16 = table16->find(targetValue);
    double elapsed16 = double(clock() - startTime) / CLOCKS_PER_SEC * 10000000;

    startTime = clock();
    int result64 = table64->find(targetValue);
    double elapsed64 = double(clock() - startTime) / CLOCKS_PER_SEC * 10000000;

    startTime = clock();
    int result128 = table128->find(targetValue);
    double elapsed128 = double(clock() - startTime) / CLOCKS_PER_SEC * 10000000;

    startTime = clock();
    int result2048 = table2048->find(targetValue);
    double elapsed2048 = double(clock() - startTime) / CLOCKS_PER_SEC * 10000000;

    QString message = "Search results:\n\n"
                      "HashTable 16: Result: " + QString::number(result16) + ", Time: " + QString::number(elapsed16/10000) + " ms\n"
                                                                                               "HashTable 64: Result: " + QString::number(result64) + ", Time: " + QString::number(elapsed64/10000) + " ms\n"
                                                                                               "HashTable 128: Result: " + QString::number(result128) + ", Time: " + QString::number(elapsed128/10000) + " ms\n"
                                                                                                 "HashTable 2048: Result: " + QString::number(result2048) + ", Time: " + QString::number(elapsed2048/10000) + " ms";

    QGraphicsView *view = ui->graphicsView;
    QGraphicsScene *scene = new QGraphicsScene(this);
    view->setScene(scene);
    QGraphicsRectItem *bar1 = new QGraphicsRectItem(0, -(elapsed16), 50, elapsed16);
    QGraphicsRectItem *bar2 = new QGraphicsRectItem(55, -(elapsed64), 50, elapsed64);
    QGraphicsRectItem *bar3 = new QGraphicsRectItem(110, -(elapsed128), 50, elapsed128);
    QGraphicsRectItem *bar4 = new QGraphicsRectItem(165, -(elapsed2048), 50, elapsed2048);
    scene->addItem(bar1);
    scene->addItem(bar2);
    scene->addItem(bar3);
    scene->addItem(bar4);

    QMessageBox::information(this, "Search Results", message);
}


void MainWindow::on_bnt_regen_clicked()
{
    table16 = new MyHashTable(16);
    table16->generateRandomTable(1, 10, 16);
    printHashTable(ui->tableWidget16, table16);

    table64 = new MyHashTable(64);
    table64->generateRandomTable(1, 10, 64);
    printHashTable(ui->tableWidget64, table64);

    table128 = new MyHashTable(128);
    table128->generateRandomTable(1, 10, 128);
    printHashTable(ui->tableWidget128, table128);

    table2048 = new MyHashTable(2048);
    table2048->generateRandomTable(1, 10, 2048);
    printHashTable(ui->tableWidget2048, table2048);
}

