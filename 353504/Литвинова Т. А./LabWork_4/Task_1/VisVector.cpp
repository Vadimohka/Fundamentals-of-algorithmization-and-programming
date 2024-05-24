#include "VisVector.h"
#include <QTableWidget>
#include <qcolor.h>
#include <qcontainerfwd.h>
#include <qgraphicsscene.h>
#include <qnamespace.h>
#include <qtablewidget.h>

VisVector::VisVector(int _size) {
  size = _size;
  ini = {};
  ini.resize(size);
  cur.resize(size);
  for (int i = 0; i < size; i++) {
    ini[i] = rand() % (MAX_HEIGHT - MIN_HEIGHT) + MIN_HEIGHT;
    cur[i] = ini[i];
  }
}

void VisVector::Draw(QGraphicsScene *scene) {
  Action curA = actions[currentAction];

  float rectW = scene->width() / size;
  for (int i = 0; i < size; i++) {
    QColor color = Qt::white;
    if (curA.index == i) {
      if (curA.type == ActionType::Read) {
        color = Qt::green;
      } else if (curA.type == ActionType::Write) {
        color = Qt::red;
      } else if (curA.type == ActionType::Swap) {
        color = Qt::blue;
      } else if (curA.type == ActionType::Find) {
        color = Qt::magenta;
      }
    }

    if (curA.type == ActionType::Swap && curA.value == i) {
      color = Qt::blue;
    }

    scene->addRect(i * rectW, 600 - cur[i], rectW, cur[i], Qt::NoPen, color);
  }
}

void VisVector::FillTable(QTableWidget *table) {
  table->setRowCount(actions.count());
  for (int i = 0; i < actions.count(); i++) {
    Action a = actions[i];
    if (a.type == ActionType::Read) {
      table->setItem(i, 0, new QTableWidgetItem("Read"));
    } else if (a.type == ActionType::Write) {
      table->setItem(i, 0, new QTableWidgetItem("Write"));
    } else if (a.type == ActionType::Swap) {
      table->setItem(i, 0, new QTableWidgetItem("Swap"));
    } else if (a.type == ActionType::Find) {
      if (a.index == -100) {
        table->setItem(i, 0, new QTableWidgetItem("Starting"));
        table->setItem(i, 1, new QTableWidgetItem("Binary"));
        table->setItem(i, 2, new QTableWidgetItem("Search"));
        continue;
      }
      table->setItem(i, 0, new QTableWidgetItem("Found"));
    }

    table->setItem(i, 1, new QTableWidgetItem(QString::number(a.index)));
    table->setItem(i, 2, new QTableWidgetItem(QString::number(a.value)));
  }
}

Stats VisVector::CollectStats() {
  Stats stats = {0, 0, 0};

  for (auto a : actions) {
    if (a.type == ActionType::Read)
      stats.reads++;
    if (a.type == ActionType::Write)
      stats.writes++;
    if (a.type == ActionType::Swap)
      stats.swaps++;
    if (a.type == ActionType::Find)
      return stats;
  }

  return stats;
}

int VisVector::Read(int index) {
  actions.push_back({ActionType::Read, index, cur[index]});
  return cur[index];
}

void VisVector::Write(int index, int val) {
  actions.push_back({ActionType::Write, index, val});
  SetCurrentAction(actions.count() - 1);
}

void VisVector::Swap(int l, int r) {
  if (l == r)
    return;

  actions.push_back({ActionType::Swap, l, r});
  SetCurrentAction(actions.count() - 1);
}

int VisVector::Size() { return size; }

void VisVector::ReportFind(int index, int el) {
  actions.push_back({ActionType::Find, index, el});
}

void VisVector::SetCurrentAction(int action_i) {
  if (action_i < currentAction) {
    cur = ini;
    currentAction = 0;
  }

  for (int i = currentAction + 1; i <= action_i; i++) {
    Action a = actions[i];
    if (a.type == ActionType::Write) {
      cur[a.index] = a.value;
    } else if (a.type == ActionType::Swap) {
      int lv = cur[a.index];
      cur[a.index] = cur[a.value];
      cur[a.value] = lv;
    }
  }

  currentAction = action_i;
}

void VisVector::Reset() {
  cur = ini;
  currentAction = 0;
  actions.clear();
}

void VisVector::ClearSearch() {
  for (int i = 0; i < actions.count(); i++) {
    if (actions[i].type == ActionType::Find) {
      actions.resize(i);
      if (currentAction >= actions.count())
        currentAction = actions.count() - 1;
      return;
    }
  }
}