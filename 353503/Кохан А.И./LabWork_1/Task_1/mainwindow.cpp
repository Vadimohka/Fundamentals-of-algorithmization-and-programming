#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1200, 775);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene->setSceneRect(0, 0, 981, 741);
    scene->setBackgroundBrush(QBrush(QColor(48, 82, 87)));
    ui->label->setStyleSheet("image: url(:/img/image/Vmake-1707504315.png)");

    myLift = new lift;

    RadioFloor_1 = new QRadioButton("1", this);
    RadioFloor_1->setGeometry(1, 300, 100, 50);
    RadioFloor_2 = new QRadioButton("2", this);
    RadioFloor_2->setGeometry(1, 250, 100, 50);
    RadioFloor_3 = new QRadioButton("3", this);
    RadioFloor_3->setGeometry(1, 200, 100, 50);
    RadioFloor_4 = new QRadioButton("4", this);
    RadioFloor_4->setGeometry(1, 150, 100, 50);

    stopButton = new StopButton(this);
    stopButton->setGeometry(50, 350, 80, 75);

    timer = new QTimer(this);
    timer->start(1000/60);
    connect(timer, SIGNAL(timeout()), this, SLOT(moveLift()));

    scene->addItem(myLift);
}

void MainWindow::moveLift() {
    static int y = 0;

    if(stopButton->isChecked()) {
        timer->start(0);
    }

    else if(RadioFloor_1->isChecked() and !stopButton->isChecked()) {
        timer->start(1000/60);

        if(y > 0) --y;
        else if(y < 0) ++y;

        myLift->setPos(0, y);
    }

    else if(RadioFloor_2->isChecked() and !stopButton->isChecked()) {
        timer->start(1000/60);

        if(y > -140) --y;
        else if(y < -140) ++y;

        myLift->setPos(0, y);
    }

    else if(RadioFloor_3->isChecked() and !stopButton->isChecked()) {
        timer->start(1000/60);

        if(y > -285) --y;
        else if(y < -285) ++y;

        myLift->setPos(0, y);
    }

    else if(RadioFloor_4->isChecked() and !stopButton->isChecked()) {
        timer->start(1000/60);

        if(y > -435) --y;
        else if(y < -435) ++y;

        myLift->setPos(0, y);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
