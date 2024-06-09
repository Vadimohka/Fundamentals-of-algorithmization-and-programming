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
}

void MainWindow::on_get_clicked()
{
    try {
        ui->output->setPlainText(QString::number(_map[ui->key->value()]));
    } catch (...) {
        ui->output->setPlainText("no such key");
    }
}

void MainWindow::on_erase_clicked()
{
    _map.erase(ui->key->value());
}

void MainWindow::on_show_clicked()
{
    ui->output->setPlainText(_map.inorderTraversal());
}

void MainWindow::on_clear_clicked()
{
    _map.clear();
}

