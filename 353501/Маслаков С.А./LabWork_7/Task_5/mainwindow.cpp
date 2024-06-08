#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
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

    redraw();
}

int MainWindow::getEl() { return ui->inp->value(); }
void MainWindow::setEl(int val) { return ui->inp->setValue(val); }

class DisplayDeq {
public:
  static void fillTable(QTableWidget *table, Deque<int> *q) {
    table->setRowCount(q->blocks_count);
    table->setColumnCount(4);
    for (int i = 0; i < q->blocks_count; i++) {
      for (int j = 0; j < q->BLOCK_SIZE; j++) {
        table->setItem(
            i, j, new QTableWidgetItem(QString::number(q->blocks[i]->els[j])));
      }
    }
  }

  static int getBegin(Deque<int> *q) { return q->_begin; }

  static int getEnd(Deque<int> *q) { return q->_end; }
};

void MainWindow::redraw() {
  ui->popBack->setEnabled(!q.empty());
  ui->popFront->setEnabled(!q.empty());

  ui->deqEls->clear();
  for (auto el : q) {
    ui->deqEls->addItem(QString::number(el));
  }

  DisplayDeq::fillTable(ui->intView, &q);
  ui->beginPos->setText(
      QString("Inner Begin: %1").arg(DisplayDeq::getBegin(&q)));
  ui->endPos->setText(QString("Inner End: %1").arg(DisplayDeq::getEnd(&q)));
}
