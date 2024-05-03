#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsRectItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    setWindowTitle("Ханойские башни");
    if (!ui->graphicsView->scene())
        ui->graphicsView->setScene(new QGraphicsScene(this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addRow(){
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
    QTableWidgetItem *pCell = ui->tableWidget->item(ui->tableWidget->rowCount() -1, 0);
    if(!pCell)
    {
        pCell = new QTableWidgetItem;
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 0, pCell);
    }
    pCell->setText(QString::number(towers[0]));

    pCell = ui->tableWidget->item(ui->tableWidget->rowCount() -1, 1);
    if(!pCell)
    {
        pCell = new QTableWidgetItem;
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 1, pCell);
    }
    pCell->setText(QString::number(towers[1]));

    pCell = ui->tableWidget->item(ui->tableWidget->rowCount() -1, 2);
    if(!pCell)
    {
        pCell = new QTableWidgetItem;
        ui->tableWidget->setItem(ui->tableWidget->rowCount() -1, 2, pCell);
    }
    pCell->setText(QString::number(towers[2]));

    if (rings.empty()){
        QVector<QVector<int>> aaa(3);
        QVector<int> a;
        aaa[1] = a;
        aaa[2] = a;
        for (int i = 1; i <= ui->spinBox->value(); ++i) {
            a.push_back(i);
        }
        aaa[0] = a;
        rings.push_back(aaa);
    }
}

void MainWindow::algorithmHTowers(int n, int from = 0, int to = 1, int aux = 2) {

    if (n == 0) return;

    if (n == 1) {
        --towers[from];
        ++towers[to];
        if (!rings.empty()){
            QVector<QVector<int>> aaa(3);
            QVector<int> a = rings.back()[from];
            a.pop_back();
            aaa[from] = a;
            a = rings.back()[to];
            a.push_back(rings.back()[from].back());
            aaa[to] = a;
            aaa[aux] = rings.back()[aux];
            rings.push_back(aaa);
        }
        addRow();
        return;
    }

    algorithmHTowers(n - 1, from, aux, to);
    --towers[from];
    ++towers[to];
    if (!rings.empty()){
        QVector<QVector<int>> aaa(3);
        QVector<int> a = rings.back()[from];
        a.pop_back();
        aaa[from] = a;
        a = rings.back()[to];
        a.push_back(rings.back()[from].back());
        aaa[to] = a;
        aaa[aux] = rings.back()[aux];
        rings.push_back(aaa);
    }
    addRow();
    algorithmHTowers(n - 1, aux, to, from);
}

void MainWindow::on_pushButton_clicked()
{
    towers[0] = ui->spinBox->value();
    towers[1] = 0;
    towers[2] = 0;
    ui->tableWidget->setRowCount(0);
    rings.clear();
    addRow();
    algorithmHTowers(ui->spinBox->value());
    sh = rings.size();
    ui->spinBox_2->setMaximum(sh);
    ui->spinBox_2->setEnabled(true);
    showStep(rings[sh - 1]);
}

void MainWindow::showStep(QVector<QVector<int>> arr)
{
    ui->graphicsView->scene()->clear();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < arr[i].size(); ++j) {
            int towerWidth = 120;
            int diskHeight = 25;
            int diskWidth = 7 * (ui->spinBox->value() - arr[i][j] + 1);
            int gap = 1;
            int x = i * towerWidth - diskWidth / 2;
            int y = ui->graphicsView->height() - (j + 1) * (diskHeight + gap);
            int width = diskWidth;
            int height = diskHeight;
            QGraphicsRectItem *disk = new QGraphicsRectItem(x+100, y, width, height);
            QColor color = QColor::fromHsv(arr[i][j] * 255 / (ui->spinBox->value()), 255, 255);
            disk->setBrush(QBrush(color));
            ui->graphicsView->scene()->addItem(disk);
        }
    }
    ui->pushButton_N->setEnabled(sh != rings.size());
    ui->pushButton_P->setEnabled(sh != 1);
    ui->spinBox_2->setValue(sh);

}


void MainWindow::on_pushButton_P_clicked()
{
    showStep(rings[--sh - 1]);
}


void MainWindow::on_pushButton_N_clicked()
{
    showStep(rings[++sh - 1]);
}


void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    sh = ui->spinBox_2->value();
    showStep(rings[sh - 1]);
}

