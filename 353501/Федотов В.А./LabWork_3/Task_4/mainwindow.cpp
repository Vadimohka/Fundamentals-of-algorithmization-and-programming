#include "mainwindow.h"
#include "hanoiGraphics.h"


MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(2);
    QStringList horizontalHeaders;
    horizontalHeaders << "From" << "To";
    ui->tableWidget->setHorizontalHeaderLabels(horizontalHeaders);

    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate); 

    graphics = new HanoiGraphics(ui->numRingsSpinBox->value());
    graphics->setTable(ui->tableWidget);
    graphics->setSpeed(ui->speedSpinBox->value());
    scene->addItem(graphics);

    connect(ui->resetButton, &QPushButton::pressed, this, &MainWindow::resetDisks);
    connect(ui->startButton, &QPushButton::pressed, this, &MainWindow::start);
    connect(ui->speedSpinBox, &QSpinBox::valueChanged, this, &MainWindow::changeSpeed);
}

void MainWindow::resetDisks(){
    scene->removeItem(graphics);
    delete graphics;

    graphics = new HanoiGraphics(ui->numRingsSpinBox->value());
    graphics->setTable(ui->tableWidget);
    graphics->setSpeed(ui->speedSpinBox->value());
    scene->addItem(graphics);
    update();
}

void MainWindow::changeSpeed(int speed){
    graphics->setSpeed(speed);
}

void MainWindow::start(){
    disconnect(ui->resetButton, &QPushButton::pressed, this, &MainWindow::resetDisks);
    disconnect(ui->startButton, &QPushButton::pressed, this, &MainWindow::start);
    ui->resetButton->hide();
    ui->startButton->hide();
    graphics->solve(graphics->getNumDisks(), 1, 3);
}
