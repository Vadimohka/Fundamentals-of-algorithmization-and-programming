#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int i = 0; i < 10; ++i) {
        set.insert(QRandomGenerator::global()->bounded(100));
        map.insert(QRandomGenerator::global()->bounded(100), QRandomGenerator::global()->bounded(100));
    }

    ui->mapTable->horizontalHeader()->setStretchLastSection(true);

    displayMap();
    displaySet();

    setFixedSize(size());

    setWindowTitle("Map + set");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayMap()
{
    ui->mapTable->clear();
    ui->mapTable->setRowCount(map.size());
    int i = 0;
    for (auto& el : map) {
        ui->mapTable->setItem(i, 0, new QTableWidgetItem(QString::number(el.key)));
        ui->mapTable->setItem(i, 1, new QTableWidgetItem(QString::number(el.val)));
        i++;
    }
}

void MainWindow::displaySet()
{
    QString text = "";
    for (auto& el : set) {
        text += QString::number(el.key) + " ";
    }
    ui->setLabel->setText(text);
}

void MainWindow::on_mapInsertButton_clicked()
{
    map.insert(ui->keySpinBox->value(), ui->valSpinBox->value());
    displayMap();
}

void MainWindow::on_mapRemoveButton_clicked()
{
    map.erase(ui->keySpinBox->value());
    displayMap();
}

void MainWindow::on_mapContainsButton_clicked()
{
    ui->mapResLabel->setText(map.contains(ui->keySpinBox->value()) ? "ДА" : "НЕТ");
}


void MainWindow::on_mapClearButton_clicked()
{
    map.clear();
    displayMap();
}


void MainWindow::on_setInsertButton_clicked()
{
    set.insert(ui->setValSpinBox->value());
    displaySet();
}


void MainWindow::on_setRemoveButton_clicked()
{
    set.erase(ui->setValSpinBox->value());
    displaySet();
}


void MainWindow::on_setContainsButton_clicked()
{
    ui->setResLabel->setText(set.contains(ui->setValSpinBox->value()) ? "ДА" : "НЕТ");
}


void MainWindow::on_setClearButton_clicked()
{
    set.clear();
    displaySet();
}

