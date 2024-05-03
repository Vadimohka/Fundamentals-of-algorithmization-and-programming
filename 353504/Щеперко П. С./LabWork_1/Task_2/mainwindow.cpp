#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer();
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateValues()
{
    ui->xSpinBox->setMinimum(-10000000);
    ui->ySpinBox->setMinimum(-10000000);
    ui->xSpinBox->setMaximum(10000000);
    ui->ySpinBox->setMaximum(10000000);
    ui->xSpinBox->setValue(figure->getCenter().x());
    ui->ySpinBox->setValue(figure->getCenter().y());
    ui->showSquareLabel->setText(QString::number(figure->findArea(), 'f', 2));
    ui->showPerimeterLabel->setText(QString::number(figure->findPerimeter(), 'f', 2));
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::black);
}

void MainWindow::on_toDrawButton_clicked()
{
    if (ui->figureChoiceComboBox->currentIndex() == 0) {
        QMessageBox::critical(nullptr, "Error", "Figure isn't selected");
    } else if (ui->figureChoiceComboBox->currentIndex() == 1) {
        scene->clear();
        figure = new Triangle();
        Triangle* triangle = dynamic_cast<Triangle*>(figure);
        connect(&triangleD, &TriangleDialog::sendTriangleSignals, triangle, &Triangle::setA);
        triangleD.exec();
        if (triangle->getA()) {
            scene->addItem(figure);
            updateValues();
            curF = 1;
        } else {
            QMessageBox::critical(nullptr, "Error", "Wrong number");
            figure = nullptr;

        }
    } else if (ui->figureChoiceComboBox->currentIndex() == 2) {
        scene->clear();
        figure = new Circle();
        Circle* circle = dynamic_cast<Circle*>(figure);
        connect(&circleD, &CircleDialog::sendCircleSignals, circle, &Circle::setR);
        connect(&circleD, &CircleDialog::sendCheckSignal, circle, &Circle::isCh);
        circleD.exec();
        if (circle->getR()) {
            scene->addItem(figure);
            updateValues();
            curF = 2;
        } else {
            QMessageBox::critical(nullptr, "Error", "Wrong number");
            figure = nullptr;
        }
    } else if (ui->figureChoiceComboBox->currentIndex() == 3) {
        scene->clear();
        figure = new Rhomb();
        Rhomb* rhomb = dynamic_cast<Rhomb*>(figure);
        connect(&rhombD, &RhombDialog::sendRhombSignals, rhomb, &Rhomb::setAB);
        rhombD.exec();
        if (rhomb->getA() && rhomb->getB()) {
            scene->addItem(figure);
            updateValues();
            curF = 3;
        } else {
            QMessageBox::critical(nullptr, "Error", "Wrong number");
            figure = nullptr;
        }
    } else if (ui->figureChoiceComboBox->currentIndex() == 4) {
        scene->clear();
        figure = new Square();
        Square* square = dynamic_cast<Square*>(figure);
        connect(&squareD, &SquareDialog::sendSquareSignals, square, &Square::setA);
        squareD.exec();
        if (square->getA()) {
            scene->addItem(figure);
            updateValues();
            curF = 4;
        } else {
            QMessageBox::critical(nullptr, "Error", "Wrong number");
            figure = nullptr;
        }
    } else if (ui->figureChoiceComboBox->currentIndex() == 5) {
        scene->clear();
        figure = new Rectangle();
        Rectangle* rectangle = dynamic_cast<Rectangle*>(figure);
        connect(&rectangleD, &RectangleDialog::sendRectangleSignals, rectangle, &Rectangle::setAB);
        rectangleD.exec();
        if (rectangle->getA() && rectangle->getB()) {
            scene->addItem(figure);
            updateValues();
            curF = 5;
        } else {
            QMessageBox::critical(nullptr, "Error", "Wrong number");
            figure = nullptr;
        }
    } else if (ui->figureChoiceComboBox->currentIndex() == 6) {
        scene->clear();
        figure = new Hexagon();
        Hexagon* hex = dynamic_cast<Hexagon*>(figure);
        connect(&hexagonD, &HexagonDialog::sendHexagonSignals, hex, &Hexagon::setR);
        hexagonD.exec();
        if (hex->getR()) {
            scene->addItem(figure);
            updateValues();
            curF = 7;
        } else {
            QMessageBox::critical(nullptr, "Error", "Wrong number");
            figure = nullptr;
        }
    } else if (ui->figureChoiceComboBox->currentIndex() == 7) {
        scene->clear();
        figure = new Trapezoid();
        Trapezoid* trapezoid = dynamic_cast<Trapezoid*>(figure);
        connect(&trapezoidD, &TrapezoidDialog::sendTrapezoidSignals, trapezoid, &Trapezoid::setABH);
        trapezoidD.exec();
        if (trapezoid->getA() && trapezoid->getB() && trapezoid->getH()) {
            scene->addItem(figure);
            updateValues();
            curF = 8;
        } else {
            QMessageBox::critical(nullptr, "Error", "Wrong number");
            figure = nullptr;
        }
    }
}


void MainWindow::on_toMoveLeftButton_clicked()
{
    if (figure) {
        figure->moveLeft();
        updateValues();
    }
}


void MainWindow::on_toMoveRightButton_clicked()
{
    if (figure) {
        figure->moveRight();
        updateValues();
    }
}


