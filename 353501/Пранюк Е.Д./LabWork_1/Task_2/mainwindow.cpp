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

    setWindowTitle("Lab 1 Task 2");
    this->setFixedSize(1300, 700);

    ui->spinBox->setRange(-1000,1000);
    ui->spinBox_2->setRange(-1000,1000);

    ui->spinBox_4->setRange(-1000,1000);

    connect(ui->spinBox_4, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::rotateFigure);
    connect(ui->spinBox_3, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::scaleFigure);
    connect(ui->spinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::on_spinBox_valueChanged);
    connect(ui->spinBox_2, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::on_spinBox_2_valueChanged);
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
        item = new Square;
        scene->addItem(item);
    }
    if (index == 3){
        item = new Circle;
        scene->addItem(item);
    }
    if (index == 4){
        item = new Triangle;
        scene->addItem(item);
    }
    if (index == 5){
        item = new Rhombus;
        scene->addItem(item);
    }
    if (index == 6){
        item = new Hexagon;
        scene->addItem(item);
    }
    if (index == 7){
        item=new Custom;
        scene->addItem(item);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_radioButton_2_clicked()
{
    item = new Star5;
    scene->addItem(item);
}
void MainWindow::on_radioButton_3_clicked()
{
    item = new Star6;
    scene->addItem(item);
}
void MainWindow::on_radioButton_clicked()
{
    item = new Star8;
    scene->addItem(item);
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

void MainWindow::SetValueP()
{
    ui->label_10->setText(QString::number(item->perimeter()));
}

void MainWindow::on_pushButton_clicked()
{
    if (item)
    SetValueP();
}

void MainWindow::SetValueA()
{
    ui->label_13->setText(QString::number(item->area()));
}



void MainWindow::on_pushButton_2_clicked()
{
    if (item)
    SetValueA();
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

