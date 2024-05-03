#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QRegularExpressionValidator>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);


    ui->lineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[1-9]{1,16}"),this));

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::reverse_clicked);
}

void MainWindow::reverse_clicked(){
    QString valueStr = ui->lineEdit->text();
    long long value = valueStr.toLongLong();
    ui->label_output->setText(QString::number(Reverse::reverse(value)));
}
