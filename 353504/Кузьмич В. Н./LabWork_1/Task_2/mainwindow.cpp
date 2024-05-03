#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::fun(){
    per = obgect -> fun_vosv_per();
    ui -> label -> setText(QString::number(static_cast<double>(per)));
    pl = obgect -> fun_vosv_pl();
    ui -> label_2 -> setText(QString::number(static_cast<double>(pl)));
    center_x = obgect -> fun_vosv_center_x();
    center_y = obgect -> fun_vosv_center_y();
    ui -> label_3 -> setText("X: " + QString::number(static_cast<double>(center_x)) + ", Y: " + QString::number(static_cast<double>(center_y)));
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    timer = new QTimer(this);
    ui->stackedWidget->setCurrentWidget(ui -> page_4);
    ui->stackedWidget_2->setCurrentWidget(ui -> page_6);
    ui->stackedWidget_3->setCurrentWidget(ui -> page_8);
}

void MainWindow::on_pushButton_pressed()
{
    obgect2 = nullptr;
    obgect = nullptr;
    ui->graphicsView->setScene(scene);
    if (ui->circleButton->isChecked()){
        obgect = new circle;
        ui->stackedWidget->setCurrentWidget(ui -> page_4);
        ui->graphicsView->viewport()->update();
    }
    else if(ui -> squareButton->isChecked()){
        obgect = new square;
        ui->stackedWidget->setCurrentWidget(ui -> page_4);
        ui->graphicsView->viewport()->update();
    }
    else if (ui -> triangleButton ->isChecked()){
        obgect = new triangle;
        ui->stackedWidget->setCurrentWidget(ui -> page);
        ui->graphicsView->viewport()->update();
    }
    else if (ui -> hexagonButton ->isChecked()){
        obgect = new hexagon;
        ui->stackedWidget->setCurrentWidget(ui -> page_3);
        ui->graphicsView->viewport()->update();
    }
    else if (ui -> rhombusButton ->isChecked()){
        obgect = new rhombus;
        ui->stackedWidget->setCurrentWidget(ui -> page_3);
        ui->graphicsView->viewport()->update();
    }
    else if (ui -> rectangleButton ->isChecked()){
        obgect = new rectangle;
        ui->stackedWidget->setCurrentWidget(ui -> page_3);
        ui->graphicsView->viewport()->update();
    }
    else if (ui -> radioButton ->isChecked()){
        obgect = new star;
        ui->stackedWidget->setCurrentWidget(ui -> page_2);
        obgect -> fun_n_5();
        ui->graphicsView->viewport()->update();
    }
    else if (ui -> radioButton_2 ->isChecked()){
        obgect = new star;
        ui->stackedWidget->setCurrentWidget(ui -> page_2);
        obgect -> fun_n_6();
        ui->graphicsView->viewport()->update();
    }
    else if (ui -> radioButton_3 ->isChecked()){
        obgect = new star;
        ui->stackedWidget->setCurrentWidget(ui -> page_2);
        obgect -> fun_n_8();
        ui->graphicsView->viewport()->update();
    }
    else if (ui -> radioButton_4 ->isChecked()){
        obgect2 = new line;
        ui->stackedWidget->setCurrentWidget(ui -> page_4);
        ui->stackedWidget_2->setCurrentWidget(ui -> page_6);
        ui->stackedWidget_3->setCurrentWidget(ui -> page_8);
        ui->graphicsView->setScene(obgect2);
        ui->graphicsView->viewport()->update();
    }
    if (obgect != nullptr) {
        ui->stackedWidget_2->setCurrentWidget(ui -> page_5);
        ui->stackedWidget_3->setCurrentWidget(ui -> page_7);
        scene->clear();
        scene->addItem(obgect);
    }
}

void MainWindow::on_pushButton_clicked()
{
    if (obgect != nullptr){
        fun();
    }
}
void MainWindow::on_pushButton_2_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(skalee_up()));
    timer->stop();
    fun();
}

void MainWindow::on_pushButton_3_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(skalee_down()));
    timer->stop();
    fun();
}

void MainWindow::on_pushButton_4_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(up()));
    timer->stop();
    fun();
}

void MainWindow::on_pushButton_6_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(down()));
    timer->stop();
    fun();
}

void MainWindow::on_pushButton_5_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(ritht()));
    timer->stop();
    fun();
}

void MainWindow::on_pushButton_7_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(left()));
    timer->stop();
    fun();
}

void MainWindow::on_pushButton_8_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(pov_r()));
    timer->stop();
    fun();
}

