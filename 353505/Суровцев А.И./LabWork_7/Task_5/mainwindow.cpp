#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(650, 223);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printDeque()
{
    ui->ln_ans->clear();
    if (dek.size() != 0){
        auto it = dek.begin();
        QString text;
        do {
            text += QString::number(*it) + " ";
            ++it;
        } while (it != dek.end());
        ui->ln_ans->setText(text);
    }
}

void MainWindow::on_bnt_push_back_clicked()
{
    dek.push_back(ui->spb_val->value());
    printDeque();
}


void MainWindow::on_bnt_push_front_clicked()
{
    dek.push_front(ui->spb_val->value());
    printDeque();
}


void MainWindow::on_bnt_pop_back_clicked()
{
    if (dek.size() == 0) QMessageBox::warning(nullptr, "Warning                                                                    ", "На данный момент Deque пустой, добавьте что-нибудь!!!");
    else {
        dek.pop_back();
        printDeque();
    }
}


void MainWindow::on_bnt_pop_front_clicked()
{
    if (dek.size() == 0) QMessageBox::warning(nullptr, "Warning                                                                    ", "На данный момент Deque пустой, добавьте что-нибудь!!!");
    else {
        dek.pop_front();
        printDeque();
    }
}

