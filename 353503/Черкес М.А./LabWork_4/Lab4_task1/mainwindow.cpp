#include "mainwindow.h"
#include <QElapsedTimer>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->sortButton, &QPushButton::clicked, this, &MainWindow::sortArray);
  connect(ui->searchButton, &QPushButton::clicked, this,
          &MainWindow::searchNumber);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::sortArray() {
  Heap();
  Quick();
  Merge();
}

int binsearch_array(int* a, int val, int n) {
  int l = 0, r = n - 1;

  while (r > l) {
    int m = (l + r) / 2;

    if (a[m] < val) {
      l = m + 1;
    } else if (a[m] > val) {
      r = m - 1;
    } else {
      return m;
    }
  }
  if (a[l] == val) {
    return l;
  } else {
    return -1;
  }
}

void MainWindow::searchNumber() {
  QStringList numbers = ui->arrayEdit->text().split(' ');
  int* array{new int[numbers.size()]};
  int n = numbers.size();
  for (int i = 0; i < n; i++) {
    array[i] = (numbers[i].toInt());
  }
  mergeSort(array, 0, n - 1);
  int numberToSearch = ui->numberEdit->text().toInt();
  int it = binsearch_array(array, numberToSearch, n);
  if (it != -1) {
    ui->outputLabel->setText("Number found at index: " + QString::number(it));
  } else {
    ui->outputLabel->setText("-1");
  }
  delete[] array;
}

void MainWindow::Heap() {
  QStringList numbers = ui->arrayEdit->text().split(' ');
  int* array{new int[numbers.size()]};
  int n = numbers.size();
  int b = 0;
  QElapsedTimer timer;
  timer.start();
  for (int i = 0; i < numbers.size(); i++) {
    array[i] = (numbers[i].toInt());
  }
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(array, n, i);
  }

  for (int i = n - 1; i >= 0; i--) {

    heapSteps++;
    b = array[0];
    array[0] = array[i];
    array[i] = b;

    heapify(array, i, 0);
  }
  int elapsed = timer.elapsed();
  ui->heap->setText("HEAP:\nsteps:" + QString::number(heapSteps) +
                    "\nTime elapsed: " + QString::number(elapsed) + " ms");
  heapSteps = 0;
  QString sortedNumbers;
  for (int i = 0; i < n; i++) {
    sortedNumbers += QString::number(array[i]) + ' ';
  }
  ui->label_5->setText(sortedNumbers);
  delete[] array;
}

void MainWindow::Quick() {
  QStringList numbers = ui->arrayEdit->text().split(' ');
  int* array{new int[numbers.size()]};
  int n = numbers.size();
  for (int i = 0; i < n; i++) {
    array[i] = (numbers[i].toInt());
  }
  QElapsedTimer timer;
  timer.start();
  quickSort(array, 0, n - 1);
  int elapsed = timer.elapsed();
  ui->quick->setText("QUICK:\nsteps:" + QString::number(quickSteps) +
                     "\nTime elapsed: " + QString::number(elapsed) + " ms");
  quickSteps = 0;
  QString sortedNumbers;
  for (int i = 0; i < n; i++) {
    sortedNumbers += QString::number(array[i]) + ' ';
  }
  ui->label_4->setText(sortedNumbers);
  delete[] array;
}

void MainWindow::Merge() {
  QStringList numbers = ui->arrayEdit->text().split(' ');
  int* array{new int[numbers.size()]};
  int n = numbers.size();
  for (int i = 0; i < n; i++) {
    array[i] = (numbers[i].toInt());
  }
  QElapsedTimer timer;
  timer.start();
  mergeSort(array, 0, n - 1);
  int elapsed = timer.elapsed();
  ui->merge->setText("MERGE:\nsteps:" +
                     QString::number(mergeSteps) +  //QString::number(steps) +
                     "\nTime elapsed: " + QString::number(elapsed) + " ms");
  mergeSteps = 0;
  QString sortedNumbers;
  for (int i = 0; i < n; i++) {
    sortedNumbers += QString::number(array[i]) + ' ';
  }
  ui->label_3->setText(sortedNumbers);
  delete[] array;
}

void MainWindow::heapify(int* arr, int n, int i) {
  heapSteps++;
  int largest = i;

  int l = 2 * i + 1;
  int r = 2 * i + 2;
  int b = 0;

  if (l < n && arr[l] > arr[largest]) {
    largest = l;
  }

  if (r < n && arr[r] > arr[largest]) {
    largest = r;
  }

  if (largest != i) {
    b = arr[i];
    arr[i] = arr[largest];
    arr[largest] = b;

    heapify(arr, n, largest);
  }
}

void swap(int* a, int* b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int MainWindow::partition(int* array, int low, int high) {

  int pivot = array[high];

  int i = (low - 1);

  for (int j = low; j < high; j++) {
    quickSteps++;
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void MainWindow::quickSort(int* array, int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

void MainWindow::merge(int* array, int const left, int const mid,
                       int const right) {
  int const subArrayOne = mid - left + 1;
  int const subArrayTwo = right - mid;

  auto *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];

  for (auto i = 0; i < subArrayOne; i++) {
    mergeSteps++;
    leftArray[i] = array[left + i];
  }
  for (auto j = 0; j < subArrayTwo; j++) {
    mergeSteps++;
    rightArray[j] = array[mid + 1 + j];
  }

  auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
  int indexOfMergedArray = left;

  while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
    mergeSteps++;
    if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
      array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
      indexOfSubArrayOne++;
    } else {
      array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
      indexOfSubArrayTwo++;
    }
    indexOfMergedArray++;
  }

  while (indexOfSubArrayOne < subArrayOne) {
    mergeSteps++;
    array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
    indexOfSubArrayOne++;
    indexOfMergedArray++;
  }


  while (indexOfSubArrayTwo < subArrayTwo) {
    mergeSteps++;
    array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
    indexOfSubArrayTwo++;
    indexOfMergedArray++;
  }
  delete[] leftArray;
  delete[] rightArray;
}

void MainWindow::mergeSort(int* array, int const begin, int const end) {
  if (begin >= end) {
    return;
  }

  int mid = begin + (end - begin) / 2;
  mergeSort(array, begin, mid);
  mergeSort(array, mid + 1, end);
  merge(array, begin, mid, end);
}
