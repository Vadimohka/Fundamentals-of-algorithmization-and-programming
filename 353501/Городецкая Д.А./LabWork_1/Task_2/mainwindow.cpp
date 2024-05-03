#include "mainwindow.h"
#include "paintscene.h"
#include "ui_mainwindow.h"
#include <QTimer>

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
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    setFixedSize(800, 600);

    timer = new QTimer();       // Инициализируем таймер
    connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
    timer->start(100/20);          // Запускаем таймер
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotTimer()
{
    scene->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
    ui->label_5->setText(scene->ChangeLabel());//площадь периметр центр масс
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QMainWindow::resizeEvent(event);
}

// Ромб
void MainWindow::on_pushButton_clicked()
{
    scene->setTypeFigure(PaintScene::RombType);
}

// Прямоугольник
void MainWindow::on_pushButton_5_clicked()
{
    scene->setTypeFigure(PaintScene::RectangleType);
}

// Треугольник
void MainWindow::on_pushButton_3_clicked()
{
    scene->setTypeFigure(PaintScene::TriangleType);
}

// Круг
void MainWindow::on_pushButton_4_clicked()
{
    scene->setTypeFigure(PaintScene::CircleType);
}

// Квадрат
void MainWindow::on_pushButton_2_clicked()
{
    scene->setTypeFigure(PaintScene::SquareType);
}

// Звезда 5
void MainWindow::on_pushButton_6_clicked()
{
    scene->setTypeFigure(PaintScene::Star5Type);
}

// Шестиугольник
void MainWindow::on_pushButton_9_clicked()
{
    scene->setTypeFigure(PaintScene::HexagonType);
}

// Звезда 6
void MainWindow::on_pushButton_7_clicked()
{
    scene->setTypeFigure(PaintScene::Star6Type);
}

// Звезда 8
void MainWindow::on_pushButton_8_clicked()
{
    scene->setTypeFigure(PaintScene::Star8Type);
}

// другая фигура
void MainWindow::on_pushButton_10_clicked()
{
    scene->setTypeFigure(PaintScene::otherfigureType);
}

// Рисунок
void MainWindow::on_pushButton_11_clicked()
{
    scene->setTypeFigure(PaintScene::BrushType);
}

void MainWindow::on_spinBox_valueChanged(int x) {//право или лево
    scene->setRotation(x);
}

void MainWindow::on_doubleSpinBox_valueChanged(qreal x) {//масштаб
    scene->setScale(x);
}

void MainWindow::on_spinBox_2_valueChanged(int x) {//угол
    scene->setX(x);
}

void MainWindow::on_spinBox_3_valueChanged(int y) {//вверх или вниз
    scene->setY(y);
}