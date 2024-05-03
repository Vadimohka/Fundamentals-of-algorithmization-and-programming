#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      scene(new QGraphicsScene(this)) {
  ui->setupUi(this);  //setScene(scene) устанавливает сцену
  ui->graphicsView->setScene(
      scene);  //(ui->graphicsView возвращает указатель на "graphicsView"(name))

  ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

  timerForButtonDown = new QTimer();
  timerForButtonUp = new QTimer();
  timerForButtonLeft = new QTimer();
  timerForButtonRight = new QTimer();

  timerForButtonDown->setInterval(25);
  timerForButtonUp->setInterval(25);
  timerForButtonLeft->setInterval(10);
  timerForButtonRight->setInterval(10);

  connect(timerForButtonUp, &QTimer::timeout, this, &MainWindow::moveUp);
  connect(timerForButtonDown, &QTimer::timeout, this, &MainWindow::moveDown);
  connect(timerForButtonLeft, &QTimer::timeout, this, &MainWindow::moveLeft);
  connect(timerForButtonRight, &QTimer::timeout, this, &MainWindow::moveRight);

  background = new Background;
  scene->addItem(background);

  plane = new Plane;
  scene->addItem(plane);
}

void MainWindow::on_ButtonChassis_clicked() {
  plane->Plane::changeChassis();
}

MainWindow::~MainWindow() {
  delete ui;
  delete plane;
  delete background;
}

void MainWindow::moveUp() {
  if (plane->getNowPossitionPlaneOnY() > -350) {
    plane->Plane::setChassis(0);
    plane->moveUp();
    plane->addPointUp();
  }
}

void MainWindow::moveDown() {
  if (plane->getNowPossitionPlaneOnY() < 220) {
    plane->moveDown();
    plane->addPointDown();
  } else
    plane->Plane::setChassis(1);
}

void MainWindow::moveLeft() {
  if (plane->getNowPossitionPlaneOnX() > -675) {
    plane->moveLeft();
    plane->addPointLeft();
  }
}

void MainWindow::moveRight() {
  if (plane->getNowPossitionPlaneOnX() < 675) {
    plane->moveRight();
    plane->addPointRight();
  }
}

void MainWindow::on_ButtonUp_pressed() {
  timerForButtonUp->start();
}

void MainWindow::on_ButtonUp_released() {
  timerForButtonUp->stop();
}

void MainWindow::on_ButtonLeft_pressed() {
  timerForButtonLeft->start();
}

void MainWindow::on_ButtonLeft_released() {
  timerForButtonLeft->stop();
}

void MainWindow::on_ButtonRight_pressed() {
  timerForButtonRight->start();
}

void MainWindow::on_ButtonRight_released() {
  timerForButtonRight->stop();
}

void MainWindow::on_ButtonDown_pressed() {
  timerForButtonDown->start();
}

void MainWindow::on_ButtonDown_released() {
  timerForButtonDown->stop();
}
