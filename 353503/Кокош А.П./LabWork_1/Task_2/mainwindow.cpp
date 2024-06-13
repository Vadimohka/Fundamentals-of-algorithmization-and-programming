#include "mainwindow.h"

enum {
    TRIANGLE = 0,
    CIRCLE = 1,
    RHOMBUS = 2,
    SQUARE = 3,
    STAR5 = 4,
    STAR6 = 5,
    STAR7 = 6,
    STAR8 = 7,
    HEXAGON = 8,
    POLYLINE = 9,
    SPINMIN = 5,
    SPINMAX = 8,
    TIMERCOUNT = 20,
    MAX_X = 960,
    MAX_Y = 540
};

MainWindow::MainWindow(QWidget * /*unused*/)
    : spin5to8(new QSpinBox)
    , spinForX(new QSpinBox)
    , spinForY(new QSpinBox)
    , textCenter(new QLabel())
    , textSquare(new QLabel())
    , textPerimeter(new QLabel())
{
    figuresArray[TRIANGLE] = myTriangle;
    figuresArray[CIRCLE] = myCircle;
    figuresArray[RHOMBUS] = myRhombus;
    figuresArray[SQUARE] = mySquare;
    figuresArray[STAR5] = myStar5;
    figuresArray[STAR6] = myStar6;
    figuresArray[STAR7] = myStar7;
    figuresArray[STAR8] = myStar8;
    figuresArray[HEXAGON] = myHexagon;
    figuresArray[POLYLINE] = myPolyline;

    auto *figuresVBox = new QVBoxLayout;
    auto *figuresGBox = new QGroupBox;
    auto *infoGBox = new QGroupBox;

    QVBoxLayout *actionsVBox = new QVBoxLayout;
    QGroupBox *actionsGBox = new QGroupBox;

    QVBoxLayout *buttonsVBox = new QVBoxLayout;

    auto *Grid = new QGridLayout(this);

    //Add My buttons

    //Triangle
    triangleButton = new QRadioButton("Triangle");
    triangleButton->setToolTip("Поставьте три точки для создания треугольника");
    figuresVBox->addWidget(triangleButton);
    triangleButton->setChecked(true);
    connect(triangleButton, SIGNAL(clicked(bool)), SLOT(selectFigure()));

    //Circle
    circleButton = new QRadioButton("Circle");
    figuresVBox->addWidget(circleButton);
    connect(circleButton, SIGNAL(clicked(bool)), SLOT(selectFigure()));

    //Rhombus
    rhombusButton = new QRadioButton("Rhombus");
    figuresVBox->addWidget(rhombusButton);
    connect(rhombusButton, SIGNAL(clicked(bool)), SLOT(selectFigure()));

    //Rectangle
    rectangleButton = new QRadioButton("Rectangle");
    figuresVBox->addWidget(rectangleButton);
    connect(rectangleButton, SIGNAL(clicked(bool)), SLOT(selectFigure()));

    //Star
    QHBoxLayout *starHBox = new QHBoxLayout;
    starButton = new QRadioButton("Star");
    connect(starButton, SIGNAL(clicked(bool)), SLOT(selectFigure()));
    starHBox->addWidget(starButton, 0);
    spin5to8->setMinimum(SPINMIN);
    spin5to8->setMaximum(SPINMAX);
    starHBox->addWidget(spin5to8);
    connect(spin5to8, SIGNAL(valueChanged(int)), SLOT(star()));

    figuresVBox->addLayout(starHBox);

    //Hexagon
    hexagonButton = new QRadioButton("Hexagon");
    figuresVBox->addWidget(hexagonButton);
    connect(hexagonButton, SIGNAL(clicked(bool)), SLOT(selectFigure()));

    //PolyLine
    polylineButton = new QRadioButton("Polyline");
    figuresVBox->addWidget(polylineButton);
    connect(polylineButton, SIGNAL(clicked(bool)), SLOT(selectFigure()));

    figuresGBox->setLayout(figuresVBox);
    Grid->addWidget(figuresGBox, 1, 0, Qt::AlignBottom);

    //For info
    QGridLayout *textInfoL = new QGridLayout;

    QLabel *label1 = new QLabel("Perimeter");

    QLabel *label2 = new QLabel("Square");

    QLabel *label3 = new QLabel("Center");

    textInfoL->addWidget(label1, 0, 0);
    textInfoL->addWidget(textPerimeter, 0, 1);
    textInfoL->addWidget(label2, 1, 0);
    textInfoL->addWidget(textSquare, 1, 1);
    textInfoL->addWidget(label3, 2, 0);
    textInfoL->addWidget(textCenter, 2, 1);
    infoGBox->setLayout(textInfoL);
    auto infoVL = new QVBoxLayout;
    actionsVBox->addWidget(infoGBox);

    ///Action buttons

    //Draw
    drawButton = new QRadioButton("Create");
    actionsVBox->addWidget(drawButton);
    drawButton->setChecked(true);

    //Move
    moveButton = new QRadioButton("Move");
    actionsVBox->addWidget(moveButton);

    //Move by cord
    QHBoxLayout *cords = new QHBoxLayout;

    spinForX->setMinimum(-MAX_X);
    spinForX->setMaximum(MAX_X);
    cords->addWidget(spinForX);

    spinForY->setMinimum(-MAX_Y);
    spinForY->setMaximum(MAX_Y);
    cords->addWidget(spinForY);
    actionsVBox->addLayout(cords);

    moveByCord = new QPushButton("Move by cords");
    actionsVBox->addWidget(moveByCord);
    connect(moveByCord, SIGNAL(clicked(bool)), SLOT(moveByCordButtonClicked()));

    //Chenge size(resize)
    QHBoxLayout *sizeHBox = new QHBoxLayout;
    sizePlus = new QPushButton("Size+");
    sizeMinus = new QPushButton("Size-");
    sizeHBox->addWidget(sizeMinus);
    sizeHBox->addSpacing(1);
    sizeHBox->addWidget(sizePlus);
    actionsVBox->addLayout(sizeHBox);
    connect(sizePlus, SIGNAL(pressed()), SLOT(on_sizePlus_pressed()));
    connect(sizePlus, SIGNAL(released()), SLOT(on_sizePlus_released()));
    connect(sizeMinus, SIGNAL(pressed()), SLOT(on_sizeMinus_pressed()));
    connect(sizeMinus, SIGNAL(released()), SLOT(on_sizeMinus_released()));

    auto resizeTextLabel = new QLabel("Resize");
    resizeTextLabel->setAlignment(Qt::AlignCenter);
    actionsVBox->addWidget(resizeTextLabel);

    //Rotate
    QHBoxLayout *rotateHBox = new QHBoxLayout;
    rotateLEFT = new QPushButton("Left");
    rotateRIGHT = new QPushButton("Right");
    rotateHBox->addWidget(rotateLEFT);
    rotateHBox->addSpacing(1);
    rotateHBox->addWidget(rotateRIGHT);
    actionsVBox->addLayout(rotateHBox);
    connect(rotateLEFT, SIGNAL(pressed()), SLOT(on_rotateLEFT_pressed()));
    connect(rotateRIGHT, SIGNAL(pressed()), SLOT(on_rotateRIGHT_pressed()));
    connect(rotateLEFT, SIGNAL(released()), SLOT(on_rotateLEFT_released()));
    connect(rotateRIGHT, SIGNAL(released()), SLOT(on_rotateRIGHT_released()));

    auto rotateText = new QLabel("Rotate");
    rotateText->setAlignment(Qt::AlignCenter);
    actionsVBox->addWidget(rotateText);

    actionsGBox->setLayout(actionsVBox);

    buttonsVBox->addStretch(100000);
    buttonsVBox->addLayout(infoVL);
    buttonsVBox->addStretch(100000);
    buttonsVBox->addWidget(actionsGBox);

    QPushButton *closeButton = new QPushButton("Close");
    connect(closeButton, SIGNAL(clicked(bool)), SLOT(closeButtonClicked()));

    QPushButton *surpriseButton = new QPushButton("???");
    connect(surpriseButton, SIGNAL(clicked(bool)), SLOT(surpriseButtonClicked()));

    QHBoxLayout *closeHBox = new QHBoxLayout;
    closeHBox->addWidget(closeButton);
    closeHBox->addWidget(surpriseButton);

    buttonsVBox->addSpacing(15);
    buttonsVBox->addLayout(closeHBox);

    Grid->setAlignment(Qt::AlignRight);
    Grid->rowStretch(1000);
    Grid->addLayout(buttonsVBox, 1, 1);
}

