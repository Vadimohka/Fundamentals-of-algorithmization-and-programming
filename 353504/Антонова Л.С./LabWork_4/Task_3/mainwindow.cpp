#include "mainwindow.h"
#include "ui_mainwindow.h"

QString MainWindow::vectorToString(const QVector<int> &arr) {
    QStringList list;
    for (int num : arr) {
        list << QString::number(num);
    }
    return list.join(", ");
}

QVector<int> MainWindow::calculateMedians(QVector<int> &arr) {
    QVector<int> medians;
    for (int i = 0; i < arr.size(); i += 3) {
        QVector<int> subArr;
        for (int j = i; j < i + 3 && j < arr.size(); ++j) {
            subArr.push_back(arr[j]);
        }
        std::sort(subArr.begin(), subArr.end());

        if (subArr.size() == 3) {
            medians.push_back(subArr[1]);
        } else {
            int sum = 0;
            for (int num : subArr) {
                sum += num;
            }
            medians.push_back(sum / subArr.size());
        }
    }
    return medians;
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

void MainWindow::on_mediansButton_clicked()
{
    QString input = ui->arrayInput->text();
    QStringList numbers = input.split(" ");
    for (const QString &number : numbers) {
        arr.append(number.toInt());
    }

    QVector<int> arr_copy;
    arr_copy = calculateMedians(arr);

    ui->output->append("Medians array: " + vectorToString(arr_copy));
}

