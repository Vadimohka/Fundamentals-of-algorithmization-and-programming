#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new MainScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setBackgroundBrush(Qt::white);
    this->setStyleSheet("background-color: grey;");

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
    timer->start(100);

    ShapeTimer = new QTimer();
    connect(ShapeTimer, &QTimer::timeout, this, &MainWindow::activateButtons);
    ShapeTimer->start();

    checkingTypeShapeTimer = new QTimer();
    connect(checkingTypeShapeTimer, &QTimer::timeout, this, &MainWindow::activateSpecialTypeButtons);

    scaleDecreaseTimer = new QTimer();
    scaleIncreaseTimer = new QTimer();
    connect(scaleDecreaseTimer, &QTimer::timeout, scene, &MainScene::scaleDecrease);
    connect(scaleIncreaseTimer, &QTimer::timeout, scene, &MainScene::scaleIncrease);

    rotateLeftTimer = new QTimer();
    rotateRightTimer = new QTimer();
    connect(rotateLeftTimer, &QTimer::timeout, scene, &MainScene::rotateLeft);
    connect(rotateRightTimer, &QTimer::timeout, scene, &MainScene::rotateRight);

    moveTopTimer = new QTimer();
    moveDownTimer = new QTimer();
    moveRightTimer = new QTimer();
    moveLeftTimer = new QTimer();
    connect(moveTopTimer, &QTimer::timeout, scene, &MainScene::moveTop);
    connect(moveDownTimer, &QTimer::timeout, scene, &MainScene::moveDown);
    connect(moveLeftTimer, &QTimer::timeout, scene, &MainScene::moveLeft);
    connect(moveRightTimer, &QTimer::timeout, scene, &MainScene::moveRight);

    ui->label_13->setVisible(false);
    ui->changeVertexValue->setVisible(false);
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
    if (scene->tempShape != nullptr)
    {
        ui->doubleSpinBox->setEnabled(true);
        ui->doubleSpinBox_2->setEnabled(true);
        ui->rotateLeftButton->setEnabled(true);
        ui->rotateRightButton->setEnabled(true);
        ui->stopRotateButton->setEnabled(true);
        ui->stopScaleButton->setEnabled(true);
        ui->increaseButton->setEnabled(true);
        ui->decreaseButton->setEnabled(true);
        ui->moveDownButton->setEnabled(true);
        ui->moveLeftButton->setEnabled(true);
        ui->moveRightButton->setEnabled(true);
        ui->moveTopButton->setEnabled(true);
        ui->stopMoveButton->setEnabled(true);
        ui->objectInformationButton->setEnabled(true);
        ShapeTimer->stop();
        checkingTypeShapeTimer->start();
    }
}


