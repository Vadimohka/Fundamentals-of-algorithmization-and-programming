#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_pushButton_clicked()
{
    if (k == 0) {
        ui->textBrowser->clear();
        n = ui->lineEdit_2->text().toDouble(&ok);
        if (!ok || n <= 0) {
            ui->textBrowser->clear();
            ui->textBrowser->append("Неправильно");
            return;
        }
        ui->lineEdit_2->setText("");
        ui->lineEdit->setText("Введите элемент массива");
        k++;
    } else {
        x = ui->lineEdit_2->text().toDouble(&ok);
        if (!ok) {
            ui->textBrowser->clear();
            ui->textBrowser->append("Неправильно");
            return;
        }
        k++;
        ui->lineEdit_2->setText("");
        a.push_back(x);
        if (k == n + 1) {
            k = 0;
            for (i = 0; i < n / 3; i++) {
                b.push_back(a[i * 3] + a[i * 3 + 1] + a[i * 3 + 2]
                            - std::max(a[i * 3], std::max(a[i * 3 + 1], a[i * 3 + 2]))
                            - std::min(a[i * 3], std::min(a[i * 3 + 1], a[i * 3 + 2])));
            }
            if (n % 3 == 1) {
                b.push_back(a[n - 1]);
            }
            if (n % 3 == 2) {
                b.push_back((a[n - 1] + a[n - 2]) / 2);
            }
            ui->textBrowser->clear();
            ui->textBrowser->append("Начальный массив");
            for (i = 0; i < a.size(); i++) {
                ui->textBrowser->append(QString::number(a[i]));
            }
            ui->textBrowser->append("Получившийся массив");
            for (i = 0; i < b.size(); i++) {
                ui->textBrowser->append(QString::number(b[i]));
            }
            a.clear();
            b.clear();
            ui->lineEdit->setText("Введите размер массива");
        }
    }
}