void MainWindow::closeButtonClicked()
{
    close();
}

void MainWindow::surpriseButtonClicked()
{
    QDesktopServices::openUrl(QUrl("https://www.youtube.com/watch?v=wjI_iJyjiU8"));
}

void MainWindow::moveByCordButtonClicked()
{
    if (moveButton->isChecked()) {
        if (selectedFigureID < POLYLINE && selectedFigureID > TRIANGLE) {
            figuresArray[selectedFigureID]->moveByCord(spinForX->value(), spinForY->value());
            update();
        }
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (drawButton->isChecked()) {
        if (selectedFigureID < POLYLINE && selectedFigureID > TRIANGLE) {
            figuresArray[selectedFigureID]->mousePressing(event);
        } else {
            figuresArray[selectedFigureID]->mouseMoving(event);
            update();
            if (selectedFigureID == 0) {
                cnt++;
                if (cnt == 3) {
                    moveButton->setChecked(true);
                    cnt = 0;
                } else {
                    textSquare->text() = "";
                    textPerimeter->text() = "";
                }
            }
        }
    } else if (moveButton->isChecked()) {
        if (selectedFigureID < POLYLINE) {
            figuresArray[selectedFigureID]->mouseMovePressing(event);
        } else {
            figuresArray[selectedFigureID]->mouseMovePressing(event);
            update();
        }
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (drawButton->isChecked() && selectedFigureID) {
        figuresArray[selectedFigureID]->mouseMoving(event);
        update();
    } else if (moveButton->isChecked()) {
        figuresArray[selectedFigureID]->mouseMoveMoving(event);
        update();
    }
    setInfo();
}

void MainWindow::paintEvent(QPaintEvent * /*event*/)
{
    auto *p = new QPainter(this);
    p->setRenderHint(QPainter::Antialiasing);

    figuresArray[selectedFigureID]->draw(p);
    figuresArray[selectedFigureID]->isShift = isShift;
    p->end();
    setInfo();
}

void MainWindow::selectFigure()
{
    if (triangleButton->isChecked()) {
        qDebug() << "Triangle Selected";
        selectedFigureID = TRIANGLE;
    } else if (circleButton->isChecked()) {
        qDebug() << "Circle Selected";
        selectedFigureID = CIRCLE;
    } else if (rhombusButton->isChecked()) {
        qDebug() << "Rhombus Selected";
        selectedFigureID = RHOMBUS;
    } else if (rectangleButton->isChecked()) {
        qDebug() << "Rectangular Selected";
        selectedFigureID = SQUARE;
    } else if (starButton->isChecked()) {
        if (spin5to8->text() == "5") {
            qDebug() << "Star 5 Selected";
            selectedFigureID = STAR5;
        } else if (spin5to8->text() == "6") {
            qDebug() << "Star 6 Selected";
            selectedFigureID = STAR6;
        } else if (spin5to8->text() == "7") {
            qDebug() << "Star 7 Selected";

            selectedFigureID = STAR7;
        } else if (spin5to8->text() == "8") {
            qDebug() << "Star 8 Selected";
            selectedFigureID = STAR8;
        }
    } else if (hexagonButton->isChecked()) {
        qDebug() << "Hexagon Selected";
        selectedFigureID = HEXAGON;
    } else if (polylineButton->isChecked()) {
        qDebug() << "Polyline Selected";
        selectedFigureID = POLYLINE;
    }
    drawButton->setChecked(true);
    figuresArray[selectedFigureID]->clear();
    update();
    setInfo();
}

////Size
//Size Plus
void MainWindow::on_sizePlus_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(upSize()));
    timer->start(TIMERCOUNT);
}

