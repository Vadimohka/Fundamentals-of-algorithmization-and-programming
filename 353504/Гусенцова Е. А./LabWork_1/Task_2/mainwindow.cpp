#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>


mainwindow::mainwindow(QWidget *) {

    figuresArray[0] = triangle;
    figuresArray[1] = circle;
    figuresArray[2] = rhombus;
    figuresArray[3] = square;
    figuresArray[4] = star5;
    figuresArray[5] = star6;
    figuresArray[6] = star8;
    figuresArray[7] = hexagon;
    figuresArray[8] = polyline;

    auto *figuresVBox = new QHBoxLayout;
    auto *figuresGBox = new QGroupBox;
    auto *actionsVBox = new QVBoxLayout;
    auto *actionsGBox = new QGroupBox;
    auto *buttonsVBox = new QVBoxLayout;
    auto *HBox = new QHBoxLayout(this);
    auto STHBox = new QHBoxLayout;
    auto PSC = new QHBoxLayout;

    polylineButton = new QRadioButton("Polyline");
    figuresVBox->addWidget(polylineButton);
    connect(polylineButton, SIGNAL(clicked(bool)), SLOT(selectFigure()));

    circleButton = new QRadioButton("Circle");
    figuresVBox->addWidget(circleButton);
    connect(circleButton, SIGNAL(clicked(bool)), SLOT(selectFigure()));

    triangleButton = new QRadioButton("Triangle");
    figuresVBox->addWidget(triangleButton);
    connect(triangleButton, SIGNAL(clicked(bool)), SLOT(selectFigure()));

    rhombusButton = new QRadioButton("Rhombus");
    figuresVBox->addWidget(rhombusButton);
    connect(rhombusButton, SIGNAL(clicked(bool)), SLOT(selectFigure()));

    rectangleButton = new QRadioButton("Rectangle");
    figuresVBox->addWidget(rectangleButton);
    connect(rectangleButton, SIGNAL(clicked(bool)), SLOT(selectFigure()));

    hexagonButton = new QRadioButton("Hexagon");
    figuresVBox->addWidget(hexagonButton);
    connect(hexagonButton, SIGNAL(clicked(bool)), SLOT(selectFigure()));

    star5Button = new QRadioButton("Star5");
    figuresVBox->addWidget(star5Button);
    connect(star5Button, SIGNAL(clicked(bool)), SLOT(selectFigure()));

    star6Button = new QRadioButton("Star6");
    figuresVBox->addWidget(star6Button);
    connect(star6Button, SIGNAL(clicked(bool)), SLOT(selectFigure()));

    star8Button = new QRadioButton("Star8");
    figuresVBox->addWidget(star8Button);
    connect(star8Button, SIGNAL(clicked(bool)), SLOT(selectFigure()));

    figuresGBox->setLayout(figuresVBox);
    figuresGBox->setAlignment(Qt::AlignCenter);
    buttonsVBox->addWidget(figuresGBox);


    auto *perimetr= new QLabel("Perimeter");
    textPerimeter = new QLabel();
    auto *square = new QLabel("Square");
    textSquare = new QLabel();
    auto *center = new QLabel("Center of the figure");
    textCenter = new QLabel();
    PSC->addWidget(perimetr);
    PSC->addWidget(textPerimeter);
    PSC->addWidget(square);
    PSC->addWidget(textSquare);
    PSC->addWidget(center);
    PSC->addWidget(textCenter);
    buttonsVBox->addLayout( PSC);

    drawButton = new QRadioButton("Repaint");
    buttonsVBox->addWidget(drawButton);

    changeButton = new QRadioButton("Change");
    buttonsVBox->addWidget(changeButton);

    sizeP = new QPushButton("Make bigger");
    sizeM = new QPushButton("make smaller");

    STHBox->addWidget(sizeM);
    STHBox->addSpacing(10);
    STHBox->addWidget(sizeP);

    connect(sizeP, SIGNAL(pressed()), SLOT(onSizePRressed()));
    connect(sizeP, SIGNAL(released()), SLOT(onSizePReleased()));
    connect(sizeM, SIGNAL(pressed()), SLOT(onSizeMPressed()));
    connect(sizeM, SIGNAL(released()), SLOT(onSizeMReleased()));

    rotateL = new QPushButton("turn left");
    rotateR = new QPushButton("turn right");
    STHBox->addWidget(rotateL);
    STHBox->addSpacing(10);
    STHBox->addWidget(rotateR);
    buttonsVBox->addLayout(STHBox);

    connect(rotateL, SIGNAL(pressed()), SLOT(onRotateLPressed()));
    connect(rotateR, SIGNAL(pressed()), SLOT(onRotateRPressed()));
    connect(rotateL, SIGNAL(released()), SLOT(onRotateLReleased()));
    connect(rotateR, SIGNAL(released()), SLOT(onRotateRReleased()));

    actionsGBox->setLayout(actionsVBox);

    buttonsVBox->addStretch(100000);
    buttonsVBox->addStretch(100000);
    buttonsVBox->addWidget(actionsGBox);

    HBox->setAlignment(Qt::AlignRight);
    HBox->addStretch(1000);
    HBox->addLayout(buttonsVBox, 1);

}

