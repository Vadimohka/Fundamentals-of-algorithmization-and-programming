#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(400, 165);
    setFixedSize(600,300);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int m = ui->spinBox->value();
    int n = ui->spinBox_2->value();
    if (n < 0 || m < 0) ui->error_label->setText("Неверный ввод");
    else if (m > 5 || (m == 4 && n > 1) || (m == 3 && n > 2046) || (m == 2 && n > pow(2,63)-3)) {
        ui->error_label->setText("Введены слишком большие значения");
        QMessageBox::warning(this, tr("Ошибка"), tr("Введены слишком большие значения!!!"));
    }
    else {
        ui->label_3->setText("Ответ: " + QString::number(func.count(m, n)));
    }
}
