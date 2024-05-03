#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    //view = new QGraphicsView(this);
    //rectangle = new rectungle();
    ui->graphicsView->setScene(scene);
    //connect(rectangle, &rectungle::sendPerimetr, this, &MainWindow::showPerimetr);
    //connect(rectangle, &rectungle::sendSquare, this, &MainWindow::showSquare);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    scene->clear();

    if(ui->comboBox->currentText() == "Прямоугольник")
    {
        scene->clear();
        basa = new rectungle();
        rectungle *rec = dynamic_cast<rectungle*>(basa);
        int width;
        int height;

        int a = 0;

        abss = 0;

        basa->getParametrs(width, height, width, a);
        basa->draw(scene, width, height, a, abss);

        connect(basa, &rectungle::sendPerimetr, this, &MainWindow::showPerimetr);
        connect(basa, &rectungle::sendSquare, this, &MainWindow::showSquare);
        basa->perSquareMasse(width, height, width);

        x = width/2;
        y = height/2;
        ui->label_8->setText(QString::number(x));
        ui->label_10->setText(QString::number(y));

    }
    else if(ui->comboBox->currentText() == "Квадрат"){
        scene->clear();
        basa = new rectungle();
        rectungle *rec = dynamic_cast<rectungle*>(basa);
        int side;
        int a = 1;
        abss = 0;
        basa->getParametrs(side, side, side, a);
        basa->draw(scene, side, side, a, abss);

        connect(basa, &rectungle::sendPerimetr, this, &MainWindow::showPerimetr);
        connect(basa, &rectungle::sendSquare, this, &MainWindow::showSquare);

        basa->perSquareMasse(side, side, side);

        x = side/2;
        y = side/2;
        ui->label_8->setText(QString::number(x));
        ui->label_10->setText(QString::number(y));
    }
    else if(ui->comboBox->currentText() == "Круг")
    {
        scene->clear();
        basa = new circle();
        circle *cir = dynamic_cast<circle*>(basa);
        int radius;
        int a = 0;
        abss = 0;
        basa->getParametrs(radius, radius, radius, a);
        basa->draw(scene, radius, radius, a, abss);

        connect(basa, &rectungle::sendPerimetr, this, &MainWindow::showPerimetr);
        connect(basa, &rectungle::sendSquare, this, &MainWindow::showSquare);

        basa->perSquareMasse(radius, radius, radius);

        x =radius;
        y = radius;
        ui->label_8->setText(QString::number(x));
        ui->label_10->setText(QString::number(y));
    }
    else if(ui->comboBox->currentText() == "Треугольник")
    {
        scene->clear();
        basa = new trungle();
        trungle *trun = dynamic_cast<trungle*>(basa);
        int side1;
        int side2;
        int side3;
        int a;
        abss = 1;
        basa->getParametrs(side1, side2, side3, a);

        basa->draw(scene, side1, side2, side3, abss);


        connect(basa, &rectungle::sendPerimetr, this, &MainWindow::showPerimetr);
        connect(basa, &rectungle::sendSquare, this, &MainWindow::showSquare);

        basa->perSquareMasse(side1, side2, side3);

        x = (0 + side1 + (side2*side2 - side3*side3 + side1*side1) / (2*side1)) / 3.0;
        y = (0 + 0 + sqrt(side2*side2 - ((side2*side2 - side3*side3 + side1*side1) / (2*side1)) * ((side2*side2 - side3*side3 + side1*side1) / (2*side1)))) / 3.0;
        ui->label_8->setText(QString::number(x));
        ui->label_10->setText(QString::number(y));
    }
    else if(ui->comboBox->currentText() == "Ромб")
    {
        scene->clear();
        basa = new romb();
        romb *rom = dynamic_cast<romb*>(basa);
        int side1;
        int height;
        int a;
        abss = 0;
        basa->getParametrs(side1, side1, side1, a);

        basa->draw(scene, side1, side1, side1, height);


        connect(basa, &rectungle::sendPerimetr, this, &MainWindow::showPerimetr);
        connect(basa, &rectungle::sendSquare, this, &MainWindow::showSquare);

        basa->perSquareMasse(side1, height, a);

        x = (0 + side1 + 2*side1 + side1) / 4.0;
        y = (height/2 + 0 + height/2 + height) / 4.0;
        ui->label_8->setText(QString::number(x));
        ui->label_10->setText(QString::number(y));
    }
}


