#include "../Headers/MyWidget.h"


MyWidget::MyWidget(QWidget *parent) : QWidget(parent) {
    this->setParent(parent);

    ID = -1;

    lastID = 0;

    this->_timer = new QTimer;

    this->tickTimer = new QTimer;

    _timer->start(10);

    tickTimer->start(10);

    QPushButton *closeButton = new QPushButton("Close", this);
    closeButton->setGeometry(1820, 10, 90, 30);
    Figure::connect(closeButton,
                    SIGNAL(clicked()),
                    this,
                    SLOT(close()));

    QPushButton *clearButton = new QPushButton("Clear", this);
    clearButton->setGeometry(1820, 360, 90, 25);
    Figure::connect(clearButton,
                    SIGNAL(clicked()),
                    this,
                    SLOT(clear()));

    //Buttons for choosing Figures
    this->figureGroup = new QButtonGroup(this);

    this->triangleRadioButton = new QRadioButton("triangle", this);
    this->triangleRadioButton->setGeometry(1820, 40, 90, 30);

    this->figureGroup->addButton(triangleRadioButton);
    Figure::connect(triangleRadioButton,
                    SIGNAL(clicked()),
                    this,
                    SLOT(createFigure()));


    this->circleRadioButton = new QRadioButton("circle", this);
    this->circleRadioButton->setGeometry(1820, 70, 90, 30);

    this->figureGroup->addButton(circleRadioButton);
    Figure::connect(circleRadioButton,
                    SIGNAL(clicked()),
                    this,
                    SLOT(createFigure()));


    this->rhombusRadioButton = new QRadioButton("rhombus", this);
    this->rhombusRadioButton->setGeometry(1820, 100, 90, 30);

    this->figureGroup->addButton(rhombusRadioButton);
    Figure::connect(rhombusRadioButton,
                    SIGNAL(clicked()),
                    this,
                    SLOT(createFigure()));


    this->rectangleRadioButton = new QRadioButton("rectangle", this);
    this->rectangleRadioButton->setGeometry(1820, 130, 90, 30);

    this->figureGroup->addButton(rectangleRadioButton);
    Figure::connect(rectangleRadioButton,
                    SIGNAL(clicked()),
                    this,
                    SLOT(createFigure()));


    this->hexagonRadioButton = new QRadioButton("hexagon", this);
    this->hexagonRadioButton->setGeometry(1820, 160, 90, 30);

    this->figureGroup->addButton(hexagonRadioButton);
    Figure::connect(hexagonRadioButton,
                    SIGNAL(clicked()),
                    this,
                    SLOT(createFigure()));


    this->squareRadioButton = new QRadioButton("square", this);
    this->squareRadioButton->setGeometry(1820, 190, 90, 30);

    this->figureGroup->addButton(squareRadioButton);
    Figure::connect(squareRadioButton,
                    SIGNAL(clicked()),
                    this,
                    SLOT(createFigure()));


    this->bernoulliLemniscateRadioButton = new QRadioButton("∞", this);
    this->bernoulliLemniscateRadioButton->setGeometry(1820, 220, 90, 30);

    this->figureGroup->addButton(bernoulliLemniscateRadioButton);
    Figure::connect(bernoulliLemniscateRadioButton,
                    SIGNAL(clicked()),
                    this,
                    SLOT(createFigure()));


    this->starRadioButton = new QRadioButton("star", this);
    this->starRadioButton->setGeometry(1820, 250, 90, 30);

    this->starSpinBox = new QSpinBox(starRadioButton);
    this->starSpinBox->setGeometry(50, 0, 40, 30);

    starSpinBox->setMinimum(5);
    starSpinBox->setMaximum(99);
    connect(starSpinBox,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(changeThorns()));

    this->figureGroup->addButton(starRadioButton);
    Figure::connect(starRadioButton,
                    SIGNAL(clicked()),
                    this,
                    SLOT(createFigure()));

    this->octagonRadioButton = new QRadioButton("octagon", this);
    this->octagonRadioButton->setGeometry(1820, 280, 90, 30);

    this->figureGroup->addButton(octagonRadioButton);
    Figure::connect(octagonRadioButton,
                    SIGNAL(clicked()),
                    this,
                    SLOT(createFigure()));

    this->lineRadioButton = new QRadioButton("line", this);
    this->lineRadioButton->setGeometry(1820, 310, 90, 30);

    this->figureGroup->addButton(lineRadioButton);
    Figure::connect(lineRadioButton,
                    SIGNAL(clicked()),
                    this,
                    SLOT(createFigure()));

    //Labels for information
    this->perimeterLabel = new QLabel("perimeter", this);
    this->perimeterLabel->setGeometry(1830, 410, 80, 30);

    this->perimeterText = new QLabel("0", this);;
    this->perimeterText->setGeometry(1825, 440, 80, 30);

    this->areaLabel = new QLabel("area", this);
    this->areaLabel->setGeometry(1850, 470, 60, 30);

    this->areaText = new QLabel("0", this);;
    this->areaText->setGeometry(1825, 500, 80, 30);

    this->centerLabel = new QLabel("center", this);
    this->centerLabel->setGeometry(1845, 530, 65, 30);

    this->centerText = new QLabel("0", this);;
    this->centerText->setGeometry(1825, 560, 80, 40);

    //Buttons for choosing movingInTime or drawing
    this->choosingGroup = new QButtonGroup(this);

    this->drawRadioButton = new QRadioButton("draw", this);
    this->drawRadioButton->setGeometry(1820, 700, 90, 30);
    this->choosingGroup->addButton(drawRadioButton);
    this->drawRadioButton->setChecked(true);

    this->moveRadioButton = new QRadioButton("move", this);
    this->moveRadioButton->setGeometry(1820, 730, 90, 30);
    this->choosingGroup->addButton(moveRadioButton);

    //Buttons for scaling
    this->increaseSizePushButton = new QPushButton("+", this);
    this->increaseSizePushButton->setGeometry(1820, 800, 40, 40);

    this->diminishSizePushButton = new QPushButton("-", this);
    this->diminishSizePushButton->setGeometry(1870, 800, 40, 40);

    //Buttons for startRotationLeft
    this->rotateToLeftPushButton = new QPushButton("⟲", this);
    this->rotateToLeftPushButton->setGeometry(1820, 900, 40, 40);

    this->rotateToRightPushButton = new QPushButton("⟳", this);
    this->rotateToRightPushButton->setGeometry(1870, 900, 40, 40);

    /*//Buttons for choosingObject
    this->previousButton = new QPushButton("<", this);
    this->previousButton->setGeometry(1820, 1000, 40, 40);

    Figure::connect(previousButton,
                    SIGNAL(clicked()),
                    this,
                    SLOT(chooseLeft()));

    this->nextButton= new QPushButton(">", this);
    this->nextButton->setGeometry(1870, 1000, 40, 40);

    Figure::connect(nextButton,
                    SIGNAL(clicked()),
                    this,
                    SLOT(chooseRight()));*/

    QWidget::connect(this->_timer,
                     SIGNAL(timeout()),
                     this,
                     SLOT(setData()));

    QWidget::connect(this->tickTimer,
                     SIGNAL(timeout()),
                     this,
                     SLOT(updating()));

    this->lineRadioButton->setChecked(true);
    this->createFigure();
}

