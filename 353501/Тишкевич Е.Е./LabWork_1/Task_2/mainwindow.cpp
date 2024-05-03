#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "circle.h"
#include "square.h"
#include "romb.h"
//#include "triangle.h"
#include "rectangle.h"
#include "hexagon.h"
#include "star.h"
#include "polyline.h"
#include "customscene.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   // scene = new QGraphicsScene();
    polyline = new ShapePolyline;
    scene= new CustomScene;
    pivot = new point;

    ui->view->setScene(scene);

    //scene->addItem(pivot);

    timer = new QTimer(this);

    ui->view->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    hideAll();


    ui->x_inp->setMinimum(-9999);
    ui->y_inp->setMinimum(-9999);
    ui->x_inp->setMaximum(9999);
    ui->y_inp->setMaximum(9999);


    ui->radA->setMaximum(1000);
    ui->radB->setMaximum(1000);
    ui->n->setMinimum(3);
    ui->n->setValue(6);
    ui->radA->setValue(45);
    ui->radB->setValue(100);

    ui->FRad->setMaximum(10000);
    ui->SRad->setMaximum(10000);

    ui->FRad->setValue(150);
    ui->SRad->setValue(150);

    ui->hei->setMaximum(10000);
    ui->wid->setMaximum(10000);

    ui->hei->setValue(250);
    ui->wid->setValue(150);

    connect(ui->comboBox, &QComboBox::currentIndexChanged, this, &MainWindow::combo_clicked);
    connect(ui->plusB, &QPushButton::pressed, this, &MainWindow::sizeUpPressed);
    connect(ui->plusB, &QPushButton::released, this, &MainWindow::sizeUpReleased);
    connect(ui->minusB, &QPushButton::pressed, this, &MainWindow::sizeDownPressed);
    connect(ui->minusB, &QPushButton::released, this, &MainWindow::sizeDownReleased);
    connect(ui->x_inp, &QSpinBox::valueChanged, this, &MainWindow::xChanged);
    connect(ui->y_inp, &QSpinBox::valueChanged, this, &MainWindow::yChanged);
    connect(ui->leftB, &QPushButton::pressed, this, &MainWindow::rotationL_on);
    connect(ui->leftB, &QPushButton::released, this, &MainWindow::rotationL_off);
    connect(ui->rightB, &QPushButton::pressed, this, &MainWindow::rotationR_on);
    connect(ui->rightB, &QPushButton::released, this, &MainWindow::rotationR_off);
     connect(ui->n, &QSpinBox::valueChanged, this, &MainWindow::nChanged);
     connect(ui->radA, &QSpinBox::valueChanged, this, &MainWindow::radAChanged);
     connect(ui->radB, &QSpinBox::valueChanged, this, &MainWindow::radBChanged);

     connect(ui->FRad, &QSpinBox::valueChanged, this, &MainWindow::FRadStart);
     connect(ui->SRad, &QSpinBox::valueChanged, this, &MainWindow::SRadStart);

     connect(ui->hei, &QSpinBox::valueChanged, this, &MainWindow::heiStart);
     connect(ui->wid, &QSpinBox::valueChanged, this, &MainWindow::widStart);

     connect(ui->first, &QSpinBox::valueChanged, this, &MainWindow::fStart);

     connect(ui->diam1, &QDoubleSpinBox::valueChanged, this, &MainWindow::diam1Start);
     connect(ui->diam2, &QDoubleSpinBox::valueChanged, this, &MainWindow::diam2Start);
      connect(ui->done, &QPushButton::pressed, this, &MainWindow::ui_back);

     ui->diam1->setValue(1.00);
     ui->diam1->setSingleStep(0.01);

     ui->diam2->setValue(1.00);
     ui->diam2->setSingleStep(0.01);

     ui->edgs->setValue(5);
     ui->edgs->setMinimum(4);

     ui->done->hide();


    // connect(ui->drawB,  &QPushButton::pressed, this, &MainWindow::actDraw);
    connect(ui->drawB, &QPushButton::pressed, this, &MainWindow::handleShapeCreated);
     connect(ui->edgs, &QSpinBox::valueChanged, this, &MainWindow::edgsChanged);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::combo_clicked(int index)
{
    scene->clear();
    if (index==0)
    {
        item=nullptr;
        hideAll();
        ui->areaVal->setText("0");
        ui->perimVal->setText("0");
        return;
    }
    else if (index==1)
    {
        item = new Square();
        hideAll();

    }
    else if (index ==2)
    {
        item = new Circle();
        hideAll();
        ui->frame_3->show();
        ui->FRad->setValue(150);
        ui->SRad->setValue(150);

        item->targetA=150;
        item->targetB=150;

        item->setRadA(150);
        item->setRadB(150);
        item->QGraphicsItem::update();
    }
    else if (index ==3)
    {
        item = new Romb();
        hideAll();
        ui->frame_5->show();

        item->targetRHei=1.00;
        item->targetRWid=1.00;

        ui->diam1->setValue(1.00);
        ui->diam2->setValue(1.00);
    }
    else if (index ==4)
    {
        item = new Rectangle();
        hideAll();
        item->targetWid=150;
        item->targetHei=250;
        ui->hei->setValue(250);
        ui->wid->setValue(150);
        ui->frame_2->show();
        item->setHei(250);
        item->setWid(150);
        item->QGraphicsItem::update();
    }
  /*  else if (index ==5)
    {
        item = new Triangle();
        hideAll();
        ui->frame_4->show();
    }*/
    else if (index ==5)
    {
        item = new Hexagon(5);
        hideAll();
        ui->frame_7->show();
    }
    else if (index ==6)
    {
        item = new Star();
        hideAll();
        ui->frame->show();
    }
    if (item==nullptr && !isPoly) return;
     ui->frame_6->show();
    ui->x_inp->setValue(0);
     ui->y_inp->setValue(0);
    scene->addItem(item);
    setEnabled(true);

    item->setFlag(QGraphicsItem::ItemIsMovable);
    isPoly=false;
    created = false;
    //added = false;
     SetValues();
}

