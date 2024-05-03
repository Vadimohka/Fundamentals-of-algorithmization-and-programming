#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer();
    scene = new QGraphicsScene();
    scene1 = new Shape();
    ui->graphicsView->setScene(scene);
    ui->RectSpinL->setRange(0.0, 500.0);
    ui->RectSpinW->setRange(0.0, 500.0);
    ui->updateSizeR8->setRange(0.0, 120.0);
    ui->TriangleSpinA->setRange(0.0, 100.0);
    ui->TriangleSpinB->setRange(0.0, 100.0);
    ui->TriangleSpinC->setRange(0.0, 100.0);
    ui->updateHexagon->setRange(0.0, 500.0);
    connect(ui->TriangleSpinA, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::updateSizeTrianA);
    connect(ui->TriangleSpinB, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::updateSizeTrianB);
    connect(ui->TriangleSpinC, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::updateSizeTrianC);
    connect(ui->RectSpinL, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::updateSize);
    connect(ui->RectSpinW, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::updateSizeW);
    connect(ui->updateSizeR, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::updateSizeRadius);
    connect(ui->updateSizeR8, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::updateSizeRadius8);
    connect(ui->updateSizeR5, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::updateSizeRadius5);
    connect(ui->updateHexagon, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::updateHexagon);
    setEnabled(false);
    pol = new polygon;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_triangle_clicked()
{
    scene->clear();
    item = new Triangle;
    ui->stackedWidget->setCurrentIndex(1);
    scene->addItem(item);
    SetValue();
    setEnabled(true);
    item->setFlag(QGraphicsItem::ItemIsMovable);
}

void MainWindow::on_pushButton_square_clicked()
{
    scene->clear();
    item = new Square;
    ui->stackedWidget->setCurrentIndex(2);
    scene->addItem(item);
    SetValue();
    setEnabled(true);
    item->setFlag(QGraphicsItem::ItemIsMovable);
}

void MainWindow::on_pushButton_rhombus_clicked()
{
    scene->clear();
    item = new Rhombus;
    ui->stackedWidget->setCurrentIndex(3);
    scene->addItem(item);
    SetValue();
    setEnabled(true);
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->update();
}

void MainWindow::on_pushButton_circle_clicked()
{
    scene->clear();
    item = new Circle;
    ui->stackedWidget->setCurrentIndex(4);
    scene->addItem(item);
    SetValue();
    setEnabled(true);
    item->setFlag(QGraphicsItem::ItemIsMovable);
}

void MainWindow::on_pushButton_star5_clicked()
{
    scene->clear();
    item = new Star5;
    scene->addItem(item);
    ui->stackedWidget->setCurrentIndex(5);
    SetValue();
    setEnabled(true);
    item->setFlag(QGraphicsItem::ItemIsMovable);
}

void MainWindow::on_pushButton_star6_clicked()
{
    scene->clear();
    item = new Star6;
    ui->stackedWidget->setCurrentIndex(6);
    scene->addItem(item);
    SetValue();
    setEnabled(true);
    item->setFlag(QGraphicsItem::ItemIsMovable);
}

void MainWindow::on_pushButton_star8_clicked()
{
    scene->clear();
    item = new Star8;
    ui->stackedWidget->setCurrentIndex(7);
    scene->addItem(item);
    SetValue();
    setEnabled(true);
    item->setFlag(QGraphicsItem::ItemIsMovable);
}

void MainWindow::on_pushButton_rectangle_clicked()
{
    scene->clear();
    item = new rectangle;
    ui->stackedWidget->setCurrentIndex(8);
    scene->addItem(item);
    SetValue();
    setEnabled(true);
    item->setFlag(QGraphicsItem::ItemIsMovable);
}



void MainWindow::on_pushButton_hexagon_clicked()
{
    scene->clear();
    item = new Hexagon;
    ui->stackedWidget->setCurrentIndex(9);
    scene->addItem(item);
    SetValue();
    setEnabled(true);
    item->setFlag(QGraphicsItem::ItemIsMovable);
}

void MainWindow::SetValue()
{
    ui->Area->setText(QString::number(item->area()));
    ui->Perimeter->setText(QString::number(item->perimeter()));
    ui->CenterMass->setText("(" + QString::number(item->getCenter().x()) + ";" + QString::number(item->getCenter().y()) + ")");
}

void MainWindow::on_pushButton_sizeup_pressed()
{
    item->setItem(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(size_slot()));
    timer->start(10);
}

void MainWindow::on_pushButton_sizeup_released()
{
    timer->stop();
    disconnect(timer, SIGNAL(timeout()), this, SLOT(size_slot()));
}

void MainWindow::on_pushButton_sizedown_pressed()
{
    item->setItem(false);
    connect(timer, SIGNAL(timeout()), this, SLOT(size_slot()));
    timer->start(10);
}

void MainWindow::on_pushButton_sizedown_released()
{
    timer->stop();
    disconnect(timer, SIGNAL(timeout()), this, SLOT(size_slot()));
}

void MainWindow::size_slot()
{
    SetValue();
    item->getSize();
}

void MainWindow::on_pushButton_moveup_pressed()//move up
{
    connect(timer, SIGNAL(timeout()), this, SLOT(move_up_slot()));
    timer->start(10);
}

void MainWindow::on_pushButton_moveup_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(move_up_slot()));
    timer->stop();
}

void MainWindow::move_up_slot()
{
    SetValue();
    item->move_up();
}

void MainWindow::on_pushButton_movedown_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(move_down_slot()));
    timer->start(10);
}

void MainWindow::on_pushButton_movedown_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(move_down_slot()));
    timer->stop();
}

