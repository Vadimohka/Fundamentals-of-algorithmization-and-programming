#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_insert_clicked()
{
    scene->clear();
    heap.insert(ui->inBox_2->value());
    heap.drawTree(scene, 0, 0, 0, 0);
}

void MainWindow::on_Max_clicked()
{
    ui->output->setText("The Max element is: " + QString::number(heap.getMax()));
}

void MainWindow::on_ExtractMax_clicked()
{
    scene->clear();
    ui->output->setText("The Max element was extracted: " + QString::number(heap.extractMax()));
    heap.drawTree(scene, 0, 0, 0, 0);
}

void MainWindow::on_delete_clicked()
{
    scene->clear();
    heap.remove(ui->inBox_2->value());
    heap.drawTree(scene, 0, 0, 0, 0);
}

void MainWindow::on_print_clicked()
{
    scene->clear();
    ui->label->setText(QString::fromStdString(heap.toString()));
    heap.drawTree(scene, 0, 0, 0, 0);
}

void MainWindow::on_clear_clicked()
{
    heap.clear();
    scene->clear();
    scene->update();
    ui->output->setText("");
    ui->label->setText("");
}

void MainWindow::on_size_clicked()
{
    ui->output->setText("The size is : " + QString::number(heap.getSize()));
}
