#include "mainwindow.h"
#include <abstractfigure.h>
#include <rectfigure.h>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  scene = new MyScene();
  ui->graphicsView->setScene(scene);
  ui->graphicsView->setRenderHint(
      QPainter::Antialiasing);  // Устанавливаем сглаживание
  ui->graphicsView->setVerticalScrollBarPolicy(
      Qt::ScrollBarAlwaysOff);  // Отключаем скроллбар по вертикали
  ui->graphicsView->setHorizontalScrollBarPolicy(
      Qt::ScrollBarAlwaysOff);  // Отключаем скроллбар по горизонтали

  timer = new QTimer();  // Инициализируем таймер
  connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
  timer->start(100);

  // scene->addItem(rec);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::slotTimer() {
  timer->stop();
  scene->setSceneRect(0, 0, ui->graphicsView->width() - 20,
                      ui->graphicsView->height() - 20);
}

void MainWindow::on_pushbutton_clicked() {}

void MainWindow::resizeEvent(QResizeEvent* event) {
  timer->start(100);
  QMainWindow::resizeEvent(event);
}
