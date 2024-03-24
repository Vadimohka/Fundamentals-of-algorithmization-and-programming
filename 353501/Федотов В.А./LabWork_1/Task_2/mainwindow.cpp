#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // scene = new QGraphicsScene();
    customScene = new CustomScene;

    circle = new ShapeCircle;
    triangle = new ShapeTriangle;
    square = new ShapeSquare;
    rectangle = new ShapeRectangle;
    rhombus = new ShapeRhombus;
    star = new ShapeStar;
    rightPolygon = new ShapeRightPolygon;
    polyline = new ShapePolyline;

    //shapes array
    shapesArray[0] = circle;
    shapesArray[1] = triangle;
    shapesArray[2] = square;
    shapesArray[3] = rectangle;
    shapesArray[4] = rhombus;
    shapesArray[5] = star;
    shapesArray[6] = rightPolygon;
    shapesArray[7] = polyline;

    //scene and window
    resize(0,0);

    ui->graphicsView->setScene(customScene);
    ui->graphicsView->setFixedSize(600, 600);
    ui->graphicsView->setAlignment(Qt::AlignBottom);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    //timer
    timer = new QTimer(this);

    //Прячем фигню
    ui->createShapeButton->hide();
    ui->polygonFrame->hide();
    ui->sidesFrame->hide();
    ui->angleFrame->hide();
    ui->starFrame->hide();
    ui->scaleRotateFrame->hide();

    //коннектим кнопки
    connect(ui->comboBoxShapes, QOverload<int>::of(&QComboBox::activated), this, &MainWindow::selectShape);

    connect(ui->detachButton, QOverload<bool>::of(&QPushButton::toggled), this, &MainWindow::setDetached);

    connect(ui->spinBoxX, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::changeXStart);
    connect(ui->spinBoxY, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::changeYStart);

    connect(ui->side1SpinBox, QOverload<qreal>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::side1Changed);
    connect(ui->side2SpinBox, QOverload<qreal>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::side2Changed);
    connect(ui->side3SpinBox, QOverload<qreal>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::side3Changed);

    connect(ui->angleSpinBox, QOverload<qreal>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::angleChanged);

    connect(ui->pointsSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::pointsChanged);
    connect(ui->radius1SpinBox, QOverload<qreal>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::radius1Changed);
    connect(ui->radius2SpinBox, QOverload<qreal>::of(&QDoubleSpinBox::valueChanged), this, &MainWindow::radius2Changed);

    connect(ui->upScaleButton, &QPushButton::pressed, this, &MainWindow::increaseSizePressed);
    connect(ui->upScaleButton, &QPushButton::released, this, &MainWindow::increaseSizeReleased);

    connect(ui->downScaleButton, &QPushButton::pressed, this, &MainWindow::decreaseSizePressed);
    connect(ui->downScaleButton, &QPushButton::released, this, &MainWindow::decreaseSizeReleased);

    connect(ui->rotateLeftButton, &QPushButton::pressed, this, &MainWindow::rotateLeftPressed);
    connect(ui->rotateLeftButton, &QPushButton::released, this, &MainWindow::rotateLeftReleased);

    connect(ui->rotateRightButton, &QPushButton::pressed, this, &MainWindow::rotateRightPressed);
    connect(ui->rotateRightButton, &QPushButton::released, this, &MainWindow::rotateRightReleased);

    connect(ui->createShapeButton, &QPushButton::clicked, this, &MainWindow::handleShapeCreated);

    selectShape(0);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete customScene;

    delete circle;
    delete triangle;
    delete square;
    delete rectangle;
    delete rhombus;
    delete star;
    delete rightPolygon;
    delete polyline;
}