void MainWindow::sizePlus()
{
    if (item==nullptr && isPoly) { polyline->sc+=0.02; polyline->QGraphicsItem::update(); return;}
    item->scale+=0.02;
    SetValues();
    item->setRadA(ui->radA->value());
    item->setRadB(ui->radB->value());
     ui->view->viewport()->update();
}

void MainWindow::sizeMinus()
{
    if (item==nullptr && isPoly) { polyline->sc-=0.02; polyline->QGraphicsItem::update(); return;}
    item->scale-=0.02;
    if(item->scale<0.04)
    {
        item->scale=0.04;
    }
    SetValues();
    item->setRadA(ui->radA->value());
    item->setRadB(ui->radB->value());
    ui->view->viewport()->update();
}


void MainWindow::sizeUpPressed()
{
    if (item == nullptr && !isPoly) return;
    connect(timer, &QTimer::timeout, this, &MainWindow::sizePlus);
    timer->start(10);
}

void MainWindow::sizeUpReleased()
{
    disconnect(timer, &QTimer::timeout, this, &MainWindow::sizePlus);
    timer->stop();
}

void MainWindow::sizeDownPressed()
{
     if (item == nullptr && !isPoly) return;
    connect(timer, &QTimer::timeout, this, &MainWindow::sizeMinus);
    timer->start(10);
}
void MainWindow::sizeDownReleased()
{
    disconnect(timer, &QTimer::timeout, this, &MainWindow::sizeMinus);
    timer->stop();
}

void MainWindow::SetValues()
{
    ui->areaVal->setText(QString::number(item->area()));
    ui->perimVal->setText(QString::number(item->perim()));
}

void MainWindow::xChanged(int str)
{
    if (item==nullptr) return;

        ui->centX->setText(QString::number(str));
    item->x=str;

   // pivot->updX(str);


    item->QGraphicsItem::update();
}

void MainWindow::yChanged(int str)
{
    if (item==nullptr) return;

    ui->centY->setText(QString::number(str));
    item->y=str;
  //  pivot->updY(str);

    item->QGraphicsItem::update();
}

void MainWindow::rotationL_on()
{
    if (item == nullptr && !isPoly) return;
    connect(timer, &QTimer::timeout, this, &MainWindow::rotLeft);
    timer->start(10);
}

void MainWindow::rotationL_off()
{
    disconnect(timer, &QTimer::timeout, this, &MainWindow::rotLeft);
    timer->stop();
}

void MainWindow::rotLeft()
{
     if (item==nullptr && isPoly) { polyline->rot-=1; polyline->QGraphicsItem::update(); return;}
    item->setTransformOriginPoint(item->x, item->y);

    item->setRotation(item->rotation()-1);
    update();
}

void MainWindow::rotationR_on()
{
    if (item == nullptr && !isPoly) return;
    connect(timer, &QTimer::timeout, this, &MainWindow::rotRight);
    timer->start(10);
}

void MainWindow::rotationR_off()
{
    disconnect(timer, &QTimer::timeout, this, &MainWindow::rotRight);
    timer->stop();
}

void MainWindow::rotRight()
{
     if (item==nullptr && isPoly) { polyline->rot+=1; polyline->QGraphicsItem::update(); return;}
    item->setTransformOriginPoint(item->x, item->y);
    item->setRotation(item->rotation()+1);
    update();
}

void MainWindow::nChanged(int num)
{
    item->setN(num);
     SetValues();
}

void MainWindow::radBChanged(int num)
{
    item->setRadB(num);
     SetValues();
}

void MainWindow::radAChanged(int num)
{
    item->setRadA(num);
     SetValues();
}

void MainWindow::hideAll()
{
    ui->frame->hide();
    ui->frame_2->hide();
    ui->frame_3->hide();
    ui->frame_4->hide();
    ui->frame_5->hide();
    ui->frame_7->hide();
}

void MainWindow::FRadChanged()
{
    if (item==nullptr) return;
    if (item->getRadF()<item->targetA) item->setRadF(item->getRadF()+0.005);
    if (item->getRadF()>item->targetA) item->setRadF(item->getRadF()-0.005);
     SetValues();
    item->QGraphicsItem::update();
}

