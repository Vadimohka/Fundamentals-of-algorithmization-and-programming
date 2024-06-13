#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(0, 0, 2000, 2000, this);
    ui->graphicsView->setScene(scene);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateScene()
{
    this->scene->update();
}

void MainWindow::printFigureSquare(const double &square)
{
    ui->textBrowser1->setText(QString::number(square));
}

void MainWindow::printFigurePerimetr(const double &perimetr)
{
    ui->textBrowser2->setText(QString::number(perimetr));
}

void MainWindow::printFigureCentre(const QPointF &centre)
{
    ui->textBrowser3->setText("("+QString::number(centre.x())+"; "+QString::number(centre.y())+")");
}

void MainWindow::on_createTriangle_triggered()
{
    items.push_back(new Triangle());
    connect(items.back(), &Figure::printSquare, this, &MainWindow::printFigureSquare);
    connect(items.back(), &Figure::printPerimetr, this, &MainWindow::printFigurePerimetr);
    connect(items.back(), &Figure::printCentre, this, &MainWindow::printFigureCentre);
    connect(items.back(), &Figure::isSceneUpdate, this, &MainWindow::updateScene);
    scene->addItem(items.back());
}


void MainWindow::on_createSquare_triggered()
{
    items.push_back(new Square());
    connect(items.back(), &Figure::printSquare, this, &MainWindow::printFigureSquare);
    connect(items.back(), &Figure::printPerimetr, this, &MainWindow::printFigurePerimetr);
    connect(items.back(), &Figure::printCentre, this, &MainWindow::printFigureCentre);
    connect(items.back(), &Figure::isSceneUpdate, this, &MainWindow::updateScene);
    scene->addItem(items.back());
}

void MainWindow::on_createCircle_triggered()
{
    items.push_back(new Circle());
    connect(items.back(), &Figure::printSquare, this, &MainWindow::printFigureSquare);
    connect(items.back(), &Figure::printPerimetr, this, &MainWindow::printFigurePerimetr);
    connect(items.back(), &Figure::printCentre, this, &MainWindow::printFigureCentre);
    connect(items.back(), &Figure::isSceneUpdate, this, &MainWindow::updateScene);
    scene->addItem(items.back());
}

void MainWindow::on_createStar5_triggered()
{
    items.push_back(new Star5());
    connect(items.back(), &Figure::printSquare, this, &MainWindow::printFigureSquare);
    connect(items.back(), &Figure::printPerimetr, this, &MainWindow::printFigurePerimetr);
    connect(items.back(), &Figure::printCentre, this, &MainWindow::printFigureCentre);
    connect(items.back(), &Figure::isSceneUpdate, this, &MainWindow::updateScene);
    scene->addItem(items.back());
}

void MainWindow::on_createStar6_triggered()
{
    items.push_back(new Star6());
    connect(items.back(), &Figure::printSquare, this, &MainWindow::printFigureSquare);
    connect(items.back(), &Figure::printPerimetr, this, &MainWindow::printFigurePerimetr);
    connect(items.back(), &Figure::printCentre, this, &MainWindow::printFigureCentre);
    connect(items.back(), &Figure::isSceneUpdate, this, &MainWindow::updateScene);
    scene->addItem(items.back());
}

void MainWindow::on_createStar8_triggered()
{
    items.push_back(new Star8());
    connect(items.back(), &Figure::printSquare, this, &MainWindow::printFigureSquare);
    connect(items.back(), &Figure::printPerimetr, this, &MainWindow::printFigurePerimetr);
    connect(items.back(), &Figure::printCentre, this, &MainWindow::printFigureCentre);
    connect(items.back(), &Figure::isSceneUpdate, this, &MainWindow::updateScene);
    scene->addItem(items.back());
}


void MainWindow::on_createParallelogram_triggered()
{
    items.push_back(new Parallelogram());
    connect(items.back(), &Figure::printSquare, this, &MainWindow::printFigureSquare);
    connect(items.back(), &Figure::printPerimetr, this, &MainWindow::printFigurePerimetr);
    connect(items.back(), &Figure::printCentre, this, &MainWindow::printFigureCentre);
    connect(items.back(), &Figure::isSceneUpdate, this, &MainWindow::updateScene);
    scene->addItem(items.back());
}

void MainWindow::on_createRectangle_triggered()
{
    items.push_back(new Rectangle());
    connect(items.back(), &Figure::printSquare, this, &MainWindow::printFigureSquare);
    connect(items.back(), &Figure::printPerimetr, this, &MainWindow::printFigurePerimetr);
    connect(items.back(), &Figure::printCentre, this, &MainWindow::printFigureCentre);
    connect(items.back(), &Figure::isSceneUpdate, this, &MainWindow::updateScene);
    scene->addItem(items.back());
}

void MainWindow::on_createHexagon_triggered()
{
    items.push_back(new Hexagon());
    connect(items.back(), &Figure::printSquare, this, &MainWindow::printFigureSquare);
    connect(items.back(), &Figure::printPerimetr, this, &MainWindow::printFigurePerimetr);
    connect(items.back(), &Figure::printCentre, this, &MainWindow::printFigureCentre);
    connect(items.back(), &Figure::isSceneUpdate, this, &MainWindow::updateScene);
    scene->addItem(items.back());
}

void MainWindow::on_createRhomb_triggered()
{
    items.push_back(new Rhomb());
    connect(items.back(), &Figure::printSquare, this, &MainWindow::printFigureSquare);
    connect(items.back(), &Figure::printPerimetr, this, &MainWindow::printFigurePerimetr);
    connect(items.back(), &Figure::printCentre, this, &MainWindow::printFigureCentre);
    connect(items.back(), &Figure::isSceneUpdate, this, &MainWindow::updateScene);
    scene->addItem(items.back());
}

void MainWindow::on_moveFigure_triggered()
{
    for (auto it:items) {
        it->status = 3;
    }
}

void MainWindow::on_resizeFigure_triggered()
{
    for (auto it:items) {
        it->status = 2;
    }
}

void MainWindow::on_deleteFigure_triggered()
{
    for (auto it:items) {
        it->status = 4;
    }
}

void MainWindow::on_rotateFigure_triggered()
{
    for (auto it:items) {
        it->status = 5;
    }
}
