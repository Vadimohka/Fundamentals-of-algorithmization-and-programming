#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qgraphicsscene.h>
#include "RectArray.h"

MainWindow::MainWindow(): ui(new Ui::MainWindow), scene(new QGraphicsScene(this)) {
  ui->setupUi(this); 

  ui->graphicsView->setScene(scene);
  ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
  scene->setSceneRect(0, 0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);

  


  array = new RectArray();
  scene->addItem(array);

}

MainWindow::~MainWindow()
{
}

void MainWindow::on_spinBox_valueChanged(int arg1) {
  array->number = arg1;
  array->update();
}