#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0,600,600);

    view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    QWidget *Widget = new QWidget;
    this->setCentralWidget(Widget);


    Right = new QPushButton("Right", this);
    Right->setFixedSize(QSize(100,50));

    Left = new QPushButton("Left", this);
    Left->setFixedSize(QSize(100,50));

    Stop = new QPushButton("Stop", this);
    Stop->setFixedSize(QSize(100,50));

    Salute = new QPushButton("Salute", this);
    Salute->setFixedSize(QSize(100,50));


    Right->setFocusPolicy(Qt::NoFocus);
    Left->setFocusPolicy(Qt::NoFocus);
    Stop->setFocusPolicy(Qt::NoFocus);
    Salute->setFocusPolicy(Qt::NoFocus);

    QHBoxLayout *buttonLayout = new QHBoxLayout;

    buttonLayout->addWidget(Left);
    buttonLayout->addWidget(Stop);
    buttonLayout->addWidget(Salute);
    buttonLayout->addWidget(Right);


    QWidget *buttonWidget = new QWidget;
    buttonWidget->setLayout(buttonLayout);


    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(view);
    mainLayout->addWidget(buttonWidget);

    Widget->setLayout(mainLayout);

    person = new Person();
    scene->addItem(person);

    qreal centerX = scene->sceneRect().width()/2-person->rect().width()/2;
    qreal centerY = scene->sceneRect().height()/2-person->rect().height()/2;

    person->setPos(centerX,centerY);

    connect(Right, &QPushButton::clicked, person, &Rectangle::moveRight);
    connect(Left, &QPushButton::clicked, person, &Rectangle::moveLeft);


    connect(Stop, &QPushButton::clicked, person, &Person::stopAnimation);
    connect(Stop, &QPushButton::clicked, person, &Person::Stop);
    connect(Salute, &QPushButton::clicked, person, &Person::rotateRightArm);


    Widget->setFocus();
}
void MainWindow::resizeEvent(QResizeEvent *)
{
    scene->setSceneRect(0, 0, view->width(), view->height());
    qreal centerX = scene->sceneRect().width()/2-person->rect().width()/2;
    qreal centerY = scene->sceneRect().height()/2-person->rect().height()/2;

    person->setPos(centerX,centerY);

}


void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Left) {
        person->moveLeft();
    } else if (e->key() == Qt::Key_Right) {
        person->moveRight();
    }else if(e->key() == Qt::Key_Up){
        person->stopAnimation();
        person->Stop();
    }else if(e->key() == Qt::Key_Down){
        person->rotateRightArm();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}





