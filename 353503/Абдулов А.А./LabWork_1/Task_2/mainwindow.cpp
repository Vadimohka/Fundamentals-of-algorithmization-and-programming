#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "figure.h"

void MainWindow::turnON(){
    ui->Rotate_Left->setEnabled(true);
    ui->Rotate_Right->setEnabled(true);
    ui->Clear->setEnabled(true);
    ui->SizeUP->setEnabled(true);
    ui->SizeDOWN->setEnabled(true);
    ui->MoveDN->setEnabled(true);
    ui->MoveLF->setEnabled(true);
    ui->MoveRG->setEnabled(true);
    ui->MoveUP->setEnabled(true);
}

void MainWindow::turnOFF(){
    ui->Rotate_Left->setEnabled(false);
    ui->Rotate_Right->setEnabled(false);
    ui->Clear->setEnabled(false);
    ui->SizeUP->setEnabled(false);
    ui->SizeDOWN->setEnabled(false);
    ui->MoveDN->setEnabled(false);
    ui->MoveLF->setEnabled(false);
    ui->MoveRG->setEnabled(false);
    ui->MoveUP->setEnabled(false);
}

void MainWindow::turnONFIG(){
    ui->CreateTriangle->setEnabled(true);
    ui->Create_Circle->setEnabled(true);
    ui->Create_Hexagon->setEnabled(true);
    ui->Create_Rectangle->setEnabled(true);
    ui->Create_Romb->setEnabled(true);
    ui->Create_Star_5->setEnabled(true);
    ui->Create_Star_6->setEnabled(true);
    ui->Create_Star_8->setEnabled(true);
    ui->Create_Square->setEnabled(true);
    ui->Create_Trapezoid->setEnabled(true);
    ui->Create_Square->setEnabled(true);
}

void MainWindow::turnOFFFIG(){
    ui->CreateTriangle->setEnabled(false);
    ui->Create_Circle->setEnabled(false);
    ui->Create_Hexagon->setEnabled(false);
    ui->Create_Rectangle->setEnabled(false);
    ui->Create_Romb->setEnabled(false);
    ui->Create_Star_5->setEnabled(false);
    ui->Create_Star_6->setEnabled(false);
    ui->Create_Star_8->setEnabled(false);
    ui->Create_Square->setEnabled(false);
    ui->Create_Trapezoid->setEnabled(false);
    ui->Create_Square->setEnabled(false);
}

void MainWindow::PrintInfo(){
    ui->area->setText(QString::number(currentItem->area()));
    ui->perimetr->setText(QString::number(currentItem->perimeter()));
    ui->valueOfScale->setText(QString::number(currentItem->getScale()));
    ui->CenterMass->setText("(" + QString::number(currentItem->getCenter().x()) + ";" + QString::number(currentItem->getCenter().y()) + ")");
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    turnOFF();

    ui->LineOFF->setEnabled(false);
    ui->area->setText("-");
    ui->perimetr->setText("-");
    ui->valueOfScale->setText("-");
    ui->CenterMass->setText("-");


    scene = new QGraphicsScene();
    timer = new QTimer();
    polygon = new Polygon();
    line = new Line();


    scene->setBackgroundBrush(Qt::gray);    

    ui->graphicsView->setScene(scene);

}

MainWindow::~MainWindow(){
    delete ui;
}

//////////////////////////////////////////////////////mouseEvents////////////////////////////////////////////////////////

void MainWindow::mousePressEvent(QMouseEvent *me){
    if(check){
        line->setPoints(me);
    }

    if(line->points.size() >= 2){
        ui->LineOFF->setEnabled(true);
    }
}

//////////////////////////////////////////////////////Circle////////////////////////////////////////////////////////


void MainWindow::on_Create_Circle_clicked(){
    scene->clear();
    currentItem = new Circle();
    PrintInfo();
    scene->addItem(currentItem);
    turnON();
}

//////////////////////////////////////////////////////Triangle////////////////////////////////////////////////////////

void MainWindow::on_CreateTriangle_clicked(){
    scene->clear();
    currentItem = new Triangle();
    PrintInfo();
    scene->addItem(currentItem);
    turnON();
}

