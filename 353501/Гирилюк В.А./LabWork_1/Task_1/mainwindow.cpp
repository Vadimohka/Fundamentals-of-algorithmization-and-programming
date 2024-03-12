#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    setFixedSize(1000,700);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,980,570);




    start = new QPushButton("Start", this);
    start->setFixedSize(100, 50);
    restart = new QPushButton("Restart", this);
    restart->setFixedSize(100, 50);


    rocket = new Rocket();
    scene->addItem(rocket);

    connect(start, &QPushButton::clicked, rocket, &Rocket::Start);
    connect(restart, &QPushButton::clicked, rocket, &Rocket::Restart);

    action = new QAction(this);
    action->setShortcut(QKeySequence(Qt::Key_Space));
    connect(action, &QAction::triggered, rocket, &Rocket::Conditional);
    addAction(action);

    rocket->setPos(490, 500);


    view = new QGraphicsView(scene);
    setCentralWidget(view);
    view->setRenderHint(QPainter::Antialiasing);

    QHBoxLayout *buttonLayout = new QHBoxLayout;

    buttonLayout->addWidget(start);
    buttonLayout->addWidget(restart);

    QWidget *buttons = new QWidget;
    buttons->setLayout(buttonLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(view);
    mainLayout->addWidget(buttons);
    QWidget *central = new QWidget;
    central->setLayout(mainLayout);
    setCentralWidget(central);

}

MainWindow::~MainWindow()
{
    delete ui;
}
