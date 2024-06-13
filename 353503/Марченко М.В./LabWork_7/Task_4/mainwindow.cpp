#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm>
#include <chrono>
#include <QElapsedTimer>
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    hashTable1 = new HashTable(16);
    hashTable1->fillWithRandomData(16);
    showTable(ui->tableWidget1, hashTable1);
    hashTable2 = new HashTable(64);
    hashTable2->fillWithRandomData(64);
    showTable(ui->tableWidget2,hashTable2);
    hashTable3 = new HashTable(128);
    hashTable3->fillWithRandomData(128);
    showTable(ui->tableWidget3,hashTable3);
    hashTable4 = new HashTable(2048);
    hashTable4->fillWithRandomData(2048);
    showTable(ui->tableWidget4,hashTable4);

    QVector<HashTable> hashTables;
    hashTables.append(*hashTable1);
    hashTables.append(*hashTable2);
    hashTables.append(*hashTable3);
    hashTables.append(*hashTable4);
    updateCollisionTable(ui->tableWidget, hashTables);

    connect(ui->generateButton, &QPushButton::clicked, this, &MainWindow::generate);
    connect(ui->searchButton, &QPushButton::clicked, this, &MainWindow::find);

}

MainWindow::~MainWindow()
{
    delete ui;
    hashTable1->clear();
    delete hashTable1;

}


void MainWindow::showTable(QTableWidget* tableWidget, HashTable *hashTable)
{
    int size = hashTable->getSize();
    tableWidget->clear();
    tableWidget->setRowCount(size);
    tableWidget->setColumnCount(3);

    QStringList headers;
    headers << "Индекс в таблице" << "Ключ" << "Значение";
    tableWidget->setHorizontalHeaderLabels(headers);
    tableWidget->verticalHeader()->setVisible(false);
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QVector<QVector<QPair<int, QString>>> res = hashTable->displayHash();

    for (int i = 0; i < res.size(); ++i) {
        tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(i)));

        QString keys;
        QString values;
        for (const auto& pair : res[i]) {
            keys += QString::number(pair.first) + " ";
            values += pair.second + " ";
        }
        tableWidget->setItem(i, 1, new QTableWidgetItem(keys.trimmed()));
        tableWidget->setItem(i, 2, new QTableWidgetItem(values.trimmed()));
    }
}


void MainWindow::find()
{
    int key = ui->keyLineEdit1->text().toInt();
    QString results;

    auto start1 = std::chrono::high_resolution_clock::now();
    QString found1 = hashTable1->find(key);
    auto end1 = std::chrono::high_resolution_clock::now();
    results += "Таблица 1 - " + (found1.isEmpty() ? "ключ не найден" : found1) + "\n";

    auto start2 = std::chrono::high_resolution_clock::now();
    QString found2 = hashTable2->find(key);
    auto end2 = std::chrono::high_resolution_clock::now();
    results += "Таблица 2 - " + (found2.isEmpty() ? "ключ не найден" : found2) + "\n";

    auto start3 = std::chrono::high_resolution_clock::now();
    QString found3 = hashTable3->find(key);
    auto end3 = std::chrono::high_resolution_clock::now();
    results += "Таблица 3 - " + (found3.isEmpty() ? "ключ не найден" : found3) + "\n";

    auto start4 = std::chrono::high_resolution_clock::now();
    QString found4 = hashTable4->find(key);
    auto end4 = std::chrono::high_resolution_clock::now();
    results += "Таблица 4 - " + (found4.isEmpty() ? "ключ не найден" : found4) + "\n";

    ui->resultTextEdit->setText(results);

    qint64 elapsedMilliseconds1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count();
    qint64 elapsedMilliseconds2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count();
    qint64 elapsedMilliseconds3 = std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3).count();
    qint64 elapsedMilliseconds4 = std::chrono::duration_cast<std::chrono::microseconds>(end4 - start4).count();

    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle("Графики сравнения поиска");

    QGraphicsScene* scene = new QGraphicsScene(dialog);

    scene->setBackgroundBrush(Qt::white);
    qDebug() << "Время поиска в таблице 1 : " << elapsedMilliseconds1;
    qDebug() << "Время поиска в таблице 2 : " << elapsedMilliseconds2;
    qDebug() << "Время поиска в таблице 3 : " << elapsedMilliseconds3;
    qDebug() << "Время поиска в таблице 4 : " << elapsedMilliseconds4;

    QGraphicsRectItem* rect1 = new QGraphicsRectItem(0,  0, elapsedMilliseconds1 * 30, 20);
    QGraphicsRectItem* rect2 = new QGraphicsRectItem(0, 30, elapsedMilliseconds2 * 30, 20);
    QGraphicsRectItem* rect3 = new QGraphicsRectItem(0, 60, elapsedMilliseconds3 * 30, 20);
    QGraphicsRectItem* rect4 = new QGraphicsRectItem(0, 90, elapsedMilliseconds4 * 30, 20);

    scene->addItem(rect1);
    scene->addItem(rect2);
    scene->addItem(rect3);
    scene->addItem(rect4);

    QGraphicsView* view = new QGraphicsView(scene, dialog);
    view->setGeometry(10, 10, 600, 600);

    dialog->exec();
}
void MainWindow::generate()
{
    hashTable1->clear();
    ui->tableWidget1->clear();
    hashTable2->clear();
    ui->tableWidget2->clear();
    hashTable3->clear();
    ui->tableWidget3->clear();
    hashTable4->clear();
    ui->tableWidget4->clear();
    hashTable1 = new HashTable(16);
    hashTable1->fillWithRandomData(10);
    showTable(ui->tableWidget1, hashTable1);
    hashTable2 = new HashTable(64);
    hashTable2->fillWithRandomData(40);
    showTable(ui->tableWidget2,hashTable2);
    hashTable3 = new HashTable(128);
    hashTable3->fillWithRandomData(80);
    showTable(ui->tableWidget3,hashTable3);
    hashTable4 = new HashTable(2048);
    hashTable4->fillWithRandomData(1500);
    showTable(ui->tableWidget4,hashTable4);
    QVector<HashTable> hashTables;

    hashTables.append(*hashTable1);
    hashTables.append(*hashTable2);
    hashTables.append(*hashTable3);
    hashTables.append(*hashTable4);

    updateCollisionTable(ui->tableWidget, hashTables);

}

void MainWindow::updateCollisionTable(QTableWidget* tableWidget, QVector<HashTable>& hashTables) {
    tableWidget->clear();
    tableWidget->setRowCount(0);
    tableWidget->setColumnCount(4);

    QStringList headers;
    headers << "16" << "64" << "128" << "2048";
    tableWidget->setHorizontalHeaderLabels(headers);

    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    int maxCollisions = 0;
    for (const auto& table : hashTables) {
        maxCollisions = std::max(maxCollisions, static_cast<int>(table.getCollisionIndices().size()));

    }

    for (int i = 0; i < maxCollisions; ++i) {
        tableWidget->insertRow(i);
        for (int j = 0; j < hashTables.size(); ++j) {
            if (i < hashTables[j].getCollisionIndices().size()) {
                int collisionIndex = hashTables[j].getCollisionIndices()[i];
                tableWidget->setItem(i, j, new QTableWidgetItem(QString::number(collisionIndex)));
            } else {
                tableWidget->setItem(i, j, new QTableWidgetItem(""));
            }
        }
    }
}
