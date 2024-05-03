#include "mainwindow.h"
#include "Ellipse.h"
#include "Glaza.h"
#include "Gubi.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <qgraphicsscene.h>

#include <QTimer>

MainWindow::MainWindow()
    : ui(new Ui::MainWindow), scene(new QGraphicsScene(this)) {
  ui->setupUi(this);
  ui->graphicsView->setScene(scene);
  ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
  setFixedSize(800, 600);

  ellipse = new Ellipse();
  glaza = new Glaza;
  gubi = new Gubi;

  scene->addItem(ellipse);
  scene->addItem(glaza);
  scene->addItem(gubi);
}

MainWindow::~MainWindow() {
  delete ellipse;
  delete glaza;
  delete gubi;
}

void MainWindow::on_pushButton_clicked() { glaza->onTime(); }
void MainWindow::on_pushButton_2_clicked() { gubi->onTime2(); }