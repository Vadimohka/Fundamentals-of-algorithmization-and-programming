#include "mainwindow.h"
#include "ui_mainwindow.h"\

#include <QTimer>

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

void MainWindow::on_pushButton_push_clicked()
{
    try {
        queue.push(ui->lineEdit_push->text());
        displayQueue();
    } catch (const char* error_message) {
        ui->label_err->setText(error_message);
        QTimer::singleShot(2000, [=]() {
            ui->label_err->setText("");
        });
    }
    ui->lineEdit_push->clear();
}


void MainWindow::on_pushButton_push_pop_clicked()
{
    try {
        queue.pop();
        displayQueue();
    } catch (const char* error_message) {
        ui->label_err->setText(error_message);
        QTimer::singleShot(2000, [=]() {
            ui->label_err->setText("");
        });
    }
}

void MainWindow::displayQueue(){
    ui->listWidget->clear();
    auto res = queue.toVector();
    for (auto & i : res) {
        ui->listWidget->addItem(i);
    }
}


void MainWindow::on_pushButton_push_proc_clicked()
{
    try {
        queue.moveElements(ui->spinBox_n->value(), ui->spinBox_m->value(), ui->spinBox_k->value());
        displayQueue();
    } catch (const char* error_message) {
        ui->label_err->setText(error_message);
        QTimer::singleShot(2000, [=]() {
            ui->label_err->setText("");
        });
    }
}

