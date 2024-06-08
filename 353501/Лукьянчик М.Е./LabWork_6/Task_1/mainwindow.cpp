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
    ship_3.attribut[1]=-1488;

    std::string cap=ui->capacity->toPlainText().toStdString();

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


    std::string ty=ui->type->toPlainText().toStdString();;
    if(ty.size()>1||ty.size()==0)
        return false;

    char type=ty[0];

    if(!(type=='A'||type=='E'||type=='C'||type=='B'))
        return false;

    std::string san=ui->notfly->toPlainText().toStdString();;
    if(san.size()>1||san.size()==0)
        return false;

    char s=san[0];

    if(!(s=='1'||s=='0'))
        return false;

    bool notfly=s-'0';

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


    std::string name=ui->name->toPlainText().toStdString();
    if(name.size()==0)
        return false;


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

    ship_3.price=cost;
    ship_3.name=new char [name.size()+1];
    for(int i=0;i<name.size();i++)
        ship_3.name[i]=name[i];
    ship_3.name[name.size()]='\0';
    ship_3.inuse=notfly;
    ship_3.human=staff;
    ship_3.type=type;
    ship_3.attribut[0]=lifting;
    ship_3.attribut[1]=c;
    return true;
}

void MainWindow::set_structs()
{
    struct(1);
    struct(2);
    //qDebug()<<ship_3.name;
    if(ship_3.attribut[1]!=-1488)
        struct(3);
    else
        ui->s3->clear();


    std::string res;
    int i=0;
    while(ship_4->name[i]!='\0')
        res+=ship_4->name[i++];
    res+=" | ";
    res+=ship_4->type;
    res+=" | ";
    res+=std::to_string(ship_4->price);
    res+=" | ";
    res+=std::to_string(ship_4->human);
    res+=" | ";
    res+=std::to_string(ship_4->attribut[0]);
    res+=" | ";
    res+=std::to_string(ship_4->attribut[1]);
    res+=" | ";
    if(ship_4->inuse)
        res+="in use";
    else
        res+="not in use";
    ui->s4->setText(QString::fromStdString(res));


    struct(5);

}

std::string MainWindow::toString(airplane x)
{
    std::string res;
    int i=0;
    while(x.name[i]!='\0')
        res+=x.name[i++];
    res+=" | ";
    res+=x.type;
    res+=" | ";
    res+=std::to_string(x.price);
    res+=" | ";
    res+=std::to_string(x.human);
    res+=" | ";
    res+=std::to_string(x.attribut[0]);
    res+=" | ";
    res+=std::to_string(x.attribut[1]);
    res+=" | ";
    if(x.inuse)
        res+="in use";
    else
        res+="not in use";
    return res;
}

void MainWindow::on_pushButton_clicked()
{


    ship_1={125,'E',false,1,"EcoPassenger",{30000,10000}};

    ship_2.price=300;
    ship_2.name="Aviasales";
    ship_2.inuse=true;
    ship_2.human=100;
    ship_2.type='A';
    ship_2.attribut[0]=5000;
    ship_2.attribut[1]=10000;

    if(!check())
    {
        QMessageBox::warning(this,"Error","You wrote incorrect data. Try again");
    }

    ship_4=new airplane();
    ship_4->price=550;
    ship_4->name="ClassicPassenger";
    ship_4->inuse=false;
    ship_4->human=80;
    ship_4->attribut[0]=12000;
    ship_4->attribut[1]=13000;


    ship_5.price=1300;
    ship_5.name="BusinessPassenger";
    ship_5.inuse=true;
    ship_5.human=30;
    ship_5.attribut[0]=125000;
    ship_5.attribut[1]=70000;
    set_structs();
}
