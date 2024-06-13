#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    selectLay = new QGroupBox(this);
    selectLay->setGeometry(1480, 0, 360, 500);

    rectangleRadio = new QRadioButton(selectLay);
    rectangleRadio->setGeometry(10, 10, 100, 20);
    rectangleRadio->setText("rectangle");
    rectangleRadio->click();

    triangleRadio = new QRadioButton(selectLay);
    triangleRadio->setGeometry(10, 40, 100, 20);
    triangleRadio->setText("triangle");

    circleRadio = new QRadioButton(selectLay);
    circleRadio->setGeometry(10, 70, 100, 20);
    circleRadio->setText("circle");

    rhombRadio = new QRadioButton(selectLay);
    rhombRadio->setGeometry(10, 100, 100, 20);
    rhombRadio->setText("rhomb");

    squareRadio = new QRadioButton(selectLay);
    squareRadio->setGeometry(10, 130, 100, 20);
    squareRadio->setText("square");

    hexagonRadio = new QRadioButton(selectLay);
    hexagonRadio->setGeometry(10, 160, 100, 20);
    hexagonRadio->setText("hexagon");

    star5Radio = new QRadioButton(selectLay);
    star5Radio->setGeometry(10, 190, 100, 20);
    star5Radio->setText("star5");

    star5Radio = new QRadioButton(selectLay);
    star5Radio->setGeometry(10, 190, 100, 20);
    star5Radio->setText("star5");

    star6Radio = new QRadioButton(selectLay);
    star6Radio->setGeometry(10, 220, 100, 20);
    star6Radio->setText("star6");

    star8Radio = new QRadioButton(selectLay);
    star8Radio->setGeometry(10, 250, 100, 20);
    star8Radio->setText("star8");

    polygon_NRadio = new QRadioButton(selectLay);
    polygon_NRadio->setGeometry(10, 280, 100, 20);
    polygon_NRadio->setText("polygon");

    polygonSpin = new QSpinBox(selectLay);
    polygonSpin->setGeometry(90, 280, 50, 20);
    polygonSpin->setMaximum(16);
    polygonSpin->setMinimum(3);

    infoLay = new QGroupBox(this);
    infoLay->setGeometry(1660, 500, 180, 120);

    areaL = new QLabel(infoLay);
    areaL->setGeometry(90, 0, 90, 40);
    areaT = new QLabel(infoLay);
    areaT->setText("area");
    areaT->setGeometry(0, 0, 90, 40);

    centreL = new QLabel(infoLay);
    centreL->setGeometry(90, 40, 90, 40);
    centreT = new QLabel(infoLay);
    centreT->setText("centre");
    centreT->setGeometry(0, 40, 90, 40);

    perimetrL = new QLabel(infoLay);
    perimetrL->setGeometry(90, 80, 90, 40);
    perimetrT = new QLabel(infoLay);
    perimetrT->setText("perimetr");
    perimetrT->setGeometry(0, 80, 90, 49);


    buttonLay = new QGroupBox(this);
    buttonLay->setGeometry(1480, 500, 180, 120);

    rotationLeft = new QPushButton(buttonLay);
    rotationLeft->setText("⟲");
    rotationLeft->setGeometry(0, 70, 50, 50);

    rotationRight = new QPushButton(buttonLay);
    rotationRight->setText("⟳");
    rotationRight->setGeometry(130, 70, 50, 50);

    rotation = new QPushButton(buttonLay);
    rotation->setGeometry(50, 95, 80, 25);
    rotation->setText("rotate");

    increaseButton = new QPushButton(buttonLay);
    increaseButton->setGeometry(0, 0, 50, 50);
    increaseButton->setText("+");

    decreaseButton = new QPushButton(buttonLay);
    decreaseButton->setGeometry(130, 0, 50, 50);
    decreaseButton->setText("-");

    enterAngle = new QLineEdit(buttonLay);
    enterAngle->setGeometry(50, 70, 80, 25);
    enterAngle->setAlignment(Qt::AlignHCenter);

    rotationTimer = new QTimer(this);
    rotationTimer->setInterval(10);
    rotationTimer->start();


    modesLay = new QGroupBox(this);
    modesLay->setGeometry(1600, 800, 200, 150);

    createMode = new QRadioButton(modesLay);
    createMode->setText("create");
    createMode->setGeometry(7, 10, 100, 15);
    createMode->click();

    moveMode = new QRadioButton(modesLay);
    moveMode->setText("move");
    moveMode->setGeometry(7, 30, 100, 15);


    MainWindow::connect(rotationLeft, SIGNAL(pressed()), this, SLOT(on_rotationLeft_pressed()));

    MainWindow::connect(rotationLeft, SIGNAL(released()), this, SLOT(on_rotationLeft_released()));

    MainWindow::connect(rotationRight, SIGNAL(pressed()), this, SLOT(on_rotationRight_pressed()));

    MainWindow::connect(rotationRight, SIGNAL(released()), this, SLOT(on_rotationRight_released()));

    MainWindow::connect(rotation, SIGNAL(pressed()), this, SLOT(on_rotation_clicked()));

    MainWindow::connect(increaseButton, SIGNAL(pressed()), this, SLOT(on_increaseButton_pressed()));

    MainWindow::connect(increaseButton, SIGNAL(released()), this, SLOT(on_increaseButton_released()));

    MainWindow::connect(decreaseButton, SIGNAL(pressed()), this, SLOT(on_decreaseButton_pressed()));

    MainWindow::connect(decreaseButton, SIGNAL(released()), this, SLOT(on_decreaseButton_released()));
}