void MainWindow::on_pushButton_2_pressed()
{
    plus = new QTimer(this);
    plus->start(65);
    connect(plus, &QTimer::timeout, this, &MainWindow::plusZoom);
}



void MainWindow::on_pushButton_3_pressed()
{
    minus = new QTimer(this);
    minus->start(65);
    connect(minus, &QTimer::timeout, this, &MainWindow::minusZoom);

}

void MainWindow::plusZoom(){
    ui->graphicsView->scale(1.2, 1.2);
}

void MainWindow::minusZoom(){
    ui->graphicsView->scale(1/1.2, 1/1.2);
}


void MainWindow::on_pushButton_2_released()
{
    plus->stop();
}


void MainWindow::on_pushButton_3_released()
{
    minus->stop();
}

void MainWindow::showPerimetr(double perimetr){
    ui->label_4->setText(QString::number(perimetr));
}

void MainWindow::showSquare(double square){
    ui->label_5->setText(QString::number(square));
}



void MainWindow::on_pushButton_4_pressed()
{
    up = new QTimer(this);
    up->start(65);
    connect(up, &QTimer::timeout, this, &MainWindow::mUp);
}

void MainWindow::mUp()
{
    basa->up(scene, x ,y);
    ui->label_8->setText(QString::number(x));
    ui->label_10->setText(QString::number(y));
}

void MainWindow::on_pushButton_4_released()
{
    up->stop();
}

void MainWindow::on_pushButton_5_pressed()
{
    down = new QTimer(this);
    down->start(65);
    connect(down, &QTimer::timeout, this, &MainWindow::mDown);
}

void MainWindow::mDown()
{
    basa->down(scene, x, y);
    ui->label_8->setText(QString::number(x));
    ui->label_10->setText(QString::number(y));
}

void MainWindow::on_pushButton_5_released()
{
    down->stop();
}


void MainWindow::on_pushButton_6_pressed()
{
    left = new QTimer(this);
    left->start(65);
    connect(left, &QTimer::timeout, this, &MainWindow::mLeft);
}

void MainWindow::mLeft()
{
    //basa->left(basa, scene, x, y);
    //this->acceptDrops()

    basa->left(scene, x, y);
    ui->label_8->setText(QString::number(x));
    ui->label_10->setText(QString::number(y));

}

void MainWindow::on_pushButton_6_released()
{
    left->stop();

}


void MainWindow::on_pushButton_7_pressed()
{
    right = new QTimer(this);
    right->start(65);
    connect(right, &QTimer::timeout, this, &MainWindow::mRight);
}

void MainWindow::mRight()
{
    basa->right(scene, x ,y);
    ui->label_8->setText(QString::number(x));
    ui->label_10->setText(QString::number(y));
}

void MainWindow::on_pushButton_7_released()
{
    right->stop();
}



void MainWindow::on_pushButton_8_pressed()
{
    rotateLef = new QTimer(this);
    rotateLef->start(65);
    connect(rotateLef, &QTimer::timeout, this, &MainWindow::rotateL);
}

void MainWindow::rotateL()
{

    basa->rotateLeft(scene, x, y, abss);
}

void MainWindow::on_pushButton_8_released()
{
    rotateLef->stop();
}



void MainWindow::on_pushButton_9_pressed()
{
    rotateRig = new QTimer(this);
    rotateRig->start(65);
    connect(rotateRig, &QTimer::timeout, this, &MainWindow::rotateR);
}

void MainWindow::rotateR()
{
    basa->rotateRight(scene, x, y, abss);
}


void MainWindow::on_pushButton_9_released()
{
    rotateRig->stop();
}


void MainWindow::on_pushButton_10_clicked()
{
    basa->centerMasse(scene, x, y);
    ui->label_8->setText(QString::number(x));
    ui->label_10->setText(QString::number(y));
}


void MainWindow::on_pushButton_11_clicked()
{
    basa->moveToObject(ui->graphicsView, x, y);
}
