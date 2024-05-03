#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include "figures.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer();
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_triangle_clicked()
{
    scene->clear();
    item = new Triangle;
    scene->addItem(item);
    GetInformation();
    item->setFlag(QGraphicsItem::ItemIsMovable);
}

void MainWindow::on_pushButton_square_clicked()
{
    scene->clear();
    item = new Square;
    scene->addItem(item);
    GetInformation();
    item->setFlag(QGraphicsItem::ItemIsMovable);
}

void MainWindow::on_pushButton_rhombus_clicked()
{
    scene->clear();
    item = new Rhombus;
    scene->addItem(item);
    GetInformation();
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->update();
}

void MainWindow::on_pushButton_circle_clicked()
{
    scene->clear();
    item = new Circle;
    scene->addItem(item);
    GetInformation();
    item->setFlag(QGraphicsItem::ItemIsMovable);
}

void MainWindow::on_pushButton_star5_clicked()
{
    scene->clear();
    item = new Star5;
    scene->addItem(item);
    GetInformation();
    item->setFlag(QGraphicsItem::ItemIsMovable);
}

void MainWindow::on_pushButton_star6_clicked()
{
    scene->clear();
    item = new Star6;
    scene->addItem(item);
    GetInformation();
    item->setFlag(QGraphicsItem::ItemIsMovable);
}

void MainWindow::on_pushButton_star8_clicked()
{
    scene->clear();
    item = new Star8;
    scene->addItem(item);
    GetInformation();
    item->setFlag(QGraphicsItem::ItemIsMovable);
}

void MainWindow::on_pushButton_rectangle_clicked()
{
    scene->clear();
    item = new Rectangle;
    scene->addItem(item);
    GetInformation();
    item->setFlag(QGraphicsItem::ItemIsMovable);
}

void MainWindow::on_pushButton_parallel_clicked()
{
    scene->clear();
    item = new Parallelohram;
    scene->addItem(item);
    GetInformation();
    item->setFlag(QGraphicsItem::ItemIsMovable);

}

void MainWindow::on_pushButton_hexagon_clicked()
{
    scene->clear();
    item = new Hexagon;
    scene->addItem(item);
    GetInformation();
    item->setFlag(QGraphicsItem::ItemIsMovable);
}

void MainWindow::GetInformation()
{
    ui->Area->setText(QString::number(item->area()));
    ui->Perimeter->setText(QString::number(item->perimeter()));
    ui->CenterMass->setText("(" + QString::number(item->getCenter().x()) + ";" + QString::number(item->getCenter().y()) + ")");
}

void MainWindow::on_pushButton_sizeup_pressed()
{
    if(item!=nullptr) {
        item->setItem(true);
        connect(timer, SIGNAL(timeout()), this, SLOT(size_slot()));
        timer->start(10);
    }
}

void MainWindow::on_pushButton_sizeup_released()
{
    if(item!=nullptr){
        timer->stop();
        disconnect(timer, SIGNAL(timeout()), this, SLOT(size_slot()));
    }
}

void MainWindow::on_pushButton_sizedown_pressed()
{
    if(item!=nullptr){
        item->setItem(false);
        connect(timer, SIGNAL(timeout()), this, SLOT(size_slot()));
        timer->start(10);
    }
}

void MainWindow::on_pushButton_sizedown_released()
{
    if(item!=nullptr) {
        timer->stop();
        disconnect(timer, SIGNAL(timeout()), this, SLOT(size_slot()));
    }
}

void MainWindow::size_slot()
{
    GetInformation();
    item->getSize();
}

void MainWindow::on_pushButton_moveup_pressed()
{
    if(item!=nullptr) {
        connect(timer, SIGNAL(timeout()), this, SLOT(move_up_slot()));
        timer->start(10);
    }
}

void MainWindow::on_pushButton_moveup_released()
{
    if(item!=nullptr) {
        disconnect(timer, SIGNAL(timeout()), this, SLOT(move_up_slot()));
        timer->stop();
    }
}

void MainWindow::move_up_slot()
{
    if(item!=nullptr) {
        GetInformation();
        item->move_up();
    }
}

void MainWindow::on_pushButton_movedown_pressed()
{
    if(item!=nullptr) {
        connect(timer, SIGNAL(timeout()), this, SLOT(move_down_slot()));
        timer->start(10);
    }
}

void MainWindow::on_pushButton_movedown_released()
{
    if(item!=nullptr) {
        disconnect(timer, SIGNAL(timeout()), this, SLOT(move_down_slot()));
        timer->stop();
    }
}

void MainWindow::move_down_slot()
{    if(item!=nullptr) {
        GetInformation();
        item->move_down();
    }
}

void MainWindow::on_pushButton_moveleft_pressed()
{
    if(item!=nullptr) {
        connect(timer, SIGNAL(timeout()), this, SLOT(move_left_slot()));
        timer->start(10);
    }
}

void MainWindow::on_pushButton_moveleft_released()
{
    if(item!=nullptr) {
        disconnect(timer, SIGNAL(timeout()), this, SLOT(move_left_slot()));
        timer->stop();
    }
}

void MainWindow::move_left_slot()
{
    if(item!=nullptr) {
        GetInformation();
        item->move_left();
    }
}

void MainWindow::on_pushButton_moveright_pressed()
{
    if(item!=nullptr) {
        connect(timer, SIGNAL(timeout()), this, SLOT(move_right_slot()));
        timer->start(10);
    }
}

void MainWindow::on_pushButton_moveright_released()
{
    if(item!=nullptr) {
        disconnect(timer, SIGNAL(timeout()), this, SLOT(move_right_slot()));
        timer->stop();
    }
}

void MainWindow::move_right_slot()
{
    GetInformation();
    item->move_right();
}

void MainWindow::on_pushButton_rotleft_pressed()
{
    if(item!=nullptr) {
        connect(timer, SIGNAL(timeout()), this, SLOT(rotate_left_slot()));
        timer->start(10);
    }
}
void MainWindow::on_pushButton_rotleft_released()
{
    if(item!=nullptr) {
        disconnect(timer, SIGNAL(timeout()), this, SLOT(rotate_left_slot()));
        timer->stop();
    }
}
void MainWindow::on_pushButton_rotright_pressed()
{
    if(item!=nullptr) {
        connect(timer, SIGNAL(timeout()), this, SLOT(rotate_right_slot()));
        timer->start(10);
    }
}
void MainWindow::on_pushButton_rotright_released()
{
    if(item!=nullptr) {
        disconnect(timer, SIGNAL(timeout()), this, SLOT(rotate_right_slot()));
        timer->stop();
    }
}

void MainWindow::rotate_right_slot()
{
    item->rotate_right();
}

void MainWindow::rotate_left_slot()
{
    item->rotate_left();
}

void MainWindow::timer_slot()
{
    timer->stop();
}
