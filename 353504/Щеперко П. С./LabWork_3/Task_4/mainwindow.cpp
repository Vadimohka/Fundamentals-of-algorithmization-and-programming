#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(new QGraphicsScene(this))
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    ui->inputLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("(10)|[1-9]"), this));
    mainTower = new HanoiTowers();
    scene->addItem(mainTower);
    ui->restartPushButton->setEnabled(false);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    ui->tableWidget->setColumnCount(2);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mainTower;
}

void MainWindow::Hanoi(int n, char source, char buffer, char target)
{
    if (n == 1) {
        moveDisk(n, source, target);
    } else {
        Hanoi(n - 1, source, target, buffer);
        moveDisk(n, source, target);
        Hanoi(n - 1, buffer, source, target);
    }
}

void MainWindow::moveDisk(int number, char source, char target)
{
    mainTower->finished = false;
    while (!mainTower->finished) {
        mainTower->animate(10 - number, source, target);
        QCoreApplication::processEvents();
    }
    ui->tableWidget->setRowCount(row);
    QTableWidgetItem *itm = new QTableWidgetItem(QString(source));
    ui->tableWidget->setItem(row - 1, 0, itm);
    itm = new QTableWidgetItem(QString(target));
    ui->tableWidget->setItem(row - 1, 1, itm);
    ui->tableWidget->scrollToBottom();
    row++;
    if (source == 'A')
        mainTower->lastEmptyPositionA += 20;
    if (source == 'B')
        mainTower->lastEmptyPositionB += 20;
    if (source == 'C')
        mainTower->lastEmptyPositionC += 20;
    update();
}

void MainWindow::on_startPushButton_clicked()
{
    ui->tableWidget->clear();
    mainTower->isChanging = false;
    mainTower->lastEmptyPositionA -= mainTower->posN[mainTower->n - 1];
    mainTower->lastEmptyPositionB -= mainTower->posN[mainTower->n - 1];
    mainTower->lastEmptyPositionC -= mainTower->posN[mainTower->n - 1];
    ui->startPushButton->setEnabled(false);
    ui->inputLineEdit->setEnabled(false);
    ui->restartPushButton->setEnabled(true);
    Hanoi(mainTower->n, 'A', 'B', 'C');
}

void MainWindow::on_restartPushButton_clicked()
{
    delete mainTower;
    ui -> tableWidget -> clear();
    mainTower = new HanoiTowers();
    scene->addItem(mainTower);
    ui->restartPushButton->setEnabled(false);
    ui->startPushButton->setEnabled(true);
    ui->inputLineEdit->setEnabled(true);
    ui->inputLineEdit->setText("1");
}

void MainWindow::on_inputLineEdit_textEdited(const QString &arg1)
{
    mainTower->changeNumberOfRings(arg1.toInt());
    update();
}

