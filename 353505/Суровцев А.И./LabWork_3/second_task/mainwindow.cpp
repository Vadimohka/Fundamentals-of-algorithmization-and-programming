#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(400, 165);
    setFixedSize(400,165);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int m = ui->spinBox->value();
    int n = ui->spinBox_2->value();
    if (n < 0 || m < 0) ui->error_label->setText("Введены неправильные значения, введите снова!!!");
    else if (m > 4 || (m == 4 && n > 0) || (m == 3 && n > 12) || (n > 300000)) {
        ui->error_label->setText("Введены слишком большие значения, введите снова!!!");
        QMessageBox::warning(this, tr("Ошибка"), tr("Введены слишком большие значения!!!"));
    }
    else {
        ui->label_3->setText("Ответ: " + QString::number(func.solve(m, n)));
    }
}
