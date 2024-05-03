#include "mainwindow.h"
#include "./ui_mainwindow.h"

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

void MainWindow::on_pushButton_convert_clicked()
{
    long double number = ui->doubleSpinBox->value();
    ui->label_answer_text->setText(b_number.convert_to_binary(number));
}

