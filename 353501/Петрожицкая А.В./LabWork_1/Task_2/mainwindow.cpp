#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(new QGraphicsScene(this))
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    this->setFixedSize(1300, 700);

    ui->spinBox->setMinimum(std::numeric_limits<int>::min());
    ui->spinBox->setMaximum(std::numeric_limits<int>::max());
    ui->spinBox_2->setMinimum(std::numeric_limits<int>::min());
    ui->spinBox_2->setMaximum(std::numeric_limits<int>::max());
    ui->spinBox_3->setMinimum(std::numeric_limits<int>::min());
    ui->spinBox_3->setMaximum(std::numeric_limits<int>::max());
    ui->doubleSpinBox->setSingleStep(0.1);
    ui->doubleSpinBox->setMaximum(std::numeric_limits<double>::max());

}

void MainWindow::on_comboBox_activated(int index)
{
    if (index == 0) {
        scene->clear();
    }
    if (index == 1){
        item = new Rectangle;
        scene->addItem(item);
    }
    if (index == 2) {
        item = new Triangle;
        scene->addItem(item);
    }
    if (index == 3){
        item = new Romb;
        scene->addItem(item);
    }
    if (index == 4){
        item = new Circle;
        scene->addItem(item);
    }
    if (index == 5){
        item = new Square;
        scene->addItem(item);
    }
    if (index == 6){
        item = new Hexagon;
        scene->addItem(item);
    }
    if (index == 7){
        item=new Star5;
        scene->addItem(item);
    }
    if (index == 8){
        item=new Star6;
        scene->addItem(item);
    }
    if (index == 9){
        item=new Star8;
        scene->addItem(item);
    }
    if (index == 10){
        item=new Arrow;
        scene->addItem(item);
    }
    if (index == 11){
        item=new Custom;
        scene->addItem(item);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::rotateFigure(int arg1)
{
    if(item)
    {
        item->setRotation(arg1);
    }
}

void MainWindow::scaleFigure(int arg1)
{
    if(item)
    {
        item->setScale(arg1);
    }
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    if(item){
        item->setX(arg1);
    }
}


void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    if (item){
        item->setY(arg1);
    }
}


void MainWindow::on_spinBox_3_valueChanged(int arg1)
{
    if(item)
    {
        item->setRotation(arg1);
    }
}



void MainWindow::on_pushButton_clicked()
{
    if(item){
        ui->label_9->setText(QString::number(item->area()));
        ui->label_7->setText(QString::number(item->perimeter()));
        ui->label_13->setText(QString::number(item->centerX()));
        ui->label_15->setText(QString::number(item->centerY()));
    }
}


void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    if(item)
    {
        item->setScale(arg1);
    }
}

