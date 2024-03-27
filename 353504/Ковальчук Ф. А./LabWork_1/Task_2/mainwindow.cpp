#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Figures.h"
#include <QtWidgets>

enum FigureIndexies{
    triangle,
    circle,
    rhomb,
    square,
    recter,
    star_5,
    star_6,
    star_8,
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //setup figureSelecter
    //ui->figureSelecter->setVisible(false);
    ui->FigureSelecter->addItem("Triangle");
    ui->FigureSelecter->addItem("Circle");
    ui->FigureSelecter->addItem("Rhomb");
    ui->FigureSelecter->addItem("Square");
    ui->FigureSelecter->addItem("Rect");
    ui->FigureSelecter->addItem("Star(5)");
    ui->FigureSelecter->addItem("Star(6)");
    ui->FigureSelecter->addItem("Star(8)");

    ui->ButMoveUp->setVisible(false);
    ui->ButMoveDown->setVisible(false);
    ui->ButMoveRight->setVisible(false);
    ui->ButMoveLeft->setVisible(false);

    ui->ButScaleL->setVisible(false);
    ui->ButScaleR->setVisible(false);

    ui->ButRotClockWise->setVisible(false);
    ui->ButRotAntiClockWise->setVisible(false);

    ui->FigureSelecter->setCurrentIndex(0);

    QColor col = QColor(Qt::red);
    if(col.isValid()) {
        QString qss = QString("color: white; background-color: black");
        ui->ButClear->setStyleSheet(qss);
    }

    m_pCurrentFigure = new Triangle();

    //ui->pushButton->setText(ui->figureSelecter->currentText());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DisplayCharacteristics(){
    ui->LblPerim->setText(("Perimetr: " + std::to_string(abs(m_pCurrentFigure->m_perimetr))).c_str());
    ui->LblSquare->setText(("Square: " + std::to_string(abs(m_pCurrentFigure->m_square))).c_str());
    //Centre of mass\nx: 0.0    y: 0.0
    ui->LblMass->setText(("Centre of mass\nX: " + std::to_string(m_pCurrentFigure->m_centre.x()) + "  Y:" + std::to_string(m_pCurrentFigure->m_centre.y())).c_str());
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(m_pCurrentFigure == nullptr) return;
    if(m_currentEditMode == Draw){
        m_pCurrentFigure->MouseEvent(event);
        update();
    }

    DisplayCharacteristics();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    if(m_pCurrentFigure == nullptr) return;
    QPainter painter(this);
    m_pCurrentFigure->Draw(&painter);
}

void MainWindow::on_ButMove_clicked()
{
    ui->ButMoveUp->setVisible(true);
    ui->ButMoveDown->setVisible(true);
    ui->ButMoveRight->setVisible(true);
    ui->ButMoveLeft->setVisible(true);

    ui->ButScaleL->setVisible(false);
    ui->ButScaleR->setVisible(false);

    ui->ButRotClockWise->setVisible(false);
    ui->ButRotAntiClockWise->setVisible(false);

    m_currentEditMode = Move;
    QColor col = QColor(Qt::red);
    if(col.isValid()) {
        QString qss = QString("color: %1").arg(col.name());
        ui->ButMove->setStyleSheet(qss);
    }
    //ui->ButPaint->setStyleSheet("");
    ui->ButScale->setStyleSheet("");
    ui->ButRotate->setStyleSheet("");
    ui->FigureSelecter->setStyleSheet("");
}

