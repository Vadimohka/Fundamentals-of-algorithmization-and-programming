#include "mainWindow.h"

mainWindow::mainWindow(QWidget *) {

    figuresArray[0] = triangle;
    figuresArray[1] = circle;
    figuresArray[2] = rhombus;
    figuresArray[3] = square;
    figuresArray[4] = star5;
    figuresArray[5] = star6;
    figuresArray[6] = star7;
    figuresArray[7] = star8;
    figuresArray[8] = hexagon;
    figuresArray[9] = polyline;


    auto *figuresVBox = new QVBoxLayout;
    auto *figuresGBox = new QGroupBox;
    auto *infoGBox = new QGroupBox;

    auto *actionsVBox = new QVBoxLayout;
    auto *actionsGBox = new QGroupBox;

    auto *buttonsVBox = new QVBoxLayout;

    auto *HBox = new QHBoxLayout(this);


    //Add buttons
    triangleButton = new QRadioButton("Triangle");
    triangleButton->setToolTip("Set 3 points to create triangle");
    figuresVBox->addWidget(triangleButton);
    triangleButton->setChecked(true);
    connect(triangleButton, SIGNAL(clicked(bool)), SLOT(selectFigure()));

    circleButton = new QRadioButton("Circle");
    figuresVBox->addWidget(circleButton);
    connect(circleButton, SIGNAL(clicked(bool)), SLOT(selectFigure()));

    rhombusButton = new QRadioButton("Rhombus");
    figuresVBox->addWidget(rhombusButton);
    connect(rhombusButton, SIGNAL(clicked(bool)), SLOT(selectFigure()));

    rectangleButton = new QRadioButton("Rectangle");
    figuresVBox->addWidget(rectangleButton);
    connect(rectangleButton, SIGNAL(clicked(bool)), SLOT(selectFigure()));

    auto *starHBox = new QHBoxLayout;
    starButton = new QRadioButton("Star");
    connect(starButton, SIGNAL(clicked(bool)), SLOT(selectFigure()));
    starHBox->addWidget(starButton, 0);
    spin5to8 = new QSpinBox;
    spin5to8->setMinimum(5);
    spin5to8->setMaximum(8);
    starHBox->addWidget(spin5to8);
    connect(spin5to8, SIGNAL(valueChanged(int)), SLOT(star()));

    figuresVBox->addLayout(starHBox);

    hexagonButton = new QRadioButton("Hexagon");
    figuresVBox->addWidget(hexagonButton);
    connect(hexagonButton, SIGNAL(clicked(bool)), SLOT(selectFigure()));

    polylineButton = new QRadioButton("Polyline");
    figuresVBox->addWidget(polylineButton);
    connect(polylineButton, SIGNAL(clicked(bool)), SLOT(selectFigure()));

    figuresGBox->setLayout(figuresVBox);

    buttonsVBox->addWidget(figuresGBox);


    //Info
    auto *textInfoL = new QGridLayout;
    auto *label1 = new QLabel("Perimeter");
    textPerimeter = new QLabel();
    auto *label2 = new QLabel("Square");
    textSquare = new QLabel();
    auto *label3 = new QLabel("Center");
    textCenter = new QLabel();
    textInfoL->addWidget(label1, 0, 0);
    textInfoL->addWidget(textPerimeter, 0, 1);
    textInfoL->addWidget(label2, 1, 0);
    textInfoL->addWidget(textSquare, 1, 1);
    textInfoL->addWidget(label3, 2, 0);
    textInfoL->addWidget(textCenter, 2, 1);
    infoGBox->setLayout(textInfoL);
    auto infoVL = new QVBoxLayout;
    infoVL->addWidget(infoGBox);



    // Actions
    drawButton = new QRadioButton("Create");
    actionsVBox->addWidget(drawButton);
    drawButton->setChecked(true);

    moveButton = new QRadioButton("Move");
    actionsVBox->addWidget(moveButton);

    auto sizeHBox = new QHBoxLayout;
    sizeP = new QPushButton("Size+");
    sizeM = new QPushButton("Size-");
    sizeHBox->addWidget(sizeM);
    sizeHBox->addSpacing(1);
    sizeHBox->addWidget(sizeP);
    actionsVBox->addLayout(sizeHBox);
    connect(sizeP, SIGNAL(pressed()), SLOT(on_sizeP_pressed()));
    connect(sizeP, SIGNAL(released()), SLOT(on_sizeP_released()));
    connect(sizeM, SIGNAL(pressed()), SLOT(on_sizeM_pressed()));
    connect(sizeM, SIGNAL(released()), SLOT(on_sizeM_released()));


    auto resizeTextLabel = new QLabel("Resize");
    resizeTextLabel->setAlignment(Qt::AlignCenter);
    actionsVBox->addWidget(resizeTextLabel);


    auto rotateHBox = new QHBoxLayout;
    rotateL = new QPushButton("⟲");
    rotateR = new QPushButton("⟳");
    rotateHBox->addWidget(rotateL);
    rotateHBox->addSpacing(1);
    rotateHBox->addWidget(rotateR);
    actionsVBox->addLayout(rotateHBox);
    connect(rotateL, SIGNAL(pressed()), SLOT(on_rotateL_pressed()));
    connect(rotateR, SIGNAL(pressed()), SLOT(on_rotateR_pressed()));
    connect(rotateL, SIGNAL(released()), SLOT(on_rotateL_released()));
    connect(rotateR, SIGNAL(released()), SLOT(on_rotateR_released()));


    auto rotateText = new QLabel("Rotate");
    rotateText->setAlignment(Qt::AlignCenter);
    actionsVBox->addWidget(rotateText);


    actionsGBox->setLayout(actionsVBox);

    buttonsVBox->addStretch(100000);
    buttonsVBox->addLayout(infoVL);
    buttonsVBox->addStretch(100000);
    buttonsVBox->addWidget(actionsGBox);

    auto closeButton = new QPushButton("Close");
    connect(closeButton, SIGNAL(clicked(bool)), SLOT(closeButtonClicked()));

    buttonsVBox->addSpacing(15);
    buttonsVBox->addWidget(closeButton);

    HBox->setAlignment(Qt::AlignRight);
    HBox->addStretch(1000);
    HBox->addLayout(buttonsVBox, 1);

}


