#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    scene->setBackgroundBrush(Qt::white);
    ui->graphicsView->setScene(scene);
    ui->label_4->setFixedWidth(200);
    ui->output->setWordWrap(true);
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
    ui->output->setText("Max number: " + QString::number(heap.getMax()));
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
        QMessageBox::warning(nullptr, "Wrong input", "No number with such index.");
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
    ui->output->setText("Size: " + QString::number(heap.getSize()));
}
