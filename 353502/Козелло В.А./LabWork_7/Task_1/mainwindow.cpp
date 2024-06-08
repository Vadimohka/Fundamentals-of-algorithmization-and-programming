#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //    try {
    //        d.at(2);
    //    } catch (...) {
    //        qDebug() << "Ошибка";
    //    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushBackButton_clicked()
{
    deque.pushBack(ui->pushBackSpinBox->value());
    ui->pushBackSpinBox->clear();
    showDeque();
}

void MainWindow::on_pushFrontButton_clicked()
{
    deque.pushFront(ui->pushFrontSpinBox->value());
    ui->pushBackSpinBox->clear();
    showDeque();
}

void MainWindow::on_popBackButton_clicked()
{
    deque.popBack();
    showDeque();
}

void MainWindow::on_popFrontButton_clicked()
{
    deque.popFront();
    showDeque();
}

void MainWindow::on_swapButton_clicked()
{
    deque.swapMinMax();
    showDeque();
}

void MainWindow::on_atButton_clicked()
{
    try {
        ui->atResLabel->setText(QString::number(deque.at(ui->atSpinBox->value())));
    } catch (...) {
        ui->atResLabel->setText("Неверный индекс");
    }
}

void MainWindow::on_isEmptyButton_clicked()
{
    if (deque.isEmpty()) {
        ui->isEmptyLabel->setText("true");
    } else {
        ui->isEmptyLabel->setText("false");
    }
}

void MainWindow::on_clearButton_clicked()
{
    deque.clear();
    showDeque();
}

void MainWindow::showDeque()
{
    size_t sz = deque.size();
    if (sz != 0) {
        ui->atSpinBox->setRange(0, sz - 1);
    } else {
        ui->atSpinBox->setRange(0, 0);
    }
    ui->tableWidget->setColumnCount(sz);
    for (size_t i = 0; i < sz; i++) {
        ui->tableWidget->setItem(0, i, new QTableWidgetItem(QString::number(deque.at(i))));
    }
    ui->tableWidget->resizeColumnsToContents();
}
