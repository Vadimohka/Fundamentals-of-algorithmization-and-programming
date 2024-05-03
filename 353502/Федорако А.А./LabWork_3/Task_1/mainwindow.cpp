#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->doubleSpinBox->setRange(0.0, 100000000000000000.0);


    ui->doubleSpinBox->setDecimals(10);


    qDebug() << solution->binaryRepresentation(12);
}

MainWindow::~MainWindow()
{

    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    double number = ui->doubleSpinBox->value();
    ui->label_2->setText(solution->binaryRepresentation(number));
}

