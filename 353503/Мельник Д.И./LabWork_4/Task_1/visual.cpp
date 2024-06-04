#include <QCoreApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPair>
#include <QtCore>

#include "thread"
#include "visual.h"

#define MAX_HEIGHT 200;

Visual::Visual() : _randomGer(QRandomGenerator::global()) {
  _items.clear();
}

void Visual::createItem(const int& count) {
  _items.clear();
  float width = 500 / static_cast<float>(count);
  float height = 0;
  for (int i = 0; i < count; ++i) {
    height = _randomGer->generate() % MAX_HEIGHT;
    _items.push_back(new QGraphicsRectItem());
    _items[i]->setRect(width * i, height, width, 200 - height);
    _items[i]->setBrush(Qt::black);
    qDebug() << "items [" << i << "] " << _items[i]->rect();
  }
}

QVector<QGraphicsRectItem*> Visual::GetItems() {
  return _items;
}

void Visual::swapItem(QVector<QGraphicsRectItem*>& items, const int& ind1,
                      const int& ind2) {
  // Подсветка элементов, которые собираются поменяться местами
  float dx = items[ind1]->pos().x() - items[ind2]->pos().x();

  items[ind1]->setBrush(Qt::red);
  items[ind2]->setBrush(Qt::red);

  // Обновление графического интерфейса
  QCoreApplication::processEvents();
  std::this_thread::sleep_for(std::chrono::milliseconds(_speed));

  items[ind1]->moveBy(dx, 0);
  items[ind2]->moveBy(-dx, 0);
  qDebug() <<"dx: [" << dx << "]";
  emit updatedScene();

  // Сброс подсветки
  items[ind1]->setBrush(Qt::black);
  items[ind2]->setBrush(Qt::black);

  // Обновление графического интерфейса
  QCoreApplication::processEvents();
  std::this_thread::sleep_for(std::chrono::milliseconds(_speed));
}

void Visual::setSpeed(int speed) {
  _speed = speed;
}

// Quicksort
void Visual::quickSort(int low, int high) {
  if (low < high) {
    int pi = partition(low, high);
    quickSort(low, pi - 1);
    quickSort(pi + 1, high);
  }
}

int Visual::partition(int low, int high) {
  int pivot = _items[high]->rect().height();
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) {
    if (_items[j]->rect().height() < pivot) {
      i++;
      swapItem(_items, i, j);
    }
  }
  swapItem(_items, i + 1, high);
  return (i + 1);
}

// Mergesort
void Visual::mergeSort(int l, int r) {
  if (l >= r) {
    return;
  }
  int m = l + (r - l) / 2;
  mergeSort(l, m);
  mergeSort(m + 1, r);
  merge(l, m, r);
}

void Visual::merge(int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  QVector<int> L(n1), R(n2);

  for (i = 0; i < n1; i++) {
    L[i] = _items[l + i]->rect().height();
  }
  for (j = 0; j < n2; j++) {
    R[j] = _items[m + 1 + j]->rect().height();
  }

  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      _items[k]->rect().setHeight(L[i]);
      i++;
    } else {
      _items[k]->rect().setHeight(R[j]);
      j++;
    }
    k++;
  }

  while (i < n1) {
    _items[k]->rect().setHeight(L[i]);;
    i++;
    k++;
  }

  while (j < n2) {
    _items[k]->rect().setHeight(R[j]);;
    j++;
    k++;
  }
}

// Heapsort
void Visual::heapSort(int n) {
  for (int i = n / 2 - 1; i >= 0; --i) {
    heapify(n, i);
  }

  for (int i = n - 1; i >= 0; i--) {
    swapItem(_items, 0, i);
      _items.swapItemsAt(0,i);
    QCoreApplication::processEvents();
    heapify(i, 0);
  }
}

void Visual::heapify(int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && _items[left]->rect().height() > _items[largest]->rect().height())
    largest = left;

  if (right < n && _items[right]->rect().height() > _items[largest]->rect().height())
    largest = right;

  if (largest != i) {
    swapItem(_items, i, largest);
    QCoreApplication::processEvents();
    heapify(n, largest);
  }
}

void Visual::quickSortStart() {
  qDebug() << "Quick start";
  for (const auto& x : _items) {
    qDebug() << x->rect().height();
  }
  quickSort(0, _items.size() - 1);
  endSort();
  qDebug() << "Quick ended";
  for (const auto& x : _items) {
    qDebug() << x->rect().height();
  }
}

void Visual::mergeSortStart() {
  qDebug() << "Merge start";
  mergeSort(0, _items.size() - 1);
  endSort();
  qDebug() << "merge ended";
}

void Visual::heapSortStart() {
  qDebug() << "Heap start";
  for (const auto& x : _items) {
    qDebug() << x->rect().height();
  }
  heapSort(_items.size());
  endSort();
  qDebug() << "Heap ended";
  for (const auto& x : _items) {
    qDebug() << x->rect().height();
  }
}

void Visual::endSort() {
  for (int i = 0; i < _items.size() - 1; ++i) {
    if (_items[i]->rect().height() > _items[i + 1]->rect().height()) {
      qDebug() << "Bad sort";
      return;
    }
    _items[i]->setBrush(Qt::red);
    _items[i + 1]->setBrush(Qt::red);

    QCoreApplication::processEvents();
    std::this_thread::sleep_for(std::chrono::milliseconds(_speed));

    _items[i]->setBrush(Qt::black);
    _items[i + 1]->setBrush(Qt::black);
  }
  qDebug() << "Good sort";
}
