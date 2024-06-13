#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , heap()
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (ui->spinPush->hasFocus()
        && (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)) {
        heap.push(ui->spinPush->value());
        ui->spinOutput->setValue(heap.max());
        ui->spinSize->setValue(heap.size());
    }
    if (ui->spinPush_2->hasFocus()
        && (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)) {
        heap2.push(ui->spinPush_2->value());
        ui->spinOutput_2->setValue(heap2.max());
        ui->spinSize_2->setValue(heap2.size());
    }
}

void MainWindow::on_popButton_clicked()
{
    if (!heap.empty()) {
        heap.pop();
        ui->spinSize->setValue(heap.size());

        if (!heap.empty()) {
            ui->spinOutput->setValue(heap.max());
        }
    }
    if (heap.empty()) {
        ui->spinOutput->setValue(0);
    }
}

void MainWindow::on_popButton_2_clicked()
{
    if (!heap2.empty()) {
        heap2.pop();
        ui->spinSize_2->setValue(heap2.size());

        if (!heap.empty()) {
            ui->spinOutput_2->setValue(heap2.max());
        }
    }
    if (heap2.empty()) {
        ui->spinOutput_2->setValue(0);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    (ui->stackedWidget->currentIndex() == 0) ? ui->stackedWidget->setCurrentIndex(1)
                                             : ui->stackedWidget->setCurrentIndex(0);
}
