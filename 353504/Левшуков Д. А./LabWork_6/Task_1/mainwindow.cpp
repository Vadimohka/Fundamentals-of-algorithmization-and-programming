#include "mainwindow.h"
#include "ui_mainwindow.h"

#define struct(x) ui->s##x->setText(QString::fromStdString(toString(ship_##x)))

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

bool MainWindow::check()
{
    ship_3.attributes[1]=-1488;
    //Capacity
    std::string cap=ui->capacity->toPlainText().toStdString();

    qDebug()<<cap.size();

    if(cap.size()==0)
        return false;
    for(auto& i:cap)
    {
        if(!(i>='0'&&i<='9'))
            return false;
    }



    int c;
    try
    {
        c=stoi(cap);
    }catch(...){
        return false;
    }

    qDebug()<<"Capacity ok";
    //Staff
    std::string st=ui->staff->toPlainText().toStdString();

    if(st.size()==0)
        return false;
    for(auto& i:st)
    {
        if(!(i>='0'&&i<='9'))
            return false;
    }

    int staff;
    try
    {
        staff=stoi(st);
    }catch(...){
        return false;
    }

    qDebug()<<"Staff ok";
    //Type
    std::string ty=ui->type->toPlainText().toStdString();;
    if(ty.size()>1||ty.size()==0)
        return false;

    char type=ty[0];

    if(!(type=='W'||type=='P'||type=='C'||type=='F'||type=='Y'||type=='U'))
        return false;

    qDebug()<<"Type ok";
    //Sank
    std::string san=ui->sank->toPlainText().toStdString();;
    if(san.size()>1||san.size()==0)
        return false;

    char s=san[0];

    if(!(s=='1'||s=='0'))
        return false;

    bool sank=s-'0';
qDebug()<<"Sank ok";
    //Cost

    std::string ca=ui->cost->toPlainText().toStdString();

    if(ca.size()==0)
        return false;

    bool point=false;
    for(auto& i:ca)
    {
        if(i=='.')
        {
            if(point)return false;
            point=true;
        }else
        if(!(i>='0'&&i<='9'))
            return false;
    }

    double cost;
    try
    {
        cost=stod(ca);
    }catch(...){
        return false;
    }

    qDebug()<<"Cost ok";
    // name

    std::string name=ui->name->toPlainText().toStdString();
    if(name.size()==0)
        return false;

    qDebug()<<"Name ok:"<<name;
    //Lifting
    std::string l=ui->lifting->toPlainText().toStdString();

    if(l.size()==0)
        return false;
    for(auto& i:l)
    {
        if(!(i>='0'&&i<='9'))
            return false;
    }

    int lifting;
    try
    {
        lifting=stoi(l);
    }catch(...){
        return false;
    }
qDebug()<<"Lifting ok";

    ship_3.cost=cost;
ship_3.name=new char [name.size()+1];
    for(int i=0;i<name.size();i++)
    ship_3.name[i]=name[i];
    ship_3.name[name.size()]='\0';
    ship_3.sank=sank;
    ship_3.staff=staff;
    ship_3.type=type;
    ship_3.attributes[0]=lifting;
    ship_3.attributes[1]=c;
    return true;
}

void MainWindow::set_structs()
{
    struct(1);
    struct(2);
    qDebug()<<ship_3.name;
    if(ship_3.attributes[1]!=-1488)
        struct(3);
    else
        ui->s3->clear();

    //4
    std::string res;
    int i=0;
    while(ship_4->name[i]!='\0')
        res+=ship_4->name[i++];
    res+=" | ";
    res+=ship_4->type;
    res+=" | ";
    res+=std::to_string(ship_4->cost);
    res+=" | ";
    res+=std::to_string(ship_4->staff);
    res+=" | ";
    res+=std::to_string(ship_4->attributes[0]);
    res+=" | ";
    res+=std::to_string(ship_4->attributes[1]);
    res+=" | ";
    if(ship_4->sank)
        res+="sank";
    else
        res+="not sank";
    ui->s4->setText(QString::fromStdString(res));

    //5
    struct(5);/*
    res="";
    i=0;
    while(ship_5.name[i]!='\0')
        res+=ship_5->name[i++];
    res+=" | ";
    res+=ship_5->type;
    res+=" | ";
    res+=std::to_string(ship_5->cost);
    res+=" | ";
    res+=std::to_string(ship_5->staff);
    res+=" | ";
    res+=std::to_string(ship_5->attributes[0]);
    res+=" | ";
    res+=std::to_string(ship_5->attributes[1]);
    res+=" | ";
    if(ship_5->sank)
        res+="sank";
    else
        res+="not sank";
    ui->s5->setText(QString::fromStdString(res));
*/

}

std::string MainWindow::toString(Ship x)
{
    std::string res;
    int i=0;
    while(x.name[i]!='\0')
    res+=x.name[i++];
    res+=" | ";
    res+=x.type;
    res+=" | ";
    res+=std::to_string(x.cost);
    res+=" | ";
    res+=std::to_string(x.staff);
    res+=" | ";
    res+=std::to_string(x.attributes[0]);
    res+=" | ";
    res+=std::to_string(x.attributes[1]);
    res+=" | ";
    if(x.sank)
        res+="sank";
    else
        res+="not sank";
    return res;
}

void MainWindow::on_pushButton_clicked()
{

        //Ship 1
        ship_1={250,'P',false,1e9,"BomBomShip",{20000,15000}};
        //Ship 2
        ship_2.cost=1e10;
        ship_2.name="NikitsShip";
        ship_2.sank=true;
        ship_2.staff=300;
        ship_2.type='W';
        ship_2.attributes[0]=3000;
        ship_2.attributes[1]=6000;
        //Ship 3
        if(!check())
        {
            QMessageBox::warning(this,"Error","You write incorrect data. Try again");
        }
        //Ship 4
        ship_4=new Ship();
        ship_4->cost=1232131231232;
        ship_4->name="PtrShip";
        ship_4->sank=false;
        ship_4->staff=1400;
        ship_4->attributes[0]=1290;
        ship_4->attributes[1]=2000;

        //Ship 5
        ship_5.cost=9876342123;
        ship_5.name="LinkShip";
        ship_5.sank=true;
        ship_5.staff=100;
        ship_5.attributes[0]=100000;
        ship_5.attributes[1]=50000;
        set_structs();
}

