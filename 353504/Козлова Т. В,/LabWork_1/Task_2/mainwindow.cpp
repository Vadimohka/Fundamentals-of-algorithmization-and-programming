#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new PaintScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
    timer->start(100);

    figureTimer = new QTimer();
    connect(figureTimer, &QTimer::timeout, this, &MainWindow::activateButtons);
    figureTimer->start();

    checkingTypeFigureTimer = new QTimer();
    connect(checkingTypeFigureTimer, &QTimer::timeout, this, &MainWindow::activateSpecialTypeButtons);

    scaleDecreaseTimer = new QTimer();
    scaleIncreaseTimer = new QTimer();
    connect(scaleDecreaseTimer, &QTimer::timeout, scene, &PaintScene::scaleDecrease);
    connect(scaleIncreaseTimer, &QTimer::timeout, scene, &PaintScene::scaleIncrease);

    rotateLeftTimer = new QTimer();
    rotateRightTimer = new QTimer();
    connect(rotateLeftTimer, &QTimer::timeout, scene, &PaintScene::rotateLeft);
    connect(rotateRightTimer, &QTimer::timeout, scene, &PaintScene::rotateRight);

    moveTopTimer = new QTimer();
    moveDownTimer = new QTimer();
    moveRightTimer = new QTimer();
    moveLeftTimer = new QTimer();
    connect(moveTopTimer, &QTimer::timeout, scene, &PaintScene::moveTop);
    connect(moveDownTimer, &QTimer::timeout, scene, &PaintScene::moveDown);
    connect(moveLeftTimer, &QTimer::timeout, scene, &PaintScene::moveLeft);
    connect(moveRightTimer, &QTimer::timeout, scene, &PaintScene::moveRight);

    ui->label_14->setVisible(false);
    ui->doubleSpinBox_7->setVisible(false);
    ui->doubleSpinBox_8->setVisible(false);
    ui->label_13->setVisible(false);
    ui->changeVertexValue->setVisible(false);
    ui->label_3->setVisible(false);
    ui->doubleSpinBox_9->setVisible(false);
    ui->doubleSpinBox_10->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::stopAllTimers()
{
    scaleDecreaseTimer->stop();
    scaleIncreaseTimer->stop();
    rotateLeftTimer->stop();
    rotateRightTimer->stop();
    moveTopTimer->stop();
    moveDownTimer->stop();
    moveLeftTimer->stop();
    moveRightTimer->stop();
}


void MainWindow::activateButtons()
{
    if (scene->tempFigure != nullptr)
    {
        ui->doubleSpinBox->setEnabled(true);
        ui->doubleSpinBox_2->setEnabled(true);
        ui->doubleSpinBox_3->setEnabled(true);
        ui->doubleSpinBox_4->setEnabled(true);
        ui->doubleSpinBox_5->setEnabled(true);
        ui->doubleSpinBox_6->setEnabled(true);
        ui->rotateLeftButton->setEnabled(true);
        ui->rotateRightButton->setEnabled(true);
        ui->stopRotateButton->setEnabled(true);
        ui->stopScaleButton->setEnabled(true);
        ui->changeSizeButton->setEnabled(true);
        ui->increaseButton->setEnabled(true);
        ui->decreaseButton->setEnabled(true);
        ui->moveDownButton->setEnabled(true);
        ui->moveLeftButton->setEnabled(true);
        ui->moveRightButton->setEnabled(true);
        ui->moveTopButton->setEnabled(true);
        ui->stopMoveButton->setEnabled(true);
        ui->objectInformationButton->setEnabled(true);
        figureTimer->stop();
        checkingTypeFigureTimer->start();
    }
}


