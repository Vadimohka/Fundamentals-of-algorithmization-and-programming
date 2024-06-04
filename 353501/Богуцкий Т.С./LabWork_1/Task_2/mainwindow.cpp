#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer;
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);

    item = new Triangle;
    scene->addItem(item);
    Values();
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
    item = new Triangle;
    scene->addItem(item);
    Values();
}

void MainWindow::on_hexaggon_clicked()
{
    scene -> clear();
    item = new Hexagon;
    scene ->addItem(item);
    Values();
}

void MainWindow::on_cirrcle_clicked()
{
    scene -> clear();
    item = new Circle;
    scene ->addItem(item);
    Values();
}

void MainWindow::on_sqquare_clicked()
{
    scene -> clear();
    item = new Square;
    scene ->addItem(item);
    Values();
}

void MainWindow::on_starfive_clicked()
{
    scene -> clear();
    item = new Star5;
    scene ->addItem(item);
    Values();
}

void MainWindow::on_starsix_clicked()
{
    scene -> clear();
    item = new Star6;
    scene ->addItem(item);
    Values();
}

void MainWindow::on_stareight_clicked()
{
    scene -> clear();
    item = new Star8;
    scene ->addItem(item);
    Values();
}

void MainWindow::on_rrhombus_clicked()
{
    scene -> clear();
    item = new Rhombus;
    scene ->addItem(item);
    Values();
}

void MainWindow::on_reectangle_clicked()
{
    scene -> clear();
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
    item ->NewCenter_x(1);
}

void MainWindow::minusxcentre_slot()
{
    item ->NewCenter_x(-1);
}

void MainWindow::plusycentre_slot()
{
    item ->NewCenter_y(1);
}

void MainWindow::minusycentre_slot()
{
    item ->NewCenter_y(-1);
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

void MainWindow::on_xpluscentre_clicked()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(plusxcentre_slot()));
}

void MainWindow::on_xmminuscentre_clicked()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(minusxcentre_slot()));
}

void MainWindow::on_tpluuscentre_clicked()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(plusycentre_slot()));
}

void MainWindow::on_ymiinuscentre_clicked()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(minusycentre_slot()));
}

void MainWindow::on_ellipse_clicked()
{
    scene -> clear();
    item = new ellipse;
    scene ->addItem(item);
    Values();
}

void MainWindow::on_paint_clicked()
{
    scene -> clear();
    paintscene = new paintScene();
    ui -> graphicsView ->setScene(paintscene);
    paintscene ->setSceneRect(0, 0, 650, 420);
}

void MainWindow::on_stop_paint_clicked()
{
    scene -> clear();
    ui->graphicsView->setScene(scene);
}