//////////////////////////////////////////////////////ROTATIOM////////////////////////////////////////////////////////

void MainWindow::on_Rotate_Right_pressed(){
    connect(timer, SIGNAL(timeout()), this, SLOT(rotate_right_slot()));
    timer->start(10);

}

void MainWindow::on_Rotate_Right_released(){
    disconnect(timer, SIGNAL(timeout()), this, SLOT(rotate_right_slot()));
    timer->stop();
}

void MainWindow::on_Rotate_Left_pressed(){
    connect(timer, SIGNAL(timeout()), this, SLOT(rotate_left_slot()));
    timer->start(10);
}

void MainWindow::on_Rotate_Left_released(){
    disconnect(timer, SIGNAL(timeout()), this, SLOT(rotate_left_slot()));
    timer->stop();
}

//slots

void MainWindow::rotate_right_slot(){
    currentItem->rotate_right();
}

void MainWindow::rotate_left_slot(){
    currentItem->rotate_left();
}

//slots

//////////////////////////////////////////////////////CLEAR////////////////////////////////////////////////////////
void MainWindow::on_Clear_clicked(){
    scene->clear();
    ui->area->setText("-");
    ui->perimetr->setText("-");
    ui->valueOfScale->setText("-");
    ui->CenterMass->setText("-");
    turnOFF();
}

//////////////////////////////////////////////////////STARS////////////////////////////////////////////////////////

void MainWindow::on_Create_Star_5_clicked(){
    scene->clear();
    currentItem = new Star5();
    PrintInfo();
    scene->addItem(currentItem);
    turnON();
}

void MainWindow::on_Create_Star_6_clicked(){
    scene->clear();
    currentItem = new Star6();
    PrintInfo();
    scene->addItem(currentItem);
    turnON();
}

void MainWindow::on_Create_Star_8_clicked(){
    scene->clear();
    currentItem = new Star8();
    PrintInfo();
    scene->addItem(currentItem);
    turnON();
}

//////////////////////////////////////////////////////EXIT////////////////////////////////////////////////////////



void MainWindow::on_exit_clicked(){
    QApplication::quit();
}

//////////////////////////////////////////////////////RECTANGLE////////////////////////////////////////////////////////


void MainWindow::on_Create_Rectangle_clicked(){
    scene->clear();
    currentItem = new rectangle();
    PrintInfo();
    scene->addItem(currentItem);
    turnON();
}

//////////////////////////////////////////////////////ROMB////////////////////////////////////////////////////////


void MainWindow::on_Create_Romb_clicked(){
    scene->clear();
    currentItem = new Romb();
    PrintInfo();
    scene->addItem(currentItem);
    turnON();
}

//////////////////////////////////////////////////////HEXAGON////////////////////////////////////////////////////////


void MainWindow::on_Create_Hexagon_clicked(){
    scene->clear();
    currentItem = new Hexagon();
    PrintInfo();
    scene->addItem(currentItem);
    turnON();
}

//////////////////////////////////////////////////////TRAPEZOID////////////////////////////////////////////////////////

void MainWindow::on_Create_Trapezoid_clicked(){
    scene->clear();
    currentItem = new Trapezoid();
    PrintInfo();
    scene->addItem(currentItem);
    turnON();
}


//////////////////////////////////////////////////////SQUARE////////////////////////////////////////////////////////

void MainWindow::on_Create_Square_clicked(){
    scene->clear();
    currentItem = new Square();
    PrintInfo();
    scene->addItem(currentItem);

    turnON();
}


//////////////////////////////////////////////////////SIZECHANGE////////////////////////////////////////////////////////

void MainWindow::SetValue(){
    ui->area->setText(QString::number(currentItem->area()));
    ui->perimetr->setText(QString::number(currentItem->perimeter()));
    ui->valueOfScale->setText(QString::number(currentItem->getScale()));
    ui->CenterMass->setText("(" + QString::number(currentItem->getCenter().x()) + ";" + QString::number(currentItem->getCenter().y()) + ")");
}

//slots

void MainWindow::size_slot(){
    SetValue();
    currentItem->getSize();
}

