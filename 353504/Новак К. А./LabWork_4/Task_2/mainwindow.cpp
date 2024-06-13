#include "mainwindow.h"
#include "ui_mainwindow.h"

QString MainWindow::vectorToString(const QVector<int> &arr) {
    QStringList list;
    for (int num : arr) {
        list << QString::number(num);
    }
    return list.join(", ");
}

void MainWindow::interpolationSort(QVector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int j = i + 1;

        while (j > 0 && arr[j - 1] > arr[j]) {
            std::swap(arr[j], arr[j - 1]);
            j--;

            ui->output->append("Interpolation sort step: " + vectorToString(arr));
        }
    }
}

int MainWindow::binpow(int digit, int powder, int mod) {
    digit %= mod;
    int result = 1;

    while (powder > 0) {
        if (powder & 1)
            result = (result * digit) % mod;

        digit = (digit * digit) % mod;
        powder >>= 1;
    }

    return result;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sortButton_clicked() {
    QString input = ui->arrayInput->text();
    QStringList numbers = input.split(" ");
    for (const QString &number : numbers) {
        arr.append(number.toInt());
    }

    QVector<int> arr_copy;
    QElapsedTimer timer;
    qint64 nanoSec;

    arr_copy = arr;
    timer.start();
    interpolationSort(arr_copy);
    nanoSec = timer.nsecsElapsed();
    ui->output->append("Interpolation sorted array: " + vectorToString(arr_copy));
    ui->output->append("Interpolation sort time: " + QString::number(nanoSec) + " ns");
}

void MainWindow::on_bin_powButton_clicked()
{
    int digit = ui->digitInput->text().toInt();
    int powder = arr.size() - 1;
    int mod = 1000000007;

    int result = binpow(digit, powder, mod);
    ui->output->append("Result of binpow: " + QString::number(result));
}
