#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QPalette>
#include <QPushButton>
#include <QRectF>
#include <QVBoxLayout>

#include "window.h"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  auto mainWindow = new QWidget;
  mainWindow->setFixedSize(820, 620);

  auto scene = new QGraphicsScene();
  auto view = new QGraphicsView(scene);

  mainWindow->setLayout(new QHBoxLayout);
  auto menu = new Window(mainWindow, scene, view);
  menu->setFixedHeight(590);
  auto frame = new QFrame;
  frame->setLayout(new QVBoxLayout);
  mainWindow->layout()->addWidget(frame);
  mainWindow->layout()->addWidget(menu);

  view->setFixedSize(600, 580);
  view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setScene(scene);
  frame->layout()->addWidget(view);

  mainWindow->show();

  auto res = app.exec();

  delete mainWindow;
  delete scene;
  delete view;
  delete frame;

  return res;
}