void MainWindow::activateSpecialTypeButtons()
{

    if(scene->buffTypeShape() == MainScene::StarType || scene->buffTypeShape() == MainScene::RegularPolygonType)
    {
        ui->label_13->setVisible(true);
        ui->changeVertexValue->setVisible(true);
    } else
    {
        ui->label_13->setVisible(false);
        ui->changeVertexValue->setVisible(false);
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

    scene->setTypeShape(MainScene::RombType);
    scene->setTypeAction(MainScene::NoneAction);
}


void MainWindow::on_createRectangleButton_clicked()
{
    this->stopAllTimers();

    scene->setTypeShape(MainScene::RectangleType);
    scene->setTypeAction(MainScene::NoneAction);
}


void MainWindow::on_createTriangleButton_clicked()
{
    this->stopAllTimers();

    scene->setTypeShape(MainScene::TriangleType);
    scene->setTypeAction(MainScene::NoneAction);
}


void MainWindow::on_createParallelogramButton_clicked()
{
    this->stopAllTimers();
    scene->setTypeShape(MainScene::ParallelogramType);
    scene->setTypeAction(MainScene::NoneAction);
}


void MainWindow::on_createEllipseButton_clicked()
{
    stopAllTimers();

    scene->setTypeShape(MainScene::EllipseType);
    scene->setTypeAction(MainScene::NoneAction);
}


void MainWindow::on_createStarButton_clicked()
{
    stopAllTimers();

    scene->setTypeShape(MainScene::StarType);
    scene->setTypeAction(MainScene::NoneAction);
}


void MainWindow::on_createHexagonButton_clicked()
{
    stopAllTimers();

    scene->setTypeShape(MainScene::RegularPolygonType);
    scene->setTypeAction(MainScene::NoneAction);
}


void MainWindow::on_changeSizeButton_clicked()
{
    stopAllTimers();

    scene->setTypeShape(MainScene::NoneType);
    scene->setTypeAction(MainScene::ChangeSizeAction);
}


void MainWindow::on_objectInformationButton_clicked()
{
    QMessageBox::information(nullptr, "Информация о фигуре", scene->ShapeInformation());
}


void MainWindow::on_decreaseButton_clicked()
{
    if (scaleIncreaseTimer->isActive()) scaleIncreaseTimer->stop();
    if (!scaleDecreaseTimer->isActive()) scaleDecreaseTimer->start(50);

    scene->setTypeShape(MainScene::NoneType);
    scene->setTypeAction(MainScene::ScaleAction);
}


void MainWindow::on_increaseButton_clicked()
{
    if (scaleDecreaseTimer->isActive()) scaleDecreaseTimer->stop();
    if (!scaleIncreaseTimer->isActive()) scaleIncreaseTimer->start(50);

    scene->setTypeShape(MainScene::NoneType);
    scene->setTypeAction(MainScene::ScaleAction);
}


void MainWindow::on_stopScaleButton_clicked()
{
    scaleDecreaseTimer->stop();
    scaleIncreaseTimer->stop();

    scene->setTypeShape(MainScene::NoneType);
    scene->setTypeAction(MainScene::ScaleAction);
}


void MainWindow::on_rotateLeftButton_clicked()
{
    if (rotateRightTimer->isActive()) rotateRightTimer->stop();
    if (!rotateLeftTimer->isActive()) rotateLeftTimer->start(50);

    scene->setTypeShape(MainScene::NoneType);
    scene->setTypeAction(MainScene::RotateAction);
}


void MainWindow::on_rotateRightButton_clicked()
{
    if (rotateLeftTimer->isActive()) rotateLeftTimer->stop();
    if (!rotateRightTimer->isActive()) rotateRightTimer->start(50);

    scene->setTypeShape(MainScene::NoneType);
    scene->setTypeAction(MainScene::RotateAction);
}


void MainWindow::on_stopRotateButton_clicked()
{
    rotateLeftTimer->stop();
    rotateRightTimer->stop();

    scene->setTypeShape(MainScene::NoneType);
    scene->setTypeAction(MainScene::RotateAction);
}


void MainWindow::on_moveTopButton_clicked()
{
    moveDownTimer->stop();
    moveTopTimer->start();

    scene->setTypeShape(MainScene::NoneType);
    scene->setTypeAction(MainScene::MoveAction);
}


void MainWindow::on_moveDownButton_clicked()
{
    moveDownTimer->start();
    moveTopTimer->stop();

    scene->setTypeShape(MainScene::NoneType);
    scene->setTypeAction(MainScene::MoveAction);
}


void MainWindow::on_moveLeftButton_clicked()
{
    moveLeftTimer->start();
    moveRightTimer->stop();

    scene->setTypeShape(MainScene::NoneType);
    scene->setTypeAction(MainScene::MoveAction);
}


void MainWindow::on_moveRightButton_clicked()
{
    moveRightTimer->start();
    moveLeftTimer->stop();

    scene->setTypeShape(MainScene::NoneType);
    scene->setTypeAction(MainScene::MoveAction);
}


void MainWindow::on_stopMoveButton_clicked()
{
    moveDownTimer->stop();
    moveTopTimer->stop();
    moveLeftTimer->stop();
    moveRightTimer->stop();

    scene->setTypeShape(MainScene::NoneType);
    scene->setTypeAction(MainScene::MoveAction);
}


void MainWindow::on_changeVertexValue_valueChanged(int arg1)
{
    scene->tempShape->setVertexCount(arg1);
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
    scene->tempShape->setRadiusA(arg1);
}


void MainWindow::on_doubleSpinBox_8_valueChanged(double arg1)
{
    scene->tempShape->setRadiusB(arg1);
}


void MainWindow::on_doubleSpinBox_9_valueChanged(double arg1)
{
    scene->changeWidth(arg1);
}


void MainWindow::on_doubleSpinBox_10_valueChanged(double arg1)
{
    scene->changeHeight(arg1);
}

