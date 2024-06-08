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
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_On_insert_2_clicked()
{
    bst.insert(ui->inBox_2->value());
    scene->clear();
    bst.drawTree(scene,bst.getRoot(),0,0,0);
}


void MainWindow::on_On_find_2_clicked()
{
    bool IsExist = bst.find(ui->inBox_2->value());
    ui->output->setText(IsExist ? "Found!" : "Not Found!");
}


void MainWindow::on_On_delete_2_clicked()
{
    bst.remove(ui->inBox_2->value());
}

void MainWindow::on_On_MaxDepth_2_clicked()
{
    int ancestor = bst.LCA(ui->inBox_3->value(),ui->inBox_4->value());
    ui->output->setText("The common ancestor is: " + QString::number(ancestor));
}

void MainWindow::on_On_clear_2_clicked()
{
    bst.clear();
    scene->clear();
}

void MainWindow::on_On_print_forward_2_clicked()
{
    ui->label->setText(QString::fromStdString(bst.toString()));
    bst.drawTree(scene,bst.getRoot(),0,0,0);
}

