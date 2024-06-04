#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QGraphicsScene>
#include "translate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Перевод в двоичную систему счисления");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_TranslateButton_clicked(){
    double x = 0.0;

    QString s = ui->textEdit->toPlainText();
    x = s.toDouble();

    Translate str;
    ui->ResultText->setText("Result: " + str.TranslateToBin(x));
}

