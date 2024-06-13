#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    heap = new TreeHeap();
}

MainWindow::~MainWindow() {
    delete ui;
    delete heap;
}

void MainWindow::on_pushBtn_clicked() {
    heap->insert(ui->inpBox->value());
    updateDisplay();
}

void MainWindow::on_initBtn_clicked() {
    for (int i = 0; i < 256; ++i) {
        heap->insert(std::rand() % 300);
    }
    updateDisplay();
}

void MainWindow::updateDisplay() {
    heap->display(ui->tree);
    ui->maxLbl->setText(QString::number(heap->top()));
}

void MainWindow::on_popBtn_clicked() {
    heap->remove();
    updateDisplay();
}
