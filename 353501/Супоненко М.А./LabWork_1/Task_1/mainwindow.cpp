#include "mainwindow.h"
#include "ui_mainwindow.h" 
#include <QGraphicsView>
#include <qgraphicsscene.h>


MainWindow::MainWindow(): ui(new Ui::MainWindow), scene(new QGraphicsScene(this)) {
  ui->setupUi(this);
  
  ui->graphicsView->setScene(scene);
  ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

  rect = new Rect();
  scene->addItem(rect);// scene.addRect(100, 100, 100, 100);
  
  det = new details();
  scene->addItem(det);
}

MainWindow::~MainWindow() {
  delete rect;
  delete det;
}
