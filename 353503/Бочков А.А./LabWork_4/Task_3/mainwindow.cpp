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
    /*std::vector<int> q;
    //myvector<int> y;
    for (i = 0; i < 10; i++) {
        q.insert(q.cbegin(), i);
        //y.insert(y.cbegin(), i);
    }
    for (i = 0; i < q.size(); i++) {
        qDebug() << q[i];
    }
    //qDebug() << y.size();
    /*for (i = 0; i < y.size(); i++) {
        qDebug() << y[i];
    }
    qDebug() << 1;*/
    //a = new myvector<double>();
    if (k == 0) {
        ui->textBrowser->clear();
        //qDebug() << 1;
        n = ui->lineEdit_2->text().toDouble(&ok);
        if (!ok || n <= 0) {
            ui->textBrowser->clear();
            ui->textBrowser->append("Error, try again");
            //qDebug() << 2;
            return;
            //ui->lineEdit_2->setEnabled(false);
            //ui->pushButton_2->setEnabled(false);
        }
        ui->lineEdit_2->setText("");
        ui->lineEdit->setText("Введите элемент массива");
        k++;
    } else {
        //for (i = 0; i < n; i++) {
        //cin >> x;
        x = ui->lineEdit_2->text().toDouble(&ok);
        if (!ok) {
            ui->textBrowser->clear();
            ui->textBrowser->append("Error, try again");
            return;
            //ui->lineEdit_2->setEnabled(false);
            //ui->pushButton_2->setEnabled(false);
        }
        k++;
        ui->lineEdit_2->setText("");
        //qDebug() << 1;
        a.push_back(x);
        //qDebug() << 2;
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
            ui->textBrowser->append("Изначальный массив");
            for (i = 0; i < a.size(); i++) {
                ui->textBrowser->append(QString::number(a[i]));
            }
            ui->textBrowser->append("Получившийся массив");
            for (i = 0; i < b.size(); i++) {
                ui->textBrowser->append(QString::number(b[i]));
            }
            a.clear();
            b.clear();
            ui->lineEdit->setText("Введите новый размер массива");
        }
    }
    //qDebug() << 2;
}
