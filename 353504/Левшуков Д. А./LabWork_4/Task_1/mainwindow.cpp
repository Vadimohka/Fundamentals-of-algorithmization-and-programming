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

void MainWindow::delar()
{
    siz=0;
    free(a);
    a=nullptr;
}

void MainWindow::add(int ch)
{
    a=(int *)realloc(a,(++siz)*sizeof(int));
    a[siz-1]=ch;
    //qDebug()<<ch;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    //qDebug()<<"PAINTEVENT";
    g.draw(&p);
}

void MainWindow::on_sortButton_clicked()
{
    delar();

    std::string s=ui->ArrayText->toPlainText().toStdString();

    if(!check(s))
    {
        InputError;
        return;
    }

    g.set(a,siz);

    qDebug()<<"All good. Go to sort";

    qDebug()<<"[Type of sort]\nHeap:"<<ui->Heap->isChecked()<<"\nQuick:"<<ui->Quick->isChecked()<<"\nMerge:"<<ui->Merge->isChecked();

    if(ui->Heap->isChecked())
    {
        ui->speed->setText(QString::fromStdString(std::to_string(heapSort(a,siz))));
    }

    if(ui->Quick->isChecked())
    {
        clock_t t1=clock();
        quickSort(a,0,siz-1);
        ui->speed->setText(QString::fromStdString(std::to_string(clock()-t1)));
    }
    if(ui->Merge->isChecked())
    {
        clock_t t1=clock();
        merge_sort(a,0,siz);
        ui->speed->setText(QString::fromStdString(std::to_string(clock()-t1)));
    }
    printArray(a,siz);
    update();
    last_sort_array=s;
}

//Heap sort
void MainWindow::heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

clock_t MainWindow::heapSort(int arr[], int n)
{
    clock_t t1=clock();
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Heap sort
    for (int i=n-1; i>=0; i--)
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }

    return clock()-t1;
}

void MainWindow::quickSort(int *arr, int l, int r)
{
    if(l<r)
    {
      int q=partition(a,l,r);
      quickSort(a,l,q);
      quickSort(a,q+1,r);
    }
    return;

}

void MainWindow::printArray(int arr[], int n)
{
    //return;
    qDebug()<<"Print Array was started";
    std::string s;
    for(int i=0;i<n;i++)
    {
        s+=std::to_string(arr[i])+" ";
    }
    //qDebug()<<s;
    ui->sortarr->setText(QString::fromStdString(s));
    qDebug()<<"Print Array was finished";
}

//BinFind
int MainWindow::binfind(int a[],int n,int el)
{
    int l=0,r=n-1;
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
    update();
    return l;
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
    ui->index->setText(QString::fromStdString(std::to_string(binfind(a,siz,e))));
}

int MainWindow::partition(int a[], int l, int r)
{
    int m=a[(l+r)/2];
    int i=l;
    int j=r;
    //int m=n/2;

    while(i<=j)
    {
        while(a[i]<m)
            i++;

        while(a[j]>m)
            j--;
        if(i>=j)
            break;

            std::swap(a[i],a[j]);
            i++;
            j--;

    }
    return j;
}

//MergeFind
void MainWindow::merge(int a[],int l,int mid, int r)
{
    int i=0,j=0;
    int *res=new int[r-l+1];
    while(l+i<mid&&mid+j<r)
    {
        if(a[i+l]<a[mid+j])
            res[i+j]=a[l+i],i++;
        else
        {
            res[i+j]=a[mid+j],j++;
        }
    }
    while(l+i<mid)
    {
        res[i+j]=a[l+i];
        i++;
    }
    while(j+mid<r)
    {
        res[i+j]=a[mid+j];
        j++;
    }

    for(int q=0;q<i+j;q++)
    {
        a[l+q]=res[q];
    }
    delete []res;
}

void MainWindow::merge_sort(int a[],int l, int r)
{
    if(l+1>=r)return;

    int mid=(l+r)/2;
    merge_sort(a,l,mid);
    merge_sort(a,mid,r);
    merge(a,l,mid,r);
}
