#include "VisualHashMap.h"
#include <QFrame>
#include <QTableWidget>
#include <climits>

const QString alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const long mod = 100000;

QString randString() {
  QString str;
  for (int i = 0; i < 11; i++) {
    str += alpha[rand() % alpha.size()];
  }
  return str;
}

VisualMap::VisualMap() : HashMap<QString>(10) {
  randomize();
}

void VisualMap::randomize() {
  clear();
  for (int i = 0; i < 200; i++) {
    insert(rand()% mod, randString());
  }
}

VisualMap::~VisualMap() {}

void VisualMap::fillEntries(QTableWidget *table) {
  table->setRowCount(0);
  for (int i = 0; i < size; i++) {
    Element *entr = elements[i];
    if (entr == nullptr)
      continue;

    int firstRow = table->rowCount();
    int spannedRows = 0;
    while (entr != nullptr) {
      int row = table->rowCount();
      table->insertRow(row);
      table->setItem(row, 1, new QTableWidgetItem(QString::number(entr->key)));
      table->setItem(row, 2, new QTableWidgetItem(entr->val));
      entr = entr->next;
      spannedRows++;
    }

    table->setItem(firstRow, 0, new QTableWidgetItem(QString::number(i)));
    if (spannedRows > 1)
      table->setSpan(firstRow, 0, spannedRows, 1);
  }
}

long VisualMap::calculateTotalSum() {
  long totalSum = 0;
  int count = 0;
  for (int i = 0; i < size; i++) {
    Element *entr = elements[i];
    while (entr != nullptr) {
      totalSum += entr->key;
      count++;
      entr = entr->next;
    }
  }
  return totalSum;
}

long VisualMap::countAboveAverage() {
  long totalSum = calculateTotalSum();
  if (totalSum == 0)
    return 0;

  long average = totalSum / size;

  int countAbove = 0;
  for (int i = 0; i < size; i++) {
    Element *entr = elements[i];
    while (entr != nullptr) {
      if (entr->key > average)
        countAbove++;
      entr = entr->next;
    }
  }
  return countAbove;
}