void MainWindow::on_pushButton_9_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(pov_l()));
    timer->stop();
    fun();
}

void MainWindow::ritht()
{
    obgect -> per_x_down();
    fun();
    ui->graphicsView->viewport()->update();
}

void MainWindow::left()
{
    obgect -> per_x_up();
    fun();
    ui->graphicsView->viewport()->update();
}

void MainWindow::on_pushButton_5_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(ritht()));
    timer->start(10);
}

void MainWindow::on_pushButton_7_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(left()));
    timer->start(10);
}

void MainWindow::on_pushButton_4_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(up()));
    timer->start(10);
}

void MainWindow::up()
{
    obgect -> per_y_up();
    fun();
    ui->graphicsView->viewport()->update();
}


void MainWindow::on_pushButton_6_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(down()));
    timer->start(10);
}

void MainWindow::down()
{
    obgect -> per_y_down();
    fun();
    ui->graphicsView->viewport()->update();
}

void MainWindow::on_pushButton_2_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(skalee_up()));
    timer->start(10);
}

void MainWindow::skalee_up()
{
    obgect -> scale_fun_up();
    fun();
    ui->graphicsView->viewport()->update();
}

void MainWindow::skalee_down()
{
    obgect -> scale_fun_down();
    fun();
    ui->graphicsView->viewport()->update();
}

void MainWindow::on_pushButton_3_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(skalee_down()));
    timer->start(10);
}

void MainWindow::on_pushButton_10_clicked()
{
    close();
}

void MainWindow::on_pushButton_9_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(pov_l()));
    timer->start(30);
}

void MainWindow::pov_r(){
    obgect -> pov_left();
    fun();
    ui->graphicsView->viewport()->update();
}

void MainWindow::on_pushButton_8_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(pov_r()));
    timer->start(30);
}

void MainWindow::pov_l(){
    obgect -> pov_rait();
    fun();
    ui->graphicsView->viewport()->update();
}

void MainWindow::on_pushButton_11_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(h_up()));
    timer->stop();
    fun();
}

void MainWindow::on_pushButton_12_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(h_down()));
    timer->stop();
    fun();
}

void MainWindow::on_pushButton_13_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(s_up()));
    timer->stop();
    fun();
}

void MainWindow::on_pushButton_14_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(s_down()));
    timer->stop();
    fun();
}

void MainWindow::on_pushButton_15_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(rad_min_up()));
    timer->stop();
    fun();
}

void MainWindow::on_pushButton_16_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(rad_min_down()));
    timer->stop();
    fun();
}

void MainWindow::on_pushButton_17_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(rad_max_up()));
    timer->stop();
    fun();
}

void MainWindow::on_pushButton_18_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(rad_max_down()));
    timer->stop();
    fun();
}


void MainWindow::on_pushButton_19_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(t1_x_up()));
    timer->stop();
    fun();
}

void MainWindow::on_pushButton_20_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(t1_x_down()));
    timer->stop();
    fun();
}

void MainWindow::on_pushButton_21_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(t2_x_up()));
    timer->stop();
    fun();
}

void MainWindow::on_pushButton_22_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(t2_x_down()));
    timer->stop();
    fun();
}

void MainWindow::on_pushButton_23_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(t3_y_up()));
    timer->stop();
    fun();
}

void MainWindow::on_pushButton_24_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(t3_y_down()));
    timer->stop();
    fun();
}

void MainWindow::on_pushButton_11_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(h_up()));
    timer->start(30);
}

void MainWindow::h_up(){
    obgect -> isk_fun_y_up();
    fun();
    ui->graphicsView->viewport()->update();
}

void MainWindow::on_pushButton_12_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(h_down()));
    timer->start(30);
}

void MainWindow::h_down(){
    if (typeid(*obgect) == typeid(hexagon)){
        obgect -> isk_fun_y_down_hexagon();
    }
    else if(typeid(*obgect) == typeid(rectangle)){
        obgect -> isk_fun_y_down_rectangle();
    }else if(typeid(*obgect) == typeid(rhombus)){
        obgect -> isk_fun_y_down_rhombus();
    }
    fun();
    ui->graphicsView->viewport()->update();
}

void MainWindow::on_pushButton_13_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(s_up()));
    timer->start(30);
}

void MainWindow::s_up(){
    obgect -> isk_fun_x_up();
    fun();
    ui->graphicsView->viewport()->update();
}

void MainWindow::on_pushButton_14_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(s_down()));
    timer->start(30);
}

