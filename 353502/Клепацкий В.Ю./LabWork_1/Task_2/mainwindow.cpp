#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    timer = new QTimer;
    timer->setInterval(10);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateLabel()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateScene()
{
    this->scene->update();
    item->updateCentre();
    item->boundingRect();
    item->update();
}


void MainWindow::on_pushButton_clicked()
{
    item = new Circle();
    connect(item, &Figure::isSceneUpdate, this, &MainWindow::updateScene);
    timer->start();
    scene->addItem(item);
}


void MainWindow::on_pushButton_2_clicked()
{
    item = new Square();
    connect(item, &Figure::isSceneUpdate, this, &MainWindow::updateScene);
    timer->start();
    scene->addItem(item);
}


void MainWindow::on_pushButton_3_clicked()
{
    item = new Rectangle();
    connect(item, &Figure::isSceneUpdate, this, &MainWindow::updateScene);
    timer->start();
    scene->addItem(item);
}


void MainWindow::on_pushButton_4_clicked()
{
    item = new Shestiygol();
    connect(item, &Figure::isSceneUpdate, this, &MainWindow::updateScene);
    timer->start();
    scene->addItem(item);
}


void MainWindow::on_pushButton_5_clicked()
{
    item = new Triangle();
    connect(item, &Figure::isSceneUpdate, this, &MainWindow::updateScene);
    timer->start();
    scene->addItem(item);
}


void MainWindow::on_pushButton_6_pressed()
{
    if (item != nullptr) {
        item->setTransformOriginPoint(item->boundingRect().center());
        ygol -= 5;
        item->setRotation(ygol);
        updateScene();
    }
}

void MainWindow::on_pushButton_7_pressed()
{
    if (item != nullptr) {
        item->setTransformOriginPoint(item->boundingRect().center());
        ygol += 5;
        item->setRotation(ygol);
        updateScene();
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    item = new Rhomb();
    connect(item, &Figure::isSceneUpdate, this, &MainWindow::updateScene);
    timer->start();
    scene->addItem(item);
    //item->isSetup = false;
}

void MainWindow::on_pushButton_9_clicked()
{
    item = new StarFive();
    connect(item, &Figure::isSceneUpdate, this, &MainWindow::updateScene);
    timer->start();
    scene->addItem(item);
    //item->isSetup = false;
}

void MainWindow::updateLabel()
{
    ui->textBrowser->setText("периметр:"+QString::number(item->updateP()));
    ui->textBrowser_2->setText("площадь:"+QString::number(item->updateS()));
}

void MainWindow::on_pushButton_10_clicked()
{
    if (item != nullptr) {
        item->isSetup = 2;
        updateScene();
    }
}

void MainWindow::on_pushButton_11_clicked()
{
    item = new StarSix();
    connect(item, &Figure::isSceneUpdate, this, &MainWindow::updateScene);
    timer->start();
    scene->addItem(item);
}

void MainWindow::on_pushButton_12_clicked()
{
    item = new StarEight();
    connect(item, &Figure::isSceneUpdate, this, &MainWindow::updateScene);
    timer->start();
    scene->addItem(item);
}

void MainWindow::on_pushButton_13_clicked()
{
    if (item != nullptr) {
        item->isSetup = 3;
        updateScene();
    }
}
