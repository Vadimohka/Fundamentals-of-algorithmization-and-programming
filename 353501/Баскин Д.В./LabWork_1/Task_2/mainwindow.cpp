#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer();
    scene = new QGraphicsScene();
    shape = new BasicShape();
    polygon = new Polygon;
    ui->graphicsView->setScene(scene);
    ui->stackedWidget_figure->setCurrentIndex(5);
    ui->stackedWidget_right->setCurrentIndex(1);
    setDraw(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setDraw(bool state)
{
    draw = state;
}

void MainWindow::SetInfo()
{
    ui->Area->setText(QString::number((figure->area())));
    ui->Perimeter->setText(QString::number((figure->perimeter())));
    ui->Position->setText("(" + QString::number(figure->getCenter().x()) + " : " + QString::number(figure->getCenter().y()) + ")");
    ui->Origin->setText("(" + QString::number(figure->getOrigin().x()) + " : " + QString::number(figure->getOrigin().y()) + ")");
}

void MainWindow::size_up_slot()
{
    figure->sizeUp();
    SetInfo();
}

void MainWindow::size_down_slot()
{
    figure->sizeDown();
    SetInfo();
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->graphicsView->setDisabled(false);
    scene->clear();
    ui->stackedWidget_right->setCurrentIndex(0);
    ui->label_Length->setText("Length: ");
    ui->label_Width->setText("Width: ");
    ui->spinBox_angle->hide();
    ui->label_angle->hide();
    figure = nullptr;
    switch (index) {
    case 0:
        figure = new Square;
        ui->stackedWidget_figure->setCurrentIndex(3);
        ui->spinBox_side->setValue(figure->getSide());
        break;
    case 1:
        figure = new Rectangle;
        ui->stackedWidget_figure->setCurrentIndex(1);
        ui->spinBox_length->setValue(figure->getLength());
        ui->spinBox_width->setValue(figure->getWidth());
        break;
    case 2:
        figure = new Triangle;
        ui->stackedWidget_figure->setCurrentIndex(1);
        ui->spinBox_angle->show();
        ui->label_angle->show();
        ui->label_Length->setText("Side 1: ");
        ui->label_Width->setText("Side 2: ");
        ui->spinBox_length->setValue(figure->getLength());
        ui->spinBox_width->setValue(figure->getWidth());
        ui->spinBox_angle->setValue(figure->getAngle());
        ui->spinBox_angle->setMaximum(90);
        break;
    case 3:
        figure = new Circle;
        ui->stackedWidget_figure->setCurrentIndex(0);
        ui->spinBox_radius->setValue(figure->getRadius());
        break;
    case 4:
        figure = new Rhombus;
        ui->stackedWidget_figure->setCurrentIndex(1);
        ui->label_Length->setText("Diagonal 1: ");
        ui->label_Width->setText("Diagonal 2: ");
        ui->spinBox_length->setValue(figure->getLength());
        ui->spinBox_width->setValue(figure->getWidth());
        break;
    case 5:
        figure = new Parallelogram;
        ui->stackedWidget_figure->setCurrentIndex(1);
        ui->spinBox_angle->show();
        ui->label_angle->show();
        ui->spinBox_length->setValue(figure->getLength());
        ui->spinBox_width->setValue(figure->getWidth());
        ui->spinBox_angle->setValue(figure->getAngle());
        ui->spinBox_angle->setMaximum(90);
        break;
    case 6:
        figure = new Hexagon;
        ui->stackedWidget_figure->setCurrentIndex(0);
        ui->spinBox_radius->setValue(figure->getRadius());
        break;
    case 7:
        figure = new Star5;
        ui->stackedWidget_figure->setCurrentIndex(2);
        ui->spinBox_radiusA->setValue(figure->getRadiusA());
        ui->spinBox_radiusB->setValue(figure->getRadiusB());
        break;
    case 8:
        figure = new Star6;
        ui->stackedWidget_figure->setCurrentIndex(2);
        ui->spinBox_radiusA->setValue(figure->getRadiusA());
        ui->spinBox_radiusB->setValue(figure->getRadiusB());
        break;
    case 9:
        figure = new Star8;
        ui->stackedWidget_figure->setCurrentIndex(2);
        ui->spinBox_radiusA->setValue(figure->getRadiusA());
        ui->spinBox_radiusB->setValue(figure->getRadiusB());
        break;
    case 10:
        ui->stackedWidget_figure->setCurrentIndex(4);
        ui->stackedWidget_right->setCurrentIndex(1);
        break;
    }
    if (figure != nullptr)
    {
        scene->addItem(figure);
        SetInfo();
    }
}

void MainWindow::on_pushButton_sizeup_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(size_up_slot()));
    timer->start(10);
}

void MainWindow::on_pushButton_sizeup_released()
{
    timer->stop();
    disconnect(timer, SIGNAL(timeout()), this, SLOT(size_up_slot()));
}

void MainWindow::on_pushButton_sizedown_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(size_down_slot()));
    timer->start(10);
}

void MainWindow::on_pushButton_sizedown_released()
{
    timer->stop();
    disconnect(timer, SIGNAL(timeout()), this, SLOT(size_down_slot()));
}

