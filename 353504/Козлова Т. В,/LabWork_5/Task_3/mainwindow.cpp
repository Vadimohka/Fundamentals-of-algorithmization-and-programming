#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int i = 0; i < 100; ++i)
        if (QRandomGenerator::global()->bounded(2) - 1 == 0) bitset.set(i);

    ui->label->setText(QString::fromUtf8(bitset.to_string()).first(50) + "\n" +
                       QString::fromUtf8(bitset.to_string()).last(50));

    connect(ui->setBtn, &QPushButton::clicked, [&]() {
        bitset.set(ui->spinBox->value());
        ui->label->setText(QString::fromUtf8(bitset.to_string()).first(50) + "\n" +
                           QString::fromUtf8(bitset.to_string()).last(50));
    });

    connect(ui->flipBtn, &QPushButton::clicked, [&]() {
        bitset.flip(ui->spinBox->value());
        ui->label->setText(QString::fromUtf8(bitset.to_string()).first(50) + "\n" +
                           QString::fromUtf8(bitset.to_string()).last(50));
    });

    connect(ui->resetBtn, &QPushButton::clicked, [&]() {
        bitset.reset(ui->spinBox->value());
        ui->label->setText(QString::fromUtf8(bitset.to_string()).first(50) + "\n" +
                           QString::fromUtf8(bitset.to_string()).last(50));
    });

    connect(ui->setAllBtn, &QPushButton::clicked, [&]() {
        bitset.set();
        ui->label->setText(QString::fromUtf8(bitset.to_string()).first(50) + "\n" +
                           QString::fromUtf8(bitset.to_string()).last(50));
    });

    connect(ui->flipAllBtn, &QPushButton::clicked, [&]() {
        bitset.flip();
        ui->label->setText(QString::fromUtf8(bitset.to_string()).first(50) + "\n" +
                           QString::fromUtf8(bitset.to_string()).last(50));
    });

    connect(ui->resetAllBtn, &QPushButton::clicked, [&]() {
        bitset.reset();
        ui->label->setText(QString::fromUtf8(bitset.to_string()).first(50) + "\n" +
                           QString::fromUtf8(bitset.to_string()).last(50));
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
