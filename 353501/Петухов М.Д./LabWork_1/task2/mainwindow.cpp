#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    figuresArray = new Figure *[11];

    circle = new Circle;
    triangle = new Triangle;
    rectangle = new Rectangle;
    rhombus = new Rhombus();
    star = new Star;
    hexagon = new Hexagon();
    myPolyline = new polyline();
    Myscene = new CustomScene(this);

    figuresArray[selectedFigure] = nullptr;
    figuresArray[0] = circle;
    figuresArray[1] = rectangle;
    figuresArray[2] = triangle;
    figuresArray[3] = rhombus;
    figuresArray[4] = star;
    figuresArray[5] = hexagon;
    figuresArray[6] = myPolyline;
    figuresArray[10] = nullptr;

    ui->setupUi(this);

    timer = new QTimer(this);

    ui->graphicsView->setScene(Myscene);

    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    connect(ui->draw, &QPushButton::clicked, this, &MainWindow::selectFigure);

    connect(ui->rotateRight, &QPushButton::pressed, this, &MainWindow::on_rotateRight_pressed);
    connect(ui->rotateRight, &QPushButton::released, this, &MainWindow::on_rotateRight_released);
    connect(ui->rotateLeft, &QPushButton::pressed, this, &MainWindow::on_rotateLeft_pressed);
    connect(ui->rotateLeft, &QPushButton::released, this, &MainWindow::on_rotateLeft_released);

    connect(ui->moveRight, &QPushButton::pressed, this, &MainWindow::on_moveRight_pressed);
    connect(ui->moveRight, &QPushButton::released, this, &MainWindow::on_moveRight_released);
    connect(ui->moveLeft, &QPushButton::pressed, this, &MainWindow::on_moveLeft_pressed);
    connect(ui->moveLeft, &QPushButton::released, this, &MainWindow::on_moveLeft_released);
    connect(ui->moveDown, &QPushButton::pressed, this, &MainWindow::on_moveDown_pressed);
    connect(ui->moveDown, &QPushButton::released, this, &MainWindow::on_moveDown_released);
    connect(ui->moveUp, &QPushButton::pressed, this, &MainWindow::on_moveUp_pressed);
    connect(ui->moveUp, &QPushButton::released, this, &MainWindow::on_moveUp_released);

    connect(ui->increase, &QPushButton::pressed, this, &MainWindow::on_increase_pressed);
    connect(ui->increase, &QPushButton::released, this, &MainWindow::on_increase_released);

    connect(ui->spinBoxPolygon, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::PolygonVertexes);

    connect(ui->widthRectangle, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::setWidthRectangle);
    connect(ui->heightRectangle, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::setHeightRectangle);

    connect(ui->valueAside, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::valueAsideChange);
    connect(ui->valueBside, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::valueBsideChange);
    connect(ui->valueCside, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::valueCsideChange);

    connect(ui->setRhombWidth, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::setRhombWidth);
    connect(ui->setRhombHeight, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::setRhombHeight);

    connect(ui->innerRadiusDown, &QPushButton::pressed, this, &MainWindow::innerRadiusDownPressed);
    connect(ui->innerRadiusDown, &QPushButton::released, this, &MainWindow::innerRadiusDownRealesed);
    connect(ui->innerRadiusUp, &QPushButton::pressed, this, &MainWindow::on_innerRadiusUp_pressed);
    connect(ui->innerRadiusUp, &QPushButton::released, this, &MainWindow::on_innerRadiusUp_released);
    connect(ui->outerRadiusDown, &QPushButton::pressed, this, &MainWindow::outerRadiusDownPressed);
    connect(ui->outerRadiusDown, &QPushButton::released, this, &MainWindow::outerRadiusDownRealesed);
    connect(ui->outerRadiusUp, &QPushButton::pressed, this, &MainWindow::on_outerRadiusUp_pressed);
    connect(ui->outerRadiusUp, &QPushButton::released, this, &MainWindow::on_outerRadiusUp_released);

    connect(Myscene, &CustomScene::mousePressed, this, &MainWindow::onMousePressed);

    connect(ui->disconnectCenter, &QPushButton::clicked, this, &MainWindow::disconnectCenter);
    connect(ui->connectCenter, &QPushButton::clicked, this, &MainWindow::connectCenter);

    connect(ui->ChangePolyline, &QPushButton::clicked, this, &MainWindow::changePolyline);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::selectFigure() {
    Myscene->removeItem(figuresArray[selectedFigure]);

    if (ui->circle->isChecked()){
        ui->commonMethods->show();
        ui->block->hide();
        ui->stackedWidget->setCurrentIndex(0);
        selectedFigure = 0;
    }
    else if (ui->rectangle->isChecked()){
        ui->commonMethods->show();
        ui->block->hide();
        ui->stackedWidget->setCurrentIndex(1);
        selectedFigure = 1;
    }
    else if(ui->triangle->isChecked()){
        ui->commonMethods->show();
        ui->block->hide();
        ui->stackedWidget->setCurrentIndex(2);
        selectedFigure = 2;
    }
    else if(ui->rhombus->isChecked()){
        ui->commonMethods->show();
        ui->block->hide();
        ui->stackedWidget->setCurrentIndex(3);
        selectedFigure = 3;
    }
    else if(ui->Star->isChecked()){
        ui->commonMethods->show();
        ui->block->hide();
        ui->stackedWidget->setCurrentIndex(4);
        selectedFigure = 4;
    }
    else if(ui->Hexagon->isChecked()){
        ui->commonMethods->show();
        ui->block->hide();
        ui->stackedWidget->setCurrentIndex(5);
        selectedFigure = 5;
    }
    else if(ui->polyline->isChecked()){
        wasChangingUsed = false;
        ui->commonMethods->hide();
        ui->block->hide();
        ui->stackedWidget->setCurrentIndex(6);
        selectedFigure = 6;
    }

    if (figuresArray[selectedFigure] != nullptr) {
        figuresArray[selectedFigure]->clear();
        figuresArray[selectedFigure]->points.clear();
        ui->graphicsView->setScene(Myscene);
        Myscene->clear();
        Myscene->addItem(figuresArray[selectedFigure]);
        setInfo();
    }

}

