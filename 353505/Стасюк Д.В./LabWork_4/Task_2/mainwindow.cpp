#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::printArr(QVector<long long> arr, QString pref, QString & out){
    out += pref;
    for (auto &i : arr)
        out += QString::number(i) + " ";
    out += "\n";
}

unsigned long long MainWindow::bin_mul(unsigned long long a, unsigned long long n, unsigned long long m) {
    unsigned long long res = 0;
    while (n) {
        if (n & 1)
            res += a;
        if (res>=m) {
            res %= m;
        }
        a += a;
        a %= m;
        n >>= 1;
    }
    return res;
}

unsigned long long MainWindow::binpow(unsigned long long a, unsigned long long n, unsigned long long m) {
    unsigned long long res = 1;
    while (n) {
        if (n & 1)
            res = bin_mul(res, a, m);
        a = bin_mul(a, a, m);
        n >>= 1;
    }
    return res;
}

long long MainWindow::binSearch(QVector<long long> & a, long long find) {
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
    \
        if (a[l] == find) {
        return l;
    } else {
        return -2;
    }
}

void MainWindow::divide(QVector<long long>& A, QVector<long long>& divideSize, int & end) {
    auto size = divideSize.back();
    divideSize.pop_back();
    auto start = end - size;
    auto min = A[start];
    auto max = A[start];
    for (int i = start + 1; i < end; i++) {
        if (A[i] < min) { min = A[i]; }
        else { if (A[i] > max) { max = A[i]; } }
    }
    if (min == max)
    {end = end - size; }
    else {
        int p = 0;
        QVector<QVector<long long>> bucket(size);
        for (int i = 0; i < size; i++) {
            bucket[i] = QVector<long long>();
        }
        for (int i = start; i < end; i++) {
            p = std::floor(( 1.*(A[i] - min ) / (max - min ) ) * (size - 1 ));
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

void MainWindow::interpolationSort(QVector<long long>& arr, QString & text) {
    long long step = 1;
    QVector<long long> divideSize;
    int end = arr.size();
    divideSize.push_back(end);
    while (!divideSize.empty()) {
        divide(arr, divideSize, end);
        printArr(arr, "sort, step " + QString::number(step++) + ": ", text);
    }
}

void MainWindow::on_pushButton_restart_clicked()
{
    ui->spinBox->setEnabled(true);
    ui->pushButton_enter->setEnabled(true);
    ui->spinBox->setMinimum(1);
    arr.clear();
    enterI = 0;
    n = 0;
    ui->textEdit->setText("");
    ui->textEdit->setReadOnly(true);
    ui->label_n->setText("");
    ui->label_mod->setText("");
    ui->label_ans->setText("");
    ui->Message->setText("Enter n:");
}


void MainWindow::on_pushButton_enter_clicked()
{
    if (ui->Message->text() == "Enter n:"){
        n = ui->spinBox->value();
        arr.resize(n);
        ui->spinBox->setMinimum(-2147483647);
        ui->Message->setText("Enter element № " + QString::number(enterI + 1) + ":");
        ui->label_n->setText("n: " + QString::number(n));
    } else if (ui->Message->text() == "Enter element to find"){
        find = ui->spinBox->value();
        ui->Message->setText("Enter MOD");
        ui->spinBox->setMinimum(1);
    } else if (ui->Message->text() == "Enter MOD"){
        mod = ui->spinBox->value();
        ui->label_mod->setText("mod: " + QString::number(mod));
        ui->Message->setText("Input ended");
        ui->spinBox->setEnabled(false);
        ui->pushButton_enter->setEnabled(false);
        long long bp = binSearch(arr, find) + 1;
        if (bp != -1){
            ui->label_ans->setText("ans: " + QString::number(binpow(bp % mod, n % mod, mod)));
        } else {
            ui->label_ans->setText("ans: no such item in array");
        }
    }
    else{
        arr[enterI] = ui->spinBox->value();

        if (enterI == 0){
            ui->textEdit->setVisible(true);
            ui->textEdit->setText("arr:        " + QString::number(arr[0]));
        }
        else
            ui->textEdit->setText(ui->textEdit->toPlainText() + " " + QString::number(arr[enterI]));
        ++enterI;
        if (enterI != n)
            ui->Message->setText("Enter element № " + QString::number(enterI + 1) + ":");
        else{
            ui->Message->setText("Enter element to find");
            QString text;
            interpolationSort(arr, text);
            ui->textEdit->setText(ui->textEdit->toPlainText() + "\n" + text);
            QString add = "Sorted arr: ";
            for (auto &i : arr) {
                add += QString::number(i) + " ";
            }
            ui->textEdit->setText(ui->textEdit->toPlainText() + add);

        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
