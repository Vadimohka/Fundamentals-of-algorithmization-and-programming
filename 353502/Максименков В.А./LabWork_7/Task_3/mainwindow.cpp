#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->insertButton, &QPushButton::clicked, this, &MainWindow::insertElement);
    connect(ui->removeButton, &QPushButton::clicked, this, &MainWindow::deleteElement);
    connect(ui->deleteEvenButton, &QPushButton::clicked, this, &MainWindow::deleteEvenKeys);

    srand(time(nullptr));
    int temp = 0;
    for (int i = 0; i < size; ++i)
    {
        temp = 1 + rand() % MAX_KEY_SIZE;// максимальный ключ
        table.insertItem(temp, temp);
    }

    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    showTable();
    setCentralWidget(ui->gridLayoutWidget);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::insertElement()
{
    table.insertItem(ui->spinBox->value(), ui->spinBox_2->value());
    showTable();
}


void MainWindow::deleteElement()
{
    table.deleteItem(ui->spinBox->value());
    showTable();
}


void MainWindow::deleteEvenKeys()
{
    table.deleteEvenKeys();
    showTable();
}


void MainWindow::showTable()
{
    ui->tableWidget->clear();
    QVector<QVector<int>> res = table.displayHash();
    ui->tableWidget->setRowCount(res.size());

    for (int i = 0; i < res.size(); ++i)
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem());
    }

    for (int i = 0; i < res.size(); ++i)
    {
        for (auto el : res[i])
        {
            ui->tableWidget->item(i, 0)->setText(ui->tableWidget->item(i, 0)->text() + " " + QString::number(el));
        }
    }
}