void MainWindow::on_toMoveUpButton_clicked()
{
    if (figure) {
        figure->moveUp();
        updateValues();
    }
}


void MainWindow::on_toMoveDownButton_clicked()
{
    if (figure) {
        figure->moveDown();
        updateValues();
    }
}


void MainWindow::on_toRotateLeftButton_clicked()
{
    if (figure) {
        figure->rotateLeft();
        updateValues();
    }
}


void MainWindow::on_toRotateRightButton_clicked()
{
    if (figure) {
        figure->rotateRight();
        updateValues();
    }
}


void MainWindow::on_toIncreaseSizeButton_clicked()
{
    if (figure) {
        figure->upScale();
        updateValues();
    }
}


void MainWindow::on_toReduceSizeButton_clicked()
{
    if (figure) {
        figure->downScale();
        updateValues();
    }
}


void MainWindow::on_xSpinBox_valueChanged(int x)
{

    if (figure) {
        figure->SBMoveX(x);
    } else {
        if (x != 0) {
            ui->xSpinBox->setValue(0);
            QMessageBox::critical(nullptr, "Error", "Figure isn't painted");
        }
    }
}

void MainWindow::on_ySpinBox_valueChanged(int y)
{
    if (figure) {
        figure->SBMoveY(y);
    } else {
        if (y != 0) {
            ui->ySpinBox->setValue(0);
            QMessageBox::critical(nullptr, "Error", "Figure isn't painted");
        }
    }
}

void MainWindow::on_toDeleteButton_clicked()
{
    if (figure) {
        scene->clear();
        figure = nullptr;

        ui->xSpinBox->setValue(0);
        ui->ySpinBox->setValue(0);

        ui->showSquareLabel->setText("");
        ui->showPerimeterLabel->setText("");

    } else {
        QMessageBox::critical(nullptr, "Error", "Figure isn't painted");
    }
}

void MainWindow::on_toMoveUpButton_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(moveUpSlot()));
    timer->start(10);
}


void MainWindow::on_toMoveUpButton_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(moveUpSlot()));
    timer->stop();
}


void MainWindow::on_toMoveRightButton_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(moveRightSlot()));
    timer->start(10);
}


void MainWindow::on_toMoveRightButton_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(moveRightSlot()));
    timer->stop();
}


void MainWindow::on_toMoveDownButton_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(moveDownSlot()));
    timer->start(10);
}


void MainWindow::on_toMoveDownButton_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(moveDownSlot()));
    timer->stop();
}


void MainWindow::on_toMoveLeftButton_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(moveLeftSlot()));
    timer->start(10);
}


void MainWindow::on_toMoveLeftButton_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(moveLeftSlot()));
    timer->stop();
}


void MainWindow::on_toRotateLeftButton_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(rotateLeftSlot()));
    timer->start(10);
}


void MainWindow::on_toRotateLeftButton_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(rotateLeftSlot()));
    timer->stop();
}


void MainWindow::on_toRotateRightButton_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(rotateRightSlot()));
    timer->start(10);
}


void MainWindow::on_toRotateRightButton_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(rotateRightSlot()));
    timer->stop();
}


void MainWindow::on_toIncreaseSizeButton_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(upScaleSlot()));
    timer->start(10);
}


void MainWindow::on_toIncreaseSizeButton_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(upScaleSlot()));
    timer->stop();
}


void MainWindow::on_toReduceSizeButton_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(downScaleSlot()));
    timer->start(10);
}


void MainWindow::on_toReduceSizeButton_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(downScaleSlot()));
    timer->stop();
}

void MainWindow::moveUpSlot()
{
    if(figure) {
        figure->moveUp();
        updateValues();
    } else {
        QMessageBox::critical(nullptr, "Error", "Figure isn't painted");
    }
}

void MainWindow::moveDownSlot()
{
    if(figure) {
        figure->moveDown();
        updateValues();
    } else {
        QMessageBox::critical(nullptr, "Error", "Figure isn't painted");
    }
}

void MainWindow::moveRightSlot()
{
    if (figure) {
        figure->moveRight();
        updateValues();
    } else {
        QMessageBox::critical(nullptr, "Error", "Figure isn't painted");
    }
}


void MainWindow::moveLeftSlot()
{
    if(figure) {
        figure->moveLeft();
        updateValues();
    } else {
        QMessageBox::critical(nullptr, "Error", "Figure isn't painted");
    }
}

void MainWindow::rotateRightSlot()
{
    if (figure) {
        figure->rotateRight();
        updateValues();
    } else {
        QMessageBox::critical(nullptr, "Error", "Figure isn't painted");
    }
}

void MainWindow::rotateLeftSlot()
{
    if(figure) {
        figure->rotateLeft();
        updateValues();
    } else {
        QMessageBox::critical(nullptr, "Error", "Figure isn't painted");
    }
}


void MainWindow::upScaleSlot()
{
    if(figure) {
        figure->upScale();
        updateValues();
    } else {
        QMessageBox::critical(nullptr, "Error", "Figure isn't painted");
    }
}


void MainWindow::downScaleSlot()
{
    if(figure) {
        figure->downScale();
        updateValues();
    } else {
        QMessageBox::critical(nullptr, "Error", "Figure isn't painted");
    }
}
