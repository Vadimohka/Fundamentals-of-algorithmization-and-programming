#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800,580);
    scene = new QGraphicsScene();
    scene->setSceneRect(0, -100, 780, 400);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing); // сглаживает границы графических объектов
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // отключает скроллбар по горизонтали

    Cart *cart = new Cart();
    scene->addItem(cart);

    connect(ui->pushButton, SIGNAL(clicked(bool)), cart, SLOT(btnClicked()));
    ui->pushButton->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}