void MainWindow::move_down_slot()
{
    SetValue();
    item->move_down();
}

void MainWindow::on_pushButton_moveleft_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(move_left_slot()));
    timer->start(10);
}

void MainWindow::on_pushButton_moveleft_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(move_left_slot()));
    timer->stop();
}

void MainWindow::move_left_slot()
{
    SetValue();
    item->move_left();
}

void MainWindow::on_pushButton_moveright_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(move_right_slot()));
    timer->start(10);
}

void MainWindow::on_pushButton_moveright_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(move_right_slot()));
    timer->stop();
}

void MainWindow::move_right_slot()
{
    SetValue();
    item->move_right();
}

void MainWindow::on_pushButton_rotleft_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(rotate_left_slot()));
    timer->start(10);
}
void MainWindow::on_pushButton_rotleft_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(rotate_left_slot()));
    timer->stop();
}
void MainWindow::on_pushButton_rotright_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(rotate_right_slot()));
    timer->start(10);
}
void MainWindow::on_pushButton_rotright_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(rotate_right_slot()));
    timer->stop();
}

void MainWindow::rotate_right_slot()
{
    item->rotate_right();
}

void MainWindow::rotate_left_slot()
{
    item->rotate_left();
}
 int lastDegree = 0;
void MainWindow::on_pushButton_drawlineon_clicked()
{
    ui->graphicsView->hide();
    ui->stackedWidget->setCurrentIndex(0);
    item=new Line;
    setEnabled(false);
    flag=0;
}
void MainWindow::on_pushButton_drawlineoff_clicked()
{
    ui->graphicsView->show();
    pol->points.resize(0);
    update();
}

void MainWindow::on_pushButton_moveline_clicked()
{
    flag=1;
}

void MainWindow::mousePressEvent(QMouseEvent *me)
{
    if(flag)
    {
        pol->mouseMovePressing(me);
        update();
    }
    else
    {
        pol->mouseMoving(me);
        update();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *me)
{
    if(flag)
    {
        pol->mouseMoveMoving(me);
        update();
    }
    else
    {
        pol->mouseMoving(me);
        update();
    }
}

void MainWindow::timer_slot()
{
    timer->stop();
}

void MainWindow::setEnabled(bool)
{

}

void MainWindow::paintEvent(QPaintEvent* )
{ int lastDegree = 0;
    auto *p = new QPainter(this);
    p->setRenderHint(QPainter::Antialiasing,true);
    p->setPen(Qt::black);
    pol->draw(p,scale);
    p->end();

}

void MainWindow::changeAngle()
{
    pol->rotate(angle);
    update();
}

void MainWindow::on_pushButton_sizelineup_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(size_plus_slot()));
    timer->start(10);
}

void MainWindow::on_pushButton_sizelineup_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(size_plus_slot()));
    timer->stop();
}

void MainWindow::on_pushButton_sizelinedown_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(size_minus_slot()));
    timer->start(10);
}
void MainWindow::on_pushButton_sizelinedown_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(size_minus_slot()));
    timer->stop();
}

void MainWindow::rotate_right_slot1()
{
    angle += 0.1;
    if(angle>180)
    {
        angle=180;
    }
    changeAngle();
}

void MainWindow::rotate_left_slot1()
{
    angle -= 0.1;
    if(angle<-180)
    {
        angle=-180;
    }
    changeAngle();
}

void MainWindow::on_pushButton_rotliner_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(rotate_right_slot1()));
    timer->start(10);
}

void MainWindow::on_pushButton_rotlinel_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(rotate_left_slot1()));
    timer->start(10);
}

void MainWindow::on_pushButton_rotliner_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(rotate_right_slot1()));
    timer->stop();
}

void MainWindow::on_pushButton_rotlinel_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(rotate_left_slot1()));
    timer->stop();
}

void MainWindow::size_plus_slot()
{
    update();
    scale+=0.02;
    auto *p = new QPainter(this);
    p->setPen(Qt::black);
    pol->draw(p,scale);
    p->end();
}

void MainWindow::size_minus_slot()
{
    update();
    scale-=0.02;
    if(scale<0.04)
    {
        scale=0.04;
    }
    auto *p = new QPainter(this);
    p->setPen(Qt::black);
    pol->draw(p,scale);
    p->end();
}



void MainWindow::updateSizeTrianA(double arg1)
{

    item->updateSizeTriangleA(arg1);
    ui->graphicsView->viewport()->update();
}


void MainWindow::updateSizeTrianB(double arg1)
{

    item->updateSizeTriangleB(arg1);
    ui->graphicsView->viewport()->update();
}


void MainWindow::updateSizeTrianC(double arg1)
{

    item->updateSizeTriangleC(arg1);
    ui->graphicsView->viewport()->update();
}
void MainWindow::updateSize(double arg1){
    item->updateSizeStorona(arg1);
    ui->graphicsView->viewport()->update();
}

void MainWindow::updateSizeW(double arg1)
{
    item->updateSizeStoronaW(arg1);
    ui->graphicsView->viewport()->update();
}


void MainWindow::updateSizeRadius(double arg1)
{
    item->updateSizeRadiushaha(arg1);
    ui->graphicsView->viewport()->update();
}


void MainWindow::updateSizeRadius8(double arg1)
{
    item->updateSizeRadiushaha(arg1);
    ui->graphicsView->viewport()->update();
}


void MainWindow::updateSizeRadius5(double arg1)
{
    item->updateSizeRadiushaha(arg1);
    ui->graphicsView->viewport()->update();
}


void MainWindow::updateHexagon(double arg1)
{
    item->updateSizeRadiushaha(arg1);
    ui->graphicsView->viewport()->update();
}

