#include "mainwindow.h"
#include "drumtrack.h"
#include "ui_mainwindow.h"
#include<QPainter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);


    QLinearGradient gradient(0, 0, 0, height());
    gradient.setColorAt(0, QColor(139, 54, 86)); // Темно-розовый цвет
    gradient.setColorAt(1, QColor(94, 6, 101)); // Темно-фиолетовый цвет

    scene->setBackgroundBrush(QBrush(gradient));

    // Устанавливаем ограничивающий прямоугольник для сцены
    scene->setSceneRect(-250, -250, 500,500); // Пример: ширина 500, высота 500
    ui->graphicsView->setScene(scene);
    scene->addLine(0, -1000, 0, 1000, QPen(Qt::darkBlue, 1));  // Вертикальная линия
    scene->addLine(-1000, 0, 1000, 0, QPen(Qt::darkBlue, 1));  // Горизонтальная линия
    rectangle = new Rectangle(-300, -100, 300, 100, this);
    Drumtrack *drumtrack = new Drumtrack(0, 0, 1000, 1000, this);
    scene->addItem(drumtrack);
    scene->addItem(rectangle);
    scene->addLine(0,-1000,0,1000);
    scene->addLine(-1000,0,1000,0);

    connect(ui->Up, SIGNAL(clicked()), this, SLOT(on_Up_clicked()));
    connect(ui->Down, SIGNAL(clicked()), this, SLOT(on_Down_clicked()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Up_clicked()
{

rectangle->moveUp();
}





void MainWindow::on_Down_clicked()
{
rectangle->moveDown();
}




