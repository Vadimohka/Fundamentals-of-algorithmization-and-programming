#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1200, 700);

    scene = new QGraphicsScene(this);
    scene -> setSceneRect(0,0, 1100, 500);

    start = new QPushButton("Start", this);
    start -> setFixedSize(100,50);
    restart = new QPushButton("Restart", this);
    restart -> setFixedSize(100,50);

    rectangle = new Rectangle();
    scene -> addItem(rectangle);

    connect(start, &QPushButton::clicked, rectangle, &Rectangle::Start);
    connect(restart, &QPushButton::clicked, rectangle, &Rectangle::Restart);



    rectangle -> setPos(10, 200);



    view = new QGraphicsView(scene);
    setCentralWidget(view);
    view -> setRenderHint(QPainter::Antialiasing);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout -> addWidget(start);
    buttonLayout -> addWidget(restart);

    QWidget *buttons = new QWidget;
    buttons -> setLayout(buttonLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout -> addWidget(view);
    mainLayout -> addWidget(buttons);
    QWidget *central = new QWidget;
    central -> setLayout(mainLayout);
    setCentralWidget(central);



}

MainWindow::~MainWindow()
{
    delete ui;
}

