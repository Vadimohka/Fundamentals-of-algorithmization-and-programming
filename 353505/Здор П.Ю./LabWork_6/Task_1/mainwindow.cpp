#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    demonstrate();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::demonstrate()
{
   pl.course_number=1232;
    pl.time_duartion=10;
    pl.type='A';
    std::string aa="";
    aa+=pl.type;
    pl.name[0]='A';
    pl.name[1]='i';
    pl.name[2]='r';
    pl.name[3]='b';
    pl.name[4]='u';
    pl.name[5]='s';
    pl.name[6]='\0';
    pl.people_amount[0]=100;
    pl.people_amount[1]=190;
    pl.people_amount[2]=42;
    pl.people_amount[3]=233;
    ui->label_8->setText(QString::number(pl.course_number)+" | "+QString::number(pl.time_duartion)+" | "+QString::fromStdString(aa)+" | "+QString::fromLatin1(pl.name,6)+" | "+QString::number(pl.people_amount[0])+" | "+QString::number(pl.people_amount[1])+" | "+QString::number(pl.people_amount[2])+" | "+QString::number(pl.people_amount[3]) );
}



void MainWindow::on_pushButton_clicked()
{
    std::string aa="";
    bool ok;
    bool fl1=1;
    while(fl1){
    int number = QInputDialog::getInt(nullptr, "Ввод числа", "Введите число (номер курса):", 0, 0, 100000, 1, &ok);
    if (ok) {
        fl1=0;
        QMessageBox::information(nullptr, "Число", QString("Вы ввели число: %1").arg(number));
        pl1.course_number=number;
    } else {
        fl1=1;
        QMessageBox::warning(nullptr, "Alert","Error");
    }

    }
    fl1=1;
    double number1 = QInputDialog::getDouble(nullptr, "Ввод числа", "Введите число (время полета):", 0, 0.0, 100000.0, 1, &ok);
    while(fl1){
    if (ok) {
            fl1=0;
        QMessageBox::information(nullptr, "Число", QString("Вы ввели число: %1").arg(number1));
         pl1.time_duartion=number1;
    }
    else {
        fl1=1;
        QMessageBox::warning(nullptr, "Alert","Error");
    }
    }
    fl1=1;
    while(fl1){
    QString text = QInputDialog::getText(nullptr, "Ввод символа", "Введите один символ( тип самолета):");
    QChar symbol;
    if (!text.isEmpty() && text.length() == 1) {
         symbol = text.at(0);
        pl1.type=symbol.toLatin1();
         fl1=0;
        QMessageBox::information(nullptr, "Символ", QString("Вы ввели символ: %1").arg(symbol));

         aa+=pl1.type;
    }
    else {
        fl1=1;
        QMessageBox::warning(nullptr, "Alert","Error");
    }
    }
    fl1=1;
    QString text;
    while(fl1){
    text = QInputDialog::getText(nullptr, "Ввод символа", "Введите имя самолета  не более 10 символов");
    QChar symbol;
    if (!text.isEmpty() && text.length() <= 10) {
        symbol = text.at(0);
        fl1=0;
        QMessageBox::information(nullptr, "Символ", QString("Вы ввели символ: %1").arg(symbol));
    }
    else {
        fl1=1;
        QMessageBox::warning(nullptr, "Alert","Error");
    }
    for(int i=0;i<text.length();++i)
    {
        pl.name[i]=text[i].toLatin1();
    }
    }

        for(int i=0;i<3;++i){
        int number = QInputDialog::getInt(nullptr, "Ввод числа", "Введите число (колво пассажиров):", 0, 0, 100000, 1, &ok);
        if (ok) {
            fl1=0;
            QMessageBox::information(nullptr, "Число", QString("Вы ввели число: %1").arg(number));
            pl1.people_amount[i]=number;
        } else {
            fl1=1;
            --i;
            QMessageBox::warning(nullptr, "Alert","Error");
        }
        fl1=0;
    }
        ui->label_9->setText(QString::number(pl1.course_number)+" | "+QString::number(pl1.time_duartion)+" | "+QString::fromStdString(aa)+" | "+QString::fromLatin1(pl1.name,text.length())+" | "+QString::number(pl1.people_amount[0])+" | "+QString::number(pl1.people_amount[1])+" | "+QString::number(pl1.people_amount[2]) );

}


void MainWindow::on_pushButton_2_clicked()
{
    p=new PLANE[1];
    p->course_number=1232;
    p->time_duartion=10;
    p->type='A';
    std::string aa="";
    aa+=p->type;
    p->name[0]='A';
    p->name[1]='i';
    p->name[2]='r';
    p->name[3]='b';
    p->name[4]='u';
    p->name[5]='s';
    p->name[6]='\0';
    p->people_amount[0]=100;
    p->people_amount[1]=190;
    p->people_amount[2]=42;
    p->people_amount[3]=233;
    ui->label_24->setText(QString::number(p->course_number)+" | "+QString::number(p->time_duartion)+" | "+QString::fromStdString(aa)+" | "+QString::fromLatin1(p->name,6)+" | "+QString::number(p->people_amount[0])+" | "+QString::number(p->people_amount[1])+" | "+QString::number(p->people_amount[2])+" | "+QString::number(p->people_amount[3]) );
}


void MainWindow::on_pushButton_3_clicked()
{

    pp.course_number=1232;
    pp.time_duartion=10;
    pp.type='A';
    std::string aa="";
    aa+=pp.type;
    pp.name[0]='A';
    pp.name[1]='i';
    pp.name[2]='r';
    pp.name[3]='b';
    pp.name[4]='u';
    pp.name[5]='s';
    pp.name[6]='\0';
    pp.people_amount[0]=100;
    pp.people_amount[1]=190;
    pp.people_amount[2]=42;
    pp.people_amount[3]=233;
    ui->label_29->setText(QString::number(pp.course_number)+" | "+QString::number(pp.time_duartion)+" | "+QString::fromStdString(aa)+" | "+QString::fromLatin1(pp.name,6)+" | "+QString::number(pp.people_amount[0])+" | "+QString::number(pp.people_amount[1])+" | "+QString::number(pp.people_amount[2])+" | "+QString::number(pp.people_amount[3]) );
}

