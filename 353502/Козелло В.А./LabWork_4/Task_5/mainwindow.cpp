#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushBack_spinBoxDouble->hide();
    ui->emplace_spinBoxDouble->hide();
    ui->pushBack_spinBoxDouble->setRange(-1e20, 1e20);
    ui->emplace_spinBoxDouble->setRange(-1e20, 1e20);
    ui->pushBack_spinBoxInt->setRange(INT_MIN, INT_MAX);
    ui->emplace_spinBoxInt->setRange(INT_MIN, INT_MAX);
    ui->emplaceNum_spinBox->setRange(0, 0);
    ui->eraseNum_spinBox->clear();
    ui->eraseNum_spinBox->setRange(0, 0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    table = index;
    if (index == 1) {
        ui->pushBack_spinBoxDouble->show();
        ui->emplace_spinBoxDouble->show();
    } else {
        ui->pushBack_spinBoxDouble->hide();
        ui->emplace_spinBoxDouble->hide();
    }
}

void MainWindow::on_pushBack_button_clicked()
{
    if (table == 0) {
        matrix.first.push_back(ui->pushBack_spinBoxInt->value());
    } else if (table == 1) {
        matrix.second.emplace_back(ui->pushBack_spinBoxInt->value(),
                                   ui->pushBack_spinBoxDouble->value());
    }
    updateTable();
}

void MainWindow::on_popBack_button_clicked()
{
    if (table == 0) {
        matrix.first.pop_back();
    } else if (table == 1) {
        matrix.second.pop_back();
    }
    updateTable();
}

void MainWindow::on_emplace_button_clicked()
{
    if (table == 0) {
        matrix.first.emplace(ui->emplaceNum_spinBox->value() - 1, ui->emplace_spinBoxInt->value());
    } else if (table == 1) {
        matrix.second.emplace(ui->emplaceNum_spinBox->value() - 1,
                              ui->emplace_spinBoxInt->value(),
                              ui->emplace_spinBoxDouble->value());
    }
    updateTable();
}

void MainWindow::on_erase_button_clicked()
{
    if (table == 0) {
        matrix.first.erase(ui->eraseNum_spinBox->value() - 1);
    } else if (table == 1) {
        matrix.second.erase(ui->eraseNum_spinBox->value() - 1);
    }
    updateTable();
}

void MainWindow::updateTable()
{
    if (table == 0) {
        ui->emplaceNum_spinBox->setRange(1, matrix.first.size() + 1);
        ui->eraseNum_spinBox->setRange(1, matrix.first.size());
        ui->firstTable->setRowCount(matrix.first.size());
        for (int i = 0; i < matrix.first.size(); i++) {
            ui->firstTable->setItem(i, 0, new QTableWidgetItem(QString::number(matrix.first[i])));
        }
    } else {
        ui->emplaceNum_spinBox->setRange(1, matrix.second.size() + 1);
        ui->eraseNum_spinBox->setRange(1, matrix.second.size());
        ui->secondTable->setRowCount(matrix.second.size());
        for (int i = 0; i < matrix.second.size(); i++) {
            ui->secondTable->setItem(i,
                                     0,
                                     new QTableWidgetItem(QString::number(matrix.second[i].first)));
            ui->secondTable->setItem(i,
                                     1,
                                     new QTableWidgetItem(QString::number(matrix.second[i].second)));
        }
    }
}
