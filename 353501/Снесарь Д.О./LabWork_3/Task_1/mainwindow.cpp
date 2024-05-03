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

QString MainWindow::iToBin(double x)
{

        if (x == 0) {
            return "0";
        } else if ((x / 2) - floor(x/2) == 0) {
            return iToBin(floor(x / 2)) + "0";
        } else {
            return iToBin(floor(x / 2)) + "1";
        }

}

QString MainWindow::dToBin(double x)
{
    QString binary;
    int c = 0;
    while (c < 1000000000 && x > 0)
    {
        c++;
        x *= 2;
        if (x >= 1)
        {
            binary.append('1');
            x -= 1;
        }
        else
        {
            binary.append('0');
        }
    }

    return binary;
}

QString MainWindow::toIEEE754(QString integer, QString fractional, bool sign)
{
    QString result;
    sign ? result.append('1') : result.append('0');
    result.append(" ");
    long long exp = +1023;
    if(integer.length() >= 1 && integer!="0")
    {

        exp += integer.length() - 1;
        QString expS = "";
        expS = expS + iToBin(exp);
        if(expS[0] != "1"){
            expS.remove(0, 1);
        }
        while(expS.length() < 11){
            expS ="0" + expS;
        }
        result.append(expS);
        result.append(" ");
        result.append(integer.mid(1, integer.length() - 1));

        result.append(fractional.mid(0, 64 + 2 - result.length() ));

        while (result.length() < 64 + 2) {
            result.append('0');
        }

        result =result.left(64 + 2);

    }
    else
    {
        int i = 0;
        while(fractional[i] != '1'){
            i++;
        }
        exp += -i - 1;
        QString expS = "";
        expS = expS + iToBin(exp);
        if(expS[0] != "1"){
            expS.remove(0, 1);
        }
        while(expS.length() < 11){
            expS ="0" + expS;
        }
        result.append(expS);
        result.append(" ");

        result.append(fractional.mid(i + 1, fractional.length() - i));
        while (result.length() < 64 + 2) {
            result.append('0');
        }

        result = result.left(64 + 2);


    }

    return result;
}


void MainWindow::on_pushButton_clicked()
{

    double x = ui->lineEdit->text().toDouble();
    if(ui->lineEdit->text() == "0")
        ui->textBrowser->setText("0 00000000000 0000000000000000000000000000000000000000000000000000");
    else
    {
        bool sign = x >= 0 ? 0 : 1;
        x = qAbs(x);

        QString intS = iToBin(floor(x));
        if(intS.size() != 1)
            intS.remove(0, 1);
        QString dS = dToBin(x - floor(x));
        QString res = toIEEE754(intS, dS, sign);
        ui->textBrowser->setText(res);
    }
}

