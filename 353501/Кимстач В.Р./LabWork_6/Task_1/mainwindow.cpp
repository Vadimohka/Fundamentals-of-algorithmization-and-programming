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
    std::string isfall="Не упал";
    plane={13,6,'s',"airbus",{13,33,12,89},false};
    std::string aa="";
    aa+=plane.type;
     ui->label_3->setText(QString::number(plane.course_number)+" | "+QString::number(plane.time_duartion)+" | "+QString::fromStdString(aa)+" | "+QString::fromLatin1(plane.name,6)+" | "+QString::number(plane.people_amount[0])+" | "+QString::number(plane.people_amount[1])+" | "+QString::number(plane.people_amount[2])+" | "+QString::number(plane.people_amount[3])+" | "+QString::fromStdString(isfall) );
    pp.course_number=666;
    pp.time_duartion=100;
    pp.type='A';
    aa="";
    aa+=pp.type;
    pp.name[0]='A';
    pp.name[1]='i';
    pp.name[2]='r';
    pp.name[3]='b';
    pp.name[4]='u';
    pp.name[5]='s';
    pp.name[6]='\0';
    pp.people_amount[0]=12;
    pp.people_amount[1]=56;
    pp.people_amount[2]=44;
    pp.people_amount[3]=78;
    pp.fall=false;
     isfall="Не упал";
    if(pp.fall){
        isfall="Упал";
    }
    ui->label_29->setText(QString::number(pp.course_number)+" | "+QString::number(pp.time_duartion)+" | "+QString::fromStdString(aa)+" | "+QString::fromLatin1(pp.name,6)+" | "+QString::number(pp.people_amount[0])+" | "+QString::number(pp.people_amount[1])+" | "+QString::number(pp.people_amount[2])+" | "+QString::number(pp.people_amount[3])+" | "+QString::fromStdString(isfall) );
    p=new PLANE[1];
    p->course_number=777;
    p->time_duartion=90;
    p->type='E';
    aa="";
    aa+=p->type;
    p->name[0]='A';
    p->name[1]='i';
    p->name[2]='r';
    p->name[3]='b';
    p->name[4]='u';
    p->name[5]='s';
    p->name[6]='\0';
    p->people_amount[0]=234;
    p->people_amount[1]=123;
    p->people_amount[2]=200;
    p->people_amount[3]=111;
    p->fall=true;
    if(p->fall){
        isfall="Упал";
    }
    ui->label_24->setText(QString::number(p->course_number)+" | "+QString::number(p->time_duartion)+" | "+QString::fromStdString(aa)+" | "+QString::fromLatin1(p->name,6)+" | "+QString::number(p->people_amount[0])+" | "+QString::number(p->people_amount[1])+" | "+QString::number(p->people_amount[2])+" | "+QString::number(p->people_amount[3])+" | "+QString::fromStdString(isfall) );
    pl.course_number=1232;
    pl.time_duartion=10;
    pl.type='A';
    aa="";
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
    pl.fall=true;
    if(pp.fall){
        isfall="Упал";
    }
    ui->label_8->setText(QString::number(pl.course_number)+" | "+QString::number(pl.time_duartion)+" | "+QString::fromStdString(aa)+" | "+QString::fromLatin1(pl.name,6)+" | "+QString::number(pl.people_amount[0])+" | "+QString::number(pl.people_amount[1])+" | "+QString::number(pl.people_amount[2])+" | "+QString::number(pl.people_amount[3])+" | "+QString::fromStdString(isfall));
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
        text = QInputDialog::getText(nullptr, "Ввод символа", "Введите имя самолета  не более 7 символов");
        QChar symbol;
        if (!text.isEmpty() && text.length() <= 7) {
            symbol = text.at(0);
            fl1=0;

        }
        else {
            fl1=1;
            QMessageBox::warning(nullptr, "Alert","Error");
        }

    }
    for(int i=0;i<text.length();++i)
    {
        pl1.name[i]=text.at(i).toLatin1();
    }

    for(int i=0;i<4;++i){
        int number = QInputDialog::getInt(nullptr, "Ввод числа", "Введите число (колво пассажиров):", 0, 0, 100000, 1, &ok);
        if (ok) {
            fl1=0;

            pl1.people_amount[i]=number;
        } else {
            fl1=1;
            --i;
            QMessageBox::warning(nullptr, "Alert","Error");
        }
        fl1=0;
    }
    fl1=1;
    while(fl1){
        int number = QInputDialog::getInt(nullptr, "Ввод числа", "Введите число (упал=1, не упал=0):", 0, 0, 100000, 1, &ok);
        if (ok&&(number==1||number==0)) {
            fl1=0;

            pl1.fall=number;
        } else {
            fl1=1;
            QMessageBox::warning(nullptr, "Alert","Error");
        }

    }
    QString isfallen="Не упал";
    if(pl1.fall){
        isfallen="упал";
    }
    qDebug()<<text.length()<<"  "<<pl1.name[0]<<" "<<pl1.name[1];
    ui->label_16->setText(QString::number(pl1.course_number)+" | "+QString::number(pl1.time_duartion)+" | "+QString::fromStdString(aa)+" | "+QString::fromLatin1(pl1.name,text.length())+" | "+QString::number(pl1.people_amount[0])+" | "+QString::number(pl1.people_amount[1])+" | "+QString::number(pl1.people_amount[2]) +" | "+QString::number(pl1.people_amount[3])+" | "+isfallen);

}