void MainWindow::s_down(){
    if (typeid(*obgect) == typeid(hexagon)){
        obgect -> isk_fun_x_down_hexagon();
    }
    else if(typeid(*obgect) == typeid(rectangle)){
        obgect -> isk_fun_x_down_rectangle();
    }else if(typeid(*obgect) == typeid(rhombus)){
        obgect -> isk_fun_x_down_rhombus();
    }
    fun();
    ui->graphicsView->viewport()->update();
}

void MainWindow::on_pushButton_15_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(rad_min_up()));
    timer->start(30);
}

void MainWindow::rad_min_up(){
    obgect -> rad_min_up();
    fun();
    ui->graphicsView->viewport()->update();
}

void MainWindow::on_pushButton_16_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(rad_min_down()));
    timer->start(30);
}

void MainWindow::rad_min_down(){
    obgect -> rad_min_down();
    fun();
    ui->graphicsView->viewport()->update();
}

void MainWindow::on_pushButton_17_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(rad_max_up()));
    timer->start(30);
}

void MainWindow::rad_max_up(){
    obgect -> rad_max_up();
    fun();
    ui->graphicsView->viewport()->update();
}


void MainWindow::on_pushButton_18_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(rad_max_down()));
    timer->start(30);
}

void MainWindow::rad_max_down(){
    obgect -> rad_max_down();
    fun();
    ui->graphicsView->viewport()->update();
}

void MainWindow::on_pushButton_19_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(t1_x_up()));
    timer->start(30);
}

void MainWindow::t1_x_up(){
    obgect -> t1_tri_up();
    fun();
    ui->graphicsView->viewport()->update();
}

void MainWindow::on_pushButton_20_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(t1_x_down()));
    timer->start(30);
}

void MainWindow::t1_x_down(){
    obgect -> t1_tri_down();
    fun();
    ui->graphicsView->viewport()->update();
}


void MainWindow::on_pushButton_21_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(t2_x_up()));
    timer->start(30);
}

void MainWindow::t2_x_up(){
    obgect -> t2_tri_up();
    fun();
    ui->graphicsView->viewport()->update();
}

void MainWindow::on_pushButton_22_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(t2_x_down()));
    timer->start(30);
}

void MainWindow::t2_x_down(){
    obgect -> t2_tri_down();
    fun();
    ui->graphicsView->viewport()->update();
}

void MainWindow::on_pushButton_23_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(t3_y_up()));
    timer->start(30);
}

void MainWindow::t3_y_up(){
    obgect -> t3_tri_up();
    fun();
    ui->graphicsView->viewport()->update();
}


void MainWindow::on_pushButton_24_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(t3_y_down()));
    timer->start(30);
}

void MainWindow::t3_y_down(){
    obgect -> t3_tri_down();
    fun();
    ui->graphicsView->viewport()->update();
}


void MainWindow::on_pushButton_25_clicked()
{
    obgect -> vr_true();
    ui->graphicsView->viewport()->update();
}


void MainWindow::on_pushButton_26_clicked()
{
    obgect -> vr_false();
    ui->graphicsView->viewport()->update();
}


void MainWindow::on_pushButton_27_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(y_down_point_vr()));
    timer->start(30);
}


void MainWindow::on_pushButton_27_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(y_down_point_vr()));
    timer->start(30);
}


void MainWindow::on_pushButton_29_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(y_up_point_vr()));
    timer->start(30);
}


void MainWindow::on_pushButton_29_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(y_up_point_vr()));
    timer->start(30);
}


void MainWindow::on_pushButton_28_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(x_down_point_vr()));
    timer->start(30);
}


void MainWindow::on_pushButton_28_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(x_down_point_vr()));
    timer->start(30);
}


void MainWindow::on_pushButton_30_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(x_up_point_vr()));
    timer->start(30);
}


void MainWindow::on_pushButton_30_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(x_up_point_vr()));
    timer->start(30);
}

void MainWindow::x_up_point_vr(){
    obgect -> x_up_point_vr();
    ui->graphicsView->viewport()->update();
}

void MainWindow::x_down_point_vr(){
    obgect -> x_down_point_vr();
    ui->graphicsView->viewport()->update();
}

void MainWindow::y_up_point_vr(){
    obgect -> y_up_point_vr();
    ui->graphicsView->viewport()->update();
}

void MainWindow::y_down_point_vr(){
    obgect -> y_down_point_vr();
    ui->graphicsView->viewport()->update();
}