void MainWindow::on_FigureSelecter_activated(int index)
{
    ui->ButMoveUp->setVisible(false);
    ui->ButMoveDown->setVisible(false);
    ui->ButMoveRight->setVisible(false);
    ui->ButMoveLeft->setVisible(false);

    ui->ButScaleL->setVisible(false);
    ui->ButScaleR->setVisible(false);

    ui->ButRotClockWise->setVisible(false);
    ui->ButRotAntiClockWise->setVisible(false);

    //ClearCanva();
    m_currentEditMode = Draw;
    ui->ButMove->setStyleSheet("");
    //ui->ButPaint->setStyleSheet("");
    ui->ButScale->setStyleSheet("");
    ui->ButRotate->setStyleSheet("");

    QColor col = QColor(Qt::red);
    if(col.isValid()) {
        QString qss = QString("color: %1").arg(col.name());
        ui->FigureSelecter->setStyleSheet(qss);
    }


    switch (index) {
    case triangle:
        delete m_pCurrentFigure;
        m_pCurrentFigure = new Triangle();
        break;
    case circle:
        delete m_pCurrentFigure;
        m_pCurrentFigure = new Circle();
        break;
    case rhomb:
        delete m_pCurrentFigure;
        m_pCurrentFigure = new Rhomb();
        break;
    case square:
        delete m_pCurrentFigure;
        m_pCurrentFigure = new Scuare();
        break;
    case recter:
        delete m_pCurrentFigure;
        m_pCurrentFigure = new Rect();
        break;
    case star_5:
        delete m_pCurrentFigure;
        m_pCurrentFigure = new NStar();
        ((NStar*)m_pCurrentFigure)->m_numAngles = 5;
        break;
    case star_6:
        delete m_pCurrentFigure;
        m_pCurrentFigure = new NStar();
        ((NStar*)m_pCurrentFigure)->m_numAngles = 6;
        break;
    case star_8:
        delete m_pCurrentFigure;
        m_pCurrentFigure = new NStar();
        ((NStar*)m_pCurrentFigure)->m_numAngles = 8;
        break;
    default:
        break;
    }

}

void MainWindow::on_ButScale_clicked()
{
    ui->ButMoveUp->setVisible(false);
    ui->ButMoveDown->setVisible(false);
    ui->ButMoveRight->setVisible(false);
    ui->ButMoveLeft->setVisible(false);

    ui->ButScaleL->setVisible(true);
    ui->ButScaleR->setVisible(true);

    ui->ButRotClockWise->setVisible(false);
    ui->ButRotAntiClockWise->setVisible(false);

    m_currentEditMode = Scale;
    QColor col = QColor(Qt::red);
    if(col.isValid()) {
        QString qss = QString("color: %1").arg(col.name());
        ui->ButScale->setStyleSheet(qss);
    }
    ui->ButMove->setStyleSheet("");
    ui->FigureSelecter->setStyleSheet("");
    //ui->ButPaint->setStyleSheet("");
    ui->ButRotate->setStyleSheet("");
}

void MainWindow::on_ButRotate_clicked()
{
    ui->ButMoveUp->setVisible(false);
    ui->ButMoveDown->setVisible(false);
    ui->ButMoveRight->setVisible(false);
    ui->ButMoveLeft->setVisible(false);

    ui->ButScaleL->setVisible(false);
    ui->ButScaleR->setVisible(false);

    ui->ButRotClockWise->setVisible(true);
    ui->ButRotAntiClockWise->setVisible(true);

    m_currentEditMode = Rotate;
    QColor col = QColor(Qt::red);
    if(col.isValid()) {
        QString qss = QString("color: %1").arg(col.name());
        ui->ButRotate->setStyleSheet(qss);
    }
    ui->ButMove->setStyleSheet("");
    ui->FigureSelecter->setStyleSheet("");
    //ui->ButPaint->setStyleSheet("");
    ui->ButScale->setStyleSheet("");
}

void MainWindow::on_ButClear_clicked()
{
    ClearCanva();
}
void MainWindow::ClearCanva(){
    m_pCurrentFigure->Clear();
    DisplayCharacteristics();
    update();
}


void MainWindow::on_ButRotAntiClockWise_pressed()
{
    connect(&m_timer,SIGNAL(timeout()),this,SLOT(RotateForButtonAntiClock()));
    m_timer.start(5);
    //m_pCurrentFigure->Rotate(-1);

}


