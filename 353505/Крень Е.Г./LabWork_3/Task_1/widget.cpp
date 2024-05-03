#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    validator->setDecimals(15);
    validator->setNotation(QDoubleValidator::ScientificNotation);

    ui->inputLineEdit->setValidator(validator);

    connect(ui->pushButton, &QPushButton::clicked, this, [this](){

        QString stringNumber = ui->inputLineEdit->text();
        bool isMinus = stringNumber[0]== '-';
        if(stringNumber[0]== '-'||stringNumber[0]== '+'){
            stringNumber.removeFirst();
        }

        QString intPart = "";
        QString floatPart = "";
        int exponent = 0;
        if (stringNumber.contains(",")){
            intPart = stringNumber.split(",")[0];
            floatPart = stringNumber.split(",")[1];
            if(floatPart.contains("e")){
                exponent = floatPart.split("e")[1].toInt();
                floatPart = floatPart.split("e")[0];
            }
        }
        else{
            intPart = stringNumber;
            floatPart = "0";
            if(stringNumber.contains("e")){
                intPart = stringNumber.split("e")[0];
                exponent = stringNumber.split("e")[1].toInt();
            }
        }

        if(exponent>308||exponent<-308) {
            ui->ansLabel->setText("Слишком большая степень");
            return;
        }

        if(exponent<0){

            for(int i = 0; i<-exponent; ++i){
                floatPart.push_front(intPart[intPart.size()-1]);
                intPart.removeLast();
                if(intPart=="")intPart="0";
            }

        }
        else{

        for(int i = 0; i < exponent; ++i){
            intPart.append(floatPart[0]);
            floatPart.removeFirst();
            if(floatPart=="")floatPart = "0";
        }
        }

        QString intAns = intToBinary(intPart);
        std::reverse(intAns.begin(), intAns.end());
        QString DoubleAns = floatToBinary(floatPart, 0);
        std::reverse(DoubleAns.begin(), DoubleAns.end());

        if(isMinus) intAns.push_front('-');

        ui->ansLabel->setText("Ответ: " + intAns + (DoubleAns ==""? "" : ("," + floatToBinary(floatPart, 0))));

    });
}

Widget::~Widget()
{
    delete ui;
}


QString Widget::intToBinary(QString stringNumber)
{
    if (stringNumber == "0" || stringNumber == "1") return stringNumber;
    QString str = stringDivisions(stringNumber);
    return (QString(stringNumber[stringNumber.size() - 1]).toInt() % 2 == 0? "0" : "1") + intToBinary(str);
}

QString Widget::floatToBinary(QString stringNumber, int Discharge)
{
    if (Discharge == 64) return "";
    bool flag = true;
    for (int i = 0; i < stringNumber.size(); ++i){
        if (stringNumber[i] != '0') flag = false;
    }
    if (flag) return "";
    stringNumber = "0" + stringNumber;
    stringNumber = stringMultiply(stringNumber);
    QString firstSumbol = stringNumber[0];
    stringNumber.replace(0, 1, "");
    return firstSumbol + floatToBinary(stringNumber, Discharge + 1);
}

QString Widget::stringDivisions(QString str)
{
    if (QString(str[str.size() - 1]).toInt() % 2 == 1) str[str.size() - 1] = char(48 + QString(str[str.size() - 1]).toInt() - 1);
    QString ans = "";
    for (int i = 0; i < str.size(); ++i) ans += "0";
    int  step = 0;
    for (long long i = 0; i < str.size(); i++)
    {
        int number = QString(str[i]).toInt();
        number += 10 * step;
        step = number % 2;
        number /= 2;
        ans[i] = char(number + 48);

    }
    while (ans[0] == '0') ans.replace(0, 1, "");
    return ans;
}

QString Widget::stringMultiply(QString stringNumber)
{
    int step = 0;
    for (int i = stringNumber.size() - 1; i >= 0; --i){
        int number = QString(stringNumber[i]).toInt();
        number *= 2;
        number += step;
        step = number / 10;
        number %= 10;
        stringNumber[i] = char(number + 48);
    }
    return stringNumber;
}
