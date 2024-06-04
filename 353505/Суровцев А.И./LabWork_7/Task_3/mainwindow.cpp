#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    htable = new MyHashTable(5);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete htable;
}

void MainWindow::printHashTable()
{
    auto vec = htable->display();
    ui->tableWidget->clear();

    int maxColumnCount = 0;

    for (const auto& row : vec) {
        if (row.size() > maxColumnCount) {
            maxColumnCount = row.size();
        }
    }

    ui->tableWidget->setColumnCount(maxColumnCount);

    for (int j = 0; j < vec.size(); ++j) {
        QVector<int> currentVec = vec[j];
        ui->tableWidget->setRowCount(j + 1);
        for (int i = 0; i < currentVec.size(); ++i) {
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(currentVec[i]));
            ui->tableWidget->setItem(j, i, item);
        }

        for (int i = currentVec.size(); i < maxColumnCount; ++i) {
            QTableWidgetItem *item = new QTableWidgetItem("nan");
            ui->tableWidget->setItem(j, i, item);
        }
    }
}


void MainWindow::on_bnt_randgen_clicked()
{
    htable->clear();
    htable = new MyHashTable(ui->spb_size->value());
    htable->generateRandomTable(ui->spb_lvalue->value(), ui->spb_rvalue->value(), ui->spb_size->value());
    printHashTable();
}


void MainWindow::on_bnt_add_clicked()
{
    htable->insert(ui->spb_key->value(), ui->spb_val->value());
    printHashTable();
}


void MainWindow::on_bnt_printMin_clicked()
{
    int temp = htable->findMinKeyStack();
    QMessageBox::information(this, "Результат!             ", QString::number(temp));
}


void MainWindow::on_bnt_delete_clicked()
{
    htable->remove(ui->spb_remspb->value());
    printHashTable();
}

