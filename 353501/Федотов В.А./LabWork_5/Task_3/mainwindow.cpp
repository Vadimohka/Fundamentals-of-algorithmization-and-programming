#include "mainwindow.h"
#include "Bitset.h"
#include "ui_mainwindow.h"
#include <qlogging.h>
#include <qpushbutton.h>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);
  
    bitset = nullptr;

    connect(ui->create, &QPushButton::pressed, this, &MainWindow::create);
    connect(ui->reset, &QPushButton::pressed, this, &MainWindow::reset);
    connect(ui->all, &QPushButton::pressed, this, &MainWindow::all);
    connect(ui->any, &QPushButton::pressed, this, &MainWindow::any);
    connect(ui->count, &QPushButton::pressed, this, &MainWindow::count);
    connect(ui->flip, &QPushButton::pressed, this, &MainWindow::flip);
    connect(ui->test, &QPushButton::pressed, this, &MainWindow::test);
    connect(ui->size, &QPushButton::pressed, this, &MainWindow::size);

    create();
}

void MainWindow::updateLineEdit() {
    if (bitset != nullptr) {
        qDebug() << bitset->to_string();
        ui->lineEdit->setText(bitset->to_string());
    }
}

void MainWindow::create( ) {
    int size = ui->spinBox->value();
    if (bitset != nullptr) {
        delete bitset;
        bitset = nullptr;
    }

    if ( size >= 0 && bitset == nullptr) {
        bitset = new Bitset(size);
        updateLineEdit();
    }
}

void MainWindow::reset( ) {
    bitset->reset();
    updateLineEdit();
}

void MainWindow::all() {
    bitset->all() ? ui->allLabel->setText("True") : ui->allLabel->setText("False");
}

void MainWindow::any() {
    bitset->any() ? ui->anyLabel->setText("True") : ui->anyLabel->setText("False");
}

void MainWindow::count() {
    ui->countLabel->setText(QString::number(bitset->count()));
}

void MainWindow::flip() {
    bitset->flip(ui->flipBox->value());
    updateLineEdit();
}

void MainWindow::test() {
    int index = ui->testBox->value();
    bitset->test(index) ? ui->testLabel->setText("True") : ui->testLabel->setText("False");
}

void MainWindow::size( ) {
    ui->sizeLabel->setText(QString::number(bitset->size()));
}