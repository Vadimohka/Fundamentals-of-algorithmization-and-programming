#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <triangle.h>
#include <circle.h>
#include <line.h>
#include <brush.h>
#include <square.h>
#include <rectangle.h>
#include <rhombus.h>
#include <hexagon.h>
#include <star.h>
#include <ellipse.h>

#include <QGraphicsProxyWidget>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QMessageBox>
#include <QGraphicsView>
#include <QLabel>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);

    label = new QLabel(this);
    ui->statusbar->addWidget(label);
    label->setText("To rotate, select a point and press R.          Use the arrows to move");

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    timer = new QTimer(this);
    timer->start(200);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateAreaDisplay(QString newArea) {
    ui->Square->setText("S: " + newArea);
}

void MainWindow::updatePerimetrDisplay(QString newP) {
    ui->Perimetr->setText("P: " + newP);
}

void MainWindow::updateCenterDisplay(QString newX, QString newY) {
    ui->CenterX->setText("CenterX: " + newX);
    ui->CenterY->setText("CenterY: " + newY);
}

void MainWindow::infoFigure(Figure* figure){
    static double oldS = figure->S;
    static double oldP = figure->P;
    static int oldX = figure->centerX;
    static int oldY = figure->centerY;
    connect(timer, &QTimer::timeout, [this, figure]{
        figure->findSquare();
        figure->findPerimetr();
        if (figure->S != oldS) {
            MainWindow::updateAreaDisplay(QString::number(figure->S));
            oldS = figure->S;
        }
        if (figure->P != oldP) {
            MainWindow::updatePerimetrDisplay(QString::number(figure->P));
            oldP = figure->P;
        }
        if (figure->centerX != oldX || figure->centerY != oldY) {
            MainWindow::updateCenterDisplay(QString::number(figure->centerX), QString::number(figure->centerY));
            oldX = figure->centerX;
            oldY = figure->centerY;
        }
    });
}

void MainWindow::on_StarButton_clicked(){
    QMessageBox message;
    message.setText("Choose star: ");

    QAbstractButton* button1 = message.addButton("5", QMessageBox::YesRole);
    QAbstractButton* button2 = message.addButton("6", QMessageBox::NoRole);
    QAbstractButton* button3 = message.addButton("8", QMessageBox::RejectRole);

    message.exec();

    Star * st;

    if(message.clickedButton() == button1){
        st = new Star(5);
    } else if(message.clickedButton() == button2){
        st = new Star(6);
    } else if(message.clickedButton() == button3){
        st = new Star(8);
    }
    scene->addItem(st);

    infoFigure(st);
}

void MainWindow::on_TriangleButton_clicked(){
    Triangle *tr = new Triangle();
    scene->addItem(tr);
    infoFigure(tr);
}

void MainWindow::on_CircleButton_clicked(){
    Circle *cr = new Circle();
    scene->addItem(cr);
    infoFigure(cr);
}

void MainWindow::on_LineButton_clicked(){
    Line *ln = new Line();
    scene->addItem(ln);
    infoFigure(ln);
}

void MainWindow::on_ClearButton_clicked(){
    QGraphicsScene *scene1 = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene1);
    scene = scene1;
}

void MainWindow::on_BrushButton_clicked(){
    QGraphicsScene *scene1 = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene1);
    scene = scene1;

    Brush *br = new Brush();
    scene->addItem(br);
    infoFigure(br);
}

void MainWindow::on_SquareButton_clicked(){
    Square *sq = new Square();
    scene->addItem(sq);
    infoFigure(sq);
}

void MainWindow::on_RectangleButton_clicked(){
    Rectangle *rec = new Rectangle();
    scene->addItem(rec);
    infoFigure(rec);
}

void MainWindow::on_RhombusButton_clicked(){
    Rhombus *rh = new Rhombus();
    scene->addItem(rh);
    infoFigure(rh);
}

void MainWindow::on_HexagonButton_clicked(){
    Hexagon *hg = new Hexagon();
    scene->addItem(hg);
    infoFigure(hg);
}

void MainWindow::on_EllipseButton_clicked(){
    Ellipse *el = new Ellipse();
    scene->addItem(el);
    infoFigure(el);
}
