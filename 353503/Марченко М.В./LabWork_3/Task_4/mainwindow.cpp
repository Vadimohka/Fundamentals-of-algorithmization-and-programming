#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::GetHanoi);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::GetHanoi()
{
    ui->list->clear();
    QString text = ui->lineEdit->text();

    if (text.isEmpty()) {

        return;
    }

    bool ok;

    int n = text.toInt(&ok);

    if (ok&& n>0) {
        moveCount = 0;
        hanoi(n);
        QString moveС = "Количество перемещений " + QString::number(moveCount);
        ui->list->addItem(moveС);
    } else {
        QMessageBox::critical(this, "Ошибка", "Некорректное значение!");
    }

}

void MainWindow::hanoi(int n, char One, char Two, char Three)
{
    if (n == 1) {
        QString move = "Кольцо " + QString::number(n) + " перемещается из " + One + " в " + Three;
        ui->list->addItem(move);
         moveCount++;
        return;
    }

    hanoi(n - 1, One, Three, Two);
    QString move = "Кольцо " + QString::number(n) + " перемещается из " + One + " в " + Three;
    ui->list->addItem(move);
    moveCount++;
    hanoi(n - 1, Two, One, Three);
}


