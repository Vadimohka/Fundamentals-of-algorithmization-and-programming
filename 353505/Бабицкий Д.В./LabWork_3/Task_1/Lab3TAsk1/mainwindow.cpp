#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    button->setParent(this);
    button->setGeometry(300,350,100,30);
    button->setText("Рассчитать");

    informationEdit->setParent(this);
    informationEdit->setGeometry(0, 40, 500, 30);
    informationEdit->setValidator(val);

    ansEdit->setParent(this);
    ansEdit->setGeometry(0, 100, 1000, 30);
    ansEdit->setEnabled(false);
    ansEdit->setText("Ответ: ");

    QPushButton::connect(button, SIGNAL(pressed()), this, SLOT(on_button_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::intToBinary(QString numb)
{
    if (numb == "0") return "0";
    if (numb == "1") return "1";
    if (numb == "2") return "01";
    QString str = stringDivisions(numb);
    return (QString(numb[numb.size() - 1]).toInt() % 2 == 0? "0" : "1") + intToBinary(str);
}

QString MainWindow::DoubleToBinary(QString numb, int Discharge)
{
    if (Discharge == 64) return "";
    bool flag = true;
    for (int i = 0; i < numb.size(); ++i){
        if (numb[i] != '0') flag = false;
    }
    if (flag) return "";
    numb = "0" + numb;
    numb = stringMultiplication(numb);
    QString firstSumbol = numb[0];
    numb.replace(0, 1, "");
    return firstSumbol + DoubleToBinary(numb, Discharge + 1);
}

bool MainWindow::comparison(QString numb1, QString numb2)
{
    if (numb1.size() > numb2.size()) return true;
    else if (numb1.size() < numb2.size()) return false;
    for (int i = 0; i < numb2.size(); ++i){
        if (QString(numb1[i]).toInt() >  QString(numb2[i]).toInt()) return true;
        else if (QString(numb1[i]).toInt() <  QString(numb2[i]).toInt()) return false;
    }
    return false;
}

QString MainWindow::stringDivisions(QString str)
{
    if (QString(str[str.size() - 1]).toInt() % 2 == 1) str[str.size() - 1] = char(48 + QString(str[str.size() - 1]).toInt() - 1);
    QString ans = "";
    for (int i = 0; i < str.size(); ++i) ans += "0";
    int  d = 0;
    for (long long i = 0; i < str.size(); i++)
    {
        int numb = QString(str[i]).toInt();
        numb += 10 * d;
        d = numb % 2;
        numb /= 2;
        ans[i] = char(numb + 48);

    }
    while (ans[0] == '0') ans.replace(0, 1, "");
    return ans;
}

QString MainWindow::stringMultiplication(QString numb)
{
    int d = 0;
    for (int i = numb.size() - 1; i >= 0; --i){
        int number = QString(numb[i]).toInt();
        number *= 2;
        number += d;
        d = number / 10;
        number %= 10;
        numb[i] = char(number + 48);
    }
    return numb;
}






void MainWindow::on_button_clicked()
{
    QString numb = informationEdit->text();
    QString numb1 = "", numb2 = "";
    if (numb.contains(".")){
        numb1 = numb.split(".")[0];
        numb2 = numb.split(".")[1];
    }
    else{
        numb1 = numb;
        numb2 = "0";
    }
    QString intAns = intToBinary(numb1);
    std::reverse(intAns.begin(), intAns.end());
    QString DoubleAns = DoubleToBinary(numb2, 0);
    std::reverse(intAns.begin(), intAns.end());

    ansEdit->setText("Ответ: " + intAns + (DoubleAns ==""? "" : ("." + DoubleToBinary(numb2, 0))));
}
