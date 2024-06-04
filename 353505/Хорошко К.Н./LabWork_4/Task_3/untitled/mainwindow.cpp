#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setMinimumSize(1300, 900);
    ui->setupUi(this);

    connect(ui->start, &QPushButton::clicked, this, &MainWindow::click_start);
}


void MainWindow::click_start(){
    bool ok;
    ui->NumEdit->setEnabled(false);
    ui->ArrayEdit->setEnabled(false);
    ui->start->setEnabled(false);
    n = ui->NumEdit->text().toInt(&ok);
    if (n < 0){
        ok = false;
    }
    if (ok){
        arr = new int[n];
        int k = 0;
        QString str = ui->ArrayEdit->text();
        int buf = 0;
        bool in = true;
        for (int i = 0; i < str.size(); i++){
            if (i == str.size()-1){
                if (str[i] >= '0' && str[i] <= '9'){
                    buf *= 10;
                    buf += str[i].digitValue();
                    arr[k] = buf;
                    buf = 0;
                    k++;
                }
                else{
                    in = false;
                    QMessageBox::critical(nullptr, "Ошибка", "Некорректный ввод массива!");
                }
            }else{
                if (str[i] >= '0' && str[i] <= '9'){
                    buf *= 10;
                    buf += str[i].digitValue();
                }
                else
                {
                    arr[k] = buf;
                    buf = 0;
                    k++;
                    if (str[i] != ','){
                        in = false;
                        QMessageBox::critical(nullptr, "Ошибка", "Некорректный ввод массива!");
                    }
                    else if (!(str[i] == ',' && i > 0 && str[i-1] >= '0' && str[i-1] <= '9')){
                        in = false;
                        QMessageBox::critical(nullptr, "Ошибка", "Некорректный ввод массива!");
                    }
                }
            }
        }
        if (in){
            if (k == n){
                sort::quick_sort(arr, 0, n-1);
                while (n > 0){
                    int a[3];
                    int buf = 0;
                    if (n > 3){
                    for (int i = n-1; i > n-4; i--){
                        a[3-n+i] = arr[i];
                    }
                    }
                    if (n > 3){
                    n -= 3;
                    sort::quick_sort(a, 0, 2);
                    buf = a[1];
                    }
                    else{
                    for (int i = n-1; i >= 0; i--){
                            buf += arr[i];
                    }
                    buf /= n;
                    n = 0;
                    }
                    rect.push_back(buf);
                }

                QString st;
                for (int i = 0; i < rect.size(); i++){
                    if (i != rect.size()-1)
                    st += QString::number(rect[i]) + ",";
                    else
                    st += QString::number(rect[i]);
                }
                ui->label_ans->setText(st);
                ui->NumEdit->setEnabled(true);
                ui->ArrayEdit->setEnabled(true);
                ui->start->setEnabled(true);
            }
            else{
                if (k < n){
                    QMessageBox::critical(nullptr, "Ошибка", "Некорректный ввод массива, недостаточно элементов!");
                }
                else {
                    QMessageBox::critical(nullptr, "Ошибка", "Некорректный ввод массива, слишком много элементов!");
                }
            }
        }
    }
    else
    {
        QMessageBox::critical(nullptr, "Ошибка", "Некорректное число!");
    }
    ui->NumEdit->setEnabled(true);
    ui->ArrayEdit->setEnabled(true);
    ui->start->setEnabled(true);
}



MainWindow::~MainWindow()
{
    delete ui;
}

