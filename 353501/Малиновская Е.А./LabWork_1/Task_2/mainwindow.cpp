#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui -> graphicsView -> setScene(scene);

    timer = new QTimer(this);
    circle = new Circle();
    triangle = new Triangle();
    rectangle = new Rectangle();
    star = new Star();
    rhombus = new Rhombus();
    square = new Square();
    right_polygone = new Right_Polygone();
    clear_scene = new Clear_scene();


    shapesArray[0] = circle;
    shapesArray[1] = rectangle;
    shapesArray[2] = right_polygone;
    shapesArray[3] = rhombus;
    shapesArray[4] = square;
    shapesArray[5] = star;
    shapesArray[6] = triangle;
    shapesArray[7] = clear_scene;


    ui->rotate_frame->hide();
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    connect(ui->comboBox, &QComboBox::activated,ui->frames, &QStackedWidget::setCurrentIndex);
    connect(ui->cahgexspinbox,&QDoubleSpinBox::valueChanged,this,&MainWindow::startChangeX);
    connect(ui->changeyspinbox,&QDoubleSpinBox::valueChanged,this,&MainWindow::startChangeY);
    connect(ui->sizespinbox,&QDoubleSpinBox::valueChanged,this,&MainWindow::startChangeSize);
    connect(ui->rotationspinbox,&QDoubleSpinBox::valueChanged,this,&MainWindow::change_rotation_start);
    connect(ui->rotationcenterXspinbox,&QDoubleSpinBox::valueChanged,this,&MainWindow::change_rotationcenterX_start);
    connect(ui->rotationcenterYspinbox,&QDoubleSpinBox::valueChanged,this,&MainWindow::change_rotationcenterY_start);
    ui->frames->hide();
    ui->Changeframe->hide();
    ui->connectCenterButton->hide();
    ui->comboBox -> setCurrentIndex(7);
}


void MainWindow::on_comboBox_activated(int index)
{
    if(index == 7){
        ui->calculateArea_label->hide();
        ui->calculatePerimeter_label->hide();
        ui->text_label2->hide();
        ui->text_label3->hide();
        //paintchoose = true;
        ui->Changeframe->hide();
        ui->rotate_frame->hide();
        ui->connectCenterButton->hide();
        scene->removeItem(shapesArray[shapeIndex]);
    }
    else {
    ui->calculateArea_label->show();
    ui->calculatePerimeter_label->show();
    ui->text_label2->show();
    ui->text_label3->show();
    ui->Changeframe->show();
    ui ->rotate_frame ->show();
    ui->connectCenterButton->show();

    scene->removeItem(shapesArray[shapeIndex]);
    shapeIndex = index;
    scene->addItem(shapesArray[shapeIndex]);
    ui->graphicsView->viewport()->update();
    ui->frames->show();
    ui->spinbox_angle_rh->setValue(60);
    ui->changeyspinbox->setValue(0);
    ui->cahgexspinbox->setValue(0);
    ui->rotationspinbox->setValue(0);
    ui->sizespinbox->setValue(0);
    ui->rotationcenterXspinbox->setValue(0);
    ui->rotationcenterYspinbox->setValue(0);
    shapesArray[shapeIndex]->X = 0;
    shapesArray[shapeIndex]->Y = 0;
    shapesArray[shapeIndex]->rotateAngle = 0;
    shapesArray[shapeIndex]->size = 1;
    shapesArray[shapeIndex]->centerConnected = true;
    shapesArray[shapeIndex]->rotateCenterX = 0;
    shapesArray[shapeIndex]->rotateCenterY = 0;
    on_connectCenterButton_toggled(shapesArray[shapeIndex]->centerConnected);
    ui->connectCenterButton->setChecked(true);
    setInformation();
    }
}

//circlespinbox for rad
void MainWindow::on_radiusSpinBox_valueChanged(double arg1)
{

    shapesArray[shapeIndex]->changerad(arg1);
    ui->graphicsView->viewport()->update();
    setInformation();
}

