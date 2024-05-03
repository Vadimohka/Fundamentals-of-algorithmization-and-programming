#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qgraphicsscene.h>
#include "Rect.h"

MainWindow::MainWindow(): ui(new Ui::MainWindow), scene(new QGraphicsScene(this)) {
  ui->setupUi(this); 

  ui->graphicsView->setScene(scene);
  ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

  connect(ui->leftPushButton, &QPushButton::clicked, this, &MainWindow::onLeftClicked);
  connect(ui->rightPushButton, &QPushButton::clicked, this, &MainWindow::onRightClicked);

  rect = new Rect();
  scene->addItem(rect);

  QPen pen1(Qt::black);
  pen1.setWidth(7);
  QGraphicsLineItem* line1 = scene->addLine(0, 80, 0, 150, pen1);
  QGraphicsLineItem* line2 = scene->addLine(0, 150, 30, 200, pen1);
  QGraphicsLineItem* line3 = scene->addLine(0, 150, -30, 200, pen1);
  QGraphicsEllipseItem* ellipse = scene->addEllipse(-25, 30, 50, 50, pen1);

}

MainWindow::~MainWindow() {
  delete rect;
}

void MainWindow::onLeftClicked()
{
  rect->setLeft(); 
}


void MainWindow::onRightClicked()
{
  rect->setRight();  
}

