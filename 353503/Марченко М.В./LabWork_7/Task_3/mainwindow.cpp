#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    hashTable = new HashTable(size);
    connect(ui->sizeButton, &QPushButton::clicked, this, &MainWindow::changeSize);
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::add);
    connect(ui->searchButton, &QPushButton::clicked, this, &MainWindow::find);
    connect(ui->removeButton, &QPushButton::clicked, this, &MainWindow::remove);
    connect(ui->clearButton, &QPushButton::clicked, this, &MainWindow::clear);
    connect(ui->taskButton, &QPushButton::clicked, this, &MainWindow::task);
    connect(ui->taskButton1, &QPushButton::clicked, this, &MainWindow::task1);

}

MainWindow::~MainWindow()
{
    delete ui;
    hashTable->clear();
    delete hashTable;
    taskHashTable->clear();
    delete taskHashTable;
}

void MainWindow::add()
{

    int key = ui->keyLineEdit->text().toInt();
    QString string = ui->stringLineEdit->text();
    Data data;
    data.key = key;
    data.value = string;
    hashTable->add(key, string);
    size = hashTable->getTableSize();
    showTable();
    ui->keyLineEdit->clear();
    ui->stringLineEdit->clear();

}

void MainWindow::showTable()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(size);
    ui->tableWidget->setColumnCount(3);

    QStringList headers;
    headers << "Индекс в таблице" << "Ключ" << "Значение";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QVector<QVector<QPair<int, QString>>> res = hashTable->displayHash();

    for (int i = 0; i < res.size(); ++i) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(i)));

        QString keys;
        QString values;
        for (const auto& pair : res[i]) {
            keys += QString::number(pair.first) + " ";
            values += pair.second + " ";
        }
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(keys.trimmed()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(values.trimmed()));
    }
}

void MainWindow::remove()
{
    if (ui->keyLineEdit1->text().isEmpty()) {

        return;
    }

    int key = ui->keyLineEdit1->text().toInt();
    hashTable->remove(key);
    showTable();

}

void MainWindow::find()
{
    int key = ui->keyLineEdit1->text().toInt();
    QString found = hashTable->find(key);
    if (!found.isEmpty()) {
        ui->resultTextEdit->setText(QString("Ключ = %1, Значение = %2").arg(key).arg(found));
    } else {
        ui->resultTextEdit->setText("Ключ не найден либо строка пуста");
    }
}


void MainWindow::clear()
{
    hashTable->clear();
    ui->tableWidget->clear();
}

void MainWindow::changeSize()
{
    clear();
    size = ui->sizeLineEdit->text().toInt();
    hashTable = new HashTable(size);
}


void MainWindow::task()
{
    clear();
    taskHashTable = new TaskHashTable(size);
    taskHashTable->fillWithRandomData(size);
    showTable1();
}

void MainWindow::task1()
{
    taskHashTable->deleteEvenKeys();
    showTable1();
}

void MainWindow::showTable1()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(size);
    ui->tableWidget->setColumnCount(3);

    QStringList headers;
    headers << "Индекс в таблице" << "Ключ" << "Значение";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QVector<QVector<QPair<int, QString>>> res = taskHashTable->displayHash();

    for (int i = 0; i < res.size(); ++i) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(i)));

        QString keys;
        QString values;
        for (const auto& pair : res[i]) {
            keys += QString::number(pair.first) + " ";
            values += pair.second + " ";
        }
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(keys.trimmed()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(values.trimmed()));
    }
}
