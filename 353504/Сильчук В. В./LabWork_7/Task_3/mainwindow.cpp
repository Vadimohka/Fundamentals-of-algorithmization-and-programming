#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int i = 0; i < size; ++i) {
        table.insertItem(QRandomGenerator::global()->bounded(1e9), QRandomGenerator::global()->bounded(1e9));
    }

    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    showTable();

    setCentralWidget(ui->gridLayoutWidget);

    setWindowTitle("Хэш-таблица");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    table.insertItem(ui->spinBox->value(), ui->spinBox_2->value());
    showTable();
}


void MainWindow::on_pushButton_2_clicked()
{
    table.deleteItem(ui->spinBox->value());
    showTable();
}


void MainWindow::on_pushButton_3_clicked()
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
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem());

    for (int i = 0; i < res.size(); ++i)
        for (auto el : res[i])
            ui->tableWidget->item(i, 0)->setText(ui->tableWidget->item(i, 0)->text() + " " + QString::number(el));
}

