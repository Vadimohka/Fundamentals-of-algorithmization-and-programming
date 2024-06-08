#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // htable = new MyHashTable(100);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete htable;
    delete positiveTable;
    // delete negativeTable;
}

void MainWindow::printHashTable(MyHashTable *ht, QTableWidget *qTableW)
{
    auto vec = ht->display();
    qTableW->clear();

    int maxColumnCount = 0;

    for (const auto& row : vec) {
        if (row.size() > maxColumnCount) {
            maxColumnCount = row.size();
        }
    }

    // ui->hSizeLabel->setText(QString::number(htable->h_size));


    qTableW->setColumnCount(maxColumnCount);

    for (int j = 0; j < vec.size(); ++j) {
        QVector<int> currentVec = vec[j];
        qTableW->setRowCount(j + 1);
        for (int i = 0; i < currentVec.size(); ++i) {
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(currentVec[i]));
            qTableW->setItem(j, i, item);
        }

        // for (int i = currentVec.size(); i < maxColumnCount; ++i) {
        //     QTableWidgetItem *item = new QTableWidgetItem();
        //     ui->tableWidget->setItem(j, i, item);
        // }
    }
}

// void MainWindow::printHashTable() {
//     ui->tableWidget->clear();

//     QVector<QVector<int>> hashTableContent = htable->display();
//     int rowCount = 0;
//     for (const auto& slot : hashTableContent) {
//         rowCount += slot.size();
//     }

//     ui->tableWidget->setRowCount(rowCount);
//     ui->tableWidget->setColumnCount(2);
//     ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Key" << "Value");

//     int row = 0;
//     for (int i = 0; i < hashTableContent.size(); ++i) {
//         for (int j = 0; j < hashTableContent[i].size(); ++j) {
//             ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(i))); // Индекс слота как ключ
//             ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(hashTableContent[i][j])));
//             ++row;
//         }
//     }
// }

void MainWindow::on_pushButton1_clicked()
{

    htable = new MyHashTable(ui->spinBox_size->value());
    positiveTable = new MyHashTable(ui->spinBox_size->value());
    negativeTable = new MyHashTable(ui->spinBox_size->value());
    htable->clear();
    positiveTable->clear();
    negativeTable->clear();
    htable->generateRandomTable(ui->spinBox_size->value());
    printHashTable(htable, ui->tableWidget);
}

void MainWindow::splitToPositiveNegative() {
    for (int i = 0; i < htable->h_size; ++i) {
        while (!htable->h_table[i].isEmpty()) {
            int value = htable->h_table[i].peek();
            htable->h_table[i].pop();
            if (value >= 0) {
                positiveTable->h_table[i].push(value);
            } else {
                negativeTable->h_table[i].push(value);
            }
        }
    }
}


void MainWindow::on_pushButton_p_and_n_clicked()
{
    splitToPositiveNegative();
    printHashTable(positiveTable, ui->tableWidget_2);
    printHashTable(negativeTable, ui->tableWidget_3);
}
