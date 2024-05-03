#include "mainwindow.h"
#include "ui_mainwindow.h"

#define InputError QMessageBox::information(this,"Error", "Wrong format of array elements or you write nothing", QMessageBox::Ok);
#define ElementError QMessageBox::information(this,"Error", "You didn't write a number", QMessageBox::Ok);
#define NotSortError QMessageBox::information(this,"Error", "Firstly, you should sort array :)", QMessageBox::Ok);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //isFullScreen();
    //QWidget::setFixedSize(1850, 1050);

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::check(std::string s)
{
    long long n=s.size();
    bool have_digit=false;
    for(long long i=0;i<n;i++)
    {
        if(s[i]!=' '&&s[i]!='\n'&&!isdigit(s[i])&&s[i]!='-')
            return false;
        if(isdigit(s[i]))have_digit=true;
    }

    if(!have_digit)
        return false;

    for(long long i=0;i<n;i++)
    {
        if(isdigit(s[i])||s[i]=='-')
        {
            int j=i+1;
            int ch=0;
            while(isdigit(s[j])&&j<n)
            {
                j++;
            }
            j--;

            if(j==i&&s[j]=='-')
            {
                qDebug()<<"Bad number";
                delar();
                return false;
            }


            try
            {
                ch=stoi(s.substr(i,j-i+1));
            }
            catch(...)
            {
                qDebug()<<"Bad number";
                delar();
                return false;
            }

            if(ch>(int)1e9*2||ch<(int)1e9*(-2))
            {
                qDebug()<<"Bad number";
                delar();
                return false;
            }

            add(ch);
            //qDebug()<<"dsadasd";
            i=j+1;
        }
        //qDebug()<<"!"<<i;
    }

    return true;
}

bool MainWindow::check_el(std::string s)
{
    long long n=s.size();
    bool have_digit=false;
    for(long long i=0;i<n;i++)
    {
        if((!isdigit(s[i])&&s[i]!='-')||(s[i]=='-'&&i!=0))
            return false;
        if(isdigit(s[i]))have_digit=true;
    }

    if(!have_digit)
        return false;

            try
            {
                stoi(s.substr(0));
            }
            catch(...)
            {
                qDebug()<<"Bad elemnt";
                return false;
            }




            return true;
}

bool MainWindow::check_anc(std::vector<int> q, std::vector<int> w)
{

    bool used[q.size()];
    for(int i=0;i<q.size();i++) used[i]=false;
    for(int i=0;i<q.size();i++){
        int j=0;
        for(;j<w.size();j++)
        {
            if(!used[j]&&q[i]==w[j])
            {
                used[j]=true;
                break;
            }
        }
    }

    for(int i=0;i<q.size();i++) if(!used[i])return false;
    return true;
}

void MainWindow::delar()
{
    a.clear();
}

void MainWindow::add(int ch)
{
    a.push_back(ch);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    //qDebug()<<"PAINTEVENT";
    g.draw(&p);
}

void MainWindow::sort(std::vector<int>& arr)
{
    int size=arr.size();
    int min=arr[0];
    int max=arr[0];

    for(int i=1;i<size;i++)
    {
        if(arr[i]>max)
            max=arr[i];
        if(arr[i]<min)
            min=arr[i];
    }

    int delta=max-min;

    if(min!=max)
    {
        int start=0;
        std::vector<std::vector<int>>bucket(size);
        int key=0;

        for(int i=0;i<size;i++)
        {
            key=arr[i]-min;
            key/=(delta);
            key*=(size-1);
            bucket[key].push_back(arr[i]);
        }

        for(int i=0;i<size;i++)
        {
            if(bucket[i].size()>1)sort(bucket[i]);

            for(int j=0;j<bucket[i].size();j++)arr[start++]=bucket[i][j];
            if(a!=ancestors.back()&&check_anc(a,c))
            ancestors.push_back(a);

        }


    }
}

//BinFind
int MainWindow::binfind(int el)
{
    int l=0,r=a.size()-1;
    while(l<r)
    {
        int m=l+r;
        m/=2;

        if(a[m]==el)
        {
            g.paint(m);
            update();
            return m;
        }

        g.paint(l,r,m);
        update();

        if(a[m]>el)
            r=m-1;
        else
            l=m+1;
    }

    g.paint(-1488);
    if(a[l]!=el)return -1;

    g.paint(l);
    qDebug()<<l<<" "<<el;
    update();
    return binpow(l%el,a.size(),el);
}

void MainWindow::on_findButton_clicked()
{
    if(!check_el(ui->element->text().toUtf8().constData()))
    {
        ElementError;
        return;
    }

    if(last_sort_array!=ui->ArrayText->toPlainText().toStdString())
    {
        NotSortError;
        return;
    }
    int e=std::stoi(ui->element->text().toUtf8().constData());
    ui->index->setText(QString::fromStdString(std::to_string(binfind(e))));
}

long long MainWindow::binpow (int digit, int powder, int mod)
{
    if(powder==0)return 1;
    if(powder==1)return digit;
    if(powder%2==0)
    {
        long long a=binpow(digit,powder/2,mod)%mod;
        return (digit*digit)%mod;
    }
    return (digit*binpow(digit,powder-1,mod))%mod;
}

void MainWindow::on_sortButton_clicked()
{
    delar();
    ancestors.clear();
    step=0;
    std::string s=ui->ArrayText->toPlainText().toStdString();

    if(!check(s))
    {
        InputError;
        return;
    }

    g.set(a);
    c=a;
    update();
    qDebug()<<"All good. Go to sort";
    ancestors.push_back(a);
    sort(a);
    last_sort_array=ui->ArrayText->toPlainText().toStdString();
    step=ancestors.size()-1;
    printArray();
    //update();
}

void MainWindow::printArray()
{
    //return;
    qDebug()<<"Print Array was started";
    std::string s;
    for(int i=0;i<ancestors[step].size();i++)
    {
        s+=std::to_string(ancestors[step][i])+" ";
    }
    //qDebug()<<s;
    ui->sortarr->setText(QString::fromStdString(s));
    qDebug()<<"Print Array was finished";
    g.set(ancestors[step]);
    update();
}

void MainWindow::on_PrevStep_clicked()
{
    if(step==0)
    {
        QMessageBox::information(this,"Step error", "It's the first step", QMessageBox::Ok);
        return;
    }
    step--;
    printArray();
}


void MainWindow::on_NextStep_clicked()
{
    if(step==ancestors.size()-1)
    {
        QMessageBox::information(this,"Step error", "It's the last step", QMessageBox::Ok);
        return;
    }
    step++;
    printArray();
}