void MyWidget::paintEvent(QPaintEvent *event) {
    this->painter = new QPainter;

    painter->begin(this);

    for (auto &figure: figures) {
        figure->draw(painter);
    }

    painter->setBrush(Qt::lightGray);

    painter->drawRect(1810, 0, 110, 1080);

    painter->setBrush(Qt::gray);

    painter->drawRect(1815, 5, 100, 335);

    painter->drawRect(1815, 405, 100, 205);

    painter->drawRect(1815, 695, 100, 70);

    painter->drawRect(1815, 795, 100, 50);

    painter->drawRect(1815, 895, 100, 50);

    //painter->drawRect(1815,995,100,50);

    painter->setBrush(Qt::lightGray);

    painter->drawRect(1820, 440, 90, 30);

    painter->drawRect(1820, 500, 90, 30);

    painter->drawRect(1820, 560, 90, 40);

    painter->setBrush(Qt::NoBrush);

//    painter->setRenderHint(QPainter::Antialiasing);

    painter->end();
}

void MyWidget::setData() {
    centerText->setText("x " + QString::number(figures[ID]->_center->x(), 'd', 1) + "\n" +
                        "y " + QString::number(figures[ID]->_center->y(), 'd', 1));

    areaText->setText(QString::number(figures[ID]->_area, 'd', 1));
    perimeterText->setText(QString::number(figures[ID]->_perimeter, 'd', 1));
}

void MyWidget::createFigure() {
    ID++;

    disconnection();

    setFigure();

    connection();

    lastID = ID;
}

void MyWidget::setFigure() {
    Figure *figure;
    if (triangleRadioButton->isChecked()) {
        figure = new Triangle(this);
    } else if (starRadioButton->isChecked()) {
        figure = new Star(this);
        figure->_thorns = starSpinBox->value();
    } else if (bernoulliLemniscateRadioButton->isChecked()) {
        figure = new BernoulliLemniscate(this);
    } else if (circleRadioButton->isChecked()) {
        figure = new Circle(this);
    } else if (hexagonRadioButton->isChecked()) {
        figure = new Hexagon(this);
    } else if (lineRadioButton->isChecked()) {
        figure = new Line(this);
    } else if (octagonRadioButton->isChecked()) {
        figure = new Octagon(this);
    } else if (rectangleRadioButton->isChecked()) {
        figure = new Rectangle(this);
    } else if (rhombusRadioButton->isChecked()) {
        figure = new Rhombus(this);
    } else if (squareRadioButton->isChecked()) {
        figure = new Square(this);
    }
    figures.emplace_back((Figure * )(figure));
    figure = nullptr;

    drawRadioButton->setChecked(true);

    figures[ID]->setFixedSize(1810, 1080);
}

