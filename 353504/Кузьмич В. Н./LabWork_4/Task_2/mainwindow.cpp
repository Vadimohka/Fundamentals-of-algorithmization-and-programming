#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString v, a = "([,][+-]?[0-9]{1,16})";
    v.insert(0, a.repeated(1200));
    ui->lineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[-+]?[0-9]{1,16}" + v),this));
    ui->lineEdit_2->setValidator(new QRegularExpressionValidator(QRegularExpression("[-+]?[0-9]{1,16}"),this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    close();
}

long long MainWindow::binpow(long long digit, long long power, long long mod) {
    long long result = 1;
    while (power > 0) {
        if (power & 1) {
            result = result * digit % mod;
        }
        digit = digit * digit % mod;
        power >>= 1;
    }
    return result;
}

void MainWindow::InterSort(QVector<long long> &numbers, bool is_firste = false)
{
    long long start = 0;
    long long size = numbers.size();
    long long min = numbers[0];
    long long max = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        } else if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    if (min != max) {
        QVector<QVector<long long>> mas(size);
        long long b = 0;
        for (int i = 0; i < size; i++) {
            b = (long long)(((double)(numbers[i] - min) / (max - min)) * (size - 1));
            mas[b].push_back(numbers[i]);
            if (is_firste){
                if (i == 0) razm_kuh.resize(size * 2);
                razm_kuh[i] = mas;
            }
        }
        for (int i = 0; i < size; i++) {
            if (mas[i].size() > 1) {
                InterSort(mas[i]);
            }
            for (int j = 0; j < mas[i].size(); j++) {
                numbers[start] = mas[i][j];
                start++;
            }
            if (is_firste) razm_kuh[i + size] = mas;
        }
    }
}

long long MainWindow::BinarySearch(const QVector<long long> &arr, long long target)
{
    long long left = 0;
    long long right = arr.size() - 1;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

void MainWindow::on_pushButton_clicked()
{
    razm_kuh.clear();
    sort_kuh.clear();
    numbers.clear();
    ui->textEdit->clear();
    QString input = ui -> lineEdit -> text();
    QStringList numbersAsStrings = input.split(",");
    for(const QString& str : numbersAsStrings) {
        long long num = str.toLongLong();
        numbers.append(num);
    }
    QString inter_sort;
    InterSort(numbers, true);
    for (int i = 0; i < razm_kuh.size(); i++){
        for (int j = 0; j < razm_kuh[i].size(); j++) {
            for (int z = 0; z < razm_kuh[i][j].size(); z++){
                inter_sort += QString::number(razm_kuh[i][j][z]);
                if (z < razm_kuh[i][j].size() - 1) {
                    inter_sort += ",";
                }
            }
            ui->textEdit->insertPlainText("[" + inter_sort + "]");
            inter_sort = "";
        }
        ui->textEdit->append("");
    }
    for (int i = 0; i < sort_kuh.size(); i++){
        for (int j = 0; j < sort_kuh[i].size(); j++) {
            for (int z = 0; z < sort_kuh[i][j].size(); z++){
                inter_sort += QString::number(sort_kuh[i][j][z]);
                if (z < sort_kuh[i][j].size() - 1) {
                    inter_sort += ",";
                }
            }
            ui->textEdit->insertPlainText("[" + inter_sort + "]");
            inter_sort = "";
        }
        ui->textEdit->append("");
    }
    inter_sort = "";
    for (int i = 0; i < numbers.size(); ++i) {
        inter_sort += QString::number(numbers[i]);
        if (i < numbers.size() - 1) {
            inter_sort += ",";
        }
    }
    ui->textEdit->append("Отсортированный массив [" + inter_sort + "]");
}


void MainWindow::on_pushButton_3_clicked()
{
    long long namber = (ui -> lineEdit_2 -> text()).toLongLong();
    ui -> label_5 -> setText(QString::number(BinarySearch(numbers, namber)));
    ui -> label_2 -> setText("Функция binpow: " + QString::number(binpow(BinarySearch(numbers, namber), numbers.size(), namber)));
}

