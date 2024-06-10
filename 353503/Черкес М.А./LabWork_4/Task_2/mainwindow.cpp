#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->button, &QPushButton::clicked, this,
          &MainWindow::handleButtonClick);
  connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::search);
  connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::clear);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::handleButtonClick() {
  QStringList list = ui->input->text().split(" ");
  QVector<int> arr;
  for (const QString& str : list) {
    arr.push_back(str.toInt());
  }
  QString result;
  for (int num : arr) {
    result += QString::number(num) + " ";
  }
  result.chop(1);
  ui->output->append(result);

  interpolationSort(arr);
}

void MainWindow::interpolationSort(QVector<int>& arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; i++) {
    int j = i + 1;
    while (j > 0 && arr[j - 1] > arr[j]) {
      std::swap(arr[j], arr[j - 1]);
      j--;
    }
    QString result;
    for (int k = 0; k < n; k++) {
      result += QString::number(arr[k]) + " ";
    }
    ui->output->append(result);
  }
}

int MainWindow::binpow(int digit, int powder, int mod) {
  digit %= mod;
  int result = 1;
  while (powder > 0) {
    if (powder & 1) {
      result = (result * digit) % mod;
    }
    digit = (digit * digit) % mod;
    powder >>= 1;
  }
  return result;
}

void MainWindow::search() {
  int i = ui->spinBox->text().toInt();
  int result = 0;
  QStringList list = ui->input->text().split(" ");
  QVector<int> arr;
  for (const QString& str : list) {
    arr.push_back(str.toInt());
  }
  for (int g = 0; g < arr.size(); g++) {
    if (arr[g] == i) {
      result = binpow(g, arr.size(), ui->spinBox_2->text().toInt());
    }
  }
  ui->output->append(" " + QString::number(result));
}

void MainWindow::clear() {
  ui->output->setText("");
}
