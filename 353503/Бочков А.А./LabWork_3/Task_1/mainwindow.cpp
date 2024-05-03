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

QString inttobin(int x, QString ans)
{
    if (x == 0) {
        return ans;
    }
    ans = QString::number(x % 2) + ans;
    return inttobin(x / 2, ans);
}

QString doubletobin(double x, QString ans)
{
    if (x == 0 || ans.size() == 10) {
        return ans;
    }
    x *= 2;
    double y;
    double z;

    y = modf(x, &z);
    qDebug() << x << y << z;
    ans = ans + QString::number(z);
    return doubletobin(y, ans);
}

void MainWindow::on_pushButton_clicked()
{
    x = ui->lineEdit_2->text().toDouble(&ok);
    if (!ok || x < 0) {
        msgBox.setText("Неправильный ввод");
        msgBox.exec();
    } else {
        double y;
        double z;
        //double *i = &z;
        y = modf(x, &z);
        QString check = doubletobin(y, "");
        if (check == "") {
            ui->lineEdit_3->setText(inttobin(z, ""));
        } else {
            ui->lineEdit_3->setText(inttobin(z, "") + "." + doubletobin(y, ""));
        }
    }
    //ui->lineEdit_2->setText("");
}
