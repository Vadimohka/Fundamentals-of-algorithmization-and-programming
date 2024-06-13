#include "mainwindow.h"

MainWindow::MainWindow(Rectangle *parent)
    : Rectangle(parent)
{
    QWidget *centralWidget = new QWidget(this);
    downButton = new QPushButton("Down");
    upButton = new QPushButton("Up");
    straightButton = new QPushButton("Straight");

    downButton->setFixedSize(200,300);
    upButton->setFixedSize(200,300);
    straightButton->setFixedSize(200,300);

    lout = new QVBoxLayout(centralWidget);

    lout->addWidget(downButton, 0, Qt::AlignBottom | Qt::AlignLeft);
    lout->addWidget(upButton, 0, Qt::AlignBottom | Qt::AlignLeft);
    lout->addWidget(straightButton, 0, Qt::AlignBottom | Qt::AlignLeft);

    this->setCentralWidget(centralWidget);

    connect(downButton, &QPushButton::clicked, this, &MainWindow::downButtonClicked);
    connect(upButton, &QPushButton::clicked, this, &MainWindow::upButtonClicked);
    connect(straightButton, &QPushButton::clicked, this, &MainWindow::straightButtonClicked);
}

MainWindow::~MainWindow() {}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.drawEllipse(825, 0, 200, 200);
    painter.drawPolygon(rect);
    painter.drawRect(825, 200, 200, 400);
    painter.drawRect(1025, 200, 85, 350);
    painter.drawRect(825, 600, 100, 350);
    painter.drawRect(925, 600, 100, 350);
    painter.end();
}

void MainWindow::downButtonClicked()
{
    rect[0] = QPoint(740,200);
    rect[1] = QPoint(825,200);
    rect[2] = QPoint(825,550);
    rect[3] = QPoint(740,550);
    update();
}

void MainWindow::upButtonClicked()
{
    rect[0] = QPoint(740,200);
    rect[1] = QPoint(825,200);
    rect[2] = QPoint(825,0);
    rect[3] = QPoint(740, 0);
    update();
}

void MainWindow::straightButtonClicked()
{
    rect[0] = QPoint(500,200);
    rect[1] = QPoint(500,275);
    rect[2] = QPoint(825,275);
    rect[3] = QPoint(825,200);
    update();
}