void mainwindow::mousePressEvent(QMouseEvent *me) {
    if (drawButton->isChecked()) {
        if (figureNum < 8 && figureNum > 0) figuresArray[figureNum]->mousePressing(me);
        else {
            figuresArray[figureNum]->mouseMoving(me);
            update();
            if (figureNum == 0) {
                cnt++;
                    textSquare->text() = "";
                    textPerimeter->text() = "";

            }
        }
    }
}

void mainwindow::mouseMoveEvent(QMouseEvent *me) {
    if (drawButton->isChecked() && figureNum) {
        figuresArray[figureNum]->mouseMoving(me);
        update();
    } else if (changeButton->isChecked()) {
        figuresArray[figureNum]->mouseMoveMoving(me);
        update();
    }
    setInfo();
}

void mainwindow::paintEvent(QPaintEvent *) {
    auto *pe = new QPainter(this);
    pe->setRenderHint(QPainter::Antialiasing);
    figuresArray[figureNum]->draw(pe);
    figuresArray[figureNum]->isShift = isShift;
    pe->end();
    setInfo();
}

void mainwindow::selectFigure() {
    if (triangleButton->isChecked()) {
        figureNum = 0;
    } else if (circleButton->isChecked()) {
        figureNum = 1;
    } else if (rhombusButton->isChecked()) {
        figureNum = 2;
    } else if (rectangleButton->isChecked()) {
        figureNum = 3;
    } else if (star5Button->isChecked()) {
        figureNum = 4;
    } else if (star6Button->isChecked()) {
        figureNum = 5;
    } else if (star8Button->isChecked()) {
        figureNum = 6;
    } else if (hexagonButton->isChecked()) {
        figureNum = 7;
    } else if (polylineButton->isChecked()) {
        figureNum = 8;
    }
    drawButton->setChecked(true);
    figuresArray[figureNum]->clear();
    update();
    setInfo();
}

void mainwindow::onSizePRressed() {
    connect(timer, SIGNAL(timeout()), this, SLOT(upSize()));
    timer->start(66);
}

void mainwindow::onSizePReleased() {
    disconnect(timer, SIGNAL(timeout()), this, SLOT(upSize()));
    timer->stop();
}

void mainwindow::onSizeMPressed() {
    connect(timer, SIGNAL(timeout()), this, SLOT(downSize()));
    timer->start(66);
}

void mainwindow::onSizeMReleased() {
    disconnect(timer, SIGNAL(timeout()), this, SLOT(downSize()));
    timer->stop();
}

void mainwindow::onRotateLPressed() {
    connect(timer, SIGNAL(timeout()), this, SLOT(rotateLeft()));
    timer->start(66);
}

void mainwindow::onRotateLReleased() {
    disconnect(timer, SIGNAL(timeout()), this, SLOT(rotateLeft()));
    timer->stop();
}

void mainwindow::onRotateRPressed() {
    connect(timer, SIGNAL(timeout()), this, SLOT(rotateRight()));
    timer->start(66);
}

void mainwindow::onRotateRReleased() {
    disconnect(timer, SIGNAL(timeout()), this, SLOT(rotateRight()));
    timer->stop();
}

void mainwindow::upSize() {
    figuresArray[figureNum]->upScale();
    repaint();
    setInfo();
}

void mainwindow::downSize() {
    figuresArray[figureNum]->downScale();
   repaint();
    setInfo();
}

void mainwindow::rotateLeft() {
    figuresArray[figureNum]->Left();
    repaint();
}

void mainwindow::rotateRight() {
    figuresArray[figureNum]->Right();
    repaint();
}


void mainwindow::setInfo() {

    QPointF center = figuresArray[figureNum]->center;
    if (figureNum == 0 && cnt < 3 && cnt > 0) center = {0, 0};
    textCenter->setText("x " + QString::number(center.x(), 'd', 1) + " " +
                        "y " + QString::number(center.y(), 'd', 1));
    double squares = figuresArray[figureNum]->square;
    if (figureNum == 0 && cnt < 3 && cnt > 0) squares = 0;
    textSquare->setText(QString::number(squares, 'd', 2));
    double perimeter = figuresArray[figureNum]->perimeter;
    if (figureNum == 0 && cnt < 3 && cnt > 0) perimeter = 0;
    textPerimeter->setText(QString::number(perimeter, 'd', 2));

}

void mainwindow::mouseReleaseEvent(QMouseEvent *me) {
    if (!polylineButton->isChecked() && figureNum != 0 && figuresArray[figureNum]->square != 0)
        changeButton->setChecked(true);
}

void mainwindow::star() {
    starButton->setChecked(true);
    selectFigure();
}