void MainWindow::on_sizePlus_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(upSize()));
    timer->stop();
}

//Size Minus
void MainWindow::on_sizeMinus_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(downSize()));
    timer->start(TIMERCOUNT);
}

void MainWindow::on_sizeMinus_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(downSize()));
    timer->stop();
}

////Rotate
//Rotate Left
void MainWindow::rotateLeft()
{
    figuresArray[selectedFigureID]->rotateLeft();
    update();
}

void MainWindow::on_rotateLEFT_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(rotateLeft()));
    timer->start(TIMERCOUNT);
}

void MainWindow::on_rotateLEFT_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(rotateLeft()));
    timer->stop();
}

//Rotate Right
void MainWindow::rotateRight()
{
    figuresArray[selectedFigureID]->rotateRight();
    update();
}

void MainWindow::on_rotateRIGHT_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(rotateRight()));
    timer->start(TIMERCOUNT);
}

void MainWindow::on_rotateRIGHT_released()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(rotateRight()));
    timer->stop();
}

////Scale
//Up Scale
void MainWindow::upSize()
{
    figuresArray[selectedFigureID]->upScale();
    update();
    setInfo();
}

//Down Scale
void MainWindow::downSize()
{
    figuresArray[selectedFigureID]->downScale();
    update();
    setInfo();
}

////Info
void MainWindow::setInfo()
{
    QPointF center = figuresArray[selectedFigureID]->center;
    if (selectedFigureID == 0 && cnt < 3 && cnt > 0) {
        center = {0, 0};
    };
    textCenter->setText("x " + QString::number(center.x(), 'd', 1) + " " + "y "
                        + QString::number(center.y(), 'd', 1));
    double squares = figuresArray[selectedFigureID]->square;
    if (selectedFigureID == 0 && cnt < 3 && cnt > 0) {
        squares = 0;
    };
    textSquare->setText(QString::number(squares, 'd', 2));
    double perimeter = figuresArray[selectedFigureID]->perimetr;
    if (selectedFigureID == 0 && cnt < 3 && cnt > 0) {
        perimeter = 0;
    };
    textPerimeter->setText(QString::number(perimeter, 'd', 2));
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);

    if (!polylineButton->isChecked() && selectedFigureID != 0
        && figuresArray[selectedFigureID]->square != 0) {
        moveButton->setChecked(true);
    }
}

void MainWindow::star() {
    starButton->setChecked(true);
    selectFigure();
}
