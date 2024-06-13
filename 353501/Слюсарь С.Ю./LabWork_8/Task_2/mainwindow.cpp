#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    scene->setBackgroundBrush(Qt::white);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_On_insert_clicked()
{
    scene->clear();
    heap.insert(ui->inBox_2->value());
    heap.drawTree(scene,0,0,0,0);
}

void MainWindow::on_On_Max_clicked()
{
    ui->output->setText("The Max element is: " + QString::number(heap.getMax()));
}

void MainWindow::on_On_ExtractMax_clicked()
{
    scene->clear();
    ui->output->setText("The Max element was extracted: " + QString::number(heap.getMax()));
    heap.extractMax();
    heap.drawTree(scene,0,0,0,0);
}

void MainWindow::on_On_delete_clicked()
{
    scene->clear();
    try
    {
        heap.remove(ui->inBox_2->value());
    }
    catch (...)
    {
        QMessageBox::warning(nullptr, "Invalid Input", "There is no element with such index!");
    }

    heap.drawTree(scene,0,0,0,0);
}

void MainWindow::on_On_print_clicked()
{
    scene->clear();
    ui->label->setText(QString::fromStdString(heap.toString()));
    heap.drawTree(scene,0,0,0,0);
}

void MainWindow::on_On_clear_clicked()
{
    heap.clear();
    scene->clear();
    scene->update();
    ui->output->setText("");
    ui->label->setText("");
}

void MainWindow::on_On_size_clicked()
{
    ui->output->setText("The size is : " + QString::number(heap.getSize()));
}