void MainWindow::on_ButRotAntiClockWise_released()
{
    disconnect(&m_timer,SIGNAL(timeout()),this,SLOT(RotateForButtonAntiClock()));
    m_timer.stop();
}




void MainWindow::on_ButRotClockWise_pressed()
{
    connect(&m_timer,SIGNAL(timeout()),this,SLOT(RotateForButtonClock()));
    m_timer.start(5);
    //m_pCurrentFigure->Rotate(-1);
}


void MainWindow::on_ButRotClockWise_released()
{
    disconnect(&m_timer,SIGNAL(timeout()),this,SLOT(RotateForButtonClock()));
    m_timer.stop();
}


void MainWindow::on_ButScaleR_pressed()
{
    connect(&m_timer,SIGNAL(timeout()),this,SLOT(SizeIncrease()));
    m_timer.start(5);
}


void MainWindow::on_ButScaleR_released()
{
    disconnect(&m_timer,SIGNAL(timeout()),this,SLOT(SizeIncrease()));
    m_timer.stop();
}


void MainWindow::on_ButScaleL_pressed()
{
    connect(&m_timer,SIGNAL(timeout()),this,SLOT(SizeDecrease()));
    m_timer.start(5);
}


void MainWindow::on_ButScaleL_released()
{
    disconnect(&m_timer,SIGNAL(timeout()),this,SLOT(SizeDecrease()));
    m_timer.stop();
}


void MainWindow::on_ButMoveRight_pressed()
{
    connect(&m_timer,SIGNAL(timeout()),this,SLOT(MoveRight()));
    m_timer.start(5);
}


void MainWindow::on_ButMoveRight_released()
{
    disconnect(&m_timer,SIGNAL(timeout()),this,SLOT(MoveRight()));
    m_timer.stop();
}


void MainWindow::on_ButMoveLeft_pressed()
{
    connect(&m_timer,SIGNAL(timeout()),this,SLOT(MoveLeft()));
    m_timer.start(5);
}
void MainWindow::on_ButMoveLeft_released()
{
    disconnect(&m_timer,SIGNAL(timeout()),this,SLOT(MoveLeft()));
    m_timer.stop();
}

void MainWindow::on_ButMoveUp_pressed()
{
    connect(&m_timer,SIGNAL(timeout()),this,SLOT(MoveUp()));
    m_timer.start(5);
}
void MainWindow::on_ButMoveUp_released()
{
    disconnect(&m_timer,SIGNAL(timeout()),this,SLOT(MoveUp()));
    m_timer.stop();
}


void MainWindow::on_ButMoveDown_pressed()
{
    connect(&m_timer,SIGNAL(timeout()),this,SLOT(MoveDown()));
    m_timer.start(5);
}


void MainWindow::on_ButMoveDown_released()
{
    disconnect(&m_timer,SIGNAL(timeout()),this,SLOT(MoveDown()));
    m_timer.stop();
}

void MainWindow::RotateForButtonClock(){
    m_pCurrentFigure->Rotate(1);
    DisplayCharacteristics();
    update();
}
void MainWindow::RotateForButtonAntiClock(){
    m_pCurrentFigure->Rotate(-1);
    DisplayCharacteristics();
    update();
}
void MainWindow::SizeIncrease(){
    m_pCurrentFigure->Scale(false);
    DisplayCharacteristics();
    update();
}
void MainWindow::SizeDecrease(){
    m_pCurrentFigure->Scale(true);
    DisplayCharacteristics();
    update();
}

void MainWindow::MoveUp(){
    m_pCurrentFigure->Translate(0.0f, 1.0f);
    update();
}
void MainWindow::MoveDown(){
    m_pCurrentFigure->Translate(0.0f, -1.0f);
    update();
}
void MainWindow::MoveRight(){
    m_pCurrentFigure->Translate(-1.0f, 0.0f);
    update();
}
void MainWindow::MoveLeft(){
    m_pCurrentFigure->Translate(1.0f, 0.0f);
    update();
}

