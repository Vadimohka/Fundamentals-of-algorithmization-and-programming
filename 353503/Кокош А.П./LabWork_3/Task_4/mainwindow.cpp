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

void MainWindow::move(int from, int to, int via, int n)
{
    if (n == 1) {
        output += QString("Move Disk From %1 to %2\n").arg(from).arg(to);
        counter++;
    } else {
        move(from, via, to, n - 1);
        output += QString("Move Disk From %1 to %2\n").arg(from).arg(to);
        move(via, to, from, n - 1);
        counter++;
    }
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->spinBox->value() != 0) {
        output.clear();
        move(1, 3, 2, ui->spinBox->value());
        ui->label->setText(QString("Moves: %1.").arg(counter));
        counter = 0;
        ui->textBrowser->setText(output);
    }
}
