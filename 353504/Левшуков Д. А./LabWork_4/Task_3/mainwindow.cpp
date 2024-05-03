#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    HiddenError();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ShowError()
{
    ui->er->setHidden(false);
    //ui->plainTextEdit->setStyleSheet("QPlaintTextExit {background-color: black; color: red;}");
    update();
}

void MainWindow::HiddenError()
{
    ui->er->setHidden(true);
    //ui->plainTextEdit->setStyleSheet("QPlaintTextExit {background-color: black; color: black;}");
    update();
}

bool MainWindow::check_element(std::string s)
{
    qDebug()<<"Check element: "<<s;

    long long a=0;
    try
    {
        a=stoll(s);
    }
    catch(...)
    {
        return false;
    }
    v.push_back(a);
    return true;
}

bool MainWindow::read(std::string s)
{
    v.clear();
    for(auto& i:s)
    {
        if(i!='-'&&!isdigit(i)&&i!=' ')
            return false;
    }

    int j=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' ')
        {
            if(!check_element(s.substr(j,i-j)))
            {
                return false;
            }
            j=i+1;
        }
        if(s[i]=='-'&&i>=1&&s[i-1]!=' ')
            return false;
    }

    return check_element(s.substr(j));
}

void MainWindow::UpdateInfo()
{
    std::string s;
    b.clear();

    for(int i=0;i<v.size();i++)
    {
        if((i+1)%3==0)
        {
            s+=std::to_string(v[i])+" }, ";
            cmp(v[i-2],v[i-1],v[i]);
        }
        if((i+1)%3==1)
        {
            s+="{ "+std::to_string(v[i])+", ";
        }
        if((i+1)%3==2)
        {
            s+=std::to_string(v[i])+", ";
        }
    }

    if(v.size()%3==1)
    {
        b.push_back(v.back());
    }
    if(v.size()%3==2)
    {
        b.push_back((v[v.size()-2]+v.back())/2);
    }


    if(v.size()%3!=0)
    {
        s.pop_back();
        s.pop_back();

        s+=" }";
    }
    else
    {
    s.pop_back();
    s.pop_back();
    }
    qDebug()<<s;
    ui->tuples->setText(QString::fromStdString(s));

    s="{";
    for(auto& i:b)
    {
        s+=std::to_string(i)+", ";
    }
    s.pop_back();
    s.pop_back();
    s+="}";
    ui->median->setText(QString::fromStdString(s));

}

void MainWindow::cmp(long long a, long long b, long long c)
{
    long long mx=std::max(a,std::max(b,c));
    long long mn=std::min(a,std::min(b,c));
    if((mx==a&&mn==c)||(mx==c&&mn==a))
    {
        this->b.push_back(b);
        return;
    }
    if((mx==b&&mn==c)||(mx==c&&mn==b))
    {
        this->b.push_back(a);
        return;
    }
    if((mx==a&&mn==b)||(mx==b&&mn==a))
    {
        this->b.push_back(c);
        return;
    }
}

void MainWindow::on_plainTextEdit_textChanged()
{
    if(!read(ui->plainTextEdit->toPlainText().toStdString()))
    {
        ShowError();
        return;
    }

    HiddenError();
    UpdateInfo();
}

