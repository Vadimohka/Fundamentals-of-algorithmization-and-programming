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

void MainWindow::on_addButton_clicked()
{
    numbers.push_back(ui->spinBox->value());
    ui->vectorEdit->setText("");
    for (int i : numbers) {
        ui->vectorEdit->setText(ui->vectorEdit->text() + QString::number(i) + " ");
    }
}

void MainWindow::on_deleteButton_clicked()
{
    if (!numbers.empty()) {
        numbers.pop_back();
        ui->vectorEdit->setText("");
        for (int i : numbers) {
            ui->vectorEdit->setText(ui->vectorEdit->text() + QString::number(i) + " ");
        }
    }
}

void MainWindow::on_deleteAllButton_clicked()
{
    if (!numbers.empty()) {
        numbers.clear();
        ui->vectorEdit->setText("");
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if ((event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
        && ui->spinBox->hasFocus()) {
        numbers.push_back(ui->spinBox->value());
        ui->vectorEdit->setText("");
        for (int i : numbers) {
            ui->vectorEdit->setText(ui->vectorEdit->text() + QString::number(i) + " ");
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->medianEdit->setText("");

    for (int i = 0; i < numbers.size(); i += 3) {
        QVector<int> temp;
        for (int j = i; j < qMin(i + 3, numbers.size()); ++j) {
            temp.push_back(numbers[j]);
        }
        std::sort(temp.begin(), temp.end());
        if (temp.size() == 3) {
            ui->medianEdit->setText(ui->medianEdit->text() + QString::number(temp[1]) + " ");
        }

        else {
            double sum = 0;
            for (int value : temp) {
                sum += value;
            }
            ui->medianEdit->setText(ui->medianEdit->text() + QString::number(sum / temp.size())
                                    + " ");
        }
    }
}
