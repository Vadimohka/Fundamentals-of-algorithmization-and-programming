#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <climits>
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
      setEl(q.pop_back());
      redraw();
    }
  });

  connect(ui->popFront, &QPushButton::clicked, [this]() {
    if (!q.empty()) {
      setEl(q.pop_front());
      redraw();
    }
  });

  connect(ui->randBtn, &QPushButton::clicked, [this]() {
    q.clear();
    for (int i = 0; i < 50; i++) {
      q.push_back(rand() % 1000);
    }
    redraw();
  });

  connect(ui->clearBtn, &QPushButton::clicked, [this]() {
    q.clear();
    redraw();
  });


  connect(ui->innerBtn, &QPushButton::clicked, [this]() {
    createRing(true);
  });


  connect(ui->outerBtn, &QPushButton::clicked, [this]() {
    createRing(false);
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

void MainWindow::createRing(bool inner) {
  if(q.empty()) return;
  
  int max = INT_MIN;
  int maxi = 0;
  int min = INT_MAX;
  int mini = 0;

  for(int i = 0; i < q.size(); i++) {
    if(q[i] > max) {
      max = q[i];
      maxi = i;
    }
    if(q[i] < min) {
      min = q[i];
      mini = i;
    }
  }
  if(mini > maxi) {
    int tmp = mini;
    mini = maxi;
    maxi = tmp;
  }

  Deque<int> nq;
  if(inner) {
    for(int i = mini; i <= maxi; i++) {
      nq.push_back(q[i]);
    }
  } else {
    for(int i = 0; i < mini; i++) {
      nq.push_back(q[i]);
    }

    for(int i = maxi + 1; i < q.size(); i++) {
      nq.push_back(q[i]);
    }
  }

  q = nq;
  redraw();
}