void mainWindow::closeButtonClicked() {
    close();
}

void mainWindow::mousePressEvent(QMouseEvent *me) {
    if (drawButton->isChecked()) {
        if (selectedFigureID < 9 && selectedFigureID > 0) figuresArray[selectedFigureID]->mousePressing(me);
        else {
            figuresArray[selectedFigureID]->mouseMoving(me);
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
        if (selectedFigureID < 9) figuresArray[selectedFigureID]->mouseMovePressing(me);
        else {
            figuresArray[selectedFigureID]->mouseMovePressing(me);
            update();
        }
    }
}

void mainWindow::mouseMoveEvent(QMouseEvent *me) {
    if (drawButton->isChecked() && selectedFigureID) {
        figuresArray[selectedFigureID]->mouseMoving(me);
        update();
    } else if (moveButton->isChecked()) {
        figuresArray[selectedFigureID]->mouseMoveMoving(me);
        update();
    }
    setInfo();
}

void mainWindow::paintEvent(QPaintEvent *) {
    auto *pe = new QPainter(this);
    pe->setRenderHint(QPainter::Antialiasing);
    figuresArray[selectedFigureID]->draw(pe);
    figuresArray[selectedFigureID]->isShift = isShift;
    pe->end();
    setInfo();
}

void mainWindow::selectFigure() {
    if (triangleButton->isChecked()) {
        qDebug() << "Triangle Selected";
        selectedFigureID = 0;
    } else if (circleButton->isChecked()) {
        qDebug() << "Circle Selected";
        selectedFigureID = 1;
    } else if (rhombusButton->isChecked()) {
        qDebug() << "Rhombus Selected";
        selectedFigureID = 2;
    } else if (rectangleButton->isChecked()) {
        qDebug() << "Rectangular Selected";
        selectedFigureID = 3;
    } else if (starButton->isChecked()) {
        if (spin5to8->text() == "5") {
            qDebug() << "Star 5 Selected";
            selectedFigureID = 4;
        } else if (spin5to8->text() == "6") {
            qDebug() << "Star 6 Selected";
            selectedFigureID = 5;
        } else if (spin5to8->text() == "7") {
            qDebug() << "Star 7 Selected";

            selectedFigureID = 6;
        } else if (spin5to8->text() == "8") {
            qDebug() << "Star 8 Selected";
            selectedFigureID = 7;
        }
    } else if (hexagonButton->isChecked()) {
        qDebug() << "Hexagon Selected";
        selectedFigureID = 8;
    } else if (polylineButton->isChecked()) {
        qDebug() << "Polyline Selected";
        selectedFigureID = 9;
    }
    drawButton->setChecked(true);
    figuresArray[selectedFigureID]->clear();
    update();
    setInfo();
}

void mainWindow::on_sizeP_pressed() {
    connect(timer, SIGNAL(timeout()), this, SLOT(upSize()));
    timer->start(10);
}

void mainWindow::on_sizeP_released() {
    disconnect(timer, SIGNAL(timeout()), this, SLOT(upSize()));
    timer->stop();
}

void mainWindow::on_sizeM_pressed() {
    connect(timer, SIGNAL(timeout()), this, SLOT(downSize()));
    timer->start(10);
}

void mainWindow::on_sizeM_released() {
    disconnect(timer, SIGNAL(timeout()), this, SLOT(downSize()));
    timer->stop();
}

void mainWindow::on_rotateL_pressed() {
    connect(timer, SIGNAL(timeout()), this, SLOT(rotateLeft()));
    timer->start(10);
}

void mainWindow::on_rotateL_released() {
    disconnect(timer, SIGNAL(timeout()), this, SLOT(rotateLeft()));
    timer->stop();
}

void mainWindow::on_rotateR_pressed() {
    connect(timer, SIGNAL(timeout()), this, SLOT(rotateRight()));
    timer->start(10);
}

void mainWindow::on_rotateR_released() {
    disconnect(timer, SIGNAL(timeout()), this, SLOT(rotateRight()));
    timer->stop();
}

void mainWindow::upSize() {
    figuresArray[selectedFigureID]->upScale();
    update();
    setInfo();
}

void mainWindow::downSize() {
    figuresArray[selectedFigureID]->downScale();
    update();
    setInfo();
}

void mainWindow::rotateLeft() {
    figuresArray[selectedFigureID]->rotateLEFT();
    update();
}

void mainWindow::rotateRight() {
    figuresArray[selectedFigureID]->rotateRIGHT();
    update();
}


void mainWindow::setInfo() {

    QPointF center = figuresArray[selectedFigureID]->center;
    if (selectedFigureID == 0 && cnt < 3 && cnt > 0) center = {0, 0};
    textCenter->setText("x " + QString::number(center.x(), 'd', 1) + " " +
                        "y " + QString::number(center.y(), 'd', 1));
    double squares = figuresArray[selectedFigureID]->square;
    if (selectedFigureID == 0 && cnt < 3 && cnt > 0) squares = 0;
    textSquare->setText(QString::number(squares, 'd', 2));
    double perimeter = figuresArray[selectedFigureID]->perimeter;
    if (selectedFigureID == 0 && cnt < 3 && cnt > 0) perimeter = 0;
    textPerimeter->setText(QString::number(perimeter, 'd', 2));

}

void mainWindow::mouseReleaseEvent(QMouseEvent *me) {
    if (!polylineButton->isChecked() && selectedFigureID != 0 && figuresArray[selectedFigureID]->square != 0)
        moveButton->setChecked(true);
}

void mainWindow::star() {
    starButton->setChecked(true);
    selectFigure();
}