void MainWindow::on_pushButton_draw_clicked()
{
    if (!draw)
    {
        ui->graphicsView->setDisabled(true);
        ui->stackedWidget_right->setCurrentIndex(1);
        figure = new Line;
        setDraw(true);
        scene->clear();
    }
    else
    {
        ui->graphicsView->setDisabled(false);
        figure = polygon;
        if (polygon->points.size())
        {
            for (int i = 0; i < polygon->points.size(); i++) {
                polygon->points[i].setX(polygon->points[i].x() - polygon->center.x());
                polygon->points[i].setY(polygon->points[i].y() - polygon->center.y());
            }
        }
        scene->addItem(polygon);
        SetInfo();
        setDraw(false);
        polygon = new Polygon;
        ui->stackedWidget_right->setCurrentIndex(0);
        update();
    }
}

void MainWindow::move_up_slot()
{
    figure->move_up();
    SetInfo();
}

void MainWindow::move_down_slot()
{
    figure->move_down();
    SetInfo();
}

void MainWindow::move_left_slot()
{
    figure->move_left();
    SetInfo();
}

void MainWindow::move_right_slot()
{
    figure->move_right();
    SetInfo();
}

void MainWindow::rotate_left_slot()
{
    figure->rotate_left();
    SetInfo();
}

void MainWindow::rotate_right_slot()
{
    figure->rotate_right();
    SetInfo();
}

void MainWindow::origin_up_slot()
{
    figure->origin_move_up();
    SetInfo();
}

void MainWindow::origin_down_slot()
{
    figure->origin_move_down();
    SetInfo();
}

void MainWindow::origin_left_slot()
{
    figure->origin_move_left();
    SetInfo();
}

void MainWindow::origin_right_slot()
{
    figure->origin_move_right();
    SetInfo();
}

void MainWindow::on_pushButton_origin_up_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(origin_up_slot()));
    timer->start(10);
}

void MainWindow::on_pushButton_origin_up_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(origin_up_slot()));
    timer->stop();
}

void MainWindow::on_pushButton_origin_down_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(origin_down_slot()));
    timer->start(10);
}

void MainWindow::on_pushButton_origin_down_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(origin_down_slot()));
    timer->stop();
}

void MainWindow::on_pushButton_origin_left_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(origin_left_slot()));
    timer->start(10);
}

void MainWindow::on_pushButton_origin_left_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(origin_left_slot()));
    timer->stop();
}

void MainWindow::on_pushButton_origin_right_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(origin_right_slot()));
    timer->start(10);
}

void MainWindow::on_pushButton_origin_right_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(origin_right_slot()));
    timer->stop();
}

void MainWindow::on_pushButton_moveup_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(move_up_slot()));
    timer->start(10);
}

void MainWindow::on_pushButton_moveup_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(move_up_slot()));
    timer->stop();
}

void MainWindow::on_pushButton_movedown_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(move_down_slot()));
    timer->start(10);
}

void MainWindow::on_pushButton_movedown_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(move_down_slot()));
    timer->stop();
}

void MainWindow::on_pushButton_moveleft_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(move_left_slot()));
    timer->start(10);
}

void MainWindow::on_pushButton_moveleft_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(move_left_slot()));
    timer->stop();
}

void MainWindow::on_pushButton_moveright_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(move_right_slot()));
    timer->start(10);
}

void MainWindow::on_pushButton_moveright_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(move_right_slot()));
    timer->stop();
}

void MainWindow::on_pushButton_rotleft_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(rotate_left_slot()));
    timer->start(10);
}

void MainWindow::on_pushButton_rotleft_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(rotate_left_slot()));
    timer->stop();
}

void MainWindow::on_pushButton_rotright_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(rotate_right_slot()));
    timer->start(10);
}

void MainWindow::on_pushButton_rotright_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(rotate_right_slot()));
    timer->stop();
}

void MainWindow::on_spinBox_radius_valueChanged(int value)
{
    figure->setRadius(value);
    SetInfo();
}

void MainWindow::on_spinBox_radiusA_valueChanged(int value)
{
    figure->setRadiusA(value);
    SetInfo();
}

void MainWindow::on_spinBox_radiusB_valueChanged(int value)
{
    figure->setRadiusB(value);
    SetInfo();
}

void MainWindow::on_spinBox_side_valueChanged(int value)
{
    figure->setSide(value);
    SetInfo();
}

void MainWindow::on_spinBox_length_valueChanged(int value)
{
    figure->setLength(value);
    SetInfo();
}

void MainWindow::on_spinBox_width_valueChanged(int value)
{
    figure->setWidth(value);
    SetInfo();
}

void MainWindow::on_spinBox_angle_valueChanged(int value)
{
    figure->setAngle(value);
    SetInfo();
}

void MainWindow::paintEvent(QPaintEvent* )
{
    if(!draw)
        return;

    QPainter *painter = new QPainter(this);
    painter->setPen(Qt::black);
    polygon->paint(painter, NULL, NULL);
    painter->end();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(!draw)
        return;

    polygon->mousePressing(event);
    update();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(!draw)
        return;

    polygon->mouseMoving(event);
    update();
}

void MainWindow::on_pushButton_reset_clicked()
{
    figure->reset();
    SetInfo();
}
