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

    updateValues = new QTimer();
    connect(updateValues, &QTimer::timeout, this, &MainWindow::update_values);
    updateValues->start(100);

    scene->setTypeFigure(PaintScene::RombType);
    ui->frame_1->show();
    ui->frame_2->hide();
    ui->frame_3->hide();
    ui->frame_4->hide();
    ui->frame_5->hide();
    ui->frame_6->hide();
    ui->frame_7->hide();

    ui->drawing->animateClick();

    ui->doubleSpinBox->setRange(1, 10);
    // ui->doubleSpinBox->setValue(0);

    ui->spinBox_rotation->setRange(-180, 180); // Установите диапазон значений (минимальное и максимальное)
    ui->spinBox_rotationX->setRange(-1000, 1000);
    ui->spinBox_rotationY->setRange(-1000, 1000);

    ui->spinBox_sideA->setRange(0, 1000);
    ui->spinBox_sideB->setRange(0, 1000);

    ui->spinBox_sideA_2->setRange(0, 1000);
    ui->spinBox_sideB_2->setRange(0, 1000);

    ui->spinBox_sideA_4->setRange(0, 1000);
    ui->spinBox_sideB_4->setRange(0, 1000);

    ui->spinBox_innerR->setRange(0, 1000);
    ui->spinBox_outerR->setRange(0, 1000);
    ui->spinBox_outerR_2->setRange(0, 1000);

    ui->spinBox_number->setRange(4, 99);
    ui->spinBox_number->setValue(4);

    ui->spinBox_number_2->setRange(3, 99);
    ui->spinBox_number_2->setValue(3);

    ui->spinBox_angel->setRange(0, 180);
    ui->spinBox_sideA_3->setRange(0, 1000);

    // Треульник

    ui->spinBox_A_x->setRange(-1000, 1000);
    ui->spinBox_A_y->setRange(-1000, 1000);
    ui->spinBox_B_x->setRange(-1000, 1000);
    ui->spinBox_B_y->setRange(-1000, 1000);
    ui->spinBox_C_x->setRange(-1000, 1000);
    ui->spinBox_C_y->setRange(-1000, 1000);

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
}

void MainWindow::update_values()
{
    ui->area->setText(QString::number(scene->returnArea()));
    ui->perimeter->setText(QString::number(scene->returnPerimeter()));
    ui->centerX->setText(QString::number(scene->returnCenterX()));
    ui->centerY->setText(QString::number(scene->returnCenterY()));

    ui->spinBox_outerR->setValue(scene->returnOuterRadius());
    ui->spinBox_outerR_2->setValue(scene->returnOuterRadius());
    ui->spinBox_innerR->setValue(scene->returnInnerRadius());

    ui->spinBox_number->setValue(scene->returnNumber());
    ui->spinBox_number_2->setValue(scene->returnNumber());

    ui->spinBox_sideA->setValue(abs(scene->returnSideA()));
    ui->spinBox_sideB->setValue(abs(scene->returnSideB()));

    ui->spinBox_sideA_2->setValue(abs(scene->returnSideA()));
    ui->spinBox_sideB_2->setValue(abs(scene->returnSideB()));

    ui->spinBox_sideA_4->setValue(abs(scene->returnSideA()));
    ui->spinBox_sideB_4->setValue(abs(scene->returnSideB()));

    ui->spinBox_sideA_3->setValue(abs(scene->returnSideA()));
    ui->spinBox_angel->setValue(scene->returnAngel());

    // Треугольник
    ui->spinBox_A_x->setValue(scene->returnPointA_x());
    ui->spinBox_A_y->setValue(scene->returnPointA_y());
    ui->spinBox_B_x->setValue(scene->returnPointB_x());
    ui->spinBox_B_y->setValue(scene->returnPointB_y());
    ui->spinBox_C_x->setValue(scene->returnPointC_x());
    ui->spinBox_C_y->setValue(scene->returnPointC_y());

    if (scene->returnIsNew() || scene->is_No_Figure()) {
        scene->setIsNew();
        ui->spinBox_rotation->setValue(0);
        ui->spinBox_rotationX->setValue(0);
        ui->spinBox_rotationY->setValue(0);
        ui->doubleSpinBox->setValue(1);
    } 


}
 
void MainWindow::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QMainWindow::resizeEvent(event);
}

// Режим редактирования
void MainWindow::on_drawing_toggled(bool checked)
{
    scene->setMouseMode(PaintScene::drawing);
}

// Режим рисования
void MainWindow::on_editing_toggled(bool checked)
{
    scene->setMouseMode(PaintScene::editing);
}

// Очистка
void MainWindow::on_clearscene_clicked()
{    
    ui->area->setText(QString::number(0));
    ui->spinBox_rotation->setValue(0);
    scene->clear();
    ui->graphicsView->items().clear();
    scene->update();
    scene->spaceFigure();
}

