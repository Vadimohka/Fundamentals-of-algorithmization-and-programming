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
    ui->searchButton->setEnabled(false);
    ui->searchEdit->setEnabled(false);
    connect(ui->searchButton, &QPushButton::clicked, this, &MainWindow::click_search);
}


void MainWindow::click_start(){
    bool ok;
    ui->NumEdit->setEnabled(false);
    ui->ArrayEdit->setEnabled(false);
    ui->start->setEnabled(false);
    ui->searchButton->setEnabled(false);
    ui->searchEdit->setEnabled(false);
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
                int max = -INT32_MIN;
                for (int i = 0; i < n; i++){
                    max = max > arr[i] ? max : arr[i];
                }
                sort::quick_sort(arr, 0, n-1, max, rect, 400, 150, this, n);
                ui->searchButton->setEnabled(true);
                ui->searchEdit->setEnabled(true);
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




void MainWindow::click_search(){
    bool ok;
    int k = ui->searchEdit->text().toInt(&ok);
    if (k < 0){
        ok = false;
    }
    if (ok){
        int buf = sort::binsearch(arr, 0, n-1, k);
        QString str = "index_search_value:";
        str += " " + QString::number(buf);
        ui->label_search->setText(str);
        str = "binpow " + QString::number(sort::binpow(buf,n,k));
        ui->label_4->setText(str);
    }
    else
    {
        QMessageBox::critical(nullptr, "Ошибка", "Некорректное число!");
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

