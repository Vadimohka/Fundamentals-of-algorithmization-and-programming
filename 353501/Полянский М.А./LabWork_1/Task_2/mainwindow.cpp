#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    
    scene = new customScene;
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    
    // currentIndex = nullptr;
    //array of elements
    shapes[0] = new Circle(100);
    shapes[1] = new Triangle(100, 100, 100);
    shapes[2] = new Rectangle(200, 100);
    shapes[3] = new Square(200);
    shapes[4] = new Star();
    shapes[5] = new Rhombus();
    shapes[6] = new Hexagon();
    shapes[7] = new customShape();
    currentIndex = shapes[0];
    scene->addItem(currentIndex);
    /*
    shapes[2] = new Hexagon();
    
    */
    ui->frame->hide();
    ui->frame_2->hide();
    ui->frame_3->hide();
    ui->frame_4->hide();
    ui->frame_5->hide();    
    ui->hexagon->hide();
    ui->frame_7->hide();
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::updateShape);
    
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::moveleft);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::moveright);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::movedown);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::moveup);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::zoomIn);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::zoomOut);
    connect(ui->spinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::moveCenterX);
    connect(ui->spinBox_2, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::moveCenterY);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &MainWindow::rotateClockwise);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::rotateUntiClockwise);
    connect(ui->firstSide, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::rezTr1);
    connect(ui->secondside, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::rezTr2);
    connect(ui->thirdside, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::rezTr3);
    connect(ui->spinBox_3, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::resRect1);
    connect(ui->spinBox_4, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::resRect2);
    connect(ui->spinBox_5, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::resSquare);
    connect(ui->spinBox_6, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::changerad1);
    connect(ui->spinBox_7, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::changerad2);
    connect(ui->spinBox_8, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::numberApex);
    connect(ui->spinBox_9, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::changeRhomA);
    connect(ui->spinBox_10, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::changeRhomS);
    connect(ui->spinBox_11, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::changeApexHex);
    connect(ui->spinBox_12, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::changeSideHex);
    connect(scene, &customScene::mousePressed, this, &MainWindow::handlMousePress);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::disconCustom);
}   

MainWindow::~MainWindow()
{
    
    for (int i = 0; i < 8; ++i) {
        delete shapes[i];
    }
    delete ui;
}

void MainWindow::updateShape(int in)
{
    


    
    // ui->spinBox->setValue(0);
    // ui->spinBox_2->setValue(0);
    // ui->spinBox_3->setValue(0);
    // ui->spinBox_4->setValue(0);
    // ui->spinBox_5->setValue(0);
    // ui->spinBox_6->setValue(0);
    // ui->spinBox_7->setValue(0);
    // ui->spinBox_8->setValue(0);
    // ui->spinBox_9->setValue(0);
    // ui->spinBox_10->setValue(0);
    // ui->spinBox_11->setValue(0);
    // ui->spinBox_12->setValue(0);
    // ui->firstSide->setValue(0);
    // ui->secondside->setValue(0);
    // ui->thirdside->setValue(0);
    ui->frame->hide();
    ui->frame_2->hide();
    ui->frame_3->hide();
    ui->frame_4->hide();
    ui->frame_5->hide();    
    ui->hexagon->hide();
    ui->frame_7->hide();
    if(in == 1){
        ui->frame->show();
        ui->frame_7->show();
        ui->per->show();
        ui->frame_6->show();
    }else if(in ==2){
        ui->frame_2->show();
        ui->frame_7->show();
        ui->per->show();
        ui->frame_6->show();
    }else if (in ==3){
        ui->frame_3->show();
        ui->frame_7->show();
        ui->per->show();
        ui->frame_6->show();
    }else if(in == 4){
        ui->frame_4->show();
        ui->frame_7->show();
        ui->per->show();
        ui->frame_6->show();
    }else if(in == 5){
        ui->frame_5->show();
        ui->frame_7->show();
        ui->per->show();
        ui->frame_6->show();
    }else if(in == 6){
        ui->hexagon->show();
        ui->frame_7->show();
        ui->per->show();
        ui->frame_6->show();
    }else if (in == 0){
        ui->frame_7->show();
        ui->frame_6->show();
        ui->per->show();
    }else if( in == 7){
        ui->frame_7->hide();
        ui->frame_6->hide();
        ui->per->hide();
        
    }else{
        in  = 0;
        ui->frame_6->show();
    }
    if (currentIndex != nullptr) {
        scene->removeItem(currentIndex);
    }

    scene->clear();
    currentIndex = shapes[in];


    

    scene->addItem(currentIndex);
    setInfo();
}


