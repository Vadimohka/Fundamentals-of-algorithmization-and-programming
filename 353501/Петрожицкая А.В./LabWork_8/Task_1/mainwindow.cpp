#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_insert_clicked()
{
    bsttree.insert(ui->inBox_2->value());
    scene->clear();
    bsttree.drawTree(scene, bsttree.getRoot(), 0, 0, 0);
}

void MainWindow::on_find_clicked()
{
    scene->clear();
    bsttree.drawTree(scene, bsttree.getRoot(), 0, 0, 0);
    bool IsExist = bsttree.find(ui->inBox_2->value());
    ui->output->setText(IsExist ? "Found!" : "Not Found!");
    if (IsExist)
        bsttree.color(scene, bsttree.getRoot(), 0, 0, 0, ui->inBox_2->value());
}

void MainWindow::on_print_forward_clicked()
{
    ui->label->setText(QString::fromStdString(bsttree.toString()));
    bsttree.drawTree(scene, bsttree.getRoot(), 0, 0, 0);
}

void MainWindow::on_clear_clicked()
{
    bsttree.clear();
    scene->clear();
}

void MainWindow::on_delete_2_clicked()
{
    bsttree.remove(ui->inBox_2->value());
    scene->clear();
    bsttree.drawTree(scene, bsttree.getRoot(), 0, 0, 0);
}

void MainWindow::on_MaxDepth_clicked()
{
    int ancestor = bsttree.LCA(ui->inBox_3->value(), ui->inBox_4->value());
    ui->output->setText("The common ancestor is: " + QString::number(ancestor));
}