//select
void MainWindow::selectShape(int index)
{
    if(selectedShapeID != -1){
        shapesArray[selectedShapeID]->clear();
        customScene->removeItem(shapesArray[selectedShapeID]);
    }

    selectedShapeID = index;

    ui->scaleRotateFrame->show();
    ui->coordsFrame->show();

    ui->createShapeButton->hide();
    ui->polygonFrame->hide();
    ui->starFrame->hide();
    ui->sidesFrame->hide();
    ui->angleFrame->hide();
    ui->radius1Frame->hide();
    ui->radius2Frame->hide();
    ui->side1Frame->hide();
    ui->side2Frame->hide();
    ui->side3Frame->hide();

    ui->areaLabel->show();
    ui->areaValueLabel->show();
    ui->perimeterLabel->show();
    ui->perimeterValueLabel->show();

    customScene->clear();

   /* if(selectedShapeID)
    {

    }
    else*/ if(selectedShapeID == 1)
    {
        ui->polygonFrame->show();
        ui->sidesFrame->show();
        ui->side1Frame->show();
        ui->side2Frame->show();
        ui->side3Frame->show();

        ui->side1SpinBox->setValue(triangle->side1);
        ui->side2SpinBox->setValue(triangle->side2);
        ui->side3SpinBox->setValue(triangle->side3);
    }
    else if(selectedShapeID == 3)
    {
        ui->polygonFrame->show();
        ui->sidesFrame->show();
        ui->side1Frame->show();
        ui->side2Frame->show();
        ui->sidesLabel->setText("Rectangle sides:");

        ui->side1SpinBox->setValue(rectangle->side1);
        ui->side2SpinBox->setValue(rectangle->side2);
    }
    else if(selectedShapeID == 4)
    {
        ui->polygonFrame->show();
        ui->angleFrame->show();
        ui->sidesFrame->hide();

        ui->angleSpinBox->setValue(rhombus->anglePoly);
    }
    else if(selectedShapeID == 5)
    {
        ui->polygonFrame->show();
        ui->starFrame->show();
        ui->radius1Frame->show();
        ui->radius2Frame->show();

        ui->pointsSpinBox->setValue(star->numPoints);
        ui->radius1SpinBox->setValue(star->radius1);
        ui->radius2SpinBox->setValue(star->radius2);
    }
    else if(selectedShapeID == 6)
    {
        ui->polygonFrame->show();
        ui->starFrame->show();

        ui->pointsSpinBox->setValue(rightPolygon->numPoints);
    }
    else if(selectedShapeID == 7){
        connect(customScene, &CustomScene::mousePressed, this, &MainWindow::handleMousePressed);

        ui->createShapeButton->show();
        ui->coordsFrame->hide();
        ui->detachButton->hide();
        ui->scaleRotateFrame->hide();
        ui->areaLabel->hide();
        ui->areaValueLabel->hide();
        ui->perimeterLabel->hide();
        ui->perimeterValueLabel->hide();
    }
    else
    {
        ui->polygonFrame->hide();
        ui->sidesFrame->hide();
        ui->angleFrame->hide();
    }

    if (selectedShapeID != 7)
    {
        ui->detachButton->show();
        disconnect(customScene, &CustomScene::mousePressed, this, &MainWindow::handleMousePressed);
    }

    ui->spinBoxX->setValue(shapesArray[selectedShapeID]->shiftX);
    ui->spinBoxY->setValue(shapesArray[selectedShapeID]->shiftY);
    ui->detachButton->setChecked(false);

    customScene->addItem(shapesArray[selectedShapeID]);
    setInfo();

}

//detached
void MainWindow::setDetached(bool isChecked)
{
    shapesArray[selectedShapeID]->setDetached(isChecked);

    if(isChecked){
        ui->detachButton->setText("Detached");
    } else {
        ui->detachButton->setText("Attached");
    }
}

//info
void MainWindow::setInfo()
{
    ui->areaValueLabel->setText(QString::number(shapesArray[selectedShapeID]->area(), 'd', 1));
    ui->perimeterValueLabel->setText(QString::number(shapesArray[selectedShapeID]->perimeter(), 'd', 1));
    ui->centerValueLabel->setText("x: " + QString::number(shapesArray[selectedShapeID]->shiftX) +
                                "  y: " + QString::number(shapesArray[selectedShapeID]->shiftY));
    ui->scaleValueLabel->setText(QString::number(shapesArray[selectedShapeID]->scale));
    ui->rotationValueLabel->setText(QString::number(shapesArray[selectedShapeID]->rotation) + "º");
}

//size
void MainWindow::increaseSizePressed()
{
    connect(timer, &QTimer::timeout, this, &MainWindow::upSize);
    timer->start(10);
}

void MainWindow::upSize()
{
    shapesArray[selectedShapeID]->upScale();
    ui->graphicsView->viewport()->update();
    setInfo();
}

void MainWindow::increaseSizeReleased()
{
    disconnect(timer, &QTimer::timeout, this, &MainWindow::upSize);
    timer->stop();
}

void MainWindow::decreaseSizePressed()
{
    connect(timer, &QTimer::timeout, this, &MainWindow::downSize);
    timer->start(10);
}

void MainWindow::downSize() {
    shapesArray[selectedShapeID]->downScale();
    ui->graphicsView->viewport()->update();
    setInfo();
}

void MainWindow::decreaseSizeReleased()
{
    disconnect(timer, &QTimer::timeout, this, &MainWindow::downSize);
    timer->stop();
}

