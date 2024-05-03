#include "mainwindow.h"
#include "./ui_mainwindow.h"
#define InputError QMessageBox::information(this,"Error", "Wrong format of array elements or you write nothing", QMessageBox::Ok);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    f.clear();
    s.clear();
    f.push_back(1);
    f.push_back(4);
    f.push_back(5);
    s.push_back({3,2.0});
    s.push_back({7,6.0});
    matrix.push_back({f,s});
    show_matrix();
    ui->pushButton_9->setHidden(true);
    ui->el1->setHidden(true);
    ui->el2->setHidden(true);
    ui->label_5->setHidden(true);
    ui->label_8->setHidden(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::show_matrix()
{
    //First matrix
    ui->First->clear();
    std::string s="";
    qDebug()<<matrix.size();
    for(int j=0;j<matrix.size();j++){
        for(int i=0;i<matrix[j].first.size();i++)
        {
            s+=std::to_string(matrix[j].first.at(i))+" ";
        }
        s.back()='\n';
    }
    qDebug()<<"First:"<<s;
    ui->First->setText(QString::fromStdString(s));
    //Second matrix
    s="";
    for(int j=0;j<matrix.size();j++){
        for(int i=0;i<matrix[j].second.size();i++)
        {
            s+="{"+std::to_string(matrix[j].second.at(i).first)+", "+std::to_string(matrix[j].second.at(i).second)+"} ";
        }
        s.back()='\n';
    }
    qDebug()<<"Seocnd:"<<s;
    ui->Sec->setText(QString::fromStdString(s));
    //Other example of func
    s="";
    //back
    s+="Back element: ";
    if(matrix.size()>0)
        s+="{"+std::to_string(matrix.back().first.back())+", {"+std::to_string(matrix.back().second.back().first)+", "+std::to_string(matrix.back().second.back().second)+"} }";
    s+="\n";
    //capacity
    s+="Capacity of vector:"+std::to_string(matrix.capacity())+"\n";
    //size
    s+="Size:"+std::to_string(matrix.size())+"\n";
    ui->Ex->setText(QString::fromStdString(s));
    update();
}

bool MainWindow::check_element()
{
    el.first.clear();
    el.second.clear();
    std::string s=ui->Element->toPlainText().toUtf8().constData();
    int kol=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=' '&&s[i]!='\n'&&!isdigit(s[i]))
            return false;
        if(s[i]=='\n')
            kol++;
        if(kol>2)return false;
    }


    if(kol!=2)return false;

    int i=0;
    for(i=0;i<s.size();i++)
    {
        if(s[i]=='\n')
        {
            if(el.first.size()==0)return false;
            break;
        }
        if(isdigit(s[i]))
        {
            int j=i+1;
            while(isdigit(s[j])&&j<s.size())
                j++;
            j--;
            int ch=0;
            try
            {
                ch=stoi(s.substr(i,j-i+1));
            }
            catch(...)
            {
                return false;
            }
            el.first.push_back(ch);
            qDebug()<<ch;
            i=j;
        }
    }
    i++;
    for(;i<s.size();i++)
    {
        if(s[i]=='\n')
        {
            if(el.second.size()==0)return false;
            break;
        }
        if(isdigit(s[i]))
        {
            int j=i+1;
            while(isdigit(s[j])&&j<s.size())
                j++;
            j--;
            int ch=0;
            try
            {
                ch=stoi(s.substr(i,j-i+1));
            }
            catch(...)
            {
                return false;
            }
            el.second.push_back({ch,INT_MIN});
            qDebug()<<ch;
            i=j;
        }
    }
    i++;
    int q=0;
    for(;i<s.size();i++)
    {
        //if(s[i]=='\n')break;
        if(isdigit(s[i]))
        {
            int j=i+1;
            int kol=0;
            while(isdigit(s[j])&&j<s.size()&&s[j]=='.')
            {
                if(s[j]=='.')kol++;
                j++;
            }
            j--;
            if(kol>1)return false;
            double ch=0;
            try
            {
                ch=stod(s.substr(i,j-i+1));
            }
            catch(...)
            {
                return false;
            }
            qDebug()<<q<<" "<<ch<<" "<<el.second.size();
            el.second[q].second=ch;
            q++;
            i=j;
        }
    }
    return el.second.back().second!=INT_MIN;
}

bool MainWindow::check_positions()
{
    std::string s=ui->posf->toPlainText().toUtf8().constData();
    if(s.size()==0)return false;
    for(int i=0;i<s.size();i++)
        if(!isdigit(s[i]))return false;
    qDebug()<<s;
    try
    {
        pos1=stoi(s);
    }
    catch(...)
    {
        return false;
    }
    /*
    s=ui->post->toPlainText().toUtf8().constData();
    qDebug()<<s;
    try
    {
        pos2=stoi(s);
    }
    catch(...)
    {
        return false;
    }

    if(pos2>=matrix.size())
        pos2=matrix.size()-1;
    return pos1>=0&&pos1<matrix.size()&&pos2>=pos1;
*/
    return pos1>=0&&pos1<matrix.size();
}

bool MainWindow::check_range()
{
    std::string s=ui->el1->toPlainText().toUtf8().constData();
    if(s.size()==0)return false;
    for(int i=0;i<s.size();i++)
        if(!isdigit(s[i]))return false;
    qDebug()<<s;
    try
    {
        pos1=stoi(s);
    }
    catch(...)
    {
        return false;
    }
    s=ui->el2->toPlainText().toUtf8().constData();
    if(s.size()==0)return false;
    for(int i=0;i<s.size();i++)
        if(!isdigit(s[i]))return false;
    qDebug()<<s;
    try
    {
        pos2=stoi(s);
    }
    catch(...)
    {
        return false;
    }

    return pos1>=0&&pos1<matrix.size()&&pos2>=0&&pos2<matrix.size();
}



void MainWindow::on_pushButton_clicked()//clear
{
    matrix.clear();
    show_matrix();
}


void MainWindow::on_pushButton_2_clicked()//push_back
{
    if(check_element())
    {
        matrix.push_back(el);
    }
    else
        InputError;
    show_matrix();

}


void MainWindow::on_pushButton_7_clicked()//erase
{
    if(check_positions())
    {
            matrix.erase(matrix.begin()+pos1);

    }
    else
        InputError;
    show_matrix();

}


void MainWindow::on_pushButton_8_clicked()
{
    if(check_positions()&&check_element())
    {
        add.clear();
        //add.push_back(el);
        matrix.insert(matrix.cbegin()+pos1,el);

    }
    else
        InputError;
    show_matrix();
}


void MainWindow::on_pushButton_6_clicked()
{
    if(!matrix.empty())
    matrix.pop_back();
    else
        QMessageBox::information(this,"Error", "Vector is empty", QMessageBox::Ok);
     show_matrix();
}


/*
void MainWindow::on_pushButton_9_clicked()
{
    if(check_range())
    {
        matrix[pos1].swap(matrix[pos2]);
    }
}

*/
