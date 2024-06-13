#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bitset = new BitSet(15);

    ui->lineEdit->setText(bitset->to_string());
    connect(ui->allButton, &QPushButton::clicked, this, &MainWindow::demonstrateAll);
    connect(ui->anyButton, &QPushButton::clicked, this, &MainWindow::demonstrateAny);
    connect(ui->countButton, &QPushButton::clicked, this, &MainWindow::demonstrateCount);
    connect(ui->noneButton, &QPushButton::clicked, this, &MainWindow::demonstrateNone);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::demonstrateReset);
    connect(ui->setButton, &QPushButton::clicked, this, &MainWindow::demonstrateSet);
    connect(ui->getSizeButton, &QPushButton::clicked, this, &MainWindow::demonstrateGetSize);
    connect(ui->ullongButton, &QPushButton::clicked, this, &MainWindow::demonstrateUllong);
    connect(ui->ulongButton, &QPushButton::clicked, this, &MainWindow::demonstrateUlong);
    connect(ui->flipButton, &QPushButton::clicked, this, &MainWindow::demonstrateFlip);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::demonstrateAll()
{
    ui->label_ans->setText("ans: " + QString(bitset->all() ? "true" : "false"));
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::demonstrateAny()
{
    ui->label_ans->setText("ans: " + QString(bitset->any() ? "true" : "false"));
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::demonstrateCount()
{
    qDebug() << 1;
    ui->label_ans->setText("ans: " + QString(QString::number(bitset->count())));
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::demonstrateNone()
{
    ui->label_ans->setText("ans: " + QString(bitset->none() ? "true" : "false"));
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::demonstrateReset()
{
    bitset->reset();
    ui->label_ans->setText("");
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::demonstrateSet()
{
    bitset->set();
    ui->label_ans->setText("");
    ui->lineEdit->setText(bitset->to_string());
    qDebug() << bitset->to_string();
}


void MainWindow::demonstrateGetSize()
{
    ui->label_ans->setText("ans: " + (QString::number(bitset->getSize())));
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::demonstrateUllong()
{
    ui->label_ans->setText("ans: " + (QString::number(bitset->to_ullong())));
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::demonstrateUlong()
{
    ui->label_ans->setText("ans: " + QString::number(bitset->to_ulong()));
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::demonstrateFlip()
{
    bitset->flip();
    ui->label_ans->setText("");
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::on_pushButton_flipArg_clicked()
{
    bitset->flip(ui->spinBox_flip->value());
    ui->label_ans->setText("");
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::on_pushButton_setArg_clicked()
{
    bitset->set(ui->spinBox_set->value());
    ui->label_ans->setText("");
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::on_pushButton_resetArg_clicked()
{
    bitset->reset(ui->spinBox_reset->value());
    ui->label_ans->setText("");
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::on_pushButton_testArg_clicked()
{
    ui->label_ans->setText("ans: " + QString::number(bitset->test(ui->spinBox_test->value())));
    ui->lineEdit->setText(bitset->to_string());
}

