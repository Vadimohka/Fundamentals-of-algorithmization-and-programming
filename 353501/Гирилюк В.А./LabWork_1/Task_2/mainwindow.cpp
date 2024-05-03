#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1, 1);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);


    ui->graphicsView->setScene(scene);

    timer = new QTimer();
    timer->setInterval(1);
    connect(timer, &QTimer::timeout, this, &MainWindow::Parameters);
    timer->start();

    ui->Param_Rect->hide();
    ui->Param_Ell->hide();
    ui->Param_Rhomb->hide();
    ui->Param_Sqr->hide();
    ui->Param_Circle->hide();
    ui->Param_Star->hide();
    ui->Param_Poly->hide();
    ui->Param_Triangle->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_activated(int index)
{
    ui->doubleSideA->setValue(100);
    ui->doubleSideB->setValue(50);
    ui->doubleSideSqr->setValue(100);
    ui->doubleMajorAxis->setValue(100);
    ui->doubleMinorAxis->setValue(50);
    ui->doubleRadiusAStar->setValue(100);
    ui->doubleRadiusBStar->setValue(50);
    ui->StarPoints->setValue(5);
    ui->doubleSpinBox_2->setValue(100);
    ui->doubleSpinBox->setValue(50);
    ui->doubleRadiusCircle->setValue(100);
    ui->doubleSidePoly->setValue(100);
    ui->PolyPoints->setValue(5);
    ui->TriangleSideA->setValue(100);
    ui->TriangleSideB->setValue(100);
    ui->TriangleSideC->setValue(100);
    if(shape != nullptr){
        delete shape;
        shape = nullptr;
    }
    if(current_Box != nullptr){
        current_Box->hide();
    }
    scene->clear();
    ui->graphicsView->setScene(nullptr);
    switch (index){
        case 0:
            current_Box = nullptr;
            break;
        case 1:
            circle = new Circle;
            shape = circle;
            current_Box = ui->Param_Circle;
            circle->circleTimer->start();
            break;
        case 2:
            custom = new Custom();
            shape = custom;
            current_Box = nullptr;
            break;
        case 3:
            ell = new Ellipse();
            shape = ell;
            current_Box = ui->Param_Ell;
            ell->ellTimer->start();
            break;
        case 4:
            poly = new Polygon();
            shape = poly;
            current_Box = ui->Param_Poly;
            poly->polyTimer->start();
            break;
        case 5:
            rect = new Rectangle();
            shape = rect;
            current_Box = ui->Param_Rect;
            rect->rectTimer->start();
            break;
        case 6:
            rhomb = new Rhombus();
            shape = rhomb;
            current_Box = ui->Param_Rhomb;
            rhomb->rhombTimer->start();
            break;
        case 7:
            square = new Square();
            shape = square;
            current_Box = ui->Param_Sqr;
            square->sqrTimer->start();
            break;
        case 8:
            star = new Star();
            shape = star;
            current_Box = ui->Param_Star;
            star->starTimer->start();
            break;
        case 9:
            triangle = new Triangle();
            shape = triangle;
            current_Box = ui->Param_Triangle;
            triangle->triangleTimer->start();
            ui->TriangleSideA->setMaximum(triangle->sideB+triangle->sideC);
            ui->TriangleSideB->setMaximum(triangle->sideA+triangle->sideC);
            ui->TriangleSideC->setMaximum(triangle->sideB+triangle->sideA);
            break;
    }
    if(current_Box != nullptr){
        current_Box->show();
    }
    if(shape != nullptr){
        scene->addItem(shape);
        scene->addItem(shape->center);
        if(!shape->timer->isActive()){
            shape->timer->start();
        }
    }
    ui->doubleCoordX->setValue(0);
    ui->doubleCoordY->setValue(0);
    ui->doubleCoordX_2->setValue(0);
    ui->doubleCoordY_2->setValue(0);
    ui->doubleRotateBox->setValue(0);
    ui->doubleScaleBox->setValue(1);
    ui->graphicsView->setScene(scene);
}


void MainWindow::on_doubleCoordX_valueChanged(double arg1)
{
    if(shape != nullptr){
        shape->coordobj_X = arg1;
    }
}


void MainWindow::on_doubleCoordY_valueChanged(double arg1)
{
    if(shape != nullptr){
        shape->coordobj_Y = arg1;
    }
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QSize new_size = event->size();
    ui->doubleCoordX->setMaximum(new_size.width()/2-150);
    ui->doubleCoordX->setMinimum(-new_size.width()/2+150);
    ui->doubleCoordY->setMaximum(new_size.height()/2-25);
    ui->doubleCoordY->setMinimum(-new_size.height()/2+25);

}


void MainWindow::on_doubleRotateBox_valueChanged(double arg1)
{
    if(shape != nullptr){
        shape->rotate = arg1;
    }
}



void MainWindow::on_doubleScaleBox_valueChanged(double arg1)
{
    if(shape != nullptr){
        shape->scale = arg1;
    }
}