void MainWindow::mousePressEvent(QMouseEvent *evt){

    if (createMode->isChecked()){
        Figure* figure = nullptr;
        num++;
        if (rectangleRadio->isChecked()){
            figure = new Rectangle(this);

        }

        if (triangleRadio->isChecked()){
            figure = new Triangle(this);

        }


        if (circleRadio->isChecked()){
            figure = new Circle(this);

        }

        if (rhombRadio->isChecked()){
            figure = new Rhomb(this);

        }

        if (squareRadio->isChecked()){
            figure = new Square(this);

        }

        if (hexagonRadio->isChecked()){
            figure = new Hexagon(this);

        }

        if (star5Radio->isChecked()){
            figure = new Star5(this);

        }

        if (star6Radio->isChecked()){
            figure = new Star6(this);

        }

        if (star8Radio->isChecked()){
            figure = new Star8(this);

        }

        if (polygon_NRadio->isChecked()){
            figure = new Polygon_N(this);
            figure->setN(polygonSpin->text());

        }

        figuresArray.emplace_back((figure));
        polygons.push_back(figure->pol);
        selectedNum = num;
        figuresArray[num]->mousePressing(evt);
    }

    else if (moveMode->isChecked()){
        for (int i = num; i >= 0; i--){
            if (polygons[i].containsPoint(evt->pos(), Qt::OddEvenFill) || figuresArray[i]->isInside(evt)){
                figuresArray[i]->mousePressingMoveMode(evt);
                selectedNum = i;
                updateInfo();
                break;
            }
            else{
                selectedNum = -1;
            }
        }
    }
}


void MainWindow::mouseMoveEvent(QMouseEvent *evt){
    if (createMode->isChecked()){

        figuresArray[num]->mouseMoving(evt);
        updateInfo();
    }


    if (moveMode->isChecked() && selectedNum >= 0){
        if (polygons[selectedNum].containsPoint(evt->pos(), Qt::OddEvenFill) || figuresArray[selectedNum]->isInside(evt) || true){
        figuresArray[selectedNum]->mouseMovingMoveMode(evt);

        updateInfo();
        }
    }

    update();
}


void MainWindow::paintEvent(QPaintEvent*evt){
    QPainter *pe = new QPainter(this);
    QPen pen;
    pen.setWidth(2);
    pe->setPen(pen);

    for (int i = 0; i <= num; i++){
        figuresArray[i]->draw(pe);

        polygons[i] = figuresArray[i]->pol;
    }
    pe->end();
}


void MainWindow::on_rotationLeft_pressed(){
    if (selectedNum >= 0){
        Figure::connect(rotationTimer, &QTimer::timeout, figuresArray[selectedNum], &Figure::rotateLeft);
        MainWindow::connect(rotationTimer, SIGNAL(timeout()), this, SLOT(update()));
        MainWindow::connect(rotationTimer, SIGNAL(timeout()), this, SLOT(updatePolygon(selectedNum)));
        MainWindow::connect(rotationTimer, SIGNAL(timeout()), this, SLOT(updateInfo()));
    }
}


void MainWindow::on_rotationLeft_released(){
    if (selectedNum >= 0){
        Figure::disconnect(rotationTimer, &QTimer::timeout, figuresArray[selectedNum], &Figure::rotateLeft);
        MainWindow::disconnect(rotationTimer, SIGNAL(timeout()), this, SLOT(update()));
        MainWindow::disconnect(rotationTimer, SIGNAL(timeout()), this, SLOT(updatePolygon(selectedNum)));
        MainWindow::disconnect(rotationTimer, SIGNAL(timeout()), this, SLOT(updateInfo()));
    }
}


