#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->graphicsView->setScene(scene);
    //scene->addItem(truck);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void paintEvent(QPaintEvent *event) {

    QPainter painter(this);

    painter.drawRect(QRect(20, 20, 100, 100));
}

