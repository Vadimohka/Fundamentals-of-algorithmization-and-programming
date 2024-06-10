#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    Notebook one = {3, 3.4, 'L', false, {6, 3, 6, 3, 7, 2, 8, 5, 3, 0}, "Burgirsto"};
    Notebook two;
    two.usbs = 2;
    two.cpuCore = 1.5;
    two.model = 'O';
    two.isGaming = false;

    two.company[0] = 'T';
    two.company[1] = 'r';
    two.company[2] = 'o';
    two.company[3] = 'l';
    two.company[4] = 't';
    two.company[5] = 'o';
    two.company[6] = 'g';
    two.company[7] = 'r';
    two.company[8] = 'o';

    Notebook vo;
    Notebook *four = &vo;
    four->usbs = 2;
    four->cpuCore = 1.5;
    four->model = 'O';
    four->isGaming = false;

    four->company[0] = 'T';
    four->company[1] = 'r';
    four->company[2] = 'o';
    four->company[3] = 'l';
    four->company[4] = 't';
    four->company[5] = 'o';
    four->company[6] = 'g';
    four->company[7] = 'r';
    four->company[8] = 'o';

    Notebook vi;
    Notebook &five = vi;
    five.usbs = 2;
    five.cpuCore = 1.5;
    five.model = 'O';
    five.isGaming = false;

    five.company[0] = 'T';
    five.company[1] = 'r';
    five.company[2] = 'o';
    five.company[3] = 'l';
    five.company[4] = 't';
    five.company[5] = 'o';
    five.company[6] = 'g';
    five.company[7] = 'r';
    five.company[8] = 'o';

    QString oneMas = "";
    QString twoMas = "";
    QString fourMas = "";
    QString fiveMas = "";
    for(int i = 0; i < 10; i++)
    {
        oneMas = oneMas + QString::number(one.id[i]);
        two.id[i] = rand()%10;
        twoMas = twoMas + QString::number(two.id[i]);
        four->id[i] = rand()%10;
        fourMas = fourMas + QString::number(four->id[i]);
        five.id[i] = rand()%10;
        fiveMas = fiveMas + QString::number(five.id[i]);
    }

    QString fourChar = "", twoChar = "";

    for(int i = 0; i < 9; i++)
    {
        fourChar = fourChar + four->company[i];
        twoChar = twoChar + two.company[i];
    }

    ui->label_3->setText(QString::number(one.usbs) + " | " + QString::number(one.cpuCore) + " | " + QString(one.model) + " | " + QString::number(one.isGaming) + " | " + oneMas + " | " + one.company);
    ui->label_4->setText(QString::number(two.usbs) + " | " + QString::number(two.cpuCore) + " | " + QString(two.model) + " | " + QString::number(two.isGaming) + " | " + twoMas + " | " + twoChar);
    ui->label_15->setText(QString::number(four->usbs) + " | " + QString::number(four->cpuCore) + " | " + QString(four->model) + " | " + QString::number(four->isGaming) + " | " + fourMas + " | " + fourChar);
    ui->label_16->setText(QString::number(five.usbs) + " | " + QString::number(five.cpuCore) + " | " + QString(five.model) + " | " + QString::number(five.isGaming) + " | " + fiveMas + " | " + five.company);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_lineEdit_textChanged(const QString &arg1)
{
    int count = 0;
    for(int i = 0; i < arg1.size(); i++)
    {
        if(arg1[i] == '.')
            count++;

        if(((arg1[i] < '0' || arg1[i] > '9') && arg1[i] != '.') || count > 1 || arg1.size() > 10)
        {
            QString txt = ui->lineEdit->text();
            txt.remove(txt.size() - 1, 1);
            ui->lineEdit->setText(txt);
            return;
        }
    }
}


void Widget::on_lineEdit_2_textEdited(const QString &arg1)
{
    for(int i = 0; i < arg1.size(); i++)
    {
        if(arg1[i] < 'A' || arg1[i] > 'Z' || arg1.size() > 1)
        {
            QString txt = ui->lineEdit_2->text();
            txt.remove(txt.size() - 1, 1);
            ui->lineEdit_2->setText(txt);
            return;
        }
    }
}


void Widget::on_lineEdit_3_textEdited(const QString &arg1)
{
    for(int i = 0; i < arg1.size(); i++)
    {
        if(arg1[i] < '0' || arg1[i] > '9' || arg1.size() > 10)
        {
            QString txt = ui->lineEdit_3->text();
            txt.remove(txt.size() - 1, 1);
            ui->lineEdit_3->setText(txt);
            return;
        }
    }
}


void Widget::on_lineEdit_4_textEdited(const QString &arg1)
{
    for(int i = 0; i < arg1.size(); i++)
    {
        if(((arg1[i] < 'A' || arg1[i] > 'Z') && (arg1[i] < 'a' || arg1[i] > 'z')) || arg1.size() > 9)
        {
            QString txt = ui->lineEdit_4->text();
            txt.remove(txt.size() - 1, 1);
            ui->lineEdit_4->setText(txt);
            return;
        }
    }
}


void Widget::on_pushButton_clicked()
{
    if(ui->lineEdit->text() == "" || ui->lineEdit_2->text() == "" || ui->lineEdit_3->text() == "" || ui->lineEdit_4->text() == "")
    {
        ui->label_13->setText("Неверно заданы характеристики");
        return;
    }
    else
        ui->label_13->setText("");

    Notebook three = {ui->spinBox->value(), ui->lineEdit->text().toDouble(), ui->lineEdit_2->text()[0].toLatin1(), ui->checkBox->isChecked(), {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, "123456789"};

    ui->label_6->setText(QString::number(three.usbs) + " | " + QString::number(three.cpuCore) + " | " + QString(three.model) + " | " + QString::number(three.isGaming) + " | " + ui->lineEdit_3->text() + " | " + ui->lineEdit_4->text());
}