void MainWindow::on_rotationRight_pressed(){
    if (selectedNum >= 0){
        Figure::connect(rotationTimer, &QTimer::timeout, figuresArray[selectedNum], &Figure::rotateRight);
        MainWindow::connect(rotationTimer, SIGNAL(timeout()), this, SLOT(update()));
        MainWindow::connect(rotationTimer, SIGNAL(timeout()), this, SLOT(updatePolygon(selectedNum)));
        MainWindow::connect(rotationTimer, SIGNAL(timeout()), this, SLOT(updateInfo()));

    }
}


void MainWindow::on_rotationRight_released(){
    if (selectedNum >= 0){
        Figure::disconnect(MainWindow::rotationTimer, &QTimer::timeout, figuresArray[selectedNum], &Figure::rotateRight);
        MainWindow::disconnect(rotationTimer, SIGNAL(timeout()), this, SLOT(update()));
        MainWindow::disconnect(rotationTimer, SIGNAL(timeout()), this, SLOT(updatePolygon(selectedNum)));
        MainWindow::disconnect(rotationTimer, SIGNAL(timeout()), this, SLOT(updateInfo()));
    }
}


void MainWindow::on_rotation_clicked(){
    QString data = enterAngle->text();
    if (data.size() > 0 && selectedNum >= 0){
        double angle = data.toDouble() * M_PI / 180;
        figuresArray[selectedNum]->rotate(angle);
        updatePolygon(selectedNum);
        updateInfo();
        update();
    }
}


void MainWindow::on_increaseButton_pressed(){
    if (selectedNum >= 0){
        Figure::connect(rotationTimer, &QTimer::timeout, figuresArray[selectedNum], &Figure::increase);
        MainWindow::connect(rotationTimer, SIGNAL(timeout()), this, SLOT(update()));
        MainWindow::connect(rotationTimer, SIGNAL(timeout()), this, SLOT(updatePolygon(selectedNum)));
        MainWindow::connect(rotationTimer, SIGNAL(timeout()), this, SLOT(updateInfo()));
    }
}


void MainWindow::on_decreaseButton_pressed(){
    if (selectedNum >= 0){
        Figure::connect(rotationTimer, &QTimer::timeout, figuresArray[selectedNum], &Figure::decrease);
        MainWindow::connect(rotationTimer, SIGNAL(timeout()), this, SLOT(update()));
        MainWindow::connect(rotationTimer, SIGNAL(timeout()), this, SLOT(updatePolygon(selectedNum)));
        MainWindow::connect(rotationTimer, SIGNAL(timeout()), this, SLOT(updateInfo()));
    }
}


void MainWindow::on_increaseButton_released(){
    if (selectedNum >= 0){
        Figure::disconnect(rotationTimer, &QTimer::timeout, figuresArray[selectedNum], &Figure::increase);
        MainWindow::disconnect(rotationTimer, SIGNAL(timeout()), this, SLOT(update()));
        MainWindow::disconnect(rotationTimer, SIGNAL(timeout()), this, SLOT(updatePolygon(selectedNum)));
        MainWindow::disconnect(rotationTimer, SIGNAL(timeout()), this, SLOT(updateInfo()));
    }
}


void MainWindow::on_decreaseButton_released(){
    if (selectedNum >= 0){
        Figure::disconnect(rotationTimer, &QTimer::timeout, figuresArray[selectedNum], &Figure::decrease);
        MainWindow::disconnect(rotationTimer, SIGNAL(timeout()), this, SLOT(update()));
        MainWindow::disconnect(rotationTimer, SIGNAL(timeout()), this, SLOT(updatePolygon(selectedNum)));
        MainWindow::disconnect(rotationTimer, SIGNAL(timeout()), this, SLOT(updateInfo()));
    }
}

void MainWindow::updatePolygon(int selected){
    polygons[selected] = figuresArray[selected]->pol;
}


void MainWindow::updateInfo(){
    figuresArray[selectedNum]->setInfo();

    areaL->setText(QString::number(figuresArray[selectedNum]->getArea()));
    centreL->setText("x : " + QString::number(figuresArray[selectedNum]->getCentre().x()) + "\ny : " + QString::number(figuresArray[selectedNum]->getCentre().y()));
    perimetrL->setText(QString::number(figuresArray[selectedNum]->getPerimetr()));
}

MainWindow::~MainWindow()
{
    delete ui;

}
