#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new PaintScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);                // Устанавливаем сглаживание
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключаем скроллбар по вертикали
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по горизонтали

    timer = new QTimer();       // Инициализируем таймер
    connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
    timer->start(100);          // Запускаем таймер
    connect(scene, &PaintScene::areaChanged, this, &MainWindow::setArea);
    connect(scene, &PaintScene::perimeterChanged, this, &MainWindow::setPerimeter);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setArea(double area) {
    ui->labelForArea->setText(QString::number(abs(area)));
}
void MainWindow::setPerimeter(double perimeter) {
    ui->labelForPerimeter->setText(QString::number(abs(perimeter)));
}

void MainWindow::slotTimer()
{
    timer->stop();
    scene->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QMainWindow::resizeEvent(event);
}


void MainWindow::on_comboBox_activated(int index)
{
    switch (index) {
    case 0:{
        scene->setTypeBasicFigure(PaintScene::Rectanglet);
        break;
    }
    case 1:{
        scene->setTypeBasicFigure(PaintScene::Rombt);
        break;
    }
    case 2:{
        scene->setTypeBasicFigure(PaintScene::Trianglet);
        break;
    }
    case 3:{
        scene->setTypeBasicFigure(PaintScene::Ellipset);
        break;
    }
    case 4:{
        scene->setTypeBasicFigure(PaintScene::Squaret);
        break;
    }
    case 5:{

        scene->setTypeBasicFigure(PaintScene::Circlet);
        break;
    }
    case 6:{

        scene->setTypeBasicFigure(PaintScene::Hexagont);
        break;
    }
    case 7:{
        scene->setTypeBasicFigure(PaintScene::Star_5t);
        break;
    }
    case 8:{
        scene->setTypeBasicFigure(PaintScene::Star_6t);
        break;
    }
    case 9:{
        scene->setTypeBasicFigure(PaintScene::Star_8t);
        break;
    }
    case 10:{
        scene->setTypeBasicFigure(PaintScene::Deletet);
        break;
    }
    case 11:{
        scene->setTypeBasicFigure(PaintScene::Warpt);
        break;
    }
    default:{
        scene->setTypeBasicFigure(PaintScene::Squaret);
        break;
    }
    }
    BasicFigure* tempBasicFigure = scene->currentBasicFigure();
    if (tempBasicFigure != nullptr){
        ui->labelForArea->setText(QString::number(tempBasicFigure->area()));
        ui->labelForPerimeter->setText(QString::number(tempBasicFigure->perimeter()));
    }
}
