#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm>
#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->numBox->setMinimum(-100);
    ui->numBox->setMaximum(100);
    ui->medianBrowser->setFontPointSize(14);
    ui->vectorBrowser->setFontPointSize(14);
}

MainWindow::~MainWindow()
{
    delete ui;
}

typedef unsigned long ul;

std::vector<int> MainWindow::calcMedians(std::vector<int> &a)
{
    std::vector<int> b;
    for (ul i = 0; i < a.size(); i += 3) {
        std::vector<int> temp;
        for (int j = i; j < std::min((int) (i + 3), (int) (a.size())); j++) {
            temp.push_back(a[j]);
        }
        quickSort(temp, 0, temp.size() - 1);
        if (temp.size() == 3) {
            b.push_back(temp[1]);
        } else if (temp.size() != 0) {
            int sum = 0;
            for (int a : temp) {
                sum += a;
            }
            b.push_back(sum / temp.size());
        }
    }
    return b;
}

void MainWindow::quickSort(std::vector<int> &arr, int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int MainWindow::partition(std::vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

std::vector<int> MainWindow::generateRandomVector()
{
    srand(time(0));
    int size = rand() % 18 + 3;
    std::vector<int> vec(size);
    for (int i = 0; i < size; i++) {
        vec[i] = rand() % 201 - 100;
    }
    return vec;
}

void MainWindow::on_generateVector_clicked()
{
    std::vector<int> vec = generateRandomVector();

    QString s;

    for (int a : vec) {
        s += QString::number(a) + " ";
    }
    ui->vectorBrowser->setPlainText(s);
    ui->medianBrowser->clear();
}

void MainWindow::on_addButton_clicked()
{
    int num = ui->numBox->value();
    QString s = ui->vectorBrowser->toPlainText();
    s += QString::number(num) + " ";
    ui->vectorBrowser->setPlainText(s);
}

void MainWindow::on_resultButton_clicked()
{
    QString s = ui->vectorBrowser->toPlainText();
    if (s.isEmpty()) {
        QMessageBox::information(this, "Ввод", "Ваш вектор пуст");
        return;
    }
    QStringList list = s.split(" ", Qt::SkipEmptyParts);
    std::vector<int> vec;
    for (const QString &s : list) {
        vec.push_back(s.toInt());
    }
    std::vector<int> medians = calcMedians(vec);
    s.clear();
    for (int num : medians) {
        s += QString::number(num) + " ";
    }
    ui->medianBrowser->setPlainText(s);
}

void MainWindow::on_clearButton_clicked()
{
    if (!ui->vectorBrowser->toPlainText().isEmpty()) {
        ui->vectorBrowser->clear();
    };
    if (!ui->medianBrowser->toPlainText().isEmpty()) {
        ui->medianBrowser->clear();
    }
}
