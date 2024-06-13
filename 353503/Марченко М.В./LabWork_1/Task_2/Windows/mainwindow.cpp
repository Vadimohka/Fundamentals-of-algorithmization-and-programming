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
    connect(scene, &PaintScene::SetLabelS, this, &MainWindow::SetLabelS);
    connect(scene, &PaintScene::SetLabelP, this, &MainWindow::SetLabelP);
    timer->start(100);          // Запускаем таймер

    rotationTimerL = new QTimer();       // Инициализируем таймер
    connect(rotationTimerL, &QTimer::timeout, this, &MainWindow::rotateItemL);
    rotationTimerR = new QTimer();       // Инициализируем таймер
    connect(rotationTimerR, &QTimer::timeout, this, &MainWindow::rotateItemR);

    increaseTimer = new QTimer();       // Инициализируем таймер
    connect(increaseTimer, &QTimer::timeout, this, &MainWindow::increase_item);
    decreaseTimer = new QTimer();       // Инициализируем таймер
    connect(decreaseTimer, &QTimer::timeout, this, &MainWindow::decrease_item);

    connect(ui->pushButton,    &QPushButton::clicked, this, &MainWindow::pushButton_clicked);
    connect(ui->pushButton_2,  &QPushButton::clicked, this, &MainWindow::pushButton_2_clicked);
    connect(ui->pushButton_3,  &QPushButton::clicked, this, &MainWindow::pushButton_3_clicked);
    connect(ui->pushButton_4,  &QPushButton::clicked, this, &MainWindow::pushButton_4_clicked);
    connect(ui->pushButton_5,  &QPushButton::clicked, this, &MainWindow::pushButton_5_clicked);
    connect(ui->pushButton_6,  &QPushButton::clicked, this, &MainWindow::pushButton_6_clicked);
    connect(ui->pushButton_7,  &QPushButton::clicked, this, &MainWindow::pushButton_7_clicked);
    connect(ui->pushButton_8,  &QPushButton::clicked, this, &MainWindow::pushButton_8_clicked);
    connect(ui->pushButton_9,  &QPushButton::clicked, this, &MainWindow::pushButton_9_clicked);
    connect(ui->pushButton_10, &QPushButton::clicked, this, &MainWindow::pushButton_10_clicked);

    connect(ui->increaseButton, &QPushButton::pressed, this, &MainWindow::increaseButton_pressed);
    connect(ui->increaseButton, &QPushButton::released, this, &MainWindow::increaseButton_released);
    connect(ui->decreaseButton, &QPushButton::pressed, this, &MainWindow::decreaseButton_pressed);
    connect(ui->decreaseButton, &QPushButton::released, this, &MainWindow::decreaseButton_released);

    connect(ui->rlButton, &QPushButton::pressed,  this, &MainWindow::rlButton_pressed);
    connect(ui->rlButton, &QPushButton::released, this, &MainWindow::rlButton_released);
    connect(ui->rrButton, &QPushButton::pressed,  this, &MainWindow::rrButton_pressed);
    connect(ui->rrButton, &QPushButton::released, this, &MainWindow::rrButton_released);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::rotateItemL()                       //?
{
    auto it = scene->getFigure();
    QTransform transform = it->transform();
    transform.translate(it->centerPoint().x(), it->centerPoint().y());
    transform.rotate(-0.5);
    transform.translate(-it->centerPoint().x(), -it->centerPoint().y());
    it->setTransform(transform);
    scene->update();
}

void MainWindow::rotateItemR()
{
    auto it = scene->getFigure();
    QTransform transform = it->transform();
    transform.translate(it->centerPoint().x(), it->centerPoint().y());
    transform.rotate(0.5);
    transform.translate(-it->centerPoint().x(), -it->centerPoint().y());

    it->setTransform(transform);
    scene->update();
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

// Ромб
void MainWindow::pushButton_clicked()
{
    scene->setTypeFigure(PaintScene::RombType);
}

// Квадрат
void MainWindow::pushButton_2_clicked()
{
    scene->setTypeFigure(PaintScene::SquareType);
}

// Треугольник
void MainWindow::pushButton_3_clicked()
{
    scene->setTypeFigure(PaintScene::TriangleType);
}

//Прямоугольник
void MainWindow::pushButton_4_clicked()
{
    scene->setTypeFigure(PaintScene::RectangleType);
}

//Круг
void MainWindow::pushButton_5_clicked()
{
    scene->setTypeFigure(PaintScene::CircleType);
}

//Звезда 5
void MainWindow::pushButton_6_clicked()
{
    scene->setTypeFigure(PaintScene::Star5Type);
}

//Звезда 6
void MainWindow::pushButton_7_clicked()
{
    scene->setTypeFigure(PaintScene::Star6Type);
}

//Звезда 8
void MainWindow::pushButton_8_clicked()
{
    scene->setTypeFigure(PaintScene::Star8Type);
}

//Шестиугольник
void MainWindow::pushButton_9_clicked()
{
    scene->setTypeFigure(PaintScene::HexagonType);
}

//Стрелка
void MainWindow::pushButton_10_clicked()
{
    scene->setTypeFigure(PaintScene::ArrowType);
}

void MainWindow::SetLabelS(qreal S)
{
    ui->areaLabel->setText("Площадь: " + QString::number(S));
}

void MainWindow::SetLabelP(qreal P)
{
    ui->perimeterLabel->setText("Периметр: " + QString::number(P));
}

void MainWindow::rlButton_pressed()
{
    rotationTimerL->start(10); // Запускаем таймер с интервалом 10 мс
}

void MainWindow::rlButton_released()
{
    rotationTimerL->stop(); // Останавливаем таймер при отпускании клавиши
}

void MainWindow::rrButton_pressed()
{
    rotationTimerR->start(10); // Запускаем таймер с интервалом 100 мс
}

void MainWindow::rrButton_released()
{
    rotationTimerR->stop(); // Останавливаем таймер при отпускании клавиши
}


void MainWindow::increaseButton_pressed()
{
    increaseTimer->start(3);
}

void MainWindow::increaseButton_released()
{
    increaseTimer->stop();
}

void MainWindow::decreaseButton_pressed()
{
    decreaseTimer->start(3);
}

void MainWindow::decreaseButton_released()
{
    decreaseTimer->stop();
}


void MainWindow::decrease_item()
{
    auto it = scene->getFigure();
    it->setScale(1/1.001);
    SetLabelP(it->GetPerimeter());
    SetLabelS(it->GetArea());
    scene->update();
}

void MainWindow::increase_item()
{
    auto it = scene->getFigure();
    it->setScale(1.001);
    SetLabelP(it->GetPerimeter());
    SetLabelS(it->GetArea());
    scene->update();
}