void MainWindow::FRadStart(int num)
{
    if (item==nullptr) return;
    item->targetA=num;
    connect(timer, &QTimer::timeout, this, &MainWindow::FRadChanged);
    timer->start(1);
}

void MainWindow::SRadChanged()
{
    if (item==nullptr) return;
    if (item->getRadS()<item->targetB) item->setRadS(item->getRadS()+0.005);
    if (item->getRadS()>item->targetB) item->setRadS(item->getRadS()-0.005);
    SetValues();
    item->QGraphicsItem::update();
}

void MainWindow::SRadStart(int num)
{
    if (item==nullptr) return;
    item->targetB=num;
    connect(timer, &QTimer::timeout, this, &MainWindow::SRadChanged);
    timer->start(1);
}

void MainWindow::heiStart(int num)
{
    if (item==nullptr) return;
    item->targetHei=num;
    connect(timer, &QTimer::timeout, this, &MainWindow::heiChanged);
    timer->start(1);
}

void MainWindow::heiChanged()
{
    if (item==nullptr) return;
    if (item->getHei()<item->targetHei) item->setHei(item->getHei()+0.01);
    if (item->getHei()>item->targetHei) item->setHei(item->getHei()-0.01);
    SetValues();
    item->QGraphicsItem::update();
}

void MainWindow::widStart(int num)
{
    if (item==nullptr) return;
    item->targetWid=num;
    connect(timer, &QTimer::timeout, this, &MainWindow::widChanged);
    timer->start(1);
}

void MainWindow::widChanged()
{
    if (item==nullptr) return;
    if (item->getWid()<item->targetWid) item->setWid(item->getWid()+0.01);
    if (item->getWid()>item->targetWid) item->setWid(item->getWid()-0.01);
    SetValues();
    item->QGraphicsItem::update();
}

void MainWindow::actDraw()
{
    ui->comboBox->setCurrentIndex(0);
    item = new ShapePolyline();
    connect(scene, &CustomScene::mousePressed, this, &MainWindow::handleMousePressed);
    isDraw=true;
}

// Source file
/*void MainWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        points.append(event->pos());
        update();
    }
}*/


/*void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QPen pen = QPen(Qt::black, 6);
    painter.setPen(pen);

    for (const QPoint &point : points) {
        painter.drawPoint(point);
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton && isDraw) {
        points.append(event->pos());
        update();
        QPainter painter(this);
        QPen pen = QPen(Qt::black, 6);
        painter.setPen(pen);

        for (const QPoint &point : points) {
            painter.drawPoint(point);
        }
    }
}
*/

void MainWindow::fStart(int num)
{
    if (item==nullptr) return;
    item->targetF=num;
    connect(timer, &QTimer::timeout, this, &MainWindow::fChanged);
    timer->start(1);
}

void MainWindow::fChanged()
{
    if (item==nullptr) return;
    if (item->getS1()<item->targetF) item->setS1(item->getS1()+0.01);
    if (item->getS1()>item->targetF) item->setS1(item->getS1()-0.01);
    SetValues();
    item->QGraphicsItem::update();
}

void MainWindow::diam1Start(double num)
{
    if (item==nullptr) return;
    item->targetRHei=num;
    connect(timer, &QTimer::timeout, this, &MainWindow::diam1Changed);
    timer->start(1);
}

void MainWindow::diam1Changed()
{
    if (item==nullptr) return;
    if (item->getDiam1()<item->targetRHei) item->setDiam1(item->getDiam1()+0.0005);
    if (item->getDiam1()>item->targetRHei) item->setDiam1(item->getDiam1()-0.0005);
    SetValues();
    item->QGraphicsItem::update();
}

void MainWindow::diam2Start(double num)
{
    if (item==nullptr) return;
    item->targetRWid=num;
    connect(timer, &QTimer::timeout, this, &MainWindow::diam2Changed);
    timer->start(1);
}

void MainWindow::diam2Changed()
{
    if (item==nullptr) return;
    if (item->getDiam2()<item->targetRWid) item->setDiam2(item->getDiam2()+0.0005);
    if (item->getDiam2()>item->targetRWid) item->setDiam2(item->getDiam2()-0.0005);
    SetValues();
    item->QGraphicsItem::update();
}

void MainWindow::handleMousePressed(const QPointF &position)
{
    polyline->getPoint(position);
    ui->view->viewport()->update();
}

void MainWindow::handleShapeCreated()
{
    ui->comboBox->setCurrentIndex(0);
    if (!added) scene->addItem(polyline);
    if (created) return;
    added = true;
    created = true;
    isPoly=true;
    ui->done->show();
    ui->frame_6->hide();
    connect(scene, &CustomScene::mousePressed, this, &MainWindow::handleMousePressed);
}

void MainWindow::ui_back()
{
    if (ui->comboBox->currentIndex()!=0) return;
    ui->frame_6->show();
    disconnect(scene, &CustomScene::mousePressed, this, &MainWindow::handleMousePressed);
     polyline->setFlag((QGraphicsItem::ItemIsMovable));
}

void MainWindow::edgsChanged(int num)
{
    item->setn(num);
    SetValues();
}




