#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_lineEdit_textEdited(const QString &arg1)
{
    QString bet = arg1;
    bet.removeLast();

    short points = 0, prev = 0, after = 0;

    bool pt = false;

    for(int i = 0; i < arg1.size(); i++)
    {
        if(arg1[i] == '.')
        {
            points++;
            pt = true;
        }

        if(arg1[i] == '-' && i != 0)
        {
            ui->lineEdit->setText("");
            return;
        }

        if(((arg1[i] < '0' || arg1[i] > '9') && arg1[i] != '.' && arg1[i] != '-') || points > 1)
        {
            ui->lineEdit->setText(bet);
            return;
        }

        if(!pt && arg1[i] != '.')
            prev++;
        else if(pt && arg1[i] != '.')
            after++;
    }

    if(prev > 9)
    {
        ui->lineEdit->setText(bet);
        return;
    }

    if(after > 5)
    {
        ui->lineEdit->setText(bet);
        return;
    }
}


void Widget::on_pushButton_clicked()
{
    minus = false;

    for(int i = 0; i < ui->lineEdit->text().size(); i++)
    {
        if(ui->lineEdit->text()[i] == '-')
            minus = true;
    }

    float *i;
    ui->label_3->setText(QString::fromStdString(floatToBinary(abs(ui->lineEdit->text().toFloat())) + "." + floatToBinary_small(abs(modf(ui->lineEdit->text().toFloat(), i)), 1)));

    if(minus == true)
    {
        ui->label_3->setText("-" + ui->label_3->text());
    }
}

std::string Widget::floatToBinary(float ch)
{
    std::string ans = "";

    if(ch >= 1)
    {
        ans = floatToBinary(int(floor(ch)) / 2) + std::to_string(int(floor(ch)) % 2);
    }

    return ans;
}

std::string Widget::floatToBinary_small(float ch, short step)
{
    std::string ans = "";

    if(step == 6)
        return ans;

    if(ch >= 1)
        ans = std::to_string(int(floor((ch - 1) * 2))) + floatToBinary_small((ch - 1) * 2, step + 1);
    else
        ans = std::to_string(int(floor(ch * 2))) + floatToBinary_small(ch * 2, step + 1);

    return ans;
}

