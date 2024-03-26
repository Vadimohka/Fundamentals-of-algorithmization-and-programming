#include "mainwindow.h"
#include "samosval.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // connect(ui->button1, &QPushButton::clicked, this, &MainWindow::slotUP);
    // // connect(ui->button3, &QPushButton::clicked, this, &MainWindow::slotSTOP);
    // connect(ui->button2, &QPushButton::clicked, this, &MainWindow::slotDOWN);
    connect(ui->button1, SIGNAL(pressed()), SLOT(button1Pressed()));
    connect(ui->button1, SIGNAL(released()), SLOT(button1Released()));
    connect(ui->button2, SIGNAL(pressed()), SLOT(button2Pressed()));
    connect(ui->button2, SIGNAL(released()), SLOT(button2Released()));
    setMinimumSize(1400, 1070);
    setMaximumSize(1400, 1070);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    sam->drawSam(&painter);
}


void MainWindow::slotUP()
{
    sam->UP();
    repaint();

}



void MainWindow::button1Pressed() {
    connect(timer, SIGNAL(timeout()), this, SLOT(slotUP()));
    timer->start(50);
}

void MainWindow::button1Released() {
    disconnect(timer, SIGNAL(timeout()), this, SLOT(slotUP()));
    timer->stop();
}

void MainWindow::button2Pressed() {
    connect(timer, SIGNAL(timeout()), this, SLOT(slotDOWN()));
    timer->start(50);
}

void MainWindow::button2Released() {
    disconnect(timer, SIGNAL(timeout()), this, SLOT(slotDOWN()));
    timer->stop();
}

// void MainWindow::slotSTOP()
// {
//     sam->STOP();
//     repaint();

// }

void MainWindow::slotDOWN()
{
    sam->DOWN();
    repaint();

}
