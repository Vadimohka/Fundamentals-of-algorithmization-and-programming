#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "star.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
 
    scene = new PaintScene();                                               // Инициализируем графическую сцену
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);                // Устанавливаем сглаживание
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключаем скроллбар по вертикали
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключаем скроллбар по горизонтали
 
    timer = new QTimer();       // Инициализируем таймер
    connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
    timer->start(100);          // Запускаем таймер

    scene->setTypeFigure(PaintScene::RombType);
    ui->frame_1->show();
    ui->frame_2->hide();
    ui->frame_3->hide();
    ui->frame_4->hide();
    ui->frame_5->hide();

    ui->spinBox_rotation->setRange(-180, 180); // Установите диапазон значений (минимальное и максимальное)
    ui->spinBox_rotationX->setRange(-1000, 1000);
    ui->spinBox_rotationY->setRange(-1000, 1000);
}
 
MainWindow::~MainWindow()
{
    delete ui;
}
 
void MainWindow::slotTimer()
{
    /* Переопределяем размеры графической сцены в зависимости
     * от размеров окна
     * */
    timer->stop();
    scene->setSceneRect(0, 0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
    // ui->area->setText(QString::number(scene->returnArea()));
}
 
void MainWindow::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QMainWindow::resizeEvent(event);
}

// TEST
void MainWindow::on_TEST_clicked()
{
    ui->area->setText(QString::number(scene->returnArea()));
}

// Режим редактирования
void MainWindow::on_radioButton_toggled(bool checked)
{
    scene->setMouseMode(PaintScene::editing);
}

// Режим рисования
void MainWindow::on_radioButton_2_toggled(bool checked)
{
    scene->setMouseMode(PaintScene::drawing);
}

// Очистка
void MainWindow::on_clearscene_clicked()
{    
    ui->area->setText(QString::number(0));
    ui->spinBox_rotation->setValue(0);
    scene->clear();
    ui->graphicsView->items().clear();
    scene->update();
}

void MainWindow::on_comboBox_currentIndexChanged(int index) {
    if (index == 0) {
        ui->frame_1->show();
        ui->frame_2->hide();
        ui->frame_3->hide();
        ui->frame_4->hide();
        ui->frame_5->hide();
        qDebug("Frame 0 (Romb)");
        scene->setTypeFigure(PaintScene::RombType);
    }
    if (index == 1) {
        ui->frame_1->hide();
        ui->frame_2->show();
        ui->frame_3->hide();
        ui->frame_4->hide();
        ui->frame_5->hide();
        qDebug("Frame 1 (Square)");
        scene->setTypeFigure(PaintScene::SquareType);
    }
    if (index == 2) {
        ui->frame_1->hide();
        ui->frame_2->hide();
        ui->frame_3->show();
        ui->frame_4->hide();
        ui->frame_5->hide();
        qDebug("Frame 2 (Triangle)");
        scene->setTypeFigure(PaintScene::TriangleType);
    }
    if (index == 3) {
        ui->frame_1->hide();
        ui->frame_2->hide();
        ui->frame_3->hide();
        ui->frame_4->show();
        ui->frame_5->hide();
        qDebug("Frame 3 (Ellipse)");
        scene->setTypeFigure(PaintScene::EllipseType);
    }
    if (index == 4) {
        ui->frame_1->hide();
        ui->frame_2->hide();
        ui->frame_3->hide();
        ui->frame_4->hide();
        ui->frame_5->show();
        qDebug("Frame 4 (Stare)");
        scene->setTypeFigure(PaintScene::StarType);
    }
}

void MainWindow::on_spinBox_number_valueChanged(int arg1)
{
    scene->setNumber(arg1);
}

void MainWindow::on_spinBox_rotation_valueChanged(int arg1)
{
    scene->setRotation(arg1);
}

void MainWindow::on_spinBox_rotationX_valueChanged(int arg1)
{
    scene->setRotationX(arg1);
}

void MainWindow::on_spinBox_rotationY_valueChanged(int arg1)
{
    scene->setRotationY(arg1);
}

void MainWindow::returnArea()
{
    ui->area->setText(QString::number(scene->returnArea()));
}




