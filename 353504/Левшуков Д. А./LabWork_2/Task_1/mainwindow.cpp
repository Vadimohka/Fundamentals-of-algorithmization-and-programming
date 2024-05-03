#include "mainwindow.h"
#include "ui_mainwindow.h"

#define BadFile QMessageBox::information(this,"Error", "The file does not match the format or file not selected", QMessageBox::Ok)
#define IncFormat QMessageBox::information(this,"Error", "New data does not match the format below", QMessageBox::Ok)

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showing=false;
    //this->showFullScreen();
    //this->showFullScreen();
    ctrlo= new QShortcut(this);
    ctrlo->setKey(Qt::CTRL + Qt::Key_O);
    //ui->Table->column
    //ui->label_4->setHidden(true);
    ui->Table->setItemDelegateForColumn(1, new NonEditTableColumnDelegate());
    ui->Table->setItemDelegateForColumn(2, new NonEditTableColumnDelegate());
    ui->Table->setItemDelegateForColumn(3, new NonEditTableColumnDelegate());
    ui->Table->setItemDelegateForColumn(4, new NonEditTableColumnDelegate());
    ui->Table->setItemDelegateForColumn(5, new NonEditTableColumnDelegate());
    connect(ctrlo, SIGNAL(activated()), this, SLOT(on_OpenFileButton_clicked()));
    s="";
    birthday={-1,-1,-1};
    //ShowTable();
    Today();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::FileRead()
{
    if(file=="")
    {
        BadFile;
        return;
    }

    std::ifstream cin(file.toUtf8().constData());

    data->clear();
    file_inside="";
    qDebug()<<"Start reading the file";
    int last=0,si,n;
    bool error=false;
    while(std::getline(cin,s))
    {
        file_inside+=s;
        n=s.size();
        for(int i=0;i<n;i++)
        {
            if(isdigit(s[i]))
            {
                si=i;
                while(i<n&&(isdigit(s[i])||s[i]=='.'))
                {
                    i++;
                }
                //if(i!=n)
                i--;
                std::string f=s.substr(si,i-si+1);
                //qDebug()<<f;
                if(current.Init(f))
                {
                    data->push_back(current,si);
                    //qDebug()<<data->get(data->size()-1).get_date()<<" : posiiton in file:"<<data->get_pos(data->size()-1);
                }
                else
                {
                    error=true;
                    break;
                }
            }
        }
        if(error)
        {break;}


    }
    if(error)
    {
        file="";
        BadFile;
        return;

    }

    qDebug()<<"Finish reading the file";
    ShowTable();
}


void MainWindow::Today()
{
    t=t.today();
    ui->Today->setText("Today: "+QString::fromStdString(t.get_date()));
}


void MainWindow::FileUpdate(int ind,std::string s, Date nw)
{
    std::string new_file_inside=s;
    std::string del="";
    qDebug()<<"NEW FILE INSIDE:"<<new_file_inside;
    qDebug()<<data->get_pos(ind)<<" "<<data->get(ind).get_date().size();
    new_file_inside+=file_inside.substr(data->get_pos(ind)+data->get(ind).get_date().size(),file_inside.size());
    qDebug()<<"NEW FILE INSIDE [2]:"<<new_file_inside;

    FILE *f=fopen(file.toUtf8().constData(),"r+");
    fseek(f,data->get_pos(ind),SEEK_SET);
    //fread(check,sizeof(char),sizeof(char)*10,f);
    //qDebug()<<check;
    while(data->get_pos(ind)+new_file_inside.size()<file_inside.size())
        new_file_inside+=" ";
    qDebug()<<"NEW FILE INSIDE [3]:"<<new_file_inside;
    fwrite(new_file_inside.c_str(),sizeof(char),sizeof(char)*new_file_inside.size(),f);
    fclose(f);
    file_inside=file_inside.substr(0,data->get_pos(ind))+new_file_inside;

    qDebug()<<"FILE INSIDE:"<<file_inside;
    //FileRead();
    data->update(nw,ind);
}


void MainWindow::FileAdd(std::string s)
{
    if(file=="")
    {
        BadFile;
        return;
    }
    FILE *f=fopen(file.toUtf8().constData(),"a");

    qDebug()<<"Try to add "<<s<<" in "<<file;
    //fseek(f,0,2);
    fwrite(s.c_str(),sizeof(char),sizeof(char)*s.size(),f);
    fclose(f);
}


