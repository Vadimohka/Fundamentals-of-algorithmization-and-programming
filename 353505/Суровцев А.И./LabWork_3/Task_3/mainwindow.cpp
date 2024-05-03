#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(400, 150);
    setFixedSize(400, 150);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int temp = ui->spinBox->value();
    int ans = inv.invert(temp);
    if (ans != -1) ui->label_ans->setText("Ответ: " + QString::number(ans));
    else ui->label_ans->setText("Вы обманули и ввели 0, низя так-_-");
}
