#include "mainwindow.h"
#include "./ui_mainwindow.h"
void MainWindow::change(){

    t1[i1]->setPos(t1[i1]->pos().x()-std::abs(j1-i1)*0.185,t1[i1]->pos().y());
    t1[j1]->setPos(t1[j1]->pos().x()+std::abs(j1-i1)*0.185,t1[j1]->pos().y());



}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(1900,700);
    for(int i=0;i<5000;++i){
        double kk=i;
     a[i]=  gen.bounded(0,10000)*0.01;
        QGraphicsRectItem *ll1=new QGraphicsRectItem(50+kk*0.185,-a[i]*6,0.0018,a[i]*6);

      t1.append(ll1);
        coordinates[i]=50+kk*0.185;
       coordinates1[i]=-a[i]*6;
      scene->addItem(t1[i]);
    }



}

int MainWindow::partition( int low, int high, double pivot){
     i1 = low;
     j1 = low;
    while( i1 <= high){
        if(a[i1] > pivot){
            i1++;
        }
        else{
            std::swap(a[i1],a[j1]);

            if(j1!=i1){
                change();
                QGraphicsRectItem *cc=new QGraphicsRectItem;
                cc=t1[i1];
                t1[i1]=t1[j1];
                t1[j1]=cc;
                scene->update();
                scene->update();
                scene->update();
                //timer->stop();



            }
            i1++;
            j1++;
        }
    }
    scene->update();
    return j1-1;
}
void MainWindow::sorting_q(QVector <QGraphicsRectItem*> t1,int left,int right){

    if(left < right){
        double pvt = a[right];
        int pos = partition(left, right, pvt);
         ui->graphicsView->viewport()->repaint();

        sorting_q(t1, left, pos-1);

        sorting_q(t1, pos+1, right);


    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    for(int i=0;i<10;++i){
        qDebug() << a[i];
    }
   sorting_q(t1,0,5000-1);
    for(int i=0;i<100;++i){
       qDebug() << a[i];
   }
    //t1[0]->setPos(std::abs(4)*10,t1[0]->pos().y());
    //t1[4]->setPos(-std::abs(4)*10,t1[4]->pos().y());

}
void MainWindow::heapify(double *a, int n, int i)
{
    int largest = i;

    int l = 2*i + 1;
    int r = 2*i + 2;


    if (l < n && a[l] > a[largest])
        largest = l;


    if (r < n && a[r] > a[largest])
        largest = r;


    if (largest != i)
    {
        std::swap(a[i], a[largest]);
        t1[i]->setPos(t1[i]->pos().x()+std::abs(i-largest)*0.185,t1[i]->pos().y());
        t1[largest]->setPos(t1[largest]->pos().x()-std::abs(i-largest)*0.185,t1[largest]->pos().y());
        QGraphicsRectItem *cc=new QGraphicsRectItem;
        cc=t1[i];
        t1[i]=t1[largest];
        t1[largest]=cc;

        heapify(a, n, largest);

    }

}


void MainWindow::heapSort(double *a, int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);


    for (int i=n-1; i>=0; i--)
    {

        std::swap(a[0], a[i]);
        t1[i]->setPos(t1[i]->pos().x()-std::abs(i)*0.185,t1[i]->pos().y());
        t1[0]->setPos(t1[0]->pos().x()+std::abs(i)*0.185,t1[0]->pos().y());
        QGraphicsRectItem *cc=new QGraphicsRectItem;
        cc=t1[i];
        t1[i]=t1[0];
        t1[0]=cc;


        heapify(a, i, 0);
         ui->graphicsView->viewport()->repaint();

    }
}

void MainWindow::on_pushButton_2_clicked()
{
    heapSort(a,5000);
}
void MainWindow::merge(double *a, int l, int m, int r) {

    int i1, j1, k, nl, nr;

    QGraphicsRectItem**t2=new QGraphicsRectItem*[5000];
     QGraphicsRectItem**t3=new QGraphicsRectItem*[5000];
    nl = m-l+1; nr = r-m;
    double* larr=new double[nl];
    double* rarr=new double[nr];
    double* c1=new double[nl];
    double* c2=new double[nr];

    for(int i = 0; i<nl; i++){
        larr[i] = a[l+i];
        c1[i]=(coordinates[l+i]);
        t2[i]=t1[l+i];
    }
    for(int j = 0; j<nr; j++){
        rarr[j] = a[m+1+j];
        c2[j]=(coordinates[m+1+j]);
        t3[j]=t1[m+1+j];
    }
    i1 = 0; j1 = 0; k = l;

    while(i1 < nl && j1<nr) {
        if(larr[i1] <= rarr[j1]) {
            a[k] = larr[i1];
           t2[i1]->moveBy(-(c1[i1]-coordinates[k]),t1[k]->pos().y());


            t1[k]=t2[i1];
            i1++;

        }else{
            a[k] = rarr[j1];
            t3[j1]->moveBy(-c2[j1]+coordinates[k],t1[k]->pos().y());

            t1[k]=t3[j1];
            j1++;
        }
        k++;
    }
    while(i1<nl) {
        a[k] = larr[i1];
       t2[i1]->moveBy(-(c1[i1]-coordinates[k]),t1[k]->pos().y());


        t1[k]=t2[i1];
        i1++; k++;
    }
    while(j1<nr) {
        a[k] = rarr[j1];
        t3[j1]->moveBy(-c2[j1]+coordinates[k],t1[k]->pos().y());


        t1[k]=t3[j1];
        j1++;
        k++;
    }
    delete[]larr;
    delete[]rarr;
    delete[]c1;
    delete[]c2;
   ui->graphicsView->viewport()->repaint();

}

void MainWindow::MergeSort(double* a, int l, int r) {

    int m;
    if(l < r) {
        int m = l+(r-l)/2;

        MergeSort(a, l, m);

        MergeSort(a, m+1, r);

        merge(a, l, m, r);

    }
   // ui->graphicsView->viewport()->repaint();

}

void MainWindow::on_pushButton_3_clicked()
{
  MergeSort(a,0,5000-1);




}

int MainWindow::binarysearch(double*a,int l,int r,double p){
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (a[mid] == p)
            return mid;

        if (a[mid] > p)
            return binarysearch(a, l, mid - 1, p);

        return binarysearch(a, mid + 1, r, p);
    }


    return -1;
}
void MainWindow::on_pushButton_4_clicked()
{
    ui->label_2->setText(QString::number(binarysearch(a,0,5000-1,a[0])));
    ui->label_4->setText(QString::number(a[0]));
}