//rotate
void MainWindow::rotateLeftPressed()
{
    connect(timer, &QTimer::timeout, this, &MainWindow::rotateLeft);
    timer->start(10);
}

void MainWindow::rotateLeft()
{
    shapesArray[selectedShapeID]->rotateLeft();
    ui->graphicsView->viewport()->update();
    setInfo();
}

void MainWindow::rotateLeftReleased()
{
    disconnect(timer, &QTimer::timeout, this, &MainWindow::rotateLeft);
    timer->stop();
}

void MainWindow::rotateRightPressed()
{
    connect(timer, &QTimer::timeout, this, &MainWindow::rotateRight);
    timer->start(10);
}

void MainWindow::rotateRight()
{
    shapesArray[selectedShapeID]->rotateRight();
    ui->graphicsView->viewport()->update();
    setInfo();
}

void MainWindow::rotateRightReleased()
{
    disconnect(timer, &QTimer::timeout, this, &MainWindow::rotateRight);
    timer->stop();
}

//coords
void MainWindow::changeXStart(int value)
{
    targetValue = value;
    currentValue = shapesArray[selectedShapeID]->shiftX;
    connect(timer, &QTimer::timeout, this, &MainWindow::xChanged);
    timer->start(1);
}

void MainWindow::xChanged()
{
    if (currentValue < targetValue) {
        currentValue++;
        shapesArray[selectedShapeID]->changeX(currentValue);
        ui->graphicsView->viewport()->update();
        setInfo();
    } else if(currentValue > targetValue){
        currentValue--;
        shapesArray[selectedShapeID]->changeX(currentValue);
        ui->graphicsView->viewport()->update();
        setInfo();
    } else {
        changeXComplete();
    }
}

void MainWindow::changeXComplete()
{
    disconnect(timer, &QTimer::timeout, this, &MainWindow::xChanged);
    timer->stop();
}

void MainWindow::changeYStart(int value)
{
    targetValue = value;
    currentValue = shapesArray[selectedShapeID]->shiftY;
    connect(timer, &QTimer::timeout, this, &MainWindow::yChanged);
    timer->start(1);
}

void MainWindow::yChanged()
{
    if (currentValue < targetValue) {
        currentValue++;
        shapesArray[selectedShapeID]->changeY(currentValue);
        ui->graphicsView->viewport()->update();
        setInfo();
    } else if(currentValue > targetValue){
        currentValue--;
        shapesArray[selectedShapeID]->changeY(currentValue);
        ui->graphicsView->viewport()->update();
        setInfo();
    } else {
        changeYComplete();
    }
}

void MainWindow::changeYComplete()
{
    disconnect(timer, &QTimer::timeout, this, &MainWindow::yChanged);
    timer->stop();
}

//sides
void MainWindow::side1Changed(qreal value)
{
    shapesArray[selectedShapeID]->changeSide1(value);
    ui->graphicsView->viewport()->update();
    setInfo();
}

void MainWindow::side2Changed(qreal value)
{
    shapesArray[selectedShapeID]->changeSide2(value);
    ui->graphicsView->viewport()->update();
    setInfo();
}

void MainWindow::side3Changed(qreal value)
{
    shapesArray[selectedShapeID]->changeSide3(value);
    ui->graphicsView->viewport()->update();
    setInfo();
}

//angle
void MainWindow::angleChanged(qreal value)
{
    shapesArray[selectedShapeID]->changeAngle(value);
    ui->graphicsView->viewport()->update();
    setInfo();
}

//points
void MainWindow::pointsChanged(int value)
{
    shapesArray[selectedShapeID]->changePoints(value);
    ui->graphicsView->viewport()->update();
    setInfo();
}

//radius
void MainWindow::radius1Changed(qreal value)
{
    shapesArray[selectedShapeID]->changeRadius1(value);
    ui->graphicsView->viewport()->update();
    setInfo();
}

void MainWindow::radius2Changed(qreal value)
{
    shapesArray[selectedShapeID]->changeRadius2(value);
    ui->graphicsView->viewport()->update();
    setInfo();
}

//polyline stuff
void MainWindow::handleMousePressed(const QPointF &position)
{
    polyline->getPoint(position);
    ui->graphicsView->viewport()->update();
}

void MainWindow::handleShapeCreated()
{
    ui->createShapeButton->hide();
    ui->coordsFrame->show();
    ui->detachButton->show();
    ui->scaleRotateFrame->show();

    disconnect(customScene, &CustomScene::mousePressed, this, &MainWindow::handleMousePressed);
}
