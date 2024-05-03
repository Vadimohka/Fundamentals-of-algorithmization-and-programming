#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::TranslateReal(double num, QString ans) {

    if (num <= 0) return ans;
    double сoefficient = num * 2;
    if (сoefficient >= 1)
    {
        return TranslateReal(сoefficient - 1, ans.append("1"));
    }
    else
    {
        return TranslateReal(сoefficient, ans.append("0"));
    }
}

QString MainWindow::TranslateWhole(int num, QString ans) {

    if (num <= 0) {
        return ans;
    }
    else {
        return TranslateWhole(num / 2, ans + QString::number(num % 2));
    }
}


QString MainWindow::Translate(double num) {
    double numReal;
    int numWhole;
    numWhole = qFloor(num);
    numReal = num - numWhole;
    QString str = TranslateWhole(numWhole, "");
    std::reverse(str.begin(), str.end());
    QString answer;
    if (str == "") {
        answer = "0";
    }
    else {
        answer = str;
    }
    answer.append(".(");
    if (TranslateReal(numReal, "") == "") {
        answer.append("0");
    }
    else {
        answer.append(TranslateReal(numReal, ""));
    }

    return answer + ")";

}

void MainWindow::OutputData(QString numT) {

    ui->textEdit->setPlainText(numT);
}

bool MainWindow::InputValidation(QString num) {

    int size = num.size();
    bool dot = false;
    for (int i = 0; i < size; ++i) {
        if (num.at(i) == '.' && dot) {
            return false;
        }
        else {
            dot = true;
            continue;
        }
        if (!(num.at(i) >= '0' && num.at(i) <= '9')) {
            return false;
        }
    }
    if (num.toDouble() > 1000000) {
        return false;
    }

    return true;
}

void MainWindow::on_pushButton_clicked()
{
    QString num = ui->lineEdit->text();
    double NewNum = num.toDouble();

    // if(InputValidation(num)) {
    //     newNum = num.toDouble();
    // }
    // else {
    //     QMessageBox::warning(this, "Внимание", "Введено неккорректное чилсо");
    //     return;
    // }

    OutputData(Translate(NewNum));
}