void MainWindow::size_plus_slot(){
    update();
    scale += 0.02;
    auto *p = new QPainter(this);
    p->setPen(Qt::black);
    polygon->draw(p,scale);
    p->end();
}

void MainWindow::size_minus_slot(){
    update();
    scale-=0.02;
    if(scale<0.04){
        scale=0.04;
    }
    auto *p = new QPainter(this);
    p->setPen(Qt::black);
    polygon->draw(p,scale);
    p->end();
}

//slots

void MainWindow::on_SizeUP_pressed(){
    currentItem->setItem(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(size_slot()));
    timer->start(10);
}

void MainWindow::on_SizeUP_released(){
    timer->stop();
    disconnect(timer, SIGNAL(timeout()), this, SLOT(size_slot()));
}

void MainWindow::on_SizeDOWN_pressed(){
    currentItem->setItem(false);
    connect(timer, SIGNAL(timeout()), this, SLOT(size_slot()));
    timer->start(10);
}

void MainWindow::on_SizeDOWN_released(){
    timer->stop();
    disconnect(timer, SIGNAL(timeout()), this, SLOT(size_slot()));
}

//////////////////////////////////////////////////////MOVING////////////////////////////////////////////////////////

//slots

void MainWindow::move_up_slot(){
    SetValue();
    currentItem->move_up();
}

void MainWindow::move_down_slot(){
    SetValue();
    currentItem->move_down();
}

void MainWindow::move_left_slot(){
    SetValue();
    currentItem->move_left();
}

void MainWindow::move_right_slot(){
    SetValue();
    currentItem->move_right();
}

//slots

void MainWindow::on_MoveUP_pressed(){
    connect(timer, SIGNAL(timeout()), this, SLOT(move_up_slot()));
    timer->start(10);
}

void MainWindow::on_MoveUP_released(){
    disconnect(timer, SIGNAL(timeout()), this, SLOT(move_up_slot()));
    timer->stop();
}

void MainWindow::on_MoveDN_pressed(){
    connect(timer, SIGNAL(timeout()), this, SLOT(move_down_slot()));
    timer->start(10);
}

void MainWindow::on_MoveDN_released(){
    disconnect(timer, SIGNAL(timeout()), this, SLOT(move_down_slot()));
    timer->stop();
}

void MainWindow::on_MoveLF_pressed(){
    connect(timer, SIGNAL(timeout()), this, SLOT(move_left_slot()));
    timer->start(10);
}

void MainWindow::on_MoveLF_released(){
    disconnect(timer, SIGNAL(timeout()), this, SLOT(move_left_slot()));
    timer->stop();
}

void MainWindow::on_MoveRG_pressed(){
    connect(timer, SIGNAL(timeout()), this, SLOT(move_right_slot()));
    timer->start(10);
}

void MainWindow::on_MoveRG_released(){
    disconnect(timer, SIGNAL(timeout()), this, SLOT(move_right_slot()));
    timer->stop();
}


//////////////////////////////////////////////////////LINE////////////////////////////////////////////////////////

void MainWindow::on_LineON_clicked(){
    line->points.clear();
    ui->LineON->setEnabled(false);
    ui->LINELABEL->setText("LINE ON");
    turnOFF();
    turnOFFFIG();
    check = true;

}


void MainWindow::on_LineOFF_clicked(){
    vector <QPoint> arr = line->points;
    int size = line->points.size();
    ui->LineOFF->setEnabled(false);
    ui->LineON->setEnabled(true);
    ui->LINELABEL->setText("");
    turnON();
    turnONFIG();
    check = false;
    for(int i = 0 ; i < size-1; i++){
        QLine *nLine = new QLine(arr[i], arr[i+1]);
        scene->addLine(*nLine);
    }
    scene->addLine(*(new QLine(arr[0],arr[size-1]) ));
    ui->Rotate_Left->setEnabled(false);
    ui->Rotate_Right->setEnabled(false);
    ui->SizeUP->setEnabled(false);
    ui->SizeDOWN->setEnabled(false);
    ui->MoveDN->setEnabled(false);
    ui->MoveLF->setEnabled(false);
    ui->MoveRG->setEnabled(false);
    ui->MoveUP->setEnabled(false);
}




























