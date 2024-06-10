#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(0, 0, 600, 600);
    ui->graphicsView->setScene(scene);
    ui->fiveStarButton->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updatingFunction()
{
    scene->update();
}

void MainWindow::getCoordinates(QPointF center)
{
    ui->textBrowserX->setText(QString::number(center.x()));
    ui->textBrowserY->setText(QString::number(center.y()));
}

void MainWindow::getSquare(qreal square)
{
    ui->squareBrowser->setText(QString::number(square));
}

void MainWindow::getPerimetr(qreal perimetr)
{
    ui->perimetrBrowser->setText(QString::number(perimetr));
}

void MainWindow::setNewItem(Figure *newFigure, QString newFigureForm)
{
    figure = newFigure;
    figure->setFigureNow(newFigureForm);
}

void MainWindow::addingItem()
{
    connect(figure, &Figure::squareSignal, this, &MainWindow::getSquare);
    connect(figure, &Figure::perimetrSignal, this, &MainWindow::getPerimetr);
    connect(figure, &Figure::newItem, this, &MainWindow::setNewItem);
    connect(figure, &Figure::deleteItem, this, &MainWindow::removingItem);
    connect(figure, &Figure::updateFigure, this, &MainWindow::updatingFunction);
    connect(figure, &Figure::centerSignal, this, &MainWindow::getCoordinates);
    figure->setAction(0);
    scene->addItem(figure);
}

void MainWindow::removingItem(Figure *deleteShape)
{
    figure = deleteShape;
    scene->removeItem(figure);
    delete figure;
    figure = nullptr;
    figure->setFigureNow(" ");
    ui->textBrowserX->setText(" ");
    ui->textBrowserY->setText(" ");
    ui->squareBrowser->setText(" ");
    ui->perimetrBrowser->setText(" ");
}

void MainWindow::on_moveButton_clicked()
{
    figure->setAction(0);
}

void MainWindow::on_deleteButton_clicked()
{
    figure->setAction(-1);
}

void MainWindow::on_circleButton_clicked()
{
    figure = new Circle();
    figure->setFigureNow("circle");
    addingItem();
}

void MainWindow::on_rectangleButton_clicked()
{
    figure = new Rectangle();
    figure->setFigureNow("rectangle");
    addingItem();
}


void MainWindow::on_squareButton_clicked()
{
    figure = new Square();
    figure->setFigureNow("square");
    addingItem();
}


void MainWindow::on_rombButton_clicked()
{
    figure = new Romb();
    figure->setFigureNow("romb");
    addingItem();
}


void MainWindow::on_triangleButton_clicked()
{
    figure = new Star(3, true);
    figure->setFigureNow("polygon");
    addingItem();
}

void MainWindow::on_starButton_clicked()
{
    if(ui->fiveStarButton->isChecked()) numberOfStar = 5;
    if(ui->sixStarButton->isChecked()) numberOfStar = 6;
    if(ui->eightStarButton->isChecked()) numberOfStar = 8;
    figure = new Star(numberOfStar);
    figure->setFigureNow("star");
    addingItem();
}

void MainWindow::on_polygonButton_clicked()
{
    const int numberOfCornersStar = 6;
    figure = new Star(numberOfCornersStar, true);
    figure->setFigureNow("polygon");
    addingItem();
}

void MainWindow::on_leftRotationButton_pressed()
{
    const int intervalTime = 20;
    timer = new QTimer(this);
    timer->setInterval(intervalTime);


    connect(timer, &QTimer::timeout, [&]() {
        figure->setLeftRotation();
    });

    timer->start();
}


void MainWindow::on_leftRotationButton_released()
{
    timer->stop();
}


void MainWindow::on_rightRotationButton_pressed()
{
    const int intervalTime = 20;
    timer = new QTimer(this);
    timer->setInterval(intervalTime);


    connect(timer, &QTimer::timeout, [&]() {
        figure->setRightRotation();
    });

    timer->start();
}


void MainWindow::on_rightRotationButton_released()
{
    timer->stop();
}


void MainWindow::on_minusSizeButton_pressed()
{
    const int intervalTime = 20;
    timer = new QTimer(this);
    timer->setInterval(intervalTime);
    connect(timer, &QTimer::timeout, [&]() {
        figure->resize(0.95);
    });
    timer->start();
}


void MainWindow::on_minusSizeButton_released()
{
    timer->stop();
}


void MainWindow::on_plusSizeButton_pressed()
{
    timer = new QTimer(this);
    timer->setInterval(40);
    connect(timer, &QTimer::timeout, [&]() {
        figure->resize(1.05);
    });

    timer->start();
}


void MainWindow::on_plusSizeButton_released()
{
    timer->stop();
}

