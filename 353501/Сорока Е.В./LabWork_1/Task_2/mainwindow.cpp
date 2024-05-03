#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer;
    scene = new QGraphicsScene;
    myshape = new NewShape;
    myScene = new NewScene;
    scene1 = new Shape;
    pol = new polygon;
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::Values()
{
    ui->squarenum->setText(QString::number(item->area()));
    ui->lengthnum->setText(QString::number(item->perimeter()));
    ui->centrenum->setText("(" + QString::number(item->getCenter().rx()) + ";" + QString::number(item->getCenter().ry()) + ")");
}


void MainWindow::on_triangle_clicked()
{
    scene -> clear();
    //scene1 -> clear();
    //ui->graphicsView->setScene(scene);
    item = new Triangle;
    scene->addItem(item);
    Values();
}

void MainWindow::paintEvent(QPaintEvent* )
{
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





void MainWindow::on_hexaggon_clicked()
{
    scene -> clear();
    //scene1 -> clear();
    //ui->graphicsView->setScene(scene);
    item = new Hexagon;
    scene ->addItem(item);
    Values();
}


void MainWindow::on_cirrcle_clicked()
{
    scene -> clear();
    //scene1 -> clear();
    //ui->graphicsView->setScene(scene);
    item = new Circle;
    scene ->addItem(item);
    Values();
}


void MainWindow::on_sqquare_clicked()
{
    scene -> clear();
    //scene1 -> clear();
    //ui->graphicsView->setScene(scene);
    item = new Square;
    scene ->addItem(item);
    Values();
}


void MainWindow::on_starfive_clicked()
{
    scene -> clear();
    //scene1 -> clear();
    //ui->graphicsView->setScene(scene);
    item = new Star5;
    scene ->addItem(item);
    Values();
}


void MainWindow::on_starsix_clicked()
{
    scene -> clear();
    //scene1 -> clear();
    //ui->graphicsView->setScene(scene);
    item = new Star6;
    scene ->addItem(item);
    Values();
}


void MainWindow::on_stareight_clicked()
{
    scene -> clear();
    //scene1 -> clear();
    //ui->graphicsView->setScene(scene);
    item = new Star8;
    scene ->addItem(item);
    Values();
}


void MainWindow::on_rrhombus_clicked()
{
    scene -> clear();
    //scene1 -> clear();
    //ui->graphicsView->setScene(scene);
    item = new Rhombus;
    scene ->addItem(item);
    Values();
}


void MainWindow::on_reectangle_clicked()
{
    scene -> clear();
    //scene1 -> clear();
    //ui->graphicsView->setScene(scene);
    item = new rectangle;
    scene ->addItem(item);
    Values();
}


void MainWindow::on_upsize_pressed()
{
    item->setItem(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(size_slot()));
    timer->start(10);
}


void MainWindow::on_upsize_released()
{
    timer->stop();
    disconnect(timer, SIGNAL(timeout()), this, SLOT(size_slot()));
}


void MainWindow::on_downsize_pressed()
{
    item->setItem(false);
    connect(timer, SIGNAL(timeout()), this, SLOT(size_slot()));
    timer->start(10);
}


void MainWindow::on_downsize_released()
{
    timer->stop();
    disconnect(timer, SIGNAL(timeout()), this, SLOT(size_slot()));
}


void MainWindow::size_slot()
{
    Values();
    item->getSize();
}



void MainWindow::moveup_slot()
{
    Values();
    item->move_up();
}


void MainWindow::movedown_slot()
{
    Values();
    item->move_down();
}

void MainWindow::moveleft_slot()
{
    Values();
    item->move_left();
}


void MainWindow::moveright_slot()
{
    Values();
    item->move_right();
}


void MainWindow::on_mooveup_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(moveup_slot()));
    timer->start(10);
}


void MainWindow::on_mooveup_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(moveup_slot()));
    timer->stop();
}


void MainWindow::on_movedownn_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(movedown_slot()));
    timer->start(10);
}


void MainWindow::on_movedownn_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(movedown_slot()));
    timer->stop();
}


void MainWindow::on_mmoveleft_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(moveleft_slot()));
    timer->start(10);
}


void MainWindow::on_mmoveleft_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(moveleft_slot()));
    timer->stop();
}


void MainWindow::on_mmooveright_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(moveright_slot()));
    timer->start(10);
}


void MainWindow::on_mmooveright_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(moveright_slot()));
    timer->stop();
}

void MainWindow::rotateleft_slot()
{
    item->setTransformOriginPoint(QPoint(item->getCenter().rx(),item->getCenter().ry()));
    scene->update();
    item->rotate_left();
}


void MainWindow::rotateright_slot()
{
    item->setTransformOriginPoint(QPoint(item->getCenter().rx(),item->getCenter().ry()));
    scene->update();
    item ->rotate_right();
}

void MainWindow::plusxcentre_slot()
{
    item ->NewCenterX(5);
    update();
}

void MainWindow::minusxcentre_slot()
{
    item ->NewCenterX(-5);
    update();
}

void MainWindow::plusycentre_slot()
{
    item ->NewCenterY(5);
    update();
}

void MainWindow::minusycentre_slot()
{
    item ->NewCenterY(-5);
    update();
}



void MainWindow::on_rrotateleft_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(rotateleft_slot()));
    timer->start(10);
}


void MainWindow::on_rrotateleft_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(rotateleft_slot()));
    timer->stop();
}


void MainWindow::on_rrottateright_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(rotateright_slot()));
    timer->start(10);
}


void MainWindow::on_rrottateright_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(rotateright_slot()));
    timer->stop();
}

void MainWindow::setEnabled(bool)
{

}




void MainWindow::on_xpluscentre_clicked()
{
    plusxcentre_slot();
}


void MainWindow::on_xmminuscentre_clicked()
{
    minusxcentre_slot();
}


void MainWindow::on_tpluuscentre_clicked()
{
    plusycentre_slot();
}


void MainWindow::on_ymiinuscentre_clicked()
{
    minusycentre_slot();
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



void MainWindow::on_newfigure_clicked()
{
    //scene -> clear();
    //ui ->graphicsView->setScene(scene1);
    //scene1->addItem(myshape);
    //Values();
}