void MainWindow::on_comboBox_currentIndexChanged(int index) {
    if (index == 0) {
        ui->frame_1->show();
        ui->frame_2->hide();
        ui->frame_3->hide();
        ui->frame_4->hide();
        ui->frame_5->hide();
        ui->frame_6->hide();
        ui->frame_7->hide();
        qDebug("Frame 0 (Romb)");
        scene->setTypeFigure(PaintScene::RombType);
    }
    if (index == 1) {
        ui->frame_1->hide();
        ui->frame_2->show();
        ui->frame_3->hide();
        ui->frame_4->hide();
        ui->frame_5->hide();
        ui->frame_6->hide();
        ui->frame_7->hide();
        qDebug("Frame 1 (Square)");
        scene->setTypeFigure(PaintScene::RectangleType);
    }
    if (index == 2) {
        ui->frame_1->hide();
        ui->frame_2->hide();
        ui->frame_3->show();
        ui->frame_4->hide();
        ui->frame_5->hide();
        ui->frame_6->hide();
        ui->frame_7->hide();
        qDebug("Frame 2 (Triangle)");
        scene->setTypeFigure(PaintScene::TriangleType);
    }
    if (index == 3) {
        ui->frame_1->hide();
        ui->frame_2->hide();
        ui->frame_3->hide();
        ui->frame_4->show();
        ui->frame_5->hide();
        ui->frame_6->hide();
        ui->frame_7->hide();
        qDebug("Frame 3 (Ellipse)");
        scene->setTypeFigure(PaintScene::EllipseType);
    }
    if (index == 4) {
        ui->frame_1->hide();
        ui->frame_2->hide();
        ui->frame_3->hide();
        ui->frame_4->hide();
        ui->frame_5->show();
        ui->frame_6->hide();
        ui->frame_7->hide();
        qDebug("Frame 4 (Stare)");
        scene->setTypeFigure(PaintScene::StarType);
    }
    if (index == 5) {
        ui->frame_1->hide();
        ui->frame_2->hide();
        ui->frame_3->hide();
        ui->frame_4->hide();
        ui->frame_5->hide();
        ui->frame_6->show();
        ui->frame_7->hide();
        qDebug("Frame 5 (Polygon)");
        scene->setTypeFigure(PaintScene::PolygonType);
    }
    if (index == 6) {
        ui->frame_1->hide();
        ui->frame_2->hide();
        ui->frame_3->hide();
        ui->frame_4->hide();
        ui->frame_5->hide();
        ui->frame_6->hide();
        ui->frame_7->show();
        qDebug("Frame 6 (Parallelogram)");
        scene->setTypeFigure(PaintScene::ParallelogramType);
    }
    if (index == 7) {
        ui->frame_1->hide();
        ui->frame_2->hide();
        ui->frame_3->hide();
        ui->frame_4->hide();
        ui->frame_5->hide();
        ui->frame_6->hide();
        ui->frame_7->hide();
        qDebug("Frame 7 (Paint)");
        scene->setTypeFigure(PaintScene::PaintType);
    }
    scene->spaceFigure();
    ui->spinBox_rotation->setValue(0); // Установите диапазон значений (минимальное и максимальное)
    ui->spinBox_rotationX->setValue(0);
    ui->spinBox_rotationY->setValue(0);

}

void MainWindow::on_spinBox_number_valueChanged(int arg1)
{
    scene->setNumber(arg1);
}

void MainWindow::on_spinBox_number_2_valueChanged(int arg1)
{
    scene->setNumber(arg1);
}

void MainWindow::on_spinBox_rotation_valueChanged(int arg1)
{
    scene->setRotation(arg1);
}

void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    scene->setScale(arg1);
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

void MainWindow::on_spinBox_outerR_valueChanged(int arg1)
{
    scene->setOuterRadius(arg1);
}

void MainWindow::on_spinBox_outerR_2_valueChanged(int arg1)
{
    scene->setOuterRadius(arg1);
}

void MainWindow::on_spinBox_innerR_valueChanged(int arg1)
{
    scene->setInnerRadius(arg1);
}

void MainWindow::on_spinBox_sideA_valueChanged(int arg1)
{
    scene->setSideA(arg1);
}

void MainWindow::on_spinBox_sideB_valueChanged(int arg1)
{
    scene->setSideB(arg1);
}

void MainWindow::on_spinBox_sideA_2_valueChanged(int arg1)
{
    scene->setSideA(arg1);
}

void MainWindow::on_spinBox_sideB_2_valueChanged(int arg1)
{
    scene->setSideB(arg1);
}

void MainWindow::on_spinBox_sideA_4_valueChanged(int arg1)
{
    scene->setSideA(arg1);
}

void MainWindow::on_spinBox_sideB_4_valueChanged(int arg1)
{
    scene->setSideB(arg1);
}

void MainWindow::on_spinBox_sideA_3_valueChanged(int arg1)
{
    scene->setSideA(arg1);
}

void MainWindow::on_spinBox_angel_valueChanged(int arg1)
{
    scene->setAngel(arg1);
}

// Треугольник

void MainWindow::on_spinBox_A_x_valueChanged(int arg1)
{
    scene->setPointA_x(arg1);
}

void MainWindow::on_spinBox_A_y_valueChanged(int arg1)
{
    scene->setPointA_y(arg1);
}

void MainWindow::on_spinBox_B_x_valueChanged(int arg1)
{
    scene->setPointB_x(arg1);
}

void MainWindow::on_spinBox_B_y_valueChanged(int arg1)
{
    scene->setPointB_y(arg1);
}

void MainWindow::on_spinBox_C_x_valueChanged(int arg1)
{
    scene->setPointC_x(arg1);
}

void MainWindow::on_spinBox_C_y_valueChanged(int arg1)
{
    scene->setPointC_y(arg1);
}
