#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_set_clicked()
{
    _map[ui->key->value()] = ui->value->value();
    update();
}


void MainWindow::on_get_clicked()
{
    try {
        ui->line->setText(QString::number(_map[ui->key->value()]));
    } catch (...) {
        ui->line->setText("no such key");
    }
}


void MainWindow::on_erase_clicked()
{
    _map.erase(ui->key->value());
    update();
}


void MainWindow::on_rehash_clicked()
{
    if (ui->value->value() > 0) {
        _map.rehash(ui->value->value());
        update();
    } else {
        ui->line->setText("you can't");
    }
}


void MainWindow::on_clear_clicked()
{
    _map.clear();
    update();
}

void MainWindow::update()
{
    ui->table->setRowCount(0);
    ui->table->setColumnCount(0);

    auto data = _map.table();
    size_t numRows = data.size();
    size_t numCols = 0;
    for (auto array : data) {
        numCols = qMax(numCols, array.size());
    }
    ui->table->setRowCount(numRows);
    ui->table->setColumnCount(numCols);

    for (size_t row = 0; row < numRows; ++row) {
        for (size_t col = 0; col < data[row].size(); ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(
                QString::number(data[row][col].first) + " - key " +
                QString::number(data[row][col].second) + " - value"
                );
            ui->table->setItem(row, col, item);
        }
    }

    // ui->line->clear();
    // for (auto now : data) {
    //     ui->line->insert(QString::number(now.first) + " - key " +
    //                      QString::number(now.second) + " - value");
    // }
}

