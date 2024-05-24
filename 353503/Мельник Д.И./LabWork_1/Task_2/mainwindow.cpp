#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new PaintScene();   // Инициализируем графическую сцену
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
    ui->label_2->setText(QString::number(abs(area)));
}
void MainWindow::setPerimeter(double perimeter) {
    ui->label_4->setText(QString::number(abs(perimeter)));
}

void MainWindow::slotTimer()
{
    /* Переопределяем размеры графической сцены в зависимости
         * от размеров окна
         * */
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
        scene->setTypeFigure(PaintScene::RectangleType);
        break;
    }
    case 1:{
        scene->setTypeFigure(PaintScene::RombType);
        break;
    }
    case 2:{
        scene->setTypeFigure(PaintScene::TriangleType);
        break;
    }
    case 3:{
        scene->setTypeFigure(PaintScene::EllipseType);
        break;
    }
    case 4:{
        scene->setTypeFigure(PaintScene::SquareType);
        break;
    }
    case 5:{
        qDebug() << "Circle";
        scene->setTypeFigure(PaintScene::CircleType);
        break;
    }
    case 6:{
        qDebug() << "Hexagon";
        scene->setTypeFigure(PaintScene::HexagonType);
        break;
    }
    case 7:{
        qDebug() << "Star_5";
        scene->setTypeFigure(PaintScene::Star_5Type);
        break;
    }
    case 8:{
        qDebug() << "Star_6";
        scene->setTypeFigure(PaintScene::Star_6Type);
        break;
    }
    case 9:{
        qDebug() << "Star_8";
        scene->setTypeFigure(PaintScene::Star_8Type);
        break;
    }
    case 10:{
        qDebug() << "Delete button on";
        scene->setTypeFigure(PaintScene::DeleteType);
        break;
    }
    case 11:{
        qDebug() << "Warp";
        scene->setTypeFigure(PaintScene::WarpType);
        break;
    }
    default:{

        qDebug() << "Default combobBOX";
        scene->setTypeFigure(PaintScene::SquareType);
        break;
    }
    }
    Figure* tempFigure = scene->currentFigure();
    if (tempFigure != nullptr){
    ui->label_2->setText(QString::number(tempFigure->area()));
    ui->label_4->setText(QString::number(tempFigure->perimeter()));
    }
}