void MainWindow::changePolyline(){
    wasChangingUsed = true;
    ui->commonMethods->show();
}

void MainWindow::disconnectCenter(){
    figuresArray[selectedFigure]->wasCenterDisconnected = true;
    figuresArray[selectedFigure]->disconnectedMoveX = figuresArray[selectedFigure]->moveX;
    figuresArray[selectedFigure]->disconnectedMoveY = figuresArray[selectedFigure]->moveY;
    figuresArray[selectedFigure]->shiftCenter = figuresArray[selectedFigure]->center;//здесь в shiftCenter присваевается center из figure, который {centerX, centerY}(без move)
    ui->graphicsView->viewport()->update();
}

void MainWindow::connectCenter(){
    figuresArray[selectedFigure]->wasCenterDisconnected = false;
    figuresArray[selectedFigure]->move = figuresArray[selectedFigure]->disconnectedMove;
    figuresArray[selectedFigure]->center = figuresArray[selectedFigure]->shiftCenter;
    ui->graphicsView->viewport()->update();
}


void MainWindow::onMousePressed(const QPointF &position)
{
    if(!wasChangingUsed){
        myPolyline->addPoint(position);
        ui->graphicsView->viewport()->update();
    }
}

//increase
void MainWindow::on_increase_pressed()
{
    connect(timer, &QTimer::timeout, this, &MainWindow::upSize);
    timer->start(50);
}

void MainWindow::upSize()
{
    figuresArray[selectedFigure]->upScale();
    setInfo();
    ui->graphicsView->viewport()->update();
}
void MainWindow::on_increase_released()
{
    disconnect(timer, &QTimer::timeout, this, &MainWindow::upSize);
    timer->stop();
}


//decrease
void MainWindow::on_decrease_pressed()
{
    connect(timer, &QTimer::timeout, this, &MainWindow::downSize);
    timer->start(50);
}
void MainWindow::downSize()
{
    figuresArray[selectedFigure]->downScale();
    setInfo();
    ui->graphicsView->viewport()->update();
}
void MainWindow::on_decrease_released()
{
    disconnect(timer, &QTimer::timeout, this, &MainWindow::downSize);
    timer->stop();
}


