#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //State 1
    State Belarus{
        10'000'000,
        100'001,
        '&',
        true,
        { "белорусы" },
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
    };
    QString qDigitsBelarus;
    for (int i = 0; i < 10; ++i) {
        if (i != 0)
            qDigitsBelarus += ' ';
        qDigitsBelarus += QString::number(Belarus.digits[i]);
    }
    QString state_1 = QString::number(Belarus.citizen) + '|'
            + QString::number(Belarus.money) + '|'
            + QString(Belarus.symbol) + '|'
            + QString::number(Belarus.exist) + '|'
            + QString(Belarus.nation) + '|'
            + qDigitsBelarus;

    ui->State_1->setText(state_1);

    //State 2
    State Neverland;
    Neverland.citizen = 12;
    Neverland.money = 0;
    Neverland.symbol = '*';
    Neverland.exist = false;
    strcpy(Neverland.nation, "неверлендцы");
    for (int i = 0; i < 5; ++i) {
        Neverland.digits[i] = i;
    }
    QString qDigitsNeverland;
    for (int i = 0; i < 5; ++i) {
        if (i != 0)
            qDigitsNeverland += ' ';
        qDigitsNeverland += QString::number(Neverland.digits[i]);
    }

    QString state_2 = QString::number(Neverland.citizen) + '|'
            + QString::number(Neverland.money) + '|'
            + QString(Neverland.symbol) + '|'
            + QString::number(Neverland.exist) + '|'
            + QString{Neverland.nation} + '|'
            + qDigitsNeverland;

    ui->State_2->setText(state_2);

    //State 4
    State USA;
    State *pUSA { &USA };
    pUSA->citizen = 300'000;
    pUSA->money = 100.995;
    pUSA->symbol = '$';
    pUSA->exist = true;
    strcpy(pUSA->nation, "американцы");
    for (int i = 0; i < 10; ++i) {
        pUSA->digits[i] = i;
    }
    QString qDigitsUSA;
    for (int i = 0; i < 10; ++i) {
        if (i != 0)
            qDigitsUSA += ' ';
        qDigitsUSA += QString::number(pUSA->digits[i]);
    }

    QString state_4 = QString::number(pUSA->citizen) + '|'
                      + QString::number(pUSA->money) + '|'
                      + QString(pUSA->symbol) + '|'
                      + QString::number(pUSA->exist) + '|'
                      + QString{pUSA->nation} + '|'
                      + qDigitsUSA;

    ui->State_4->setText(state_4);

    //State 5
    State Maya;
    State &refMaya {Maya};
    refMaya.citizen = 50'000;
    refMaya.money = 1'000;
    refMaya.symbol = '~';
    refMaya.exist = false;
    strcpy(refMaya.nation, "майа");
    for (int i = 0; i < 20; ++i) {
        refMaya.digits[i] = i;
    }
    QString qDigitsMaya;
    for (int i = 0; i < 20; ++i) {
        if (i != 0)
            qDigitsMaya += ' ';
        qDigitsMaya += QString::number(refMaya.digits[i]);
    }
    QString state_5 = QString::number(refMaya.citizen) + '|'
                      + QString::number(refMaya.money) + '|'
                      + QString(refMaya.symbol) + '|'
                      + QString::number(refMaya.exist) + '|'
                      + QString{refMaya.nation} + '|'
                      + qDigitsMaya;

    ui->State_5->setText(state_5);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked() {
    State MyState;

    QString citizen = ui->citizen_int->text();
    MyState.citizen = citizen.toUInt();

    QString money = ui->money_double->text();
    MyState.money = money.toDouble();

    QString symbol = ui->symbol_char->text();
    MyState.symbol = symbol.toStdString()[0];

    QString exist = ui->exist_bool->text();
    MyState.exist = exist.toUInt();

    QString qNation = ui->nation_char_m->text();
    std::string nation = qNation.toStdString();
    for (int i = 0; i < nation.size(); ++i) {
        MyState.nation[i] = nation[i];
    }

    QString qDigits = ui->digits_int_m->text();
    std::string digits = qDigits.toStdString();
    for (int i = 0, j = 0; i < digits.size(); ++i) {
        if (digits[i] != ' ') {
            MyState.digits[j] = digits[i];
            j += 2;
        }
    }

    QString result = citizen + '|' + money + '|' + symbol + '|' + exist + '|' + qNation + '|' + qDigits;
    ui->State_3->setText(result);
}