void MainWindow::setInformation()
{
    ui->calculateArea_label->setText(QString::number(shapesArray[shapeIndex]->calculateArea()));
    ui->calculatePerimeter_label->setText(QString::number(shapesArray[shapeIndex]->calculatePerimeter()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//animation spinx
//move x
void MainWindow::startChangeX(double value)
{
    currentvalue = shapesArray[shapeIndex]->X;
    targetvalue = value;
    connect(timer,&QTimer::timeout,this,&MainWindow::handlerChangeX);
    timer->start(15);
}
void MainWindow::handlerChangeX(){
    if(currentvalue < targetvalue){
        currentvalue++;
        shapesArray[shapeIndex]->moveX(currentvalue);
        ui->graphicsView->viewport()->update();
        setInformation();
    }
    else if(currentvalue > targetvalue){
        currentvalue--;
        shapesArray[shapeIndex]->moveX(currentvalue);
        ui->graphicsView->viewport()->update();
        setInformation();
    }
    else{
        finishChangeX();
    }
}
void MainWindow::finishChangeX(){
    disconnect(timer, &QTimer::timeout, this, &MainWindow::handlerChangeX);
    timer->stop();
}
//move y
void MainWindow::startChangeY(double value)
{
    currentvalue = shapesArray[shapeIndex]->Y;
    targetvalue = value;
    connect(timer,&QTimer::timeout,this,&MainWindow::handlerChangeY);
    timer->start(15);
}
void MainWindow::handlerChangeY(){
    if(currentvalue < targetvalue){
        currentvalue++;
        shapesArray[shapeIndex]->moveY(currentvalue);
        ui->graphicsView->viewport()->update();
        setInformation();
    }
    else if(currentvalue > targetvalue){
        currentvalue--;
        shapesArray[shapeIndex]->moveY(currentvalue);
        ui->graphicsView->viewport()->update();
        setInformation();
    }
    else{
        finishChangeY();
    }
}
void MainWindow::finishChangeY(){
    disconnect(timer, &QTimer::timeout, this, &MainWindow::handlerChangeY);
    timer->stop();
}
//size change
void MainWindow::startChangeSize(double value)
{
    currentvalue = shapesArray[shapeIndex]->size;
    targetvalue = value;
    connect(timer,&QTimer::timeout,this,&MainWindow::changesizehandler);
    timer->start(15);
}
void MainWindow::changesizehandler(){
    if(currentvalue < targetvalue){
        currentvalue += 0.25;
        shapesArray[shapeIndex]->changesize(currentvalue);
        ui->graphicsView->viewport()->update();
        setInformation();
    }
    else if(currentvalue > targetvalue){
        currentvalue -= 0.25;
        shapesArray[shapeIndex]->changesize(currentvalue);
        ui->graphicsView->viewport()->update();
        setInformation();
    }
    else{
        changesizecomplete();
    }
}
void MainWindow::changesizecomplete(){
    disconnect(timer, &QTimer::timeout, this, &MainWindow::changesizehandler);
    timer->stop();
}
//rotation animation
void MainWindow::change_rotation_start(double value)
{
    currentvalue = shapesArray[shapeIndex]->rotateAngle;
    targetvalue = value;
    connect(timer,&QTimer::timeout,this,&MainWindow::change_rotation_handler);
    timer->start(15);
}
void MainWindow::change_rotation_handler(){
    if(currentvalue < targetvalue){
        currentvalue++;
        shapesArray[shapeIndex]->rotate(currentvalue);
        ui->graphicsView->viewport()->update();
        setInformation();
    }
    else if(currentvalue > targetvalue){
        currentvalue--;
        shapesArray[shapeIndex]->rotate(currentvalue);
        ui->graphicsView->viewport()->update();
        setInformation();
    }
    else{
        change_rotation_complete();
    }
}
void MainWindow::change_rotation_complete(){
    disconnect(timer, &QTimer::timeout, this, &MainWindow::change_rotation_handler);
    timer->stop();
}
//rotation center x
void MainWindow::change_rotationcenterX_start(double value)
{
    currentvalue = shapesArray[shapeIndex]->rotateCenterX;
    targetvalue = value;
    connect(timer,&QTimer::timeout,this,&MainWindow::change_rotationcenterX_handler);
    timer->start(15);
}
void MainWindow::change_rotationcenterX_handler(){
    if(currentvalue < targetvalue){
        currentvalue++;
        shapesArray[shapeIndex]->changerotateCenterX(currentvalue);
        ui->graphicsView->viewport()->update();
        setInformation();
    }
    else if(currentvalue > targetvalue){
        currentvalue--;
        shapesArray[shapeIndex]->changerotateCenterX(currentvalue);
        ui->graphicsView->viewport()->update();
        setInformation();
    }
    else{
        change_rotationcenterX_complete();
    }
}
void MainWindow::change_rotationcenterX_complete(){
    disconnect(timer, &QTimer::timeout, this, &MainWindow::change_rotationcenterX_handler);
    timer->stop();
}
//rotate center y
void MainWindow::change_rotationcenterY_start(double value)
{
    currentvalue = shapesArray[shapeIndex]->rotateCenterY;
    targetvalue = value;
    connect(timer,&QTimer::timeout,this,&MainWindow::change_rotationcenterY_handler);
    timer->start(15);
}
void MainWindow::change_rotationcenterY_handler(){
    if(currentvalue < targetvalue){
        currentvalue++;
        shapesArray[shapeIndex]->changerotateCenterY(currentvalue);
        ui->graphicsView->viewport()->update();
        setInformation();
    }
    else if(currentvalue > targetvalue){
        currentvalue--;
        shapesArray[shapeIndex]->changerotateCenterY(currentvalue);
        ui->graphicsView->viewport()->update();
        setInformation();
    }
    else{
        change_rotationcenterY_complete();
    }
}
void MainWindow::change_rotationcenterY_complete(){
    disconnect(timer, &QTimer::timeout, this, &MainWindow::change_rotationcenterY_handler);
    timer->stop();
}
//triangle frame
void MainWindow::on_side1trianglespin_valueChanged(double arg1)
{
    triangle->changeSide1(arg1);
    ui->graphicsView->viewport()->update();
    setInformation();
}


void MainWindow::on_side2trianglespin_valueChanged(double arg1)
{
    triangle->changeSide2(arg1);
    ui->graphicsView->viewport()->update();
    setInformation();
}


void MainWindow::on_side3trianglespin_valueChanged(double arg1)
{
    triangle->changeSide3(arg1);
    ui->graphicsView->viewport()->update();
    setInformation();
}


void MainWindow::on_heightrectspinbox_valueChanged(double arg1)
{
    rectangle->changeHeight(arg1);
    ui->graphicsView->viewport()->update();
    setInformation();
}


void MainWindow::on_widthrectspinbox_valueChanged(double arg1)
{
    rectangle->changeWidth(arg1);
    ui->graphicsView->viewport()->update();
    setInformation();
}

void MainWindow::on_apexes_spinbox_valueChanged(int arg1)
{
    star->number_apexes(arg1);
    ui->graphicsView->viewport()->update();
    setInformation();
}


void MainWindow::on_radius1_spinbox_valueChanged(double arg1)
{
    star->change_radius1(arg1);
    ui->graphicsView->viewport()->update();
    setInformation();
}


void MainWindow::on_radius2_spinbox_valueChanged(double arg1)
{
    star->change_radius2(arg1);
    ui->graphicsView->viewport()->update();
    setInformation();
}



void MainWindow::on_spinboxnumapexes_rp_valueChanged(int arg1)
{
    right_polygone->number_apexes(arg1);
    ui->graphicsView->viewport()->update();
    setInformation();
}


void MainWindow::on_spinboxside_rd_valueChanged(double arg1)
{
    right_polygone->changeSide(arg1);
    ui->graphicsView->viewport()->update();
    setInformation();
}


void MainWindow::on_spinbox_angle_rh_valueChanged(double arg1)
{
    rhombus->changeAngle(arg1);
    ui->graphicsView->viewport()->update();
    setInformation();
}


void MainWindow::on_spinbox_side_rh_valueChanged(double arg1)
{
    rhombus->changeSide(arg1);
    ui->graphicsView->viewport()->update();
    setInformation();
}


void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    square->changeSide(arg1);
    ui->graphicsView->viewport()->update();
    setInformation();
}


void MainWindow::on_connectCenterButton_toggled(bool checked)
{
    if(checked){
        shapesArray[shapeIndex]->centerConnected = true;
        ui->rotate_frame->hide();
    }
    else{
        shapesArray[shapeIndex]->centerConnected = false;
        ui->rotate_frame->show();
    }
    ui->graphicsView->viewport()->update();
}

