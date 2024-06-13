#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRandomGenerator>
#include <QElapsedTimer>
#include <QGraphicsRectItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_pushButton_2_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::display(){
    {
        auto vec = table16->displayHash();
        QString ans;
        for (int i = 0; i < vec.size(); ++i) {
            ans += QString::number(i) + ": ";
            ans += QString::number(vec[i].first) + "," + QString::number(vec[i].second) + "\n\n";
        }
        ui->textEdit_16->setText(ans);
    }
    {
        auto vec = table64->displayHash();
        QString ans;
        for (int i = 0; i < vec.size(); ++i) {
            ans += QString::number(i) + ": ";
            ans += QString::number(vec[i].first) + "," + QString::number(vec[i].second) + "\n\n";
        }
        ui->textEdit_64->setText(ans);
    }
    {
        auto vec = table128->displayHash();
        QString ans;
        for (int i = 0; i < vec.size(); ++i) {
            ans += QString::number(i) + ": ";
            ans += QString::number(vec[i].first) + "," + QString::number(vec[i].second) + "\n\n";
        }
        ui->textEdit_128->setText(ans);
    }
    {
        auto vec = table2048->displayHash();
        QString ans;
        for (int i = 0; i < vec.size(); ++i) {
            ans += QString::number(i) + ": ";
            ans += QString::number(vec[i].first) + "," + QString::number(vec[i].second) + "\n\n";
        }
        ui->textEdit_2048->setText(ans);
    }
}

void MainWindow::on_pushButton_clicked()
{
    QElapsedTimer timer;
    timer.start();

    int result16 = table16->findItem(ui->spinBox->value());

    qint64 elapsed16 = timer.elapsed();
    ui->label_16->setText("res: " + QString::number(result16) + " time: " + QString::number(elapsed16) + " ms");

    timer.start();

    int result64 = table64->findItem(ui->spinBox->value());

    qint64 elapsed64 = timer.elapsed();
    ui->label_64->setText("res: " + QString::number(result64) + " time: " + QString::number(elapsed64) + " ms");

    timer.start();

    int result128 = table128->findItem(ui->spinBox->value());

    qint64 elapsed128 = timer.elapsed();
    ui->label_128->setText("res: " + QString::number(result128) + " time: " + QString::number(elapsed128) + " ms");

    timer.start();

    int result2048 = table2048->findItem(ui->spinBox->value());

    qint64 elapsed2048 = timer.elapsed();

    ui->label_2048->setText("res: " + QString::number(result2048) + " time: " + QString::number(elapsed2048) + " ms");

    QGraphicsView *view = ui->graphicsView;
    QGraphicsScene *scene = new QGraphicsScene(this);
    view->setScene(scene);
    QGraphicsRectItem *bar1 = new QGraphicsRectItem(0, -(elapsed16), 50, elapsed16);
    QGraphicsRectItem *bar2 = new QGraphicsRectItem(55, -(elapsed64), 50, elapsed64);
    QGraphicsRectItem *bar3 = new QGraphicsRectItem(110, -(elapsed128), 50, elapsed128);
    QGraphicsRectItem *bar4 = new QGraphicsRectItem(165, -(elapsed2048), 50, elapsed2048);
    scene->addItem(bar1);
    scene->addItem(bar2);
    scene->addItem(bar3);
    scene->addItem(bar4);

}


void MainWindow::on_pushButton_2_clicked()
{
    table16 = new HashTable(16);
    table64 = new HashTable(64);
    table128 = new HashTable(128);
    table2048 = new HashTable(2048);
    for (int i = 0; i < 16; ++i) {
        table16->insertItem(QRandomGenerator::global()->bounded(1, 100), QRandomGenerator::global()->bounded(1, 100));
    }

    for (int i = 0; i < 64; ++i) {
        table64->insertItem(QRandomGenerator::global()->bounded(1, 100), QRandomGenerator::global()->bounded(1, 100));
    }

    for (int i = 0; i < 128; ++i) {
        table128->insertItem(QRandomGenerator::global()->bounded(1, 100), QRandomGenerator::global()->bounded(1, 100));
    }

    for (int i = 0; i < 1024; ++i) {
        table2048->insertItem(QRandomGenerator::global()->bounded(1, 100), QRandomGenerator::global()->bounded(1, 100));
    }
    display();
}

