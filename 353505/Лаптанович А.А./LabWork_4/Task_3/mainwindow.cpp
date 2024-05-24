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

void MainWindow::on_pushButton_enter_clicked()
{
    if (ui->Message->text() == "Введите n:"){
        n = ui->spinBox->value();
        arr.resize(n);
        ui->spinBox->setMinimum(-2147483647);
        ui->Message->setText("Введите элемент № " + QString::number(enterI + 1) + ":");
        ui->label_n->setText("n: " + QString::number(n));
    } else{
        arr[enterI] = ui->spinBox->value();

        if (enterI == 0){
            ui->textEdit->setVisible(true);
            ui->textEdit->setText("Массив: " + QString::number(arr[0]));
        }
        else
            ui->textEdit->setText(ui->textEdit->toPlainText() + " " + QString::number(arr[enterI]));

        ++enterI;

        if (enterI != n)
            ui->Message->setText("Введите элемент № " + QString::number(enterI + 1) + ":");
        else{
            //ui->Message->setText("Input ended");
            ui->spinBox->setEnabled(false);
            ui->pushButton_enter->setEnabled(false);
            QString add = "Ответ: ";
            long long a, b, c;
            for (long long i = 2; i < arr.size(); i += 3) {
                a = arr[i - 2];
                b = arr[i - 1];
                c = arr[i    ];
                if (a > b) std::swap(a, b);
                if (a > c) std::swap(a, c);
                if (b > c) std::swap(b, c);

                add += QString::number(b) + " ";
            }
            long long sum = 0;
            if (arr.size() % 3){
                for (long long i = arr.size() - arr.size() % 3; i < arr.size(); ++i) {
                    sum += arr[i];
                }
                add += QString::number(qRound((1. * sum) / (arr.size() % 3))) + " ";
            }
            ui->textEdit->setText(ui->textEdit->toPlainText() + "\n" + add);

        }
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
    ui->Message->setText("Введите n:");
}
