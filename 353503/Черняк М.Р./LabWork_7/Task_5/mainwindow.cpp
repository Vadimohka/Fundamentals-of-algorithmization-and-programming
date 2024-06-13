#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qtablewidget.h>

MainWindow::MainWindow() : ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->pushBack, &QPushButton::clicked, [this]() {
    q.push_back(getEl());
    redraw();
  });

  connect(ui->pushFront, &QPushButton::clicked, [this]() {
    q.push_front(getEl());
    redraw();
  });

  connect(ui->popBack, &QPushButton::clicked, [this]() {
    if (!q.empty()) {
      q.pop_back();
      redraw();
    }
  });

  connect(ui->popFront, &QPushButton::clicked, [this]() {
    if (!q.empty()) {
      q.pop_front();
      redraw();
    }
  });

  redraw();
}

int MainWindow::getEl() { return ui->inp->value(); }
void MainWindow::setEl(int val) { return ui->inp->setValue(val); }



void MainWindow::redraw() {
  ui->popBack->setEnabled(!q.empty());
  ui->popFront->setEnabled(!q.empty());

  ui->deqEls->clear();
  for (auto el : q) {
    ui->deqEls->addItem(QString::number(el));
  }
}
