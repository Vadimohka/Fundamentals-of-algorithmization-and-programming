#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <face.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(new QGraphicsScene())
{
    ui->setupUi(this);

    ui->graphicsView->setScene(scene);
    Face* face = new Face(0, 0, 300, 300);
    scene -> addItem(face);

    connect(ui -> movePupils, SIGNAL(pressed()), face, SLOT(startMovingPupils()));
    connect(face -> timerEyes, SIGNAL(timeout()), face, SLOT(movePupils()));
    connect(ui -> openMouth, SIGNAL(pressed()), face, SLOT(startMovingLips()));
    connect(face -> timerLips, SIGNAL(timeout()), face, SLOT(moveLips()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