void MainWindow::activateSpecialTypeButtons()
{
    if(scene->buffTypeFigure() == PaintScene::EllipseType)
    {
        ui->label_14->setVisible(true);
        ui->doubleSpinBox_7->setVisible(true);
        ui->doubleSpinBox_8->setVisible(true);
    } else
    {
        ui->label_14->setVisible(false);
        ui->doubleSpinBox_7->setVisible(false);
        ui->doubleSpinBox_8->setVisible(false);
    }

    if(scene->buffTypeFigure() == PaintScene::StarType || scene->buffTypeFigure() == PaintScene::RegularPolygonType)
    {
        ui->label_13->setVisible(true);
        ui->changeVertexValue->setVisible(true);
    } else
    {
        ui->label_13->setVisible(false);
        ui->changeVertexValue->setVisible(false);
    }

    if(scene->buffTypeFigure() == PaintScene::RectangleType)
    {
        ui->label_3->setVisible(true);
        ui->doubleSpinBox_9->setVisible(true);
        ui->doubleSpinBox_10->setVisible(true);
    } else
    {
        ui->label_3->setVisible(false);
        ui->doubleSpinBox_9->setVisible(false);
        ui->doubleSpinBox_10->setVisible(false);
    }
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


void MainWindow::on_createRombButton_clicked()
{
    this->stopAllTimers();

    scene->setTypeFigure(PaintScene::RombType);
    scene->setTypeAction(PaintScene::NoneAction);
}


void MainWindow::on_createRectangleButton_clicked()
{
    this->stopAllTimers();

    scene->setTypeFigure(PaintScene::RectangleType);
    scene->setTypeAction(PaintScene::NoneAction);
}


void MainWindow::on_createTriangleButton_clicked()
{
    this->stopAllTimers();

    scene->setTypeFigure(PaintScene::TriangleType);
    scene->setTypeAction(PaintScene::NoneAction);
}


void MainWindow::on_createParallelogramButton_clicked()
{
    this->stopAllTimers();
    scene->setTypeFigure(PaintScene::ParallelogramType);
    scene->setTypeAction(PaintScene::NoneAction);
}


void MainWindow::on_createEllipseButton_clicked()
{
    stopAllTimers();

    scene->setTypeFigure(PaintScene::EllipseType);
    scene->setTypeAction(PaintScene::NoneAction);
}


void MainWindow::on_createStarButton_clicked()
{
    stopAllTimers();

    scene->setTypeFigure(PaintScene::StarType);
    scene->setTypeAction(PaintScene::NoneAction);
}


void MainWindow::on_createHexagonButton_clicked()
{
    stopAllTimers();

    scene->setTypeFigure(PaintScene::RegularPolygonType);
    scene->setTypeAction(PaintScene::NoneAction);
}


void MainWindow::on_changeSizeButton_clicked()
{
    stopAllTimers();

    scene->setTypeFigure(PaintScene::NoneType);
    scene->setTypeAction(PaintScene::ChangeSizeAction);
}


void MainWindow::on_objectInformationButton_clicked()
{
    QMessageBox::information(nullptr, "Информация о фигуре", scene->figureInformation());
}


void MainWindow::on_decreaseButton_clicked()
{
    if (scaleIncreaseTimer->isActive()) scaleIncreaseTimer->stop();
    if (!scaleDecreaseTimer->isActive()) scaleDecreaseTimer->start(50);

    scene->setTypeFigure(PaintScene::NoneType);
    scene->setTypeAction(PaintScene::ScaleAction);
}


void MainWindow::on_increaseButton_clicked()
{
    if (scaleDecreaseTimer->isActive()) scaleDecreaseTimer->stop();
    if (!scaleIncreaseTimer->isActive()) scaleIncreaseTimer->start(50);

    scene->setTypeFigure(PaintScene::NoneType);
    scene->setTypeAction(PaintScene::ScaleAction);
}


void MainWindow::on_stopScaleButton_clicked()
{
    scaleDecreaseTimer->stop();
    scaleIncreaseTimer->stop();

    scene->setTypeFigure(PaintScene::NoneType);
    scene->setTypeAction(PaintScene::ScaleAction);
}


void MainWindow::on_rotateLeftButton_clicked()
{
    if (rotateRightTimer->isActive()) rotateRightTimer->stop();
    if (!rotateLeftTimer->isActive()) rotateLeftTimer->start(50);

    scene->setTypeFigure(PaintScene::NoneType);
    scene->setTypeAction(PaintScene::RotateAction);
}


void MainWindow::on_rotateRightButton_clicked()
{
    if (rotateLeftTimer->isActive()) rotateLeftTimer->stop();
    if (!rotateRightTimer->isActive()) rotateRightTimer->start(50);

    scene->setTypeFigure(PaintScene::NoneType);
    scene->setTypeAction(PaintScene::RotateAction);
}


void MainWindow::on_stopRotateButton_clicked()
{
    rotateLeftTimer->stop();
    rotateRightTimer->stop();

    scene->setTypeFigure(PaintScene::NoneType);
    scene->setTypeAction(PaintScene::RotateAction);
}


void MainWindow::on_moveTopButton_clicked()
{
    moveDownTimer->stop();
    moveTopTimer->start();

    scene->setTypeFigure(PaintScene::NoneType);
    scene->setTypeAction(PaintScene::MoveAction);
}


void MainWindow::on_moveDownButton_clicked()
{
    moveDownTimer->start();
    moveTopTimer->stop();

    scene->setTypeFigure(PaintScene::NoneType);
    scene->setTypeAction(PaintScene::MoveAction);
}


void MainWindow::on_moveLeftButton_clicked()
{
    moveLeftTimer->start();
    moveRightTimer->stop();

    scene->setTypeFigure(PaintScene::NoneType);
    scene->setTypeAction(PaintScene::MoveAction);
}


void MainWindow::on_moveRightButton_clicked()
{
    moveRightTimer->start();
    moveLeftTimer->stop();

    scene->setTypeFigure(PaintScene::NoneType);
    scene->setTypeAction(PaintScene::MoveAction);
}


void MainWindow::on_stopMoveButton_clicked()
{
    moveDownTimer->stop();
    moveTopTimer->stop();
    moveLeftTimer->stop();
    moveRightTimer->stop();

    scene->setTypeFigure(PaintScene::NoneType);
    scene->setTypeAction(PaintScene::MoveAction);
}


void MainWindow::on_changeVertexValue_valueChanged(int arg1)
{
    scene->tempFigure->setVertexCount(arg1);
}


void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    scene->changeCenterX(arg1);
}


void MainWindow::on_doubleSpinBox_2_valueChanged(double arg1)
{
    scene->changeCenterY(arg1);
}


void MainWindow::on_doubleSpinBox_3_valueChanged(double arg1)
{
    scene->changeStartPointX(arg1);
}


void MainWindow::on_doubleSpinBox_4_valueChanged(double arg1)
{
    scene->changeStartPointY(arg1);
}


void MainWindow::on_doubleSpinBox_5_valueChanged(double arg1)
{
    scene->changeEndPointX(arg1);
}


void MainWindow::on_doubleSpinBox_6_valueChanged(double arg1)
{
    scene->changeEndPointY(arg1);
}


void MainWindow::on_doubleSpinBox_7_valueChanged(double arg1)
{
    scene->tempFigure->setRadiusA(arg1);
}


void MainWindow::on_doubleSpinBox_8_valueChanged(double arg1)
{
    scene->tempFigure->setRadiusB(arg1);
}


void MainWindow::on_doubleSpinBox_9_valueChanged(double arg1)
{
    scene->changeWidth(arg1);
}


void MainWindow::on_doubleSpinBox_10_valueChanged(double arg1)
{
    scene->changeHeight(arg1);
}