//Right
void MainWindow::on_moveRight_pressed()
{
    connect(timer, &QTimer::timeout, this, &MainWindow::moveRight);
    timer->start(50);
}
void MainWindow::moveRight()
{
    figuresArray[selectedFigure]->moveRight();
    setInfo();
    ui->graphicsView->viewport()->update();
}
void MainWindow::on_moveRight_released()
{
    disconnect(timer, &QTimer::timeout, this, &MainWindow::moveRight);
    timer->stop();
}


//Down
void MainWindow::on_moveDown_pressed()
{
    connect(timer, &QTimer::timeout, this, &MainWindow::moveDown);
    timer->start(50);
}
void MainWindow::moveDown()
{
    figuresArray[selectedFigure]->moveDown();
    setInfo();
    ui->graphicsView->viewport()->update();
}
void MainWindow::on_moveDown_released()
{
    disconnect(timer, &QTimer::timeout, this, &MainWindow::moveDown);
    timer->stop();
}


void MainWindow::on_moveLeft_pressed()
{
    connect(timer, &QTimer::timeout, this, &MainWindow::moveLeft);
    timer->start(50);
}
void MainWindow::moveLeft()
{
    figuresArray[selectedFigure]->moveLeft();
    setInfo();
    ui->graphicsView->viewport()->update();
}
void MainWindow::on_moveLeft_released()
{
    disconnect(timer, &QTimer::timeout, this, &MainWindow::moveLeft);
    timer->stop();
}


void MainWindow::on_moveUp_pressed()
{
    connect(timer, &QTimer::timeout, this, &MainWindow::moveUp);
    timer->start(50);
}
void MainWindow::moveUp()
{
    figuresArray[selectedFigure]->moveUp();
    setInfo();
    ui->graphicsView->viewport()->update();
}
void MainWindow::on_moveUp_released()
{
    disconnect(timer, &QTimer::timeout, this, &MainWindow::moveUp);
    timer->stop();
}

void MainWindow::valueAsideChange(double arg1)
{
    if(figuresArray[selectedFigure] != nullptr){
        figuresArray[selectedFigure]->setValueA(arg1);
    }
    setInfo();
    ui->graphicsView->viewport()->update();
}

void MainWindow::valueBsideChange(double arg1)
{
    if(figuresArray[selectedFigure] != nullptr){
        figuresArray[selectedFigure]->setValueB(arg1);
    }
    setInfo();
    ui->graphicsView->viewport()->update();
}

void MainWindow::valueCsideChange(double arg1)
{
    if(figuresArray[selectedFigure] != nullptr){
        figuresArray[selectedFigure]->setValueC(arg1);
    }
    setInfo();
    ui->graphicsView->viewport()->update();
}


void MainWindow::setWidthRectangle(double arg1){
    if(figuresArray[selectedFigure] != nullptr){
        figuresArray[selectedFigure]->setWidthRectangle(arg1);
    }
    setInfo();
    ui->graphicsView->viewport()->update();
}

void MainWindow::setHeightRectangle(double arg1){
    if(figuresArray[selectedFigure] != nullptr){
        figuresArray[selectedFigure]->setHeightRectangle(arg1);
    }
    setInfo();
    ui->graphicsView->viewport()->update();
}

void MainWindow::on_rotateRight_pressed()
{
    connect(timer, &QTimer::timeout, this, &MainWindow::rotateRight);
    timer->start(50);
}
void MainWindow::rotateRight(){
    figuresArray[selectedFigure]->rotate_right();
    setInfo();
    ui->graphicsView->viewport()->update();
}
void MainWindow::on_rotateRight_released()
{
    disconnect(timer, &QTimer::timeout, this, &MainWindow::rotateRight);
    timer->stop();
}