void MainWindow::on_Reset_clicked()
{
    ui->doubleSideA->setValue(100);
    ui->doubleSideB->setValue(50);
    ui->doubleSideSqr->setValue(100);
    ui->doubleMajorAxis->setValue(100);
    ui->doubleMinorAxis->setValue(50);
    ui->doubleRadiusAStar->setValue(100);
    ui->doubleRadiusBStar->setValue(50);
    ui->StarPoints->setValue(5);
    ui->doubleSpinBox_2->setValue(100);
    ui->doubleSpinBox->setValue(50);
    ui->doubleRadiusCircle->setValue(100);
    ui->doubleSidePoly->setValue(100);
    ui->PolyPoints->setValue(5);
    ui->TriangleSideA->setValue(100);
    ui->TriangleSideB->setValue(100);
    ui->TriangleSideC->setValue(100);
    if(shape != nullptr){
        delete shape;
        shape = nullptr;
    }
    scene->clear();
    ui->graphicsView->setScene(nullptr);
    int index = ui->comboBox->currentIndex();
    switch (index){
    case 0:
        current_Box = nullptr;
        break;
    case 1:
        circle = new Circle;
        shape = circle;
        circle->circleTimer->start();
        break;
    case 2:
        custom = new Custom();
        shape = custom;
        current_Box = nullptr;
        break;
    case 3:
        ell = new Ellipse();
        shape = ell;
        ell->ellTimer->start();
        break;
    case 4:
        poly = new Polygon();
        shape = poly;
        poly->polyTimer->start();
        break;
    case 5:
        rect = new Rectangle();
        shape = rect;
        rect->rectTimer->start();
        break;
    case 6:
        rhomb = new Rhombus();
        shape = rhomb;
        rhomb->rhombTimer->start();
        break;
    case 7:
        square = new Square();
        shape = square;
        square->sqrTimer->start();
        break;
    case 8:
        star = new Star();
        shape = star;
        star->starTimer->start();
        break;
    case 9:
        triangle = new Triangle();
        shape = triangle;
        triangle->triangleTimer->start();
        ui->TriangleSideA->setMaximum(triangle->sideB+triangle->sideC);
        ui->TriangleSideB->setMaximum(triangle->sideA+triangle->sideC);
        ui->TriangleSideC->setMaximum(triangle->sideB+triangle->sideA);
        break;
    }
    if(shape != nullptr){
        scene->addItem(shape);
        scene->addItem(shape->center);
        if(!shape->timer->isActive()){
            shape->timer->start();
        }
    }
    ui->doubleCoordX->setValue(0);
    ui->doubleCoordY->setValue(0);
    ui->doubleCoordX_2->setValue(0);
    ui->doubleCoordY_2->setValue(0);
    ui->doubleRotateBox->setValue(0);
    ui->doubleScaleBox->setValue(1);
    ui->graphicsView->setScene(scene);
}


void MainWindow::on_doubleCoordX_2_valueChanged(double arg1)
{
    if(shape != nullptr){
        shape->coordCenter_X = arg1;
    }
}


void MainWindow::on_doubleCoordY_2_valueChanged(double arg1)
{
    if(shape != nullptr){
        shape->coordCenter_Y = arg1;
    }
}


void MainWindow::on_doubleSideA_valueChanged(double arg1)
{
    rect->sideA = arg1;
}


void MainWindow::on_doubleSideB_valueChanged(double arg1)
{
    rect->sideB = arg1;
}


void MainWindow::on_doubleMajorAxis_valueChanged(double arg1)
{
    ell->sideA = arg1;
}


void MainWindow::on_doubleMinorAxis_valueChanged(double arg1)
{
    ell->sideB = arg1;
}


void MainWindow::on_doubleSpinBox_2_valueChanged(double arg1)
{
    rhomb->diagA = arg1;
}


void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    rhomb->diagB = arg1;
}


void MainWindow::on_doubleSideSqr_valueChanged(double arg1)
{
    square ->sideA = arg1;
}


void MainWindow::on_doubleRadiusCircle_valueChanged(double arg1)
{
    circle->sideA = arg1;
}

void MainWindow::on_StarPoints_valueChanged(int arg1)
{
    star->count_points = arg1;
    star->update();
}


void MainWindow::on_doubleRadiusAStar_valueChanged(double arg1)
{
    star->radA = arg1;
}


void MainWindow::on_doubleRadiusBStar_valueChanged(double arg1)
{
    star->radB = arg1;
}


void MainWindow::on_doubleSidePoly_valueChanged(double arg1)
{
    poly->radA = arg1;
}


void MainWindow::on_PolyPoints_valueChanged(int arg1)
{
    poly->count_points = arg1;
    poly->update();
}


void MainWindow::on_TriangleSideA_valueChanged(double arg1)
{
    triangle->sideA = arg1;
    ui->TriangleSideB->setMaximum(triangle->sideA+triangle->sideC);
    ui->TriangleSideC->setMaximum(triangle->sideB+triangle->sideA);

}


void MainWindow::on_TriangleSideB_valueChanged(double arg1)
{
    triangle->sideB = arg1;
    ui->TriangleSideA->setMaximum(triangle->sideB+triangle->sideC);
    ui->TriangleSideC->setMaximum(triangle->sideB+triangle->sideA);
}


void MainWindow::on_TriangleSideC_valueChanged(double arg1)
{
    triangle->sideC = arg1;
    ui->TriangleSideB->setMaximum(triangle->sideA+triangle->sideC);
    ui->TriangleSideA->setMaximum(triangle->sideB+triangle->sideC);
}

void MainWindow::Parameters()
{
    if(shape != nullptr){
        ui->Perimeter->setText(QString::number(shape->perimeter));
        ui->Area->setText(QString::number(shape->area));
    }
}

