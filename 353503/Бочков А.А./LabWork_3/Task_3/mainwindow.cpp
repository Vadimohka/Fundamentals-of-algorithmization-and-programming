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

int revers(int x, int ans)
{
    if (x == 0) {
        return ans;
    }
    ans = ans * 10 + x % 10;
    return revers(x / 10, ans);
}

void MainWindow::on_pushButton_clicked()
{
    x = ui->lineEdit_2->text().toInt(&ok);
    if (ok) {
        ui->lineEdit_3->setText(QString::number(revers(x, 0)));
    } else {
        msgBox.setText("Неправильный ввод");
        msgBox.exec();
    }
}