void MainWindow::on_rotateLeft_pressed()
{
    connect(timer, &QTimer::timeout, this, &MainWindow::rotateLeft);
    timer->start(50);
}
void MainWindow::rotateLeft(){
    figuresArray[selectedFigure]->rotate_left();
    setInfo();
    ui->graphicsView->viewport()->update();
}
void MainWindow::on_rotateLeft_released()
{
    disconnect(timer, &QTimer::timeout, this, &MainWindow::rotateLeft);
    timer->stop();
}


void MainWindow::on_innerRadiusUp_pressed()
{
    connect(timer, &QTimer::timeout, this, &MainWindow::starInnerRadUp);
    timer->start(50);
}
void MainWindow::starInnerRadUp(){
    figuresArray[selectedFigure]->setInnerRadius();
    setInfo();
    ui->graphicsView->viewport()->update();
}
void MainWindow::on_innerRadiusUp_released()
{
    disconnect(timer, &QTimer::timeout, this, &MainWindow::starInnerRadUp);
    timer->stop();
}


void MainWindow::on_outerRadiusUp_pressed()
{
    connect(timer, &QTimer::timeout, this, &MainWindow::starOuterRadUp);
    timer->start(50);
}
void MainWindow::starOuterRadUp(){
    figuresArray[selectedFigure]->setOuterRadius();
    setInfo();
    ui->graphicsView->viewport()->update();
}
void MainWindow::on_outerRadiusUp_released()
{
    disconnect(timer, &QTimer::timeout, this, &MainWindow::starOuterRadUp);
    timer->stop();
}


void MainWindow::innerRadiusDownPressed(){
    connect(timer, &QTimer::timeout, this, &MainWindow::setInnerRadiusDown);
    timer->start(50);
}
void MainWindow::setInnerRadiusDown(){
    figuresArray[selectedFigure]->setInnerRadiusDown();
    setInfo();
    ui->graphicsView->viewport()->update();
}
void MainWindow::innerRadiusDownRealesed()
{
    disconnect(timer, &QTimer::timeout, this, &MainWindow::setInnerRadiusDown);
    timer->stop();
}

void MainWindow::outerRadiusDownPressed(){
    connect(timer, &QTimer::timeout, this, &MainWindow::setOuterRadiusDown);
    timer->start(50);
}
void MainWindow::setOuterRadiusDown(){
    figuresArray[selectedFigure]->setOuterRadiusDown();
    setInfo();
    ui->graphicsView->viewport()->update();
}
void MainWindow::outerRadiusDownRealesed()
{
    disconnect(timer, &QTimer::timeout, this, &MainWindow::setOuterRadiusDown);
    timer->stop();
}

void MainWindow::on_vertexes_valueChanged(int arg1)
{
    figuresArray[selectedFigure]->setVertices(arg1);
    setInfo();
    ui->graphicsView->viewport()->update();
}

void MainWindow::setRhombHeight(double arg1){
    figuresArray[selectedFigure]->setRhombHeight(arg1);
    setInfo();
    ui->graphicsView->viewport()->update();
}

void MainWindow::setRhombWidth(double arg1){
    figuresArray[selectedFigure]->setRhombWidth(arg1);
    setInfo();
    ui->graphicsView->viewport()->update();
}

void MainWindow::setInfo(){
    if(selectedFigure != 7 && selectedFigure != 6){
        ui->textSquare->show();
        ui->textPerimeter->show();
        QPointF center = figuresArray[selectedFigure]->center;
        ui->textCenter->setText("x " + QString::number(center.x(), 'd', 1) + " " + "y " + QString::number(center.y(), 'd', 1));
        ui->textSquare->setText(QString::number(figuresArray[selectedFigure]->findSquare()));
        ui->textPerimeter->setText(QString::number(figuresArray[selectedFigure]->findPerimeter()));
    }
    else if(selectedFigure == 6){
        QPointF center = figuresArray[selectedFigure]->center;
        ui->textCenter->setText("x " + QString::number(center.x(), 'd', 1) + " " + "y " + QString::number(center.y(), 'd', 1));
        ui->textSquare->hide();
        ui->textPerimeter->hide();
    }
}

void MainWindow::PolygonVertexes(int arg1){
    figuresArray[selectedFigure]->setVertices(arg1);
    setInfo();
    ui->graphicsView->viewport()->update();
}