void MyWidget::updating() {
    this->update();
    figures[ID]->setFixedSize(1810, 1080);
}

void MyWidget::mousePressEvent(QMouseEvent *event) {
    if (drawRadioButton->isChecked()) {
        this->figures[ID]->drawPress(event);
        this->update();
    } else if (moveRadioButton->isChecked()) {
        this->figures[ID]->movingClick(event);
        this->update();
    }
}

void MyWidget::mouseReleaseEvent(QMouseEvent *event) {
    if (triangleRadioButton->isChecked()) {
        if (this->figures[ID]->points.size() == 3) { moveRadioButton->setChecked(true); }
    } else { moveRadioButton->setChecked(true); }
}

void MyWidget::mouseMoveEvent(QMouseEvent *event) {
    if (drawRadioButton->isChecked() && event->x() <= 1810) {
        this->figures[ID]->drawMove(event);
        this->update();
    } else if (moveRadioButton->isChecked() && event->x() <= 1810) {
        this->figures[ID]->startMoving(event);
        this->update();
    }
}

/*
    Figure::connect(tickTimer, SIGNAL(timeout()), figures[ID], SLOT(startMoving(event)));
*/

/*
void MyWidget::chooseLeft() {
    if(ID > 0) { ID--; }
    if(ID > 0) { ID--; }
    maxID--;

}

void MyWidget::chooseRight() {
    if(ID < maxID) { ID++; }
    if(ID < maxID) { ID--; }
    maxID--;
}*/

void MyWidget::disconnection() {
    if (ID) {
        Figure::disconnect(rotateToLeftPushButton,
                           SIGNAL(pressed()),
                           figures[lastID],
                           SLOT(startRotationLeft()));
        Figure::disconnect(rotateToLeftPushButton,
                           SIGNAL(released()),
                           figures[lastID],
                           SLOT(stopRotationLeft()));

        Figure::disconnect(rotateToRightPushButton,
                           SIGNAL(pressed()),
                           figures[lastID],
                           SLOT(startRotationRight()));
        Figure::disconnect(rotateToRightPushButton,
                           SIGNAL(released()),
                           figures[lastID],
                           SLOT(stopRotationRight()));

        Figure::disconnect(increaseSizePushButton,
                           SIGNAL(pressed()),
                           figures[lastID],
                           SLOT(startIncreasingSize()));
        Figure::disconnect(increaseSizePushButton,
                           SIGNAL(released()),
                           figures[lastID],
                           SLOT(stopIncreasingSize()));

        Figure::disconnect(diminishSizePushButton,
                           SIGNAL(pressed()),
                           figures[lastID],
                           SLOT(startDiminishingSize()));
        Figure::disconnect(diminishSizePushButton,
                           SIGNAL(released()),
                           figures[lastID],
                           SLOT(stopDiminishingSize()));
    }
}

void MyWidget::connection() {
    if (figures[ID] != nullptr) {
        Figure::connect(rotateToLeftPushButton,
                        SIGNAL(pressed()),
                        figures[ID],
                        SLOT(startRotationLeft()));
        Figure::connect(rotateToLeftPushButton,
                        SIGNAL(released()),
                        figures[ID],
                        SLOT(stopRotationLeft()));

        Figure::connect(rotateToRightPushButton,
                        SIGNAL(pressed()),
                        figures[ID],
                        SLOT(startRotationRight()));
        Figure::connect(rotateToRightPushButton,
                        SIGNAL(released()),
                        figures[ID],
                        SLOT(stopRotationRight()));

        Figure::connect(increaseSizePushButton,
                        SIGNAL(pressed()),
                        figures[ID],
                        SLOT(startIncreasingSize()));
        Figure::connect(increaseSizePushButton,
                        SIGNAL(released()),
                        figures[ID],
                        SLOT(stopIncreasingSize()));

        Figure::connect(diminishSizePushButton,
                        SIGNAL(pressed()),
                        figures[ID],
                        SLOT(startDiminishingSize()));
        Figure::connect(diminishSizePushButton,
                        SIGNAL(released()),
                        figures[ID],
                        SLOT(stopDiminishingSize()));
    }
}

void MyWidget::changeThorns() {
    starRadioButton->setChecked(false);
    starRadioButton->setChecked(true);

    createFigure();

    figures[ID]->update();

}

void MyWidget::clear() {
    figures.clear();

    ID = -1;

    lastID = 0;

    createFigure();
}



/*
void Canvas::mouseMove(QMouseEvent *mouseEvent) {
    this->figures[this->cur_figure]->drawMove(mouseEvent);
    this->update();
}*/
