#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(new MyScene(this))
    , figure(new Circle)
{
    ui->setupUi(this);

    ui -> comboBox -> addItem("Circle");
    ui -> comboBox -> addItem("Ellipse");
    ui -> comboBox -> addItem("Triangle");
    ui -> comboBox -> addItem("Square");
    ui -> comboBox -> addItem("Rectangle");
    ui -> comboBox -> addItem("Hexagon");
    ui -> comboBox -> addItem("Five-pointed Star");
    ui -> comboBox -> addItem("Six-pointed Star");
    ui -> comboBox -> addItem("Eight-pointed Star");
    ui->comboBox->addItem("Paint");

    ui->graphicsView->setScene(scene);

    ui -> comboBox -> setCurrentIndex(0);
    this -> ui -> SliderCircleRadius -> setValue(100);

    scene->addItem(figure);
    setValue();

    connect(ui -> comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeFigure(int)));
    connect(ui -> SliderMoveFigureByX, SIGNAL(valueChanged(int)), this, SLOT(moveFigureByX(int)));
    connect(ui -> SliderMoveFigureByY, SIGNAL(valueChanged(int)), this, SLOT(moveFigureByY(int)));
    connect(ui -> SliderRotateFigure, SIGNAL(valueChanged(int)), this, SLOT(rotateFigure(int)));
    connect(ui -> SliderHexagonRadius, SIGNAL(valueChanged(int)), this, SLOT(setRadius(int)));
    connect(ui -> SliderEllipseRadius, SIGNAL(valueChanged(int)), this, SLOT(setRadius(int)));
    connect(ui -> SliderCircleRadius, SIGNAL(valueChanged(int)), this, SLOT(setRadius(int)));
    connect(ui -> SliderRectangleHeight, SIGNAL(valueChanged(int)), this, SLOT(setHeight(int)));
    connect(ui -> SliderRectangleWidth, SIGNAL(valueChanged(int)), this, SLOT(setWidth(int)));
    connect(ui -> SliderSquareSide, SIGNAL(valueChanged(int)), this, SLOT(setSize(int)));
    connect(ui -> SliderTriangleSize, SIGNAL(valueChanged(int)), this, SLOT(setSize(int)));
    connect(ui -> Slider5StarRadius1, SIGNAL(valueChanged(int)), this, SLOT(setRadius1(int)));
    connect(ui -> Slider5StarRadius2, SIGNAL(valueChanged(int)), this, SLOT(setRadius2(int)));
    connect(ui -> Slider6StarRadius1, SIGNAL(valueChanged(int)), this, SLOT(setRadius1(int)));
    connect(ui -> Slider6StarRadius2, SIGNAL(valueChanged(int)), this, SLOT(setRadius2(int)));
    connect(ui -> SliderStar8Radius1, SIGNAL(valueChanged(int)), this, SLOT(setRadius1(int)));
    connect(ui -> SliderStar8Radius2, SIGNAL(valueChanged(int)), this, SLOT(setRadius2(int)));
    connect(ui -> SliderMoveCenterOfMassByX, SIGNAL(valueChanged(int)), this, SLOT(setCenterX(int)));
    connect(ui -> SliderMoveCenterOfMassByY, SIGNAL(valueChanged(int)), this, SLOT(setCenterY(int)));
    connect(scene, &MyScene::mousePressed, this, &MainWindow::onMousePressed);
    connect(ui -> SliderBrushThickness, SIGNAL(valueChanged(int)), this, SLOT(setScale(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeFigure(int currentIndex)
{
    ui -> stackedWidget_2 -> setCurrentIndex(0);
    scene -> clear();
    _wasPaint = false;
    switch(currentIndex)
    {
    case 0:
        putCircle();
        ui -> stackedWidget -> setCurrentIndex(0);
        break;
    case 1:
        putEllipse();
        ui -> stackedWidget -> setCurrentIndex(6);
        break;
    case 2:
        putTriangle();
        ui -> stackedWidget -> setCurrentIndex(1);
        break;
    case 3:
        putSquare();
        ui -> stackedWidget -> setCurrentIndex(7);
        break;
    case 4:
        putRectangle();
        ui -> stackedWidget -> setCurrentIndex(9);
        break;
    case 5:
        putHexagon();
        ui -> stackedWidget -> setCurrentIndex(8);
        break;
    case 6:
        putFivePointedStar();
        ui -> stackedWidget -> setCurrentIndex(4);
        break;
    case 7:
        putSixPointedStar();
        ui -> stackedWidget -> setCurrentIndex(2);
        break;
    case 8:
        putEightPointedStar();
        ui -> stackedWidget -> setCurrentIndex(5);
        break;
    case 9:
        _wasPaint = true;
        putPaintedFigure();
        ui -> stackedWidget -> setCurrentIndex(3);
        break;
    }

    if(_wasPaint)
    {
        this -> ui -> stackedWidget_2 -> setCurrentIndex(1);
    }
    else
    {
        setCenterX(0);
        setCenterY(0);
        setValue();
    }

    setSliderValue();
}

void MainWindow::moveFigureByX(int newX)
{
    if(!_wasPaint)
    {
        figure -> setX(newX);
        setValue();
    }
    else
    {
        paintedFigure -> setX(newX);
    }
}

void MainWindow::moveFigureByY(int newY)
{
    if(!_wasPaint)
    {
        figure -> setY(newY);
        setValue();
    }
    else
    {
        paintedFigure -> setY(newY);
    }
}

void MainWindow::rotateFigure(int newAngle)
{
    if(!_wasPaint)
    {
        figure -> setTransformOriginPoint(QPoint(figure -> getCenter().rx(), figure -> getCenter().ry()));
        scene -> update();
        figure -> setRotation(newAngle);
        setValue();
    }
    else
    {
        paintedFigure -> setRotation(newAngle);
        scene -> update();
    }
}

void MainWindow::putCircle()
{
    figure = new Circle;
    scene -> addItem(figure);
}

void MainWindow::putEllipse()
{
    figure = new Ellipse;
    scene -> addItem(figure);
}

void MainWindow::putTriangle()
{
    figure = new Triangle;
    scene -> addItem(figure);
}

void MainWindow::putSquare()
{
    figure = new Square;
    scene -> addItem(figure);
}

void MainWindow::putRectangle()
{
    figure = new Rectangle;
    scene -> addItem(figure);
}

void MainWindow::putHexagon()
{
    figure = new Hexagon;
    scene -> addItem(figure);
}

void MainWindow::putFivePointedStar()
{
    figure = new FivePointedStar;
    scene -> addItem(figure);
}

void MainWindow::putSixPointedStar()
{
    figure = new SixPontedStar;
    scene -> addItem(figure);
}

void MainWindow::putEightPointedStar()
{
    figure = new EightPointedStar;
    scene -> addItem(figure);
}

void MainWindow::putPaintedFigure()
{
    paintedFigure = new PaintedFigure;
    setCenterX(0);
    setCenterY(0);
    scene -> addItem(paintedFigure);
}

void MainWindow::setValue()
{
    if(!_wasPaint)
    {
        ui -> Area -> setText(QString::number(figure -> Area()));
        ui -> Perimeter -> setText(QString::number(figure -> Perimeter()));
    }
    ui -> CenterOfMass -> setText("(" + QString::number(figure -> getCenter().x()) + ";" + QString::number(figure -> getCenter().y()) + ")");
}

void MainWindow::onMousePressed(const QPointF &pos)
{
    if(_wasPaint)
    {
        ui -> graphicsView -> viewport() -> update();
        paintedFigure -> pullPoint(pos);
        ui -> graphicsView -> viewport() -> update();
    }
}

void MainWindow::setCenterX(int newCenterX)
{
    if(!_wasPaint)
    {
        figure -> changeCenterX(newCenterX);
        scene -> update();
    }
    else
    {
        paintedFigure -> changeCenterX(newCenterX);
        paintedFigure -> setTransformOriginPoint(QPoint(paintedFigure -> getCenter().rx(), paintedFigure -> getCenter().ry()));
        scene -> update();
    }
    setValue();
}

void MainWindow::setCenterY(int newCenterY)
{
    if(!_wasPaint)
    {
        figure -> changeCenterY(newCenterY);
        scene -> update();
    }
    else
    {
        paintedFigure -> changeCenterY(newCenterY);
        paintedFigure -> setTransformOriginPoint(QPoint(paintedFigure -> getCenter().rx(), paintedFigure -> getCenter().ry()));
        scene -> update();
    }
    setValue();
}

void MainWindow::setRadius(int newRadius)
{
    figure -> changeRadius(newRadius);
    scene -> update();
    setValue();
}

void MainWindow::setHeight(int newHeight)
{
    figure -> changeHeight(newHeight);
    scene -> update();
    setValue();
}

void MainWindow::setWidth(int newWidth)
{
    figure -> changeWidth(newWidth);
    scene -> update();
    setValue();
}

void MainWindow::setSize(int newSize)
{
    figure -> changeSize(newSize);
    scene -> update();
    setValue();
}

void MainWindow::setScale(int newScale)
{
    paintedFigure -> changeScale(newScale);
    scene -> update();
}

void MainWindow::setRadius1(int newRadius1)
{
    figure -> changeRadius1(newRadius1);
    scene -> update();
    setValue();
}

void MainWindow::setRadius2(int newRadius2)
{
    figure -> changeRadius2(newRadius2);
    scene -> update();
    setValue();
}

void MainWindow::setSliderValue()
{
    this -> ui -> SliderMoveFigureByX -> setValue(0);
    this -> ui -> SliderMoveFigureByY -> setValue(0);
    this -> ui -> SliderRotateFigure -> setValue(0);
    this -> ui -> SliderMoveCenterOfMassByX -> setValue(0);
    this -> ui -> SliderMoveCenterOfMassByY -> setValue(0);
    this -> ui -> SliderCircleRadius -> setValue(2 * _sliderValue);
    this -> ui -> SliderEllipseRadius -> setValue(2 * _sliderValue);
    this -> ui -> SliderHexagonRadius -> setValue(2 * _sliderValue);
    this -> ui -> SliderRectangleHeight -> setValue(4 * _sliderValue);
    this -> ui -> SliderRectangleWidth -> setValue(2 * _sliderValue);
    this -> ui -> SliderSquareSide -> setValue(_sliderValue);
    this -> ui -> SliderTriangleSize-> setValue(_sliderValue);
    this -> ui -> Slider5StarRadius1-> setValue(_sliderValue);
    this -> ui -> Slider5StarRadius2-> setValue(_sliderValue);
    this -> ui -> Slider6StarRadius1-> setValue(_sliderValue);
    this -> ui -> Slider6StarRadius2-> setValue(_sliderValue);
    this -> ui -> SliderStar8Radius1-> setValue(_sliderValue);
    this -> ui -> SliderStar8Radius2-> setValue(_sliderValue);
    figure -> makeFlagTrue();
}
