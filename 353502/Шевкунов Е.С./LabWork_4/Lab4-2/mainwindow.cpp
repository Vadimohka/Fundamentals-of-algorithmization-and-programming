#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QLabel>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createUI()
{
    textEdit = new QTextEdit(this);
    textEdit->setGeometry(20, 20, 300, 200);
    textEdit->setReadOnly(true);

    spinBox = new QSpinBox(this);
    spinBox->setGeometry(20, 250, 100, 25);
    spinBox->setMinimum(1);

    restartButton = new QPushButton("Restart", this);
    restartButton->setGeometry(20, 290, 80, 30);
    connect(restartButton, &QPushButton::clicked, this, &MainWindow::restartClicked);

    enterButton = new QPushButton("Enter", this);
    enterButton->setGeometry(120, 290, 80, 30);
    connect(enterButton, &QPushButton::clicked, this, &MainWindow::enterClicked);

    label_n = new QLabel("n:", this);
    label_n->setGeometry(220, 250, 100, 25);

    label_mod = new QLabel("mod:", this);
    label_mod->setGeometry(220, 280, 100, 25);

    label_ans = new QLabel("ans:", this);
    label_ans->setGeometry(220, 310, 100, 25);

    messageLabel = new QLabel("Enter n:", this);
    messageLabel->setGeometry(20, 330, 100, 25);
}

void MainWindow::restartClicked()
{
    spinBox->setEnabled(true);
    enterButton->setEnabled(true);
    spinBox->setMinimum(1);
    arr.clear();
    enterI = 0;
    n = 0;
    textEdit->clear();
    label_n->setText("");
    label_mod->setText("");
    label_ans->setText("");
    messageLabel->setText("Enter n:");
}

void MainWindow::enterClicked()
{
    if (messageLabel->text() == "Enter n:") {
        n = spinBox->value();
        arr.resize(n);
        spinBox->setMinimum(-2147483647);
        messageLabel->setText("Enter element № " + QString::number(enterI + 1) + ":");
        label_n->setText("n: " + QString::number(n));
    } else if (messageLabel->text() == "Enter element to find") {
        find = spinBox->value();
        messageLabel->setText("Enter MOD");
        spinBox->setMinimum(1);
    } else if (messageLabel->text() == "Enter MOD") {
        mod = spinBox->value();
        label_mod->setText("mod: " + QString::number(mod));
        messageLabel->setText("Input ended");
        spinBox->setEnabled(false);
        enterButton->setEnabled(false);
        long long bp = binSearch(arr, find) + 1;
        if (bp != -1) {
            label_ans->setText("ans: " + QString::number(binpow(bp % mod, n % mod, mod)));
        } else {
            label_ans->setText("ans: no such item in array");
        }
    } else {
        arr[enterI] = spinBox->value();

        if (enterI == 0) {
            textEdit->setVisible(true);
            textEdit->setText("arr:        " + QString::number(arr[0]));
        } else {
            textEdit->setText(textEdit->toPlainText() + " " + QString::number(arr[enterI]));
        }
        ++enterI;
        if (enterI != n)
            messageLabel->setText("Enter element № " + QString::number(enterI + 1) + ":");
        else {
            messageLabel->setText("Enter element to find");
            QString text;
            interpolationSort(arr, text);
            textEdit->setText(textEdit->toPlainText() + "\n" + text);
            QString add = "Sorted arr: ";
            for (auto &i : arr) {
                add += QString::number(i) + " ";
            }
            textEdit->setText(textEdit->toPlainText() + add);
        }
    }
}

void MainWindow::printArr(const QVector<long long> &arr, const QString &pref, QString &out)
{
    out += pref;
    for (auto &i : arr)
        out += QString::number(i) + " ";
    out += "\n";
}

unsigned long long MainWindow::bin_mul(unsigned long long a, unsigned long long n, unsigned long long m)
{
    unsigned long long res = 0;
    while (n) {
        if (n & 1)
            res += a;
        if (res >= m) {
            res %= m;
        }
        a += a;
        a %= m;
        n >>= 1;
    }
    return res; //(a*n)%m
}

unsigned long long MainWindow::binpow(unsigned long long a, unsigned long long n, unsigned long long m)
{
    unsigned long long res = 1;
    while (n) {
        if (n & 1)
            res = bin_mul(res, a, m);
        a = bin_mul(a, a, m);
        n >>= 1;
    }
    return res;
}

long long MainWindow::binSearch(const QVector<long long> &a, long long find)
{
    long long l = 0, r = a.size() - 1;

    while (r > l) {
        long long m = (l + r) / 2;

        if (a[m] < find) {
            l = m + 1;
        } else if (a[m] > find) {
            r = m - 1;
        } else {
            return m;
        }
    }

    if (a[l] == find) {
        return l;
    } else {
        return -2;
    }
}

void MainWindow::divide(QVector<long long> &A, QVector<long long> &divideSize, int &end)
{
    auto size = divideSize.back();
    divideSize.pop_back();
    auto start = end - size;
    auto min = A[start];
    auto max = A[start];
    for (int i = start + 1; i < end; i++) {
        if (A[i] < min) { min = A[i]; }
        else { if (A[i] > max) { max = A[i]; } }
    }
    if (min == max) {
        end = end - size;
    } else {
        int p = 0;
        QVector<QVector<long long>> bucket(size);
        for (int i = 0; i < size; i++) {
            bucket[i] = QVector<long long>();
        }
        for (int i = start; i < end; i++) {
            p = std::floor((1. * (A[i] - min) / (max - min)) * (size - 1));
            bucket[p].push_back(A[i]);
        }
        for (int i = 0; i < size; i++) {
            if (!bucket[i].empty()) {
                for (int j = 0; j < bucket[i].size(); ++j) { A[start++] = bucket[i][j]; }
                divideSize.push_back(bucket[i].size());
            }
        }
    }
}

void MainWindow::interpolationSort(QVector<long long> &arr, QString &text)
{
    long long step = 1;
    QVector<long long> divideSize;
    int end = arr.size();
    divideSize.push_back(end);
    while (!divideSize.empty()) {
        divide(arr, divideSize, end);
        printArr(arr, "sort, step " + QString::number(step++) + ": ", text);
    }
}