void MainWindow::ShowTable()
{
    Today();

    long long n=data->size();
    long long rows=ui->Table->rowCount();
    showing=true;
    for(int i=0;i<rows;i++)
        ui->Table->removeRow(i);

    ui->Table->setRowCount(n);
    qDebug()<<"Start build table\nRows"<<n;

    for(int i=0;i<n;i++)
    {
        // qDebug()<<"["<<i<<"] 0";
        QTableWidgetItem* real= new QTableWidgetItem;
        real->setTextAlignment(Qt::AlignCenter);
        real->setText(QString::fromStdString(data->get_string(i)));
        ui->Table->setItem(i,0,real);

        //qDebug()<<"["<<i<<"] 1";
        QTableWidgetItem* prev= new QTableWidgetItem;
        prev->setTextAlignment(Qt::AlignCenter);
        prev->setText(QString::fromStdString(data->get(i).PreviousDay()));
        ui->Table->setItem(i,1,prev);

        // qDebug()<<"["<<i<<"] 2";
        QTableWidgetItem* next= new QTableWidgetItem;
        next->setTextAlignment(Qt::AlignCenter);
        next->setText(QString::fromStdString(data->get(i).NextDay()));
        ui->Table->setItem(i,2,next);

        // qDebug()<<"["<<i<<"] 3";
        if(birthday.get_day()!=-1)
        {
        //qDebug()<<(data->get(i).Duration(birthday));
        QTableWidgetItem* bi= new QTableWidgetItem;
        bi->setTextAlignment(Qt::AlignCenter);
        if((birthday.get_month()==data->get(i).get_month()&&birthday.get_day()>=data->get(i).get_day())||(birthday.get_month()>data->get(i).get_month()))
        birthday.set_year(data->get(i).get_year());
        else
            birthday.set_year(data->get(i).get_year()+1);
        long long bdr =data->get(i).Duration(birthday);
        //birthday.set_year(y);
        std::string bdr_str=std::to_string(abs(bdr));
        if(bdr==0)
            bdr_str = "now";
        bi->setText(QString::fromStdString(bdr_str));
        ui->Table->setItem(i,3,bi);
        }
        else
        {
            QTableWidgetItem* bi= new QTableWidgetItem;
            bi->setTextAlignment(Qt::AlignCenter);
            bi->setText("NO INFO");
            ui->Table->setItem(i,3,bi);
        }

        // qDebug()<<"["<<i<<"] 4";
        if(i>0)
        {
        QTableWidgetItem* dur= new QTableWidgetItem;
        dur->setTextAlignment(Qt::AlignCenter);
        //qDebug()<<data->get_string(i)<<" and "<<data->get_string(i-1);
        long long dr =data->get(i).Duration(data->get(i-1));
        std::string d_str=std::to_string(abs(dr));
        if(dr>0)
            d_str += " ago";
        else if(dr<0)
            d_str += " before";
        else
            d_str="now";
        dur->setText(QString::fromStdString(d_str));
        ui->Table->setItem(i,4,dur);
        }

        // qDebug()<<"["<<i<<"] 5";
        QTableWidgetItem* to_today= new QTableWidgetItem;
        to_today->setTextAlignment(Qt::AlignCenter);
        long long d=data->get(i).Duration(t);
        std::string to_t=std::to_string(abs(d))+" ";
        if(d<0)
        {
            to_t+="ago";
        }
        else
            to_t+="before";
        to_today->setText(QString::fromStdString(to_t));
        ui->Table->setItem(i,5,to_today);

    }
    showing=false;

}


void MainWindow::on_OpenFileButton_clicked()
{
    file=QFileDialog::getOpenFileName(this,"Open File","/home/dzmitry","*.txt");
    qDebug()<<file;
    FileRead();
}


void MainWindow::on_DateOfBirthday_textChanged()
{
    //QString text=ui->DateOfBirthday->toPlainText();
    std::string text=ui->DateOfBirthday->toPlainText().toStdString();
    //qDebug()<<text<<"[1]";
    if(!isdigit(text.back())&&text.back()!='.'&&text.size()>0)
    {
        text.pop_back();
        //qDebug()<<text<<"[2]";
        //ui->DateOfBirthday->clear();
        //ui->DateOfBirthday->setText(QString::fromStdString(text));
        if(!birthday.Init(text))
        {
            ui->DateOfBirthday->clear();
            ui->DateOfBirthday->setTextColor(Qt::red);
            //ui->DateOfBirthday->setTe
            ui->DateOfBirthday->setPlainText("You are retard <3");
            //ui->DateOfBirthday->setText("You are retard <3");
            ui->DateOfBirthday->setTextColor(Qt::white);
            //timer->start(1e4);
            ui->DateOfBirthday->repaint();
            QThread::sleep(1);
            ui->DateOfBirthday->clear();
            IncFormat;
            return;
        }
        else
        {
            ui->DateOfBirthday->clear();
            ui->birth->setText(QString::fromStdString(birthday.get_date()));
            ShowTable();
        }
    }
}


void MainWindow::on_Table_itemChanged(QTableWidgetItem *item)
{
    if(showing)return;
    if(item->column())
        return item->setText(QString::fromStdString(data->get(item->row()).get_date()));

    qDebug()<<"Try to edit. ID: "<<item->row();
    std::string new_value=item->text().toUtf8().constData();
    Date nw;
    if(!nw.Init(new_value))
    {
        qDebug()<<"Incorrect edit";
        item->setText(QString::fromStdString(data->get(item->row()).get_date()));
        IncFormat;
        return;
    }
    else
    {

        qDebug()<<"Correct edit";
        //qDebug()<<data->get(item->row()).get_date();
        FileUpdate(item->row(),new_value,nw);
        ShowTable();
    }
}


void MainWindow::on_Add_textChanged()
{
    std::string text=ui->Add->toPlainText().toStdString();
    Date new_element;
    if(!isdigit(text.back())&&text.back()!='.'&&text.size()>0)
    {
        text.pop_back();
        //qDebug()<<text<<"[2]";
        //ui->DateOfBirthday->clear();
        //ui->DateOfBirthday->setText(QString::fromStdString(text));
        if(!new_element.Init(text))
        {
            ui->Add->clear();
            ui->Add->setTextColor(Qt::red);
            //ui->Add->setTe
            ui->Add->setPlainText("You are dumb <3");
            //ui->Add->setText("You are retard <3");
            ui->Add->setTextColor(Qt::white);
            //timer->start(1e4);
            ui->Add->repaint();
            QThread::sleep(1);
            ui->Add->clear();
            IncFormat;
            return;
        }
        else
        {
            ui->Add->clear();
            int last=std::max(data->get_pos(data->size()-2),0);
            data->push_back(new_element,1+last);
            FileAdd(" "+new_element.get_date());
            ShowTable();
        }
    }
}

