#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRegularExpressionValidator>
#include <QRegularExpression>

bool MainWindow::isnull(QString n){
    for (auto u : n)
        if (u != '0')
            return false;
    return true;
}

QString MainWindow::multiply2(const QString& numberString) {
    QString result;
    int carry = 0;

    for (int i = numberString.length() - 1; i >= 0; --i) {
        int digit = (numberString.at(i).digitValue() * 2 + carry) % 10;
        carry = (numberString.at(i).digitValue() * 2 + carry) / 10;
        result.prepend(QString::number(digit));
    }

    if (carry > 0)
        result.prepend(QString::number(carry));
    // qDebug() << result;
    // qDebug();
    return result;
}

QString MainWindow::div2(QString num){
    // qDebug() << num;
    QString result;
    int carry = 0;

    for (int i = 0; i < num.length(); ++i) {
        int digit = (num.at(i).digitValue() + carry * 10) / 2;
        carry = (num.at(i).digitValue() + carry * 10) % 2;
        result.append(QString::number(digit));
    }

    result.remove(0, result.indexOf(QRegularExpression("[^0]")));
    // qDebug() << result;
    return result.isEmpty() ? "0" : result;
}

QString MainWindow::intToBinary(QString num) {
    if (num == "0" || num == "")
        return "0";
    int l = QString(num.back()).toInt();
    // qDebug() << l;
    QString ans = intToBinary(div2(num)) + QString::number(l % 2);
    ans.remove(0, ans.indexOf(QRegularExpression("[^0]")));
    return ans;
}

QString MainWindow::fracToBinary(QString num, long long pres) {
    // num.remove(0, num.indexOf(QRegularExpression("[^0]")));
    // qDebug() << num;
    if (num == "0" || num == "" || pres == 0)
        return "0";
    int l = num.size();
    num = multiply2(num);
    QChar aa = (num.size() == l ? '0' : '1');
    if (num.size() != l)
        num.remove(0, 1);
    QString ans = QString(aa) + fracToBinary(num, pres - 1);
    // ans.remove(0, ans.indexOf(QRegularExpression("[^0]")));
    return ans;
}




QString MainWindow::doubleToBinary(QString str) {
    str.replace(',', '.');
    QString i_str = str.left(str.indexOf('.')), f_str = str.mid(str.lastIndexOf('.') + 1);
    // qDebug() << str;
    // qDebug() << i_str;
    // qDebug() << f_str;
    // qDebug();
    if (str.indexOf('.') != -1 && !isnull(f_str))
        return intToBinary(i_str) + '.' + fracToBinary(f_str, f_str.size() * 10);
    else if (isnull(f_str))
        return intToBinary(i_str)+".0";
    else
        return intToBinary(i_str);
}

QString MainWindow::procOut(QString & str) {
    long long n = str.size();
    str.insert(0, '\n');
    for(long long i = 1; i * 100 < n; ++i){
        str.insert(i * 100 + i, '\n');
    }
    return str;
}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->lineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("^[-+]?[0-9]{1,310}(?:[.,][0-9]{1,310})?$"),this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString str = ui->lineEdit->text();
    if (str == ""){
        ui->ans->setText("Fill some number");
    } else {
        ui->ans->setText("Processing...");
        QCoreApplication::processEvents();
        str = doubleToBinary(str);
        // ui->lineEdit->setText(str);
        str = procOut(str);
        // ui->lineEdit_2->setText(str);
        ui->ans->setText(str);
    }
}
