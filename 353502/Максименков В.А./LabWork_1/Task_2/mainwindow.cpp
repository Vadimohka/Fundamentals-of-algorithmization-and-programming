#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(0, 0, 600, 600);
    ui->graphicsView->setScene(scene);
    ui->numberOfStarShow->setText(QString::number(numberOfStar));
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

void MainWindow::setNewItem(Shape *newShape, QString newShapeForm)
{
    shape = newShape;
    shape->setShapeNow(newShapeForm);
}

void MainWindow::addingItem()
{
    connect(shape, &Shape::squareSignal, this, &MainWindow::getSquare);
    connect(shape, &Shape::perimetrSignal, this, &MainWindow::getPerimetr);
    connect(shape, &Shape::mouseHasAlreadyClicked, this, &MainWindow::createTriangle);
    connect(shape, &Shape::newItem, this, &MainWindow::setNewItem);
    connect(shape, &Shape::deleteItem, this, &MainWindow::removingItem);
    connect(shape, &Shape::updateShape, this, &MainWindow::updatingFunction);
    connect(shape, &Shape::centerSignal, this, &MainWindow::getCoordinates);
    shape->setSostoyanie(0);
    scene->addItem(shape);
}

void MainWindow::removingItem(Shape *deleteShape)
{
    shape = deleteShape;
    scene->removeItem(shape);
    delete shape;
    shape = nullptr;
    shape->setShapeNow(" ");
    ui->textBrowserX->setText(" ");
    ui->textBrowserY->setText(" ");
    ui->squareBrowser->setText(" ");
    ui->perimetrBrowser->setText(" ");
}

void MainWindow::on_moveButton_clicked()
{
    clearTriangle();
    shape->setSostoyanie(0);
}

void MainWindow::on_resizeButton_clicked()
{
    clearTriangle();
    shape->setSostoyanie(1);
}

void MainWindow::on_deleteButton_clicked()
{
    clearTriangle();
    shape->setSostoyanie(-1);
}

void MainWindow::on_circleButton_clicked()
{
    clearTriangle();
    shape = new Circle();
    shape->setShapeNow("circle");
    addingItem();
}

void MainWindow::on_rectangleButton_clicked()
{
    clearTriangle();
    shape = new Rectangle();
    shape->setShapeNow("rectangle");
    addingItem();
}


void MainWindow::on_squareButton_clicked()
{
    clearTriangle();
    shape = new Square();
    shape->setShapeNow("square");
    addingItem();
}


void MainWindow::on_rombButton_clicked()
{
    clearTriangle();
    shape = new Romb();
    shape->setShapeNow("romb");
    addingItem();
}


void MainWindow::on_triangleButton_clicked()
{
    if (triangle == -1)
    {
        triangle = 0;
        shape = new VirtualShape();
        shape->setShapeNow("virtual shape");
        addingItem();
        shape->setSostoyanie(3);
    }
}


void MainWindow::createTriangle(QPointF point)
{
    if (triangle == 0)
    {
        points.push_back(point);
        triangle = 1;
    }
    else if (triangle == 1)
    {
        points.push_back(point);
        triangle = 2;
    }
    else if (triangle == 2)
    {
        points.push_back(point);
        triangle = -1;
        scene->removeItem(shape);
        shape = new Triangle(points[0], points[1], points[2]);
        shape->setShapeNow("triangle");
        addingItem();
        points = QVector<QPointF> ();
    }
}

void MainWindow::clearTriangle()
{
    if (triangle != -1)
    {
        scene->removeItem(shape);
    }
    triangle = -1;
    points = QVector<QPointF> ();
    updatingFunction();
}

void MainWindow::on_starButton_clicked()
{
    clearTriangle();
    shape = new Star(numberOfStar);
    shape->setShapeNow("star");
    addingItem();
    ui->numberOfStarShow->setText(QString::number(numberOfStar));
}


void MainWindow::on_minusButton_clicked()
{
    clearTriangle();
    numberOfStar--;
    if(numberOfStar < 3)numberOfStar=3;
    ui->numberOfStarShow->setText(QString::number(numberOfStar));
}


void MainWindow::on_plusButton_clicked()
{
    clearTriangle();
    numberOfStar++;
    ui->numberOfStarShow->setText(QString::number(numberOfStar));
}


void MainWindow::on_polygonButton_clicked()
{
    clearTriangle();
    shape = new Star(numberOfStar, true);
    shape->setShapeNow("polygon");
    addingItem();
    ui->numberOfStarShow->setText(QString::number(numberOfStar));
}


void MainWindow::on_updatingButton_clicked()
{
    qreal parametr1 = ui->parametr1->toPlainText().toDouble();
    qreal parametr2 = ui->parametr2->toPlainText().toDouble();
    if (shape->getShapeNow() == "rectangle" || shape->getShapeNow() == "romb" || shape->getShapeNow() == "star")
    {
        shape->reinterpret(parametr1, parametr2);
    }
}