void MainWindow::moveleft()
{
    currentIndex->moveLeft();
    ui->graphicsView->viewport()->update();
    
}

void MainWindow::moveright()
{
    currentIndex->moveRight();
    ui->graphicsView->viewport()->update();
    
}
void MainWindow::moveup()
{
    currentIndex->moveUp();
    ui->graphicsView->viewport()->update();
    
}

void MainWindow::movedown()
{
    currentIndex->moveDown();
    ui->graphicsView->viewport()->update();
    
}

void MainWindow::zoomIn()
{
    currentIndex->zoomIn();
    ui->graphicsView->viewport()->update();
    setInfo();
}

void MainWindow::zoomOut()
{
    currentIndex->zoomOut();
    ui->graphicsView->viewport()->update();
    setInfo();
}

void MainWindow::moveCenterX(double x){
    currentIndex->cnetermovex(x);
    ui->graphicsView->viewport()->update();
}

void MainWindow::moveCenterY(double y){
    currentIndex->cnetermovey(y);
    ui->graphicsView->viewport()->update();
}

void MainWindow::rotateClockwise(){
    currentIndex->rotateclockwise();
    ui->graphicsView->viewport()->update();
}

void MainWindow::rotateUntiClockwise(){
    currentIndex->unticlockwise();
    ui->graphicsView->viewport()->update();
}

void MainWindow::rezTr1(int newSize)
{
    currentIndex->resizeTriangle1(newSize);
    ui->graphicsView->viewport()->update();
    setInfo();
}

void MainWindow::rezTr2(int newSize)
{
    currentIndex->resizeTriangle2(newSize);
    ui->graphicsView->viewport()->update();
    setInfo();
}

void MainWindow::rezTr3(int newSize)
{
    
    currentIndex->resizeTriangle3(newSize);
    ui->graphicsView->viewport()->update();
    setInfo();
}

void MainWindow::resRect1(int newwidth){
    currentIndex->resizeRectW(newwidth);
    ui->graphicsView->viewport()->update();
    setInfo();
}
void MainWindow::resRect2(int newhight){
    currentIndex->resizeRectH(newhight);
    ui->graphicsView->viewport()->update();
    setInfo();
}

void MainWindow::resSquare(int newside){
    currentIndex->resSide(newside);
    ui->graphicsView->viewport()->update();
    setInfo();
}

void MainWindow::changerad1(int newrad1){
    currentIndex->changeRadius1(newrad1);
    ui->graphicsView->viewport()->update();
    setInfo();
}

void MainWindow::changerad2(int newrad2){
    currentIndex->changeRadius1(newrad2);
    ui->graphicsView->viewport()->update();
    setInfo();
}

void MainWindow::numberApex(int newapexes){
    currentIndex->numberApexes(newapexes);
    ui->graphicsView->viewport()->update();
    setInfo();
}

void MainWindow::changeRhomA(double newangle){
    currentIndex->changeangle(newangle);
    ui->graphicsView->viewport()->update();
    setInfo();
}
void MainWindow::changeRhomS(double newside){
    currentIndex->change_side(newside);
    ui->graphicsView->viewport()->update();
    setInfo();
}



void MainWindow::changeSideHex(double newside){
    currentIndex->change_side(newside);
    ui->graphicsView->viewport()->update();
    setInfo();
}

void MainWindow::changeApexHex(double newapex){
    currentIndex->numberApexes(newapex);
    ui->graphicsView->viewport()->update();
    setInfo();

}

void MainWindow::setInfo(){
    ui->per->setText(QString::number(currentIndex->perimeter()));
    ui->ar->setText(QString::number(currentIndex->area()));
    ui->frame_7->update();
}

void MainWindow::handlMousePress(const QPointF &Position){
    currentIndex->addPoint(Position);
    ui->graphicsView->viewport()->update();
}

void MainWindow::disconCustom(){
    disconnect(scene, &customScene::mousePressed, this, &MainWindow::handlMousePress);
    ui->frame_6->show();
    
